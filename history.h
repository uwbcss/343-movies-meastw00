#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"
#include "customer.h"
#include "hash.h"
#include <map>

class History : public Command {
public:
  string execute(map<string, Hashmap *, greater<string>> movieStocks, map<int, Customer*> customers, string& s) override;
};

class HistoryFactory : public CommandFactory {
public:
  HistoryFactory();
  Command *makeCommand() const override;
};

#endif // HISTORY_H