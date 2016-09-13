del /F /Q /S /AH ipch\*
rmdir /Q /S ipch

del /F /Q /S /AH packages\*
rmdir /Q /S packages

del /F /Q /S /AH Output\*
rmdir /Q /S Output

del /F /Q /S /AH .vs\*
rmdir /Q /S .vs

del /F /Q /S /AH Debug\*
rmdir /Q /S Debug

del /F /Q /S /AH Platforms\Android-Application\ARM
rmdir /Q /S Platforms\Android-Application\ARM

del /F /Q /S /AH Platforms\Android-Application\ARM64
rmdir /Q /S Platforms\Android-Application\ARM64

del /F /Q /S /AH Platforms\Android-Application\x64
rmdir /Q /S Platforms\Android-Application\x64

del /F /Q /S /AH Platforms\Android-Application\x86
rmdir /Q /S Platforms\Android-Application\x86

del /F /Q *.db
