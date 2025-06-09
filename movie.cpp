#include "movie.h"
#include <iostream>

using namespace std;

/**
 * Storage place for the concrete movie factories
 * Having it available only through this function guarantees that
 * this static variable is initialized
 * when a concrete factory tires to register itself
 * @return map
 */
map<string, MovieFactory *> &MovieFactory::getMap() {
  static map<string, MovieFactory *> factories;
  return factories;
}

// register a concrete factory with a given name
void MovieFactory::registerType(const string &type, MovieFactory *factory) {
  getMap().emplace(type, factory);
}

// find the corresponding movie factory and get factory to create the object
Movie *MovieFactory::create(const string &type, vector<string> details) {
  if (getMap().count(type) == 0) {
    cout << "Don't know how to create " << type << endl;
    return nullptr;
  }
  return getMap().at(type)->makeMovie(details);
}

// Adjusts the value of the stock by the requested amount
// If there is not enough stock to make the adjustment it prints
// an error message to the console
bool Movie::adjustStock(const int &adjustment) {
  if (stock < adjustment) {
    cout << "Not enough stock available" << endl;
    return false;
  }
  stock -= adjustment;
  return true;
}
