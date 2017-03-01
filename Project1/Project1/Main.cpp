#include <iostream>
#include <string>
#include "Monster.h"
#include "Character.h"
//#include "Items.h"
#include "Abilities.h"

using namespace std;

void CharacterCreation(string &name, char &prof);
void Rounds(Character &player);
bool Combat(Monster &monster, Character &player);
int Ability(Character &character, Monster &monster);

int main()
{
	string name = "";
	char prof = 'a';
	CharacterCreation(name, prof);

	Character character = Character(name, prof);
	

	Rounds(character);

	system("PAUSE");
	return 0;
}

void CharacterCreation(string &name, char &prof)
{
	cout << "Welcome to the arena!  What is your name challenger?" << endl;
	getline(cin, name);
	cout << "What is your profession? A (W)arrior? Perhaps a (M)age?" << endl;
	cin >> prof;
	prof = toupper(prof);
	
}

void Rounds(Character &character)
{
	bool death = false;
	for (int round = 0; round < 5; round++)
	{
		if (death == true)
		{
			cout << "You have died! Your soul has been cursed to this evil realm forever! " << endl;
			break;
		}
		Monster monster = Monster(round);
		cout << "\nA " + monster.getMonsterName() + " appears!\n" << endl;
		death = Combat(monster, character);
	}

	if(death == false)
		cout << "You have conquered the arena! Consider the preservation of your life a gift. " << endl;
}

bool Combat(Monster &monster, Character &character)
{
	character.restorePlayerMana();
	char action;
	while (monster.getMonsterHealth() > 0)
	{
		cout << character.getName() << "\t\t\t" << monster.getMonsterName() << endl;
		cout << "Health: " << character.getHealth() << "\t\tHealth: " << monster.getMonsterHealth() << endl;
		cout << "Mana: " << character.getMana() << "\t\tAttack: " << monster.getMonsterAttack() << endl;
 		cout << "Attack: " << character.getAttack() <<  endl;

		cout << "\nWhat will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;

		if (toupper(action) == 'M')
		{
			monster.subtractDamage(character.getAttack());
			cout << "\nYou deal " << character.getAttack() << " damage.";
		}

		else
		{
			Ability(character, monster);
		}

		if (monster.getMonsterHealth() > 0)
		{
			cout << "\nThe " + monster.getMonsterName() + " hits for " 
				 << monster.getMonsterAttack() << " damage.\n" << endl;
			character.subtractDamage(monster.getMonsterAttack());
		}

		if (character.getHealth() <= 0)
		{
			return true;
		}
	}

	cout << "\nYou have defeated the " + monster.getMonsterName() << "." << endl;
	return false;
}

int Ability(Character &character, Monster &monster)
{
	char choice;
	int damage;
	int heal;

	if (character.getMana() < 20)
	{
		cout << "\nYou do not have enough mana to cast anything. " << endl;
		return 0;
	}

	cout << "What ability will you use?" << endl;
	if (character.getClass() == "Warrior")
	{
		cout << "(C)leave (2x damage, -25 MP)" << endl;
		cout << "(W)ar Cry (+25 HP, -20 MP)" << endl;
		cin >> choice;
		choice = toupper(choice);

		if (choice == 'C')
		{
			damage = character.useAbility(choice);
			cout << "\nYou deal " << damage << " damage. " << endl;
			monster.subtractDamage(damage);
		}
		else
		{
			heal = character.useAbility(choice);
			cout << "\nYou healed for " << heal << "." << endl;
			character.addHealth(heal);
		}
	}

	if (character.getClass() == "Mage")
	{
		cout << "(M)ana Bomb (200 damage, -100 MP)" << endl;
		cout << "(H)eal (+80 HP, -50 MP)" << endl;
		cin >> choice;
		choice = toupper(choice);

		if (choice == 'M')
		{
			damage = character.useAbility(choice);
			cout << "\nYou deal " << damage << " damage." << endl;
			monster.subtractDamage(damage);
		}
		else
		{
			heal = character.useAbility(choice);
			cout << "You healed for " << heal << "." << endl;
			character.addHealth(heal);
		}
	}

	return 0;
}

