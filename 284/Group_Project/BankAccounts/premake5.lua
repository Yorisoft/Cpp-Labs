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
   language "C++11"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
