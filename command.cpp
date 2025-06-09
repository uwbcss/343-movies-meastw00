#include "command.h"
#include "store.h"
#include <iostream>

using namespace std;

/**
 * Storage place for the concrete command factories
 * Having it available only through this function guarantees that
 * this static variable is initialized
 * when a concrete factory tires to register itself
 * @return map
 */
map<string, CommandFactory *> &CommandFactory::getMap() {
  static map<string, CommandFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void CommandFactory::registerType(const string &type, CommandFactory *factory) {
  getMap().emplace(type, factory);
}
// find the corresponding command factory and get factory to create the object
Command *CommandFactory::create(const string &type) {
  if (getMap().count(type) == 0) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->makeCommand();
}