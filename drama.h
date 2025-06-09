#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include <iostream>

class Drama : public Movie {
private:
  bool compare(const Drama* other) const;
public:
  explicit Drama(vector<string> details);

  // Returns the string containing the formatted information about the movie
  string info() const override;

  // Returns the values used for sorting between instances of the movie type
  pair<string, string> sorting() const override;

  // Defines how instances of this movie type are compared to eachother
  bool operator<(Movie* other) const override {
    Drama* temp = dynamic_cast<Drama*>(other);
    if(temp != NULL) {
      return compare(temp);
    }
    cout << "Illegal comparison between objects" << endl;
    return false;
  }
};

class DramaFactory : public MovieFactory {
public:
  DramaFactory();
  Movie *makeMovie(vector<string> details) const override;
};

#endif // DRAMA_H