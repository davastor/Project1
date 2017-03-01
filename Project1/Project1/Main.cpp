#include <iostream>
#include <string>
#include "Monster.h"
#include "Character.h"
//#include "Items.h"
#include "Abilities.h"

using namespace std;

void CharacterCreation(string &name, char &prof);
void Rounds(Character player /*, Abilities ability*/);
bool Combat(Monster monster, Character player/*, Abilities ability*/);
//void Ability(Character character/*, Abilities ability*/);

int main()
{
	string name = "";
	char prof = 'a';
	CharacterCreation(name, prof);

	Character character = Character(name, prof);
	//Abilities ability = Abilities(character.getClass());

	Rounds(character/*, ability*/);

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

void Rounds(Character character/*, Abilities ability*/)
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
		cout << "A " + monster.getMonsterName() + " appears!\n" << endl;
		death = Combat(monster, character/*, ability*/);
	}
}

bool Combat(Monster monster, Character character/*, Abilities ability*/)
{
	
	char action;
	while (monster.getMonsterHealth() >= 0)
	{
		cout << character.getName() << "\t\t\t" << monster.getMonsterName() << endl;
		cout << "Health: " << character.getHealth() << "\t\tHealth: " << monster.getMonsterHealth() << endl;
		cout << "Attack: " << character.getAttack() << "\t\tAttack: " << monster.getMonsterAttack() << endl;

		cout << "\nWhat will you do? Use a (M)elee attack?  Or use an (A)bility?" << endl;
		cin >> action;

		if (toupper(action) == 'M')
		{
			monster.subtractDamage(character.getAttack());
			cout << "\nYou deal " << character.getAttack() << " damage.";
		}

		//else
		//{
			//Ability(character, ability);
		//}

		if (monster.getMonsterHealth() >= 0)
		{
			cout << "\nThe " + monster.getMonsterName() + " hits back for " 
				 << monster.getMonsterAttack() << " damage.\n" << endl;
			character.subtractDamage(monster.getMonsterAttack());
		}

		if (character.getHealth() <= 0)
		{
			return true;
		}
	}

	cout << "\nYou have defeated the " + monster.getMonsterHealth() << "." << endl;
	return false;
}

/*void Ability(Character character, Abilities ability)
{
	char choice;

	cout << "What ability will you use?" << endl;
	if (character.getClass() == "Warrior")
	{
		cout << "(C)leave (2x damage, -20 MP)" << endl;
		cout << "(W)ar Cry (+25 HP, -20 MP)" << endl;
		cin >> choice;
		choice = toupper(choice);


	}
}
*/
