#include "Abilities.h"


void Abilities::setDamageMulti()
{		
	_damageMulti = 2;
}

int Abilities::getDamageMulti()
{
	return _damageMulti;
}

void Abilities::setManaCost(char choice)
{
	if (choice == 'C')
		_manaCost = 25;
	else if (choice == 'W')
		_manaCost = 20;
	else if (choice == 'M')
		_manaCost == 100;
	else
		_manaCost = 50;
}

int Abilities::getManaCost()
{
	return _manaCost;
}

void Abilities::setHealAmt(char choice)
{
	if (choice == 'W')
		_healAmt = 25;
	else
		_healAmt = 80;
}

int Abilities::getHealAmt()
{
	return _healAmt;
}


Abilities::Abilities()
{
	setDamageMulti();
	
}


Abilities::~Abilities()
{
}
