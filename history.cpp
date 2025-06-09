
#include "history.h"
#include "customer.h"
#include "hash.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Prints the history of the requested customer's actions
// Printed order is chronological
string History::execute(map<string, Hashmap *, greater<string>> movieStocks,
                        map<int, Customer *> customers, string &s) {
  // string str = s.substr(s.find(' '));
  Customer *user = customers[stoi(s.substr(s.find(' ')))];
  if (user != nullptr) {
    vector<string> history = user->retrieveHistory();
    for (string next : history) {
      cout << next << endl;
    }
    if (history.empty()) {
      cout << "Customer does not have any history yet" << endl;
    }
  } else {
    cout << "Customer ID does not exist" << endl;
  }
  return "";
}

HistoryFactory::HistoryFactory() { registerType("H", this); }

Command *HistoryFactory::makeCommand() const { return new History(); }

// creating the object registers the type at run time
HistoryFactory anonymousHistoryFactory;