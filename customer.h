#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;


class Customer {
private:
  int id;
  string name;
  vector<string> history;

public:
  Customer(int id, string name) {
    this->id = id;
    this->name = name;
  }

  ~Customer() {

  }

  void updateHistory(string& s);

  bool verifyRental(string& s);

  vector<string> retrieveHistory();
};

#endif // CUSTOMER_H