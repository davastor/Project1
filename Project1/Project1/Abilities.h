#pragma once
#include <string>
using namespace std;

class Abilities
{
private:
	int _damageMulti = 3;
	int _abilityDamage;
	int _healAmt;
	int _manaCost;
	string _class;

public:
	int getAbilityDamage(char choice, int attack);
	int getManaCost();
	int getHealAmt();
	Abilities(char choice, int attack);
	~Abilities();
};

