#include <iostream>

using namespace std;

class Creature
{
public:
  Creature();
  Creature(const string Name, int Power, int Toughness);
  string getName();
  int getPower();
  int getToughness();
  void print();
  void printZoneStatus();
  bool isInGraveyard();
  void doBattle(Creature creature);
private:
  string mName;
  int mPower;
  int mToughness;
  void reduceToughness(int amount);
};

Creature::Creature()
{
  mName = "Token";
  mPower = 0;
  mToughness = 1;
}

Creature::Creature(const string name, const int power, const int toughness)
{
  mName = name;
  mPower = power;
  mToughness = toughness;
}

string Creature::getName()
{
  return mName;
}

int Creature::getPower()
{
  return mPower;
}

int Creature::getToughness()
{
  return mToughness;
}

void Creature::print()
{
  cout << "Name: " << getName() << '\n';
  cout << "Power: " << getPower() << '\n';
  cout << "Toughness: " << getToughness() << "\n\n";
}

void Creature::printZoneStatus()
{
  if (isInGraveyard())
    cout << getName() << " is in the graveyard.\n";
  else
    cout << getName() << " is in the battlefield.\n";
}

bool Creature::isInGraveyard()
{
  return (mToughness == 0);
}

void Creature::doBattle(Creature creature)
{
  reduceToughness(creature.getPower());
}

void Creature::reduceToughness(int amount)
{
  mToughness-=amount;
  if (mToughness < 0)
    mToughness = 0;
}

int main() {
  Creature token;
  Creature c1("Molderhulk", 6, 6);
  Creature c2("Varis", 3, 3);
  token.print();
  c1.print();
  c2.print();
  c1.printZoneStatus();
  c2.printZoneStatus();
  cout << "\n";
  cout << c1.getName() << " and " << c2.getName() << " start a battle.\n";
  c1.doBattle(c2);
  c2.doBattle(c1);
  cout << "The battle ends.\n\n";
  c1.printZoneStatus();
  c2.printZoneStatus();
  cout << "\n";
  c1.print();
  c2.print();
}
