#ifndef HASH_H
#define HASH_H

#include "movie.h"
#include <queue>
#include <vector>

using namespace std;


class Hashmap {
private:
  vector<Movie*> movies;

  static int hash(string s);

public:
  Hashmap() : movies(101) {
    for(int i = 0; i < movies.size(); i++) {
      movies[i] = nullptr;
    }
  }

  ~Hashmap() {
    for(int i = 0; i < movies.size(); i++) {
      if(movies[i] != nullptr) {
        delete movies[i];
        movies[i] = nullptr;
      }
    }
  }

  // Adds a new movie object to the hashmap
  // If the map already contains the item, the item will not be added
  // If space cannot be found, the item will not be added
  void add(Movie* m);

  // Removes the requested movie from the hashmap
  // If the movie cannot be found nothing will be removed
  void remove(pair<string, string> sort);

  // Gets the requested movie from the hashmap
  // If the movie is not found it will return nullptr
  Movie* get(pair<string, string> sort);

  // Returns a priority queue containing every movie in the hashmap
  priority_queue<Movie*> getAll();
};

#endif // HASH_H