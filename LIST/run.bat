@echo off

if not exist build (
    mkdir build
)

cd build
cmake ..
cmake --install .
cmake --build .
cd ..
copy src\*.txt build\Debug\*.txt
cd build\Debug\
MyContainerExecutable.exe
pause