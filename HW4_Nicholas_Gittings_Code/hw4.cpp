#include <iostream>
#include "SpellChecker.h"
using namespace std;

//Client to test SpellChecker
int main(void) {
  SpellChecker spell("words.txt");
  bool running = true;
  char menu;
  string word;

  while(running) {
    cout << "1. Check word" << endl;
    cout << "2. Check file" << endl;
    cout << "3. Exit" << endl;

    cin >> menu;

    switch(menu) {
      case '1':
        cout << "Input word" << endl;
        cin >> word;
        cout << spell.check(word) << endl;
        break;

      case '2':
        cout << "Input file name..." << endl;
        cin >> word;
        spell.checkFile(word);
        break;

      case '3':
        running = false;
        break;

      default:
        cout << "Wrong input..." << endl;
        break;

    }
  }


  return 0;
}
