workspace "disana"
  configurations
	{
		"Debug",
		"Release",
		"Dist",
    "Testing"
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

  startproject "tests" -- temporary

  filter { "platforms:Win32" }
    system "Windows"
    architecture "x86"

  filter { "platforms:Win64" }
    system "Windows"
    architecture "x86_64"

  filter { "configurations:Test" }
    startproject "tests"

  filter { "configurations:Full-Test" }
    startproject "tests"
    defines "FULL_TEST"

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

  includeDir = {}
  includeDir["catch2"] = "%{wks.location}/lib/catch2/extras"

  -- Specify the folders of .lib files
  libraryDirs = {}

  -- Specify the actual .lib files (prefer using the libraryDirs variable)
  libraries = {}

include "disana"
include "disana-tests"
