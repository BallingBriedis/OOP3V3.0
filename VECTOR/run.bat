@echo off

if not exist build (
    mkdir build
)

cd build
cmake ..
cmake --build . --config Release

echo.
echo Building and running main application...
cd ..
copy src\*.txt build\Release\*.txt 2>nul
cd build\Release

echo Running tests...
cd ..
if exist Release\OOP2V20_tests.exe (
    Release\OOP2V20_tests.exe
) else if exist Debug\OOP2V20_tests.exe (
    Debug\OOP2V20_tests.exe
) else if exist OOP2V20_tests.exe (
    OOP2V20_tests.exe
) else (
    echo Test executable not found!
)

cd Release
echo Running main executable...
OOP2V20.exe

pause