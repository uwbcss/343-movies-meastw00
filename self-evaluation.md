# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: -1

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Partial, I could not for the life of me get the Movies to be in sorted order
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: command.cpp line 26

invalid movie type: movie.cpp line 25, borrow.cpp line 55, and return.cpp line 55

invalid customer ID: borrow.cpp line 58 and return.cpp line 58
 
invalid movie: hash.cpp line 69

factory classes: BorrowFactory, ClassicsFactory, ComedyFactory, CommandFactory, DramaFactory, HistoryFactory, InventoryFactory, MovieFactory, ReturnFactory

hashtable: It holds the movies from a given category within it, placing them using double hashing based on their first then second sorted orders

container used for comedy movies: Hashmap

function for sorting comedy movies: The operator< overload within each movie type's file

function where comedy movies are sorted: The add function in hash.cpp and the getAll function in hash.cpp

functions called when retrieving a comedy movie based on title and year: The get function in hash.cpp and the sorting function in comedy.cpp

functions called for retrieving and printing customer history: The execute function within history.cpp and the getAll function within hash.cpp

container used for customer history: A vector within each customer object holds each previous command as a string

functions called when borrowing a movie: The execute and trimString function in borrow.cpp, the adjustStock function in movie.cpp

explain borrowing a movie that does not exist: If someone attempts to borrow a movie that does not exist, the message "Movie does not exist" is printed to the console and no actions are done

explain borrowing a movie that has 0 stock: If someone attempts to borrow a movie that is out of stock, the message "Not enough stock available" will be printed to the console and no actions will be done

explain returning a movie that customer has not checked out: If someone attempts to return a movie that they do not currently have at least one borrowed copy of, the message "Customer has not borrowed any copies to return" will be printed to the console and no actions are done

any static_cast or dynamic_cast used: I used dynamic_cast in my attempts to sort, but the lines of code where they are is never reached

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? There are multiple files that should work and can successfully compile and run without those functions




Q: Total points: 29 (max 25 (+ 5 Bonus))