#include <iostream>
#include <string>
#include "Monster.h"
#include "Character.h"
//#include "Items.h"
#include "Abilities.h"

using namespace std;

Character CharacterCreation();
void Rounds(Character player, Abilities ability);
void Combat(Monster monster, Character player, Abilities ability);
void Ability(Character character, Abilities ability);

int main()
{
	Character character = CharacterCreation();
	Abilities ability = Abilities(character.getClass());

	Rounds(character, ability);

	system("PAUSE");
	return 0;
}

Character CharacterCreation()
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

void Rounds(Character character, Abilities ability)
{
	for (int round = 0; round < 5; round++)
	{
		Monster monster = Monster(round);
		cout << "A " + monster.getMonsterName() + " appears!" << endl;
		Combat(monster, character, ability);
	}
}

void Combat(Monster monster, Character character, Abilities ability)
{
	
	char action;
	while (monster.getMonsterHealth() >= 0)
	{
		cout << "Monster: " + monster.getMonsterName();
		cout << "Health: " + monster.getMonsterHealth();
		cout << "Attack: " + monster.getMonsterAttack();

		cout << "What will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;

		if (toupper(action) == 'M')
		{
			monster.subtractDamage(character.getAttack());
			cout << "You deal " << character.getAttack() << " damage.";

		}
		else
		{
			Ability(character, ability);
		}

		if (monster.getMonsterHealth() >= 0)
		{
			cout << "The " + monster.getMonsterName() + " hits back for " 
				 << monster.getMonsterAttack() << " damage." << endl;
		}
	}

	cout << "You have defeated the" + monster.getMonsterHealth() << endl;
}

void Ability()
{
	cout << "What ability will you use?" << endl;
	if (player.getClass*( == "Warrior")
	{
		cout << ""
	}
}
