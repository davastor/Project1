#include "Abilities.h"


int Abilities::getAbilityDamage(char choice, int attack)
{
	return _abilityDamage;
}

int Abilities::getHealAmt()
{
	return _healAmt;
}

int Abilities::getManaCost()
{
	return _manaCost;
}



Abilities::Abilities(char choice, int attack)
{
	if (choice == 'C')
	{
		_abilityDamage = attack*_damageMulti;
		_manaCost = 25;
	}
		
	else if (choice == 'W')
	{
		_healAmt = 50;
		_manaCost = 20;
	}
	else if (choice == 'M')
	{
		_abilityDamage = 200;
		_manaCost = 100;
	}
	else
	{
		_healAmt = 125;
		_manaCost = 50;
	}
}

Abilities::~Abilities()
{
}
