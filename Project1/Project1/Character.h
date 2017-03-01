#pragma once
#include <string>
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
	string getName();
	string getClass();
	void subtractDamage(int damage);
	int getHealth();
	int getMana();
	int getAttack();
	
	Character(string name, char prof);
	~Character();
};

