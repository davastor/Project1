#include "Monster.h"
#include <ctime>


string Monster::getMonsterName()
{
	return _name;
}

int Monster::getMonsterHealth()
{
	return _health;
}

int Monster::getMonsterAttack()
{
	return _attack;
}

void Monster::subtractDamage(int damage)
{
	_health -= damage;

}

Monster::Monster(int round)
{
	if (round != 5)
	{
		srand((unsigned int)time(NULL));
		_name = _monsters[rand()%3];
	}
	else
	{
		_name = "Elder Lich";
		_health = 300;
		_attack = 40;
	}

	if(_name == "Minotaur")
	{
		_health = 250;
		_attack = 20;
	}
	else if (_name == "Goblin")
	{
		_health = 60;
		_attack = 10;
	}
	else
	{
		_health = 150;
		_attack = 30;
	}
}

Monster::~Monster()
{
}
