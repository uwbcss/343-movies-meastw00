#include "hash.h"
#include "movie.h"
#include <iostream>
#include <queue>

using namespace std;

// Takes a string, sums the ascii values of it's characters,
// and returns the remained of it divided by the hashmap size
int Hashmap::hash(string s) {
  int num = 0;
  for (char c : s) {
    num += c;
  }
  return (num % 101);
}

// Adds a new movie object pointer into the hashmap
// Attempts to place it by the first sorting method
// Then attempts the second repeatedly
// Will fail if no spot can be found within 101 attempts
void Hashmap::add(Movie *m) {
  pair<string, string> sort = m->sorting();
  int hashFirst = hash(sort.first);
  if (movies[hashFirst] == nullptr) {
    movies[hashFirst] = m;
    return;
  }
  if (movies[hashFirst] == m) {
    return;
  }
  int hashSecond = hash(sort.second);
  int attempts = 1;
  while (attempts <= 100) {
    if (movies[(hashFirst + (attempts * hashSecond)) % 101] == nullptr) {
      movies[(hashFirst + (attempts * hashSecond)) % 101] = m;
      return;
    }
    if (movies[(hashFirst + (attempts * hashSecond)) % 101] == m) {
      return;
    }
    attempts++;
  }
  cout << "Cannot find hashmap space" << endl;
}

// Removes a movie from the hashmap
// Attempts to find it by the first sorting method
// Then attempts the second repeatedly
// Will fail if the object is not found within 101 attempts
void Hashmap::remove(pair<string, string> sort) {
  int hashFirst = hash(sort.first);
  if (movies[hashFirst]->sorting() == sort) {
    movies[hashFirst] = nullptr;
  } else {
    int hashSecond = hash(sort.second);
    int attempts = 1;
    while (attempts <= 100) {
      if (movies[(hashFirst + (attempts * hashSecond)) % 101]->sorting() ==
          sort) {
        movies[(hashFirst + (attempts * hashSecond)) % 101] = nullptr;
        return;
      }
      attempts++;
    }
    cout << "Item is not in map" << endl;
  }
}

// Returns a movie from the hashmap
// Attempts to find it by the first sorting method
// Then attempts the second repeatedly
// Will fail if the object is not found within 101 attempts
Movie *Hashmap::get(pair<string, string> sort) {
  int hashFirst = hash(sort.first);
  if (movies[hashFirst] != nullptr && movies[hashFirst]->sorting() == sort) {
    return movies[hashFirst];
  }
  int hashSecond = hash(sort.second);
  int attempts = 1;
  while (attempts <= 100) {
    if (movies[(hashFirst + (attempts * hashSecond)) % 101] == nullptr) {
      cout << "Movie does not exist" << endl;
      return nullptr;
    }
    if (movies[(hashFirst + (attempts * hashSecond)) % 101]->sorting() ==
        sort) {
      return movies[(hashFirst + (attempts * hashSecond)) % 101];
    }
    attempts++;
  }
  cout << "Item is not in map" << endl;
  return nullptr;
}

// Returns all movie objects from the map in sorted order
priority_queue<Movie *> Hashmap::getAll() {
  priority_queue<Movie *> list;
  // Movie *one = nullptr;
  // Movie *two = nullptr;
  for (Movie *m : movies) {
    if (m != nullptr) {
      // if(one == nullptr && two == nullptr) {
      //   two = m;
      // }
      // one = m;
      // auto temp1 = one->sorting();
      // auto temp2 = two->sorting();
      // bool test = *one < *two;
      // cout << "Comparison test: " << test << endl;
      list.push(m);
      // two = m;
    }
  }
  return list;
}