// Copyright 2015 Markus Jylhänkangas

#include "battlefield.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#ifdef __linux__
auto Battlefield::rdtsc() -> unsigned long long {
  unsigned int lo, hi;
  __asm__ __volatile__("rdtsc" : "=a" (lo), "=d" (hi));
  return ((unsigned long long)hi << 32) | lo;
}
#endif

auto Battlefield::attack(Guy* characters) -> void {

	/* rdtsc measures the total pseudo-cycles since the processor was powered on.
	Given the high frequency of today's machines,
	it's extremely unlikely that two processors will return the same value even if
	they booted at the same time and are clocked at the same speed.*/

#ifdef _WIN32
  srand(__rdtsc());
#endif
#ifdef __linux__
  srand(rdtsc());
#endif

  auto damage = rand() % 5;
  auto from = rand() % count;
  auto to = rand() % count;

  if (characters[from].isDead) {
	from = rand() % count;
  }
  if (characters[to].isDead) {
	to = rand() % count;
  }

  cout << "Fighter " << from+1 << ": deals " << damage * characters[from].level
       << " Damage to fighter " << to+1 << endl;
  characters[to].health -= damage * characters[from].level;

  if (characters[to].health <= 0) {
    characters[to].isDead = true;
    characters[from].level++;
  }
}

auto Battlefield::display(Guy* characters) -> void {
  for (auto i = 0; i <= count-1; i++) {
    if (!characters[i].isDead) {
      cout << endl << "WINNER IS:\nFighter " << i+1 << ":" << endl
           << "Level: " << characters[i].level << endl
           << "Health: " << characters[i].health << endl
           << "Max Damage: " << characters[i].damage*characters[i].level
           << endl;
    }
  }
}

auto Battlefield::check(Guy* characters) -> void {
  int alive = 0;
  for (auto i = 0; i <= count-1; i++) {
    if (characters[i].health <= 0) {
      characters[i].isDead = true;
      alive++;
      if (alive == count-1) {
        running = false;
      }
    }
  }
}
