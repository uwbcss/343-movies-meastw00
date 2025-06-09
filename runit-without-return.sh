#!/bin/bash

# shortcut to compile and run the program

echo "========================="
echo "* Compiling without return.cpp"
rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp store_test.cpp hash.cpp customer.cpp store.cpp movie.cpp classics.cpp comedy.cpp drama.cpp command.cpp borrow.cpp history.cpp inventory.cpp
./a.out 