#include "Character.h"


string Character::getName()
{
	return _name;
}

string Character::getClass()
{
	return _class;
}

int Character::useAbility(char choice)
{
	int x;

	ability.setManaCost(choice);
	_mana -= ability.getManaCost();

	if (choice == 'C')
		x = _attack*ability.getDamageMulti();
	else if (choice == 'W')
	{
		ability.setHealAmt('W');
		x = ability.getHealAmt();
	}

	else if (choice == 'M')
		x = 200;
	else
	{
		ability.setHealAmt('H');
		x = ability.getHealAmt();
	}


	return x;
}

	
void Character::restorePlayerMana()
{
	_mana += 30;
}

void Character::subtractDamage(int damage)
{
	_health -= damage;
}

void Character::addHealth(int heal)
{
	_health += heal;
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
