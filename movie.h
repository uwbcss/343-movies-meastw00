#ifndef MOVIE_H
#define MOVIE_H

#include <map>
#include <string>
#include <vector>

using namespace std;

// forward declaration, will declare class Movie fully later
class Movie;

// An abstract MovieFactory, each subclass of Movie needs its own concrete version
class MovieFactory {
public:
  virtual Movie *makeMovie(vector<string> details) const = 0;

  // find the corresponding movie factory and get factory to create the object
  static Movie *create(const string &type, vector<string> details);

protected:
  // register a concrete factory with a given name
  static void registerType(const string &type, MovieFactory *factory);

private:
  /**
   * Storage place for the concrete movie factories
   * Having it available only through this function guarantees that
   * this static variable is initialized
   * when a concrete factory tires to register itself
   * @return map
   */
  static map<string, MovieFactory *> &getMap();
};

/**
 * The abstract class at the top of the hierarchy
 * All Movies are derived from this class
 * Stores movie factories and creates movie objects through static functions
 **/
class Movie {
public:
  // Comparison for different movie types, all must implement it
  virtual bool operator<(Movie* other) const = 0;

  // different movie have different information display formats so they must all implement it
  virtual string info() const = 0;

  // Used to return the specific items used to sort a given movie type
  virtual pair<string, string> sorting() const = 0;

  bool adjustStock(const int &adjustment);

  // Abstract classes should always have virtual destructors
  // not really used in this case
  virtual ~Movie() = default;

protected:
  int stock;
  string director;
  string title;
  string year;
};

#endif // MOVIE_H