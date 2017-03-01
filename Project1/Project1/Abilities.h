#pragma once
#include <string>
#include "Character.h"
using namespace std;

class Abilities
{
private:
	int _damage;
	int _heal;

public:
	void damageAbility(int damage, int manaCost);
	Abilities(string prof);
	~Abilities();
};

