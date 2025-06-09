
#include "comedy.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Comedy::Comedy(vector<string> details) {
  stock = stoi(details[1]);
  director = details[2];
  title = details[3];
  year = details[4];
}

// Compares this object with another of the same type
bool Comedy::compare(const Comedy *other) const {
  if (title != other->title) {
    return title < other->title;
  }
  return year < other->year;
}

// Returns the string containing the formatted information about the movie
string Comedy::info() const {
  string out =
      "F, " + to_string(stock) + ", " + director + ", " + title + ", " + year;
  return out;
}

// Returns the values used for sorting between instances of the movie type
pair<string, string> Comedy::sorting() const { return {title, year}; }

ComedyFactory::ComedyFactory() { registerType("F", this); }

Movie *ComedyFactory::makeMovie(vector<string> details) const {
  return new Comedy(details);
}

// creating the object registers the type at run time
ComedyFactory anonymousComedyFactory;
