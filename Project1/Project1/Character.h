#pragma once
#include <string>
#include "Abilities.h"
using namespace std;

class Character
{
private:
	string _name;
	string _class;
    int _health;
	int _mana;
	int _attack;


public:
	Abilities ability = Abilities();
	string getName();
	string getClass();
	int useAbility(char choice);
	void restorePlayerMana();
	void subtractDamage(int damage);
	void addHealth(int heal);
	int getHealth();
	int getMana();
	int getAttack();
	
	Character(string name, char prof);
	~Character();
};

