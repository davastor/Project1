#pragma once
#include <string>
using namespace std;

class Character
{
private:
	string _name;
	string _class;
	static int _health;
	static int _mana;
	int _attack;


public:
	void setStats();
	string getName();
	string getClass();
	void subtractDamage(int damage);
	int getHealth();
	int getMana();
	int getAttack();
	Character(string name, char prof);
	~Character();
};

