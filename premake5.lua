workspace "Render"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" } 

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["SDL2"] = "Algernon/vendor/SDL/include"

LibraryDir = {}
LibraryDir["SDL2"] = "Algernon/vendor/SDL/lib"

Libraries = {}
Libraries["SDL2"] = "SDL2"
Libraries["SDL2main"] = "SDL2main"

-- group "Dependencies"
-- 	include "Algernon/vendor/SDL"

project "Algernon"
    location "Algernon"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    group "Headers"
    files
    {
        "%{prj.name}/src/**.h",
    }

    group "Sources"
    files
    {
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{IncludeDir.SDL2}"
    }

    filter "system:windows"
		systemversion "latest"

        libdirs
        {
            "%{LibraryDir.SDL2}"  -- Directory where SDL2.lib is located
        }

        links
        {
            "%{Libraries.SDL2}",
            "%{Libraries.SDL2main}",
        }

    filter "configurations:Debug"
		defines "AL_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "AL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "AL_DIST"
		runtime "Release"
		optimize "on"