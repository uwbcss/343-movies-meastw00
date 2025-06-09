#include "return.h"
#include "customer.h"
#include "hash.h"
#include "movie.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Trims all spaces off the edges of the string
string Return::trimString(const string &str) {
  string temp = str.substr(0, str.find(','));
  return temp.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}

// Increases the stock of the requested movie by one
// If the movie does not exist, the customer hasn't borrowed any copies,
// or the customer ID doesn't exist it prints a statement to the console
string Return::execute(map<string, Hashmap *, greater<string>> movieStocks,
                       map<int, Customer *> customers, string &s) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);
  while (getline(tokenStream, token, ' ')) {
    tokens.push_back(token);
  }
  int id = stoi(tokens[1]);
  Hashmap *category = movieStocks[tokens[3]];
  Customer *customer = customers[id];
  if (category != nullptr && customer != nullptr) {
    pair<string, string> search;
    bool comma = false;
    for (int i = 4; i < tokens.size(); i++) {
      if (comma) {
        search.second += tokens[i] + " ";
      } else {
        search.first += tokens[i] + " ";
        if (tokens[i].find(',') < tokens[i].size()) {
          comma = true;
        }
      }
    }
    if (!comma) {
      search.first = tokens[4] + " " + tokens[5];
      for (int i = 6; i < tokens.size(); i++) {
        search.second += tokens[i] + " ";
      }
    }
    search.first = trimString(search.first);
    search.second = trimString(search.second);
    Movie *found = category->get(search);
    if (found != nullptr && customer->verifyRental(s)) {
      found->adjustStock(-1);
      customer->updateHistory(s);
    }
  } else {
    if (category != nullptr) {
      cout << "Movie type does not exist" << endl;
    }
    if (customer != nullptr) {
      cout << "Customer ID does not exist" << endl;
    }
  }
  return "";
}

ReturnFactory::ReturnFactory() { registerType("R", this); }

Command *ReturnFactory::makeCommand() const { return new Return(); }

// creating the object registers the type at run time
ReturnFactory anonymousReturnFactory;