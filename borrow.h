#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include "customer.h"
#include "hash.h"
#include <map>

class Borrow : public Command {
private:
  static string trimString(const string &str);
public:
  // Decreases the stock of the requested movie by one
  // If the movie does not exist, doesn't have stock left, 
  // or the customer ID doesn't exist it prints a statement to the console
  string execute(map<string, Hashmap *, greater<string>> movieStocks, map<int, Customer*> customers, string& s) override;
};

class BorrowFactory : public CommandFactory {
public:
  BorrowFactory();
  Command *makeCommand() const override;
};

#endif // BORROW_H