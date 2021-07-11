includeDir = {}

-- Specify the folders of .lib files
libraryDirs = {}

-- Specify the actual .lib files (prefer using the libraryDirs variable)
libraries = {}

workspace "disana"
  configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

  platforms
  {
    "Win32",
    "Win64"
  }

  flags
  {
    "MultiProcessorCompile"
  }

  filter { "platforms:Win32" }
    system "Windows"
    architecture "x86"

  filter { "platforms:Win64" }
    system "Windows"
    architecture "x86_64"

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  project "disana"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
      "src/**.h",
      "src/**.cpp",
      ".clang-format"
    }

    defines
    {
      "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
  	{
  		"src"
    }

    filter "system:windows"
  		systemversion "latest"

    filter "configurations:Debug"
    	defines "DISANA_DEBUG"
  		runtime "Debug"
  		symbols "on"

    filter "configurations:Release"
  		defines "DISANA_RELEASE"
  		runtime "Release"
  		optimize "on"

    filter "configurations:Dist"
  		defines "DISANA_DIST"
  		runtime "Release"
  		optimize "on"
