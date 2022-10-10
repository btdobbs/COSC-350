#include <iostream>

using namespace std;

class Creature
{
public:
  //1. default constructor - no arguments
  Creature();
  Creature(const string Name, int Power, int Toughness);
  //2. copy constructor - takes class and copies private members
  Creature(const Creature& creature);
  //3. const to define accessor
  string getName() const;
  int getPower() const;
  int getToughness() const;
  //4. define operators
  bool operator==(const Creature& a);
  //5. define nested class
    class Counter
    {
    public:
      //6.  All functions defined inline
      Counter() { mCount = 0; }
      short getCount() const { return mCount; }
      void print() { cout << mCount << "/" << mCount << "\n"; }
    private:
      short mCount;
      void increment() { mCount++; }
      //7. friend functionality allows access to private members
      friend class Creature;
      //8. can also do the following but not recommended
      friend void increment(Creature::Counter& counter);
    };
  Creature::Counter getCounter();
  void addCounter();
  void print();
  void printZoneStatus();
  bool isInGraveyard();
  void doBattle(Creature creature);
private:
  string mName;
  int mPower;
  int mToughness;
  Counter mCounter;
  void reduceToughness(int amount);
};

//Just for example below
void increment(Creature::Counter& counter)
{
  counter.mCount++;
}

//default constructor
Creature::Creature()
{
  mName = "Token";
  mPower = 0;
  mToughness = 1;
}

Creature::Creature(const string name, const int power, const int toughness)
{
    this->mName = name;
    this->mPower = power;
    this->mToughness = toughness;
}

//copy constructor
Creature::Creature(const Creature& creature)
{
  mName = creature.getName();
  mPower = creature.getPower();
  mToughness = creature.getToughness();
}

//const to define accessor (x3)
string Creature::getName() const
{
  return mName;
}

int Creature::getPower() const
{
  return mPower + mCounter.getCount();
}

int Creature::getToughness() const
{
  return mToughness + mCounter.getCount();
}

//define operators
bool Creature::operator==(const Creature& creature)
{
  return (getName() == creature.getName());
}

Creature::Counter Creature::getCounter()
{
  return mCounter;
}

void Creature::addCounter()
{
    //7. use friend functionality
    mCounter.increment();
    //8. alternate way to use friend functionality
    //We could have done the following but not recommended
    //increment(mCounter);
}

void Creature::print()
{
  cout << "Name: " << getName() << '\n';
  cout << "Power: " << getPower() << '\n';
  cout << "Toughness: " << getToughness() << "\n";
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

class Game
{
public:
  Game();
  int getCreatureCount() const;
  int addCreature(Creature creature);
  void doBattle(const int creatureIndex1, const int creatureIndex2);
  void print();
private:
  int mMaxCreatures;
  int mCreatureCount;
  Creature creatures[100];
};

Game::Game()
{
  mMaxCreatures = 100;
  mCreatureCount = 0;
}

int Game::getCreatureCount() const
{
  return mCreatureCount;
}

int Game::addCreature(Creature creature)
{
  if (mCreatureCount == mMaxCreatures)
  {
    cout << "Maximum creature limit reached.\n";
    return -1;
  }
  else
  {
    mCreatureCount++;
    creatures[mCreatureCount-1] = creature;
    cout << "+" << creature.getName() << " added.\n";
    return mCreatureCount-1;
  }
}

void Game::doBattle(const int creatureIndex1, const int creatureIndex2)
{
  cout << creatures[creatureIndex1].getName() << " and "
       << creatures[creatureIndex2].getName() << " start a battle.\n";
  creatures[creatureIndex1].doBattle(creatures[creatureIndex2]);
  creatures[creatureIndex2].doBattle(creatures[creatureIndex1]);
  cout << "The battle ends.\n\n";
}

void Game::print()
{
  cout << "Current Game State:\n";
  cout << "----There are " << mCreatureCount << " creatures in the game----\n";
  for(int i = 0; i < mCreatureCount; i++)
  {
    cout << "--Creature " << i+1 << "--\n";
    creatures[i].print();
    creatures[i].printZoneStatus();
  }
}

int main() {
  //1. use default constructor
  Creature token1;
  //2. use copy constructor
  Creature token2(token1);
  Creature goblin("goblin",1,1);
  cout << "First Token\n";
  token1.print();
  cout << "Second Token\n";
  token2.print();
  goblin.print();
  //3. use accessor
  cout << token1.getName() << " and " << goblin.getName() << " start a battle.\n";
  token1.doBattle(goblin);
  goblin.doBattle(token1);
  cout << "The battle ends.\n\n";
  //4. use == operators
  //why can't we use != below?
  if (token1 == token2)
    cout << "token1 and token2 are equal\n";
  else
    cout << "token1 and token2 are not equal\n";
  if (token1 == goblin)
    cout << "token1 and goblin are equal\n";
  else
    cout << "token1 and goblin are not equal\n";
  cout << "\n";
  cout << "First Token\n";
  token1.print();
  cout << "Second Token\n";
  token2.print();
  goblin.print();
  //5. get nested class
  Creature::Counter counter = token1.getCounter();
  //6. use nested class
  counter.print();
  token1.addCounter();
  counter = token1.getCounter();
  counter.print();
  cout << "\n";
  cout << "First Token\n";
  token1.print();
  //9. adding some design
  Game game;
  game.print();
  Creature c1("Molderhulk", 6, 6);
  int indexMolderhulk = game.addCreature(c1);
  Creature c2("Varis", 3, 3);
  int indexVaris = game.addCreature(c2);
  game.print();
  game.doBattle(indexMolderhulk, indexVaris);
  game.print();
}
