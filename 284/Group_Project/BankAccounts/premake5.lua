-- premake5.lua
workspace "testProject"
   configurations { "Debug", "Release" }

project "BankAccounts"
   location "testProject"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   dialect { 
      ['C'] = 'C99', 
      ['C++'] = 'C++11' 
  }

   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
