#ifndef COMMAND_H
#define COMMAND_H

#include "customer.h"
#include "hash.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration, will declare class Command fully later
class Command;

// An abstract CommandFactory, each subclass of Command needs its own concrete version
class CommandFactory {
public:
  virtual Command *makeCommand() const = 0;

  // find the corresponding command factory and get factory to create the object
  static Command *create(const string &type);

protected:
  // register a concrete factory with a given name
  static void registerType(const string &type, CommandFactory *factory);

private:
  /**
   * Storage place for the concrete command factories
   * Having it available only through this function guarantees that
   * this static variable is initialized
   * when a concrete factory tires to register itself
   * @return map
   */
  static map<string, CommandFactory *> &getMap();
};

/**
 * The abstract class at the top of the hierarchy
 * All commands are derived from this class
 **/
class Command {
public:
  // Different commands have do different operations and must all implement it
  virtual string execute(map<string, Hashmap *, greater<string>> movieStocks, map<int, Customer*> customers, string& s) = 0;

  // Abstract classes should always have virtual destructors
  // not really used in this case
  virtual ~Command() = default;
};

#endif // COMMAND_H