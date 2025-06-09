#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include "customer.h"
#include "hash.h"
#include <map>

class Return : public Command {
private:
  static string trimString(const string &str);
public:
  string execute(map<string, Hashmap *, greater<string>> movieStocks, map<int, Customer*> customers, string& s) override;
};

class ReturnFactory : public CommandFactory {
public:
  ReturnFactory();
  Command *makeCommand() const override;
};

#endif // RETURN_H