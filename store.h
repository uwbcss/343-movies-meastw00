#ifndef STORE_H
#define STORE_H

#include "command.h"
#include "customer.h"
#include "hash.h"
#include "movie.h"
#include <map>
#include <set>
#include <vector>

using namespace std;

class Store {
private:
  map<string, Hashmap*, greater<string>> movieStocks;
  map<int, Customer*> customers;

  // Trims all spaces off the edges of the string
  static string trimString(const string &str);

  // helper - split string into multiple based on delimiter
  static vector<string> splitString(const string &str, char delimiter);

  // Removes all instances of the requested character from the string
  static void clearCharacter(string &str, char toRemove);

public:
  Store() {

  }

  ~Store() {
    for(pair<string, Hashmap*> hash : movieStocks) {
      delete hash.second;
    }
    for(pair<int, Customer*> customer : customers) {
      delete customer.second;
    }
  }

  // Reads the requested file for either command, customer, or movie
  // based on the keyword in the filename
  // A file can only contain one of the 3 between command, customer, or movie
  void readFile(string filename);

  // Checks if a command is valid before executing it if it is
  void receiveCommand(string &s);  

  // Returns the requested customer
  // Returns nullptr if it the ID does not exist
  Customer* getCustomer(int &id);

  // Returns the hashmap for the requested movie type
  // Returns nullptr if the movie type does not exist
  Hashmap* getCategory(string &s);
};

#endif // STORE_H