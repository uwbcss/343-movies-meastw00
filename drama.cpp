#include "drama.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

Drama::Drama(vector<string> details) {
  stock = stoi(details[1]);
  director = details[2];
  title = details[3];
  year = details[4];
}

// Compares this object with another of the same type
bool Drama::compare(const Drama *other) const {
  if (director != other->director) {
    return director < other->director;
  }
  return title < other->title;
}

// Returns the string containing the formatted information about the movie
string Drama::info() const {
  string out =
      "D, " + to_string(stock) + ", " + director + ", " + title + ", " + year;
  return out;
}

// Returns the values used for sorting between instances of the movie type
pair<string, string> Drama::sorting() const { return {director, title}; }

DramaFactory::DramaFactory() { registerType("D", this); }

Movie *DramaFactory::makeMovie(vector<string> details) const {
  return new Drama(details);
}

// creating the object registers the type at run time
DramaFactory anonymousDramaFactory;
