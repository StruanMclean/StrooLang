rm -rf build
cmake -S . -B build
cmake --build build
cd build
cmake ..
make
cd ..
./build/StrooLang repl