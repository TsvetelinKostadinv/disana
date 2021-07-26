project "disana-tests"
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
    "%{wks.location}/lib/catch2/extras/catch_amalgamated.cpp",
    ".clang-format"
  }

  includedirs
  {
    "src",
    "%{wks.location}/disana/src",
    "%{includeDir.catch2}"
  }

  links
  {
    "disana"
  }

  defines
  {
    "_CRT_SECURE_NO_WARNINGS"
  }
