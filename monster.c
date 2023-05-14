#include <stdio.h>


typedef struct {
  char* power;
} Walable;

void walk(const Walable* monster, const char* name) {
  printf("%s is walking...\n", name);
}


typedef struct {
  char* power;
} Swimable;

void swim(const Swimable* monster, const char* name) {
  printf("%s is swamming...\n", name);
}


typedef struct {
  char* name;
 } Monster;

void attack(const Monster* monster) {
  printf("%s attack\n", monster->name);
}

char* get_name(const Monster* monster) {
  return monster->name;
}


typedef struct {
  Monster monster;
  Walable walkable;
} LandMonster;


typedef struct {
  Monster monster;
  Swimable swamable;
  Walable walkable;
} LandAndSeaMonster;


int main(const int argc, const char *argv[]) {
  LandMonster bear = { 
    { "Beast" },
    { "Strong" }
  };

  LandAndSeaMonster crab = { 
    { "Ninja" }, 
    { "Knife" },
    { "Super fast" }, 
  };

  walk(&bear.walkable, get_name(&bear.monster));
  attack(&bear.monster);

  walk(&crab.walkable, get_name(&crab.monster));
  swim(&crab.swamable, get_name(&crab.monster));
  attack(&crab.monster);

  return 1;
}
