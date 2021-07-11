project "disana"
  kind "StaticLib"
  language "C++"
  cppdialect "C++17"
  staticruntime "off"

  targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
  objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

  removeconfigurations "Testing"

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
