
#include "classics.h"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Trims spaces off the ends of the string
string trimString(const string &str) {
  return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}

Classics::Classics(vector<string> details) {
  stock = stoi(details[1]);
  director = details[2];
  title = details[3];
  vector<string> tokens;
  string token;
  istringstream tokenStream(details[4]);
  while (getline(tokenStream, token, ' ')) {
    tokens.push_back(trimString(token));
  }
  actor = tokens[0] + " " + tokens[1];
  month = tokens[2];
  year = tokens[3];
}

// Compares this object with another of the same type
bool Classics::compare(const Classics *other) const {
  if (year != other->year) {
    return year < other->year;
  }
  if (month != other->month) {
    return month < other->month;
  }
  return actor < other->actor;
}

// Returns the string containing the formatted information about the movie
string Classics::info() const {
  string out = "C, " + to_string(stock) + ", " + director + ", " + title +
               ", " + actor + " " + month + " " + year;
  return out;
}

// Returns the values used for sorting between instances of the movie type
pair<string, string> Classics::sorting() const {
  return {month + " " + year, actor};
}

ClassicsFactory::ClassicsFactory() { registerType("C", this); }

Movie *ClassicsFactory::makeMovie(vector<string> details) const {
  return new Classics(details);
}

// creating the object registers the type at run time
ClassicsFactory anonymousClassicsFactory;