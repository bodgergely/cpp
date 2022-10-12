DIR="$HOME/workspace/cpp"
# clang++ -std=c++20 -g -O3 -march=native -Wall -Wextra -Werror -Weffc++ -Wpedantic -Wshadow -Wconversion -o $DIR/cpp/main $DIR/cpp/main.cpp
g++ -std=c++17 -g -O0 -march=native -Wall -Wextra -Werror -Wpedantic -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -o $DIR/cpp/main $DIR/cpp/main.cpp
# gcc -std=c99 -g -O0 -march=native -o $DIR/cpp/main $DIR/cpp/main.c
