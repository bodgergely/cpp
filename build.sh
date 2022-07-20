DIR='/c/Users/gergely.bod/workspace/cpp'
# clang++ -std=c++20 -g -O3 -march=native -Wall -Wextra -Werror -Wpedantic -Wshadow -Wconversion -o $DIR/cpp/main.exe $DIR/cpp/main.cpp
g++ -std=c++17 -g -O0 -march=native -Wall -Wextra -Wno-sign-compare -o $DIR/cpp/main.exe $DIR/cpp/main.cpp
# gcc -std=c99 -g -O0 -march=native -o $DIR/cpp/main.exe $DIR/cpp/main.c
