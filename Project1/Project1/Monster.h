#pragma once
#include <string>
using namespace std;

class Monster
{
private:
	string _monsters[3] = { "Minotaur", "Goblin", "Wyvern" };
	string _name;
	int _health;
	int _attack;

public:
	string getMonsterName();
	int getMonsterHealth();
	int getMonsterAttack();
	void subtractDamage(int damage);
	Monster(int round);
	~Monster();
};

