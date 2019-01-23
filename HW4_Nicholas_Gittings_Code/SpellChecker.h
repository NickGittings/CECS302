#include <list>
#include <fstream>
#include <string>
#include "HashTable.h"

using namespace std;


class SpellChecker {
private:
  HashTable table;

public:
  SpellChecker(string dictFile) {
    ifstream file(dictFile);
    string line;
    if(file.is_open()) {
      while(getline(file,line)) table.insert(line);
      file.close();
      cout << "Dictionary Loaded..." << endl;
    }
    else cout << "File could not be opened" << endl;

  }

  void printTable() {
    table.printList();
  }

  bool check(string word) {
    return table.contains(word);
  }

  bool checkFile(string fileName) {
    ifstream file(fileName);
    string line;
    if(file.is_open()) {
      while(getline(file, line)) {
        if(!check(line)) {
          cout << line << endl;
        }
      }
    }
  }


};
