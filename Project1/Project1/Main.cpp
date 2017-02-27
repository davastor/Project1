#include <iostream>
#include <string>
#include "Monster.h"
#include "Character.h"
//#include "Items.h"
//#include "Abilities.h"

using namespace std;

Character CharacterSet();
void Rounds(Character player);
void Combat(Monster monster, Character player);

int main()
{
	Rounds(CharacterSet());

	system("PAUSE");
	return 0;
}

Character CharacterSet()
{
	string name;
	char prof;

	cout << "Welcome to the arena!  What is your name challenger?" << endl;
	getline(cin, name);
	cout << "What is your profession? A (W)arrior? Perhaps a (M)age?" << endl;
	cin >> prof;
	prof = toupper(prof);

	Character player = Character(name, prof);

	return player;
}

void Rounds(Character player)
{
	for (int round = 0; round < 5; round++)
	{
		Monster monster = Monster(round);
		cout << "A " + monster.getMonsterName() + " appears!" << endl;
		Combat(monster, player);
	}
}

void Combat(Monster monster, Character player)
{
	
	char action;
	while (monster.getMonsterHealth() >= 0)
	{
		cout << "Monster: " + monster.getMonsterName();
		cout << "Health: " + monster.getMonsterAttack();
		cout << "Attack: " + monster.getMonsterAttack();

		cout << "What will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;
		if (toupper(action) == 'M')
		{
			monster.subtractDamage(player.getAttack());
		}
		else
		{

		}
	}
}
