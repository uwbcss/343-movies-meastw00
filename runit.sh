#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling with everything"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp store_test.cpp hash.cpp customer.cpp store.cpp movie.cpp classic.cpp comedy.cpp drama.cpp command.cpp borrow.cpp history.cpp inventory.cpp return.cpp
./a.out 