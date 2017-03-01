#include "Character.h"



string Character::getName()
{
	return _name;
}

string Character::getClass()
{
	return _class;
}

void Character::subtractDamage(int damage)
{
	_health -= damage;
}

int Character::getHealth()
{
	return _health;
}

int Character::getMana()
{
	return _mana;
}

int Character::getAttack()
{
	return _attack;
}

Character::Character(string name, char prof)
{
	_name = name;
	if (toupper(prof) == 'W')
	{
		_class = "Warrior";
		_health = 150;
		_mana = 50;
		_attack = 20;
	}
	else
	{
		_class = "Mage";
		_health = 80;
		_mana = 150;
		_attack = 8;
	}
}


Character::~Character()
{
}
