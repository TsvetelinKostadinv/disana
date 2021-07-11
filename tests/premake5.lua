project "tests"
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

  includedirs
  {
    "src",
    "%{wks.location}/disana/src"
  }

  links
  {
    "disana"
  }

  defines
  {
    "_CRT_SECURE_NO_WARNINGS"
  }
