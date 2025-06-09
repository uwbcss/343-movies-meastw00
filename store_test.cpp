/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

// #include "movie.h"
#include "store.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  cout << "End testStore1" << endl;
}

void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "Comparison testing" << endl;
  // string m1 = {"C", "10", "Michael Curtiz", "Casablanca", "Humphrey Bogart",
  // } Humphrey Bogart 8 1942"; string m2 = "C, 10, Victor Fleming, The Wizard
  // of Oz, Judy Garland 7 1939";

  // Movie* one = MovieFactory::create("C", m1);
  cout << "End testStore2" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  Store movieShop;
  movieShop.readFile("data4movies.txt");
  cout << "data4movies.txt read to completion" << endl << endl;
  movieShop.readFile("data4customers.txt");
  cout << "data4customers.txt read to completion" << endl << endl;
  movieShop.readFile("data4commands.txt");
  cout << "data4commands.txt read to completion" << endl << endl;
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testStore1();
  testStore2();
  testStoreFinal();
}
