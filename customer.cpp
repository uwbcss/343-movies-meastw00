#include "customer.h"
#include <iostream>

using namespace std;

// Adds the most recent user action to their history
void Customer::updateHistory(string &s) { history.push_back(s); }

// Checks to see that the customer currently has the requested movie rented out
bool Customer::verifyRental(string &str) {
  string s = str.substr(2);
  int count = 0;
  for (string action : history) {
    if (action == "B " + s) {
      count++;
    } else if (action == "R " + s) {
      count--;
    }
  }
  if (count > 0) {
    return true;
  }
  if (count < 0) {
    cout << "Customer has returned more copies of this movie than they borrowed"
         << endl;
  }
  cout << "Customer has not borrowed any copies to return" << endl;
  return false;
}

// Returns the customer's whole history
vector<string> Customer::retrieveHistory() { return history; }