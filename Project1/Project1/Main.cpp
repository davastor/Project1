#include <iostream>
#include <string>
#include <iomanip>
#include "Monster.h"
#include "Character.h"
#include "Items.h"
#include "Abilities.h"

using namespace std;

void CharacterCreation(string &name, char &prof);
void Rounds(Character &player);
bool Combat(Monster &monster, Character &player);
int Ability(Character &character, Monster &monster);
void collectLoot(Character &character, Monster monster);

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
	cout << "\nWhat is your profession? A (W)arrior? Perhaps a (M)age?" << endl;
	cin >> prof;
	prof = toupper(prof);	
}

void Rounds(Character &character)
{
	bool death = false;
	for (int round = 5; round <= 5; round++)
	{
		Monster monster = Monster(round);
		cout << "\nA " << monster.getMonsterName() << " appears!\n" << endl;
		death = Combat(monster, character);

		if (death == true)
		{
			cout << "You have died! Your soul has been cursed to wander this evil realm forever! " << endl;
			break;
		}
	}

	if(death == false)
		cout << "You have conquered the arena! Consider your life a gift. " << endl;
}

bool Combat(Monster &monster, Character &character)
{
	character.restorePlayerMana();
	char action;
	while (monster.getMonsterHealth() > 0)
	{
		cout << character.getClass() << ": " <<  setw(5) << character.getName() << setw(16) << monster.getMonsterName() << endl;
		cout << "Health: " << character.getHealth() << setw(17) << "Health: " << monster.getMonsterHealth() << endl;
		cout << "Mana: " << character.getMana() << setw(20) << "Attack: " << monster.getMonsterAttack() << endl;
 		cout << "Attack: " << character.getAttack() <<  endl;

		cout << "\nWhat will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;

		if (toupper(action) == 'M')
		{
			monster.subtractDamage(character.getAttack());
			cout << "\nYou deal " << character.getAttack() << " damage." << endl;
		}

		else
		{
			Ability(character, monster);
		}

		if (monster.getMonsterHealth() > 0)
		{
			cout << "The " + monster.getMonsterName() + " hits you for " 
				 << monster.getMonsterAttack() << " damage.\n" << endl;
			character.subtractDamage(monster.getMonsterAttack());
		}

		if (character.getHealth() <= 0)
		{
			return true;
		}
	}
	cout << "\nYou have defeated the " + monster.getMonsterName() << "." << endl;
	collectLoot(character, monster);
	return false;
}

void collectLoot(Character &character, Monster monster)
{
	Items item = Items();
	string itemName = item.getItemName();

	cout << "\nYou obtained a " << itemName << " from the corpse of the " << monster.getMonsterName() << "." << endl;

	if (itemName == "Mysterious Amulet")
	{
		cout << "You've gained " << item.getAttackBuff() << " attack." << endl;
		character.buffAttack(item.getAttackBuff());
	}
	else if (itemName == "Health Potion")
	{
		cout << "You've gained " << item.getHealthInc() << " health." << endl;
		character.addHealth(item.getHealthInc());
	}
	else
	{
		cout << "You've gained " << item.getManaInc() << " mana." << endl;
		character.addMana(item.getManaInc());
	}	
}

int Ability(Character &character, Monster &monster)
{
	char choice;
	int damage;
	int heal;

	cout << "\nWhat ability will you use?" << endl;
	if (character.getClass() == "Warrior")
	{
		cout << "\n(C)leave (2x damage, -25 MP)" << endl;
		cout << "(W)ar Cry (+50 HP, -20 MP)" << endl;
		cin >> choice;
		choice = toupper(choice);
		Abilities ability = Abilities(choice, character.getAttack());

		while (character.getMana()-ability.getManaCost() < 0)
		{
			cout << "\nYou attempted to cast your ability but failed. " << endl;
			return 0;
		}

		if (choice == 'C')
		{
			damage = ability.getAbilityDamage(choice, character.getAttack());
			cout << "\nYou deal " << damage << " damage. " << endl;
			monster.subtractDamage(damage);
		}
		else
		{
			heal = ability.getHealAmt();
			cout << "\nYou healed for " << heal << "." << endl;
			character.addHealth(heal);
		}

		character.subtractMana(ability.getManaCost());
	}

	if (character.getClass() == "Mage")
	{
		cout << "\n(M)ana Bomb (200 damage, -100 MP)" << endl;
		cout << "(H)eal (+120 HP, -50 MP)" << endl;
		cin >> choice;
		choice = toupper(choice);
		Abilities ability = Abilities(choice, character.getAttack());

		while (character.getMana() - ability.getManaCost() < 0)
		{
			cout << "\nYou attempted to cast your ability but failed. " << endl;
			return 0;
		}

		if (choice == 'M')
		{
			damage = ability.getAbilityDamage(choice, character.getAttack());
			cout << "\nYou deal " << damage << " damage." << endl;
			monster.subtractDamage(damage);
		}
		else
		{
			heal = ability.getHealAmt();
			cout << "You healed for " << heal << "." << endl;
			character.addHealth(heal);
		}

		character.subtractMana(ability.getManaCost());
	}

	return 0;
}

