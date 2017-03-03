#include "Character.h"
#include <iostream>


string Character::getName()
{
	return _name;
}

string Character::getClass()
{
	return _class;
}

void Character::addMana(int mana)
{
	_mana += mana;
}

void Character::restorePlayerMana()
{
	_mana += 30;
}

void Character::subtractDamage(int damage)
{
	_health -= damage;
}

void Character::subtractMana(int manaCost)
{
	_mana -= manaCost;
}

void Character::addHealth(int heal)
{
	_health += heal;
}

void Character::buffAttack(int buff)
{
	_attack += buff;
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
	cout << "Until next time . . . farewell, challenger!" << endl;
	system("PAUSE");
}
