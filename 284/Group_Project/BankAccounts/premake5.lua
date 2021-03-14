-- premake5.lua
workspace "testProject"
   configurations { "Debug", "Release" }

--[[ dialect { 
   ['C'] = 'C99', 
   ['C++'] = 'C++11' 
} ]]

project "BankAccounts"
   location "testProject"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      cppdialect "C++11"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      cppdialect "C++11"
      defines { "NDEBUG" }
      optimize "On"
