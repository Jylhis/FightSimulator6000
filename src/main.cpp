// Copyright 2015 Markus Jylhänkangas

#include <iostream>
#include "battlefield.h"
#include <limits>
#include <time.h>
#include "version.h"  // Version numbers from CMakeLists

using namespace std;

auto main() -> int {
  Battlefield battle;

  time_t t1, t2;

  cout << "************************************\n"
       << "*       Fight simulator 6000       *\n"
       << "*              V" << VERSION_MAJOR << "." << VERSION_MINOR << "."
       << VERSION_PATCH << "              *\n"
       << "************************************\n";

  cout << endl << "How many fighters? ";

  while (!(cin >> battle.count)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Try again: ";
  }

  Guy* characters = new Guy[battle.count];

  cout << "\n*****************\n"
       << "*       Log       *\n"
       << "*******************"	<< endl;

  t1 = clock();

  while (battle.running) {
    battle.attack(characters);
    battle.check(characters);
  }

  t2 = clock();

  cout << "\n************************\n"
       << "*         DONE         *\n"
       << "************************" << endl;

  battle.display(characters);

  double diff = ((float)t2 - (float)t1) / CLOCKS_PER_SEC;

  cout << "\nBattle took: " << diff << " sec" << endl;

  delete[] characters;

#ifdef _WIN32
  system("PAUSE");
#endif

  return 0;
}
