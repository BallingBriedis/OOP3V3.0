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
if exist Release\OOP3V30_tests.exe (
    Release\OOP3V30_tests.exe
) else if exist Debug\OOP3V30_tests.exe (
    Debug\OOP3V30_tests.exe
) else if exist OOP3V30_tests.exe (
    OOP3V30_tests.exe
) else (
    echo Test executable not found!
)

cd Release
echo Running main executable...
OOP3V30.exe

pause