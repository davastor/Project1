#pragma once
#include <string>
using namespace std;

class Abilities
{
private:
	int _damageMulti;
	int _healAmt;
	int _manaCost;
	string _class;

public:
	void setDamageMulti();
	int getDamageMulti();
	void setManaCost(char choice);
	int getManaCost();
	void setHealAmt(char choice);
	int getHealAmt();
	Abilities();
	~Abilities();
};

