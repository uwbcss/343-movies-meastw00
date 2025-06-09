#include "inventory.h"
#include "customer.h"
#include "hash.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

// Prints a list of all movies in reverse order by type, and then
// sorted by it's specific sorting method (ideally)
string Inventory::execute(map<string, Hashmap *, greater<string>> movieStocks,
                          map<int, Customer *> customers, string &s) {
  for (pair<string, Hashmap *> category : movieStocks) {
    priority_queue<Movie *> movies = category.second->getAll();
    while (!movies.empty()) {
      Movie *curr = movies.top();
      movies.pop();
      cout << curr->info() << endl;
    }
  }
  return "";
}

InventoryFactory::InventoryFactory() { registerType("I", this); }

Command *InventoryFactory::makeCommand() const { return new Inventory(); }

// creating the object registers the type at run time
InventoryFactory anonymousInventoryFactory;