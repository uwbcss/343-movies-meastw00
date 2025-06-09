#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"
#include <iostream>

class Classics : public Movie {
private:
  string month;
  string actor;

  bool compare(const Classics* other) const;
public:
  explicit Classics(vector<string> details);

  // Returns the string containing the formatted information about the movie
  string info() const override;

  // Returns the values used for sorting between instances of the movie type
  pair<string, string> sorting() const override;

  // Defines how instances of this movie type are compared to eachother
  bool operator<(Movie* other) const override{
    Classics* temp = dynamic_cast<Classics*>(other);
    if(temp != NULL) {
      return compare(temp);
    }
    cout << "Illegal comparison between objects" << endl;
    return false;
  }
};

class ClassicsFactory : public MovieFactory {
public:
  ClassicsFactory();
  Movie *makeMovie(vector<string> details) const override;
};

#endif // CLASSICS_H