#include "store.h"
#include "command.h"
#include "customer.h"
#include "movie.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Trims all spaces off the edges of the string
string Store::trimString(const string &str) {
  return str.substr(str.find_first_not_of(' '), str.find_last_not_of(' ') + 1);
}

// helper - split string into multiple based on delimiter
vector<string> Store::splitString(const string &str, char delimiter) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiter)) {
    tokens.push_back(trimString(token));
  }
  return tokens;
}

// Removes all instances of the requested character from the string
void Store::clearCharacter(string &str, char toRemove) {
  str.erase(remove(str.begin(), str.end(), toRemove), str.end());
}

// Checks if the string is made of exclusively numbers
bool isNumbers(string &s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] > 57 || s[i] < 48) {
      return false;
    }
  }
  return true;
}

// Reads the requested file for either command, customer, or movie
// based on the keyword in the filename
// A file can only contain one of the 3 between command, customer, or movie
void Store::readFile(string filename) {
  ifstream fs(filename);
  if (!fs.is_open()) {
    cerr << "Could not open file: " << filename << endl;
  }
  cout << filename << endl;
  string str;
  if (filename.find("movie") < filename.length()) {
    while (getline(fs, str) && !str.empty()) {
      vector<string> vs = splitString(str, ',');
      Movie *curr = MovieFactory::create(vs[0], vs);
      if (curr != nullptr) {
        if (movieStocks[vs[0]] == nullptr) {
          movieStocks[vs[0]] = new Hashmap();
        }
        movieStocks[vs[0]]->add(curr);
      }
    }
  } else if (filename.find("command") < filename.length()) {
    while (getline(fs, str) && !str.empty()) {
      receiveCommand(str);
    }
  } else if (filename.find("customer") < filename.length()) {
    while (getline(fs, str) && !str.empty()) {
      vector<string> vs = splitString(str, ' ');
      if (isNumbers(vs[0]) && vs[0].size() == 4 && vs.size() == 3) {
        if (customers.count(stoi(vs[0])) > 0) {
          cout << "Customer already exists" << endl;
        } else {
          Customer *created = new Customer(stoi(vs[0]), vs[1] + " " + vs[2]);
          customers[stoi(vs[0])] = created;
        }
      }
    }
  } else {
    cout << "File name does not follow naming conventions" << endl;
  }
}

// Checks if a command is valid before executing it if it is
void Store::receiveCommand(string &s) {
  // cout << s.substr(0, s.find(" ")) << endl;
  Command *command = CommandFactory::create(s.substr(0, s.find(" ")));
  if (command != nullptr) {
    command->execute(movieStocks, customers, s);
    delete command;
  }
}

// Returns the requested customer
// Returns nullptr if it the ID does not exist
Customer *Store::getCustomer(int &id) {
  if (customers.count(id) > 0) {
    return customers[id];
  }
  cout << "Customer does not exist" << endl;
  return nullptr;
}

// Returns the hashmap for the requested movie type
// Returns nullptr if the movie type does not exist
Hashmap *Store::getCategory(string &s) {
  if (movieStocks.count(s) > 0) {
    return movieStocks[s];
  }
  cout << "Movie type not found" << endl;
  return nullptr;
}