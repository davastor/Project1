#pragma once
#include <string>
using namespace std;

class Abilities
{
private:
	string _class;
	int _damage;
	int _heal;

public:
	void setClass(string prof);
	Abilities();
	~Abilities();
};

