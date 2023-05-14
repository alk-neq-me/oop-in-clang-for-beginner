#include <stdio.h>


typedef struct {
  char* power;
} Walable;

void walk(Walable* monster) {
  printf("walking...\n");
}


typedef struct {
  char* power;
} Swimable;

void swim(Swimable* monster) {
  printf("swamming...\n");
}


typedef struct {
  char* name;
  Walable* walkable;
 } PigMonster;

void attack_pig(PigMonster* monster) {
  printf("%s attack with %s\n", monster->name, monster->walkable->power);
}


typedef struct {
  char* name;
  Swimable* swamable;
  Walable* walkable;
} Crab;

void attack_crab(Crab* monster) {
  printf("%s attack with %s in %s\n", monster->name, monster->walkable->power, monster->swamable->power);
}


int main(const int argc, const char *argv[]) {
  Walable pig_walk = { "hummer" };
  PigMonster pig = {"pig", &pig_walk};

  Walable crab_walk = { "knife" };
  Swimable crab_swam = { "fast" };
  Crab crab = { "ninja-crab", &crab_swam, &crab_walk };

  attack_pig(&pig);
  attack_crab(&crab);

  return 1;
}
