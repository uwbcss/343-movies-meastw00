#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
#include "customer.h"
#include "hash.h"
#include <map>

class Inventory : public Command {
public:
  string execute(map<string, Hashmap *, greater<string>> movieStocks, map<int, Customer*> customers, string& s) override;
};

class InventoryFactory : public CommandFactory {
public:
  InventoryFactory();
  Command *makeCommand() const override;
};

#endif // INVENTORY_H