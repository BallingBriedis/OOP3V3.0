@echo off

if not exist build (
    mkdir build
)

cd build
cmake ..
cmake --build . --config Release
cmake --install . --config Release
cd ..
copy src\*.txt build\Release\*.txt
cd build\Release\
OOP2V12.exe
pause