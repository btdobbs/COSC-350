#include <iostream>
#include <string>

using namespace std;

//Why structures
//structure - aggregations of elements known as member or field each of which can have a different type
//Designing structures
//Creating structures (init)
//Updating structures
//Using structures

//Questions:
// Why can't I use the creatureCode namespace at the top of the file?
// Why have a damageCreature function?
// Why do we need to pass creature by reference?

namespace creatureGame {
struct creature {
  string name;
  int power;
  int toughness;
};

void printCreature(const creature c) {
  cout << "Name: " << c.name << '\n';
  cout << "Power: " << c.power << '\n';
  cout << "Toughness: " << c.toughness << "\n\n";
}

void damageCreature(creature &c, int damage) {
  c.toughness -= damage;
  if (c.toughness < 0)
  {
    c.toughness = 0;
    cout << c.name << " is incapacitated.\n";
  }
}

void battleCreatures(creature &c1, creature &c2) {
  cout << c1.name << " and " << c2.name << " start a battle.\n";
  damageCreature(c1, c2.power);
  damageCreature(c2, c1.power);
  cout << "The battle ends.\n\n";
}

} // namespace creatureGame

using namespace creatureGame;

int main() {
  creature cDefaultInit = {};
  creature c1 = {"Bruenor", 5, 3};
  creature c2 = {"Varis", 3, 3};
  creature creatures[10];
  printCreature(cDefaultInit);
  printCreature(c1);
  printCreature(c2);
  battleCreatures(c1, c2);
  printCreature(c1);
  printCreature(c2);
}
