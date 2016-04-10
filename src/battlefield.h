// Copyright 2015 Markus Jylhänkangas
#ifndef SRC_BATTLEFIELD_H_
#define SRC_BATTLEFIELD_H_

struct Guy {
  int health = 100;
  int damage = 5;
  int level = 1;
  bool isDead = false;
};

class Battlefield {
 private:
#ifdef __linux__
  auto rdtsc() -> unsigned long long;
#endif
 public:
  int count = 0;
  bool running = true;
  auto attack(Guy* characters) -> void;
  auto display(Guy* characters) -> void;
  auto check(Guy* characters) -> void;
};

#endif  // SRC_BATTLEFIELD_H_
