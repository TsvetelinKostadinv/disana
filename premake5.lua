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

  filter { "configurations:Testing" }
    startproject "tests"

  outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "disana"
include "tests"
