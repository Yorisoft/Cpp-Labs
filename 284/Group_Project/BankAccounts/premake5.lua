-- premake5.lua

--[[ dialect { 
   ['C'] = 'C99', 
   ['C++'] = 'C++11' 
} ]]
workspace "testProject"
   configurations { "deposit-fees-test", "Debug", "Release" }
   
project "BankAccounts"
   location "testProject"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   files { "**.h", "**.cpp" }
   

   filter {"configurations:Debug"}
      excludes "checking-account-deposit-fees.test.cpp"
      cppdialect "C++11"
      defines { "DEBUG" }
      symbols "On"

   filter {"configurations:Release"}
      excludes "checking-account-deposit-fees.test.cpp"
      cppdialect "C++11"
      defines { "NDEBUG" }
      optimize "On"

   filter {"configurations:deposit-fees-test"}
      excludes "main.cpp"
      cppdialect "C++11"
      defines { "NDEBUG" }
      optimize "On"