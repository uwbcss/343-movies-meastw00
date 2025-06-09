#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <iostream>


class Comedy : public Movie {
private:
  bool compare(const Comedy* other) const;
public:
  explicit Comedy(vector<string> details);

  // Returns the string containing the formatted information about the movie
  string info() const override;

  // Returns the values used for sorting between instances of the movie type
  pair<string, string> sorting() const override;

  // Defines how instances of this movie type are compared to eachother
  bool operator<(Movie* other) const override {
    Comedy* temp = dynamic_cast<Comedy*>(other);
    if(temp != NULL) {
      return compare(temp);
    }
    cout << "Illegal comparison between objects" << endl;
    return false;
  }
};

class ComedyFactory : public MovieFactory {
public:
  ComedyFactory();
  Movie *makeMovie(vector<string> details) const override;
};

#endif // COMEDY_H