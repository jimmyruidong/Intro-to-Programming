#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Weapon
{
public:
	Weapon(string weaponType, string weaponName, string weaponDescription, int weaponAttack, int weaponRange) {
		type = weaponType;
		name = weaponName;
		description = weaponDescription;
		attack = weaponAttack;
		range = weaponRange;
	}

	string returnName() {
		return name;
	}

	string returnType() {
		return type;
	}
	string returnDescription() {
		return description;
	}

	int returnAttack() {
		return attack;
	}

	int returnRange() {
		return range;
	}
private:
	string type;
	string name;
	string description;
	int attack;
	int range;
};

class Armor
{
public:
	Armor(string armorType, string armorName, string armorDescription, int armorDefense) {
		type = armorType;
		name = armorName;
		description = armorDescription;
		defense = armorDefense;
	}

	string returnName() {
		return name;
	}

	string returnType() {
		return type;
	}
	string returnDescription() {
		return description;
	}

	int returnDefense() {
		return defense;
	}

private:
	string type;
	string name;
	string description;
	int defense;
};

class Shield
{
public:
	Shield(bool YNShield, string shieldType, string shieldName, string shieldDescription, int shieldDefense) {
		hasShield = YNShield;
		type = shieldType;
		name = shieldName;
		defense = shieldDefense;
		description = shieldDescription;
	}

	string returnName() {
		return name;
	}

	string returnType() {
		return type;
	}
	string returnDescription() {
		return description;
	}

	int returnDefense() {
		return defense;
	}

	bool returnhasShield() {
		return hasShield;
	}

private:
	string type;
	string name;
	string description;
	int defense;
	bool hasShield;
};

bool yesorno(char inputChar) {
	while (true) {
		if (inputChar == 'y' || inputChar == 'Y') {
			return true;
			break;
		}
		else if (inputChar == 'n' || inputChar == 'N') {
			return false;
			break;
		}
		else {
			cout << "Error, you entered: " << inputChar << ", which is not an acceptable input." << endl;
			cout << "Enter Y or y for yes." << endl;
			cout << "Enter N or n for no." << endl << flush;
			cin >> inputChar;
		}
	}
}

class PlayerClass
{
public:
	PlayerClass() {

	}

	void createPlayer() {
		name = createName();
		race = createRace();
		combatClass = createCombatClass();
		initHP();
		printAllStats();
	}
	//returns string 'name'
	string createName() {
		string playerName;
		char inputChar;
		while (true) {
			system("CLS");

			cout << "What is the name of your character?" << endl;
			cin >> playerName;

			system("CLS");

			cout << "Your name is: " << playerName << ". Is that correct? (Y/N)" << endl;
			cin >> inputChar;

			if (yesorno(inputChar) == true) {
				cout << "Name created." << endl;
				return playerName;
				break;
			}
			else if (yesorno(inputChar) == false) {
				cout << "Re-running name creator..." << endl;
			}
			else {
				cout << "BUG! BUG! FIND IT AND SQUASH IT!" << endl;
			}
		}

	}

	//returns string 'race'
	string createRace() {
		string playerRace;
		char inputChar;
		while (true) {
			system("CLS");

			raceIntro();

			system("CLS");

			cout << "What is the race of your character? (Elf, Human, Dwarf, Halfling)" << endl;
			cin >> playerRace;

			if (playerRace == "elf" || playerRace == "Elf" || playerRace == "elvish"
				|| playerRace == "Elvish" || playerRace == "elven" || playerRace == "Elven") {
				playerRace == "elf";

			}
			else if (playerRace == "man" || playerRace == "Man" || playerRace == "men" ||
				playerRace == "Men" || playerRace == "human" || playerRace == "Human") {
				playerRace == "human";

			}
			else if (playerRace == "dwarf" || playerRace == "Dwarf" || playerRace == "dwarven"
				|| playerRace == "Dwarven" || playerRace == "Dwarfish" || playerRace == "dwarfish") {
				playerRace == "dwarf";

			}
			else if (playerRace == "halfling" || playerRace == "Halfling" || playerRace == "half-ling"
				|| playerRace == "Half-ling" || playerRace == "hobbit" || playerRace == "Hobbit"
				|| playerRace == "half" || playerRace == "Half") {
				playerRace == "halfling";
			}
			else {
				cout << "Yeah keep breaking this game you overgrown cabbage." << endl;
			}

			system("CLS");

			cout << "You are a" << " " << playerRace << ". Is that correct? (Y/N)" << endl;
			cin >> inputChar;
			system("CLS");
			if (yesorno(inputChar) == true) {
				if (playerRace == "elf") {
					createElf();
				}
				else if (playerRace == "man") {
					createHuman();
				}
				else if (playerRace == "dwarf") {
					createDwarf();
				}
				else if (playerRace == "halfling") {
					createHalfling();
				}
				cout << "Race created." << endl;
				return playerRace;
				break;
			}
			else if (yesorno(inputChar) == false) {
				cout << "Re-running race creator..." << endl;

			}
			else {
				cout << "BUG! BUG! FIND IT AND SQUASH IT!" << endl;
			}
		}

	}

	void raceIntro() {
		int inputNum;

		while (true) {
			cout << "Enter 1 to read a brief introduction of dwarfs" << endl;
			cout << "Enter 2 to read a brief introduction of elves" << endl;
			cout << "Enter 3 to read a brief introduction of humans" << endl;
			cout << "Enter 4 to read a brief introduction of halflings" << endl;
			cout << "Enter 0 to choose your race." << endl << endl;

			cin >> inputNum;
			system("CLS");
			if (inputNum == 1) {
				dwarfIntro();
			}
			else if (inputNum == 2) {
				elfIntro();
			}
			else if (inputNum == 3) {
				humanIntro();
			}
			else if (inputNum == 4) {
				halflingIntro();
			}
			else if (inputNum == 0) {
				break;
			}
			else {
				cout << "Error, you entered: " << inputNum << ", which is not an acceptable input." << endl;
				cout << "Please enter a number that is between 1-4 or 0." << endl << endl;
			}

		}
	}
	void dwarfIntro() {
		cout << "Kingdoms rich in ancient grandeur, " << endl;
		cout << "halls carved into the roots of mountains, " << endl;
		cout << "the echoing of picks and hammers in deep mines and blazing forges, " << endl;
		cout << "a commitment to clan and tradition," << endl;
		cout << "and a burning hatred of goblins and orcs — these common threads unite all dwarves." << endl << endl;

		cout << "Dwarvish Traits" << endl;
		cout << "Strengh: +4" << endl;
		cout << "Constitution: +2" << endl;
		cout << "Age: 50-300" << endl;
		cout << "Size: Medium" << endl;
		cout << "Speed: 25" << endl;

		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}
	void elfIntro() {
		cout << "Elves are a magical people of otherworldly grace, " << endl;
		cout << "living in the world but not entirely part of it." << endl;
		cout << "They live in places of ethereal beauty, " << endl;
		cout << "in the midst of ancient forests or in silvery spires glittering with faerie light, " << endl;
		cout << "where soft music drifts through the air and gentle fragrances waft on the breeze." << endl;
		cout << "Elves love nature and magic, art and artistry, music and poetry, and the good things of the world." << endl << endl;

		cout << "Elvish Traits: " << endl;
		cout << "Agility: +4" << endl;
		cout << "Wisdom: +2" << endl;
		cout << "Age: 150-700" << endl;
		cout << "Size: Medium" << endl;
		cout << "Speed: 30" << endl;

		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}
	void humanIntro() {
		cout << "In the reckonings of most worlds, humans are the youngest of the common races, " << endl;
		cout << "late to arrive on the world scene and short-lived in comparison to dwarves, elves, and dragons." << endl;
		cout << "Perhaps it is because of their shorter lives that they strive to achieve as much as they can in the years they are given. " << endl;
		cout << "Or maybe they feel they have something to prove to the elder races," << endl;
		cout << "and that’s why they build their mighty empires on the foundation of conquest and trade. " << endl;
		cout << "Whatever drives them, humans are the innovators, the achievers, and the pioneers of the worlds." << endl << endl;

		cout << "Human Traits:" << endl;
		cout << "Strength: +2" << endl;
		cout << "Agility: +2" << endl;
		cout << "Wisdom: +1" << endl;
		cout << "Luck: +1" << endl;
		cout << "Age: 18-80" << endl;
		cout << "Size: Medium" << endl;
		cout << "Speed: 30" << endl;

		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}
	void halflingIntro() {
		cout << "The comforts of home are the goals of most halflings’ lives:" << endl;
		cout << "a place to settle in peace and quiet," << endl;
		cout << "far from marauding monsters and clashing armies;" << endl;
		cout << "a blazing fire and a generous meal; " << endl;
		cout << "fine drink and fine conversation." << endl;
		cout << " Though some halflings live out their days in remote agricultural communities, " << endl;
		cout << "others form nomadic bands that travel constantly," << endl;
		cout << "lured by the open road and the wide horizon to discover the wonders of new lands and peoples." << endl;
		cout << "But even these wanderers love peace, food, hearth, and home," << endl;
		cout << "though home might be a wagon jostling along an dirt road or a raft floating downriver." << endl << endl;

		cout << "Halfling Traits:" << endl;
		cout << "Agility: +2" << endl;
		cout << "Constitution: +1" << endl;
		cout << "Luck: +4" << endl;
		cout << "Age: 20-150" << endl;
		cout << "Size: Small" << endl;
		cout << "Speed: 25" << endl;

		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}

	void createDwarf() {
		strength = +4;
		constitution = +2;
		age = 50+rand() % 250;
		weight = 150+rand() % 50;
		speed = 25;
		size = "medium";
	}
	void createElf() {
		agility = +4;
		wisdom = +2;
		weight = 100+rand() % 50;
		age = 150+rand() % 550 ;
		speed = 30;
		size = "medium";
	}
	void createHuman() {
		strength = +2;
		agility = +2;
		wisdom = +1;
		luck = +1;
		age = 18 +rand() % 62;
		weight = 130+rand() % 60 ;
		speed = 30;
		size = "medium";
	}
	void createHalfling() {
		agility = +2;
		constitution = +1;
		luck = +4;
		speed = 25;
		age = 20+rand() % 130 ;
		weight = 100+rand() % 30 ;
		size = "small";
	}

	string createCombatClass() {
		string playerCombatClass;
		char inputChar;
		while (true) {
			system("CLS");
			combatClassIntro();
			system("CLS");
			cout << "What is the combat class of your character? (Archer, Sorcerer, Warrior)" << endl;
			cin >> playerCombatClass;
			if (playerCombatClass == "archer" || playerCombatClass == "Archer") {
				playerCombatClass = "archer";

			}
			else if (playerCombatClass == "warrior" || playerCombatClass == "Warrior") {
				playerCombatClass = "warrior";

			}
			else if (playerCombatClass == "sorcerer" || playerCombatClass == "Sorcerer") {
				playerCombatClass == "sorcerer";

			}
			else {
				cout << "NO NOT AGAIN." << endl;
				cout << endl << flush;
				system("PAUSE");
				system("CLS"); //what if enter wrong?
			}
			system("CLS");
			cout << "Your combat class is: " << playerCombatClass << ". Is that correct? (Y/N)" << endl;
			cin >> inputChar;
			system("CLS");
			if (yesorno(inputChar) == true) {
				if (playerCombatClass == "archer" || playerCombatClass == "Archer") {

					createArcher();
				}
				else if (playerCombatClass == "warrior" || playerCombatClass == "Warrior") {

					createWarrior();
				}
				else if (playerCombatClass == "sorcerer" || playerCombatClass == "Sorcerer") {

					createSorcerer();
				}
				cout << "Combat class created." << endl;
				return playerCombatClass;
				break;
			}
			else if (yesorno(inputChar) == false) {
				cout << "Re-running combat class creator..." << endl;
			}
			else {
				cout << "BUG! BUG! FIND IT AND SQUASH IT!" << endl;
			}
		}

	}

	void combatClassIntro() {
		int inputNum;

		while (true) {
			cout << "Enter 1 to read a brief introduction of archers" << endl;
			cout << "Enter 2 to read a brief introduction of sorcerers" << endl;
			cout << "Enter 3 to read a brief introduction of warriors" << endl;
			cout << "Enter 0 to choose your combat class." << endl << endl;

			cin >> inputNum;
			system("CLS");
			if (inputNum == 1) {
				archerIntro();
			}
			else if (inputNum == 2) {
				sorcererIntro();
			}
			else if (inputNum == 3) {
				warriorIntro();
			}
			else if (inputNum == 0) {
				break;
			}
			else {
				cout << "Error, you entered: " << inputNum << ", which is not an acceptable input." << endl;
				cout << "Please enter a number that is between 1-3 or 0." << endl << endl;
			}

		}
	}
	void archerIntro() {
		archerTraits();
		cout << "Archer Traits:" << endl;
		cout << "Primary Ability: Agility" << endl;
		cout << "Uses ranged weapons such as bows or crossbows." << endl;
		cout << "Can wear light or medium armor." << endl;
		cout << "Cannot use a shield." << endl;




		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}

	void archerTraits() {
		cout << "A master of ranged combat, skilled with the bow, crossbow and darts." << endl << endl;
	}
	void sorcererIntro() {

		sorcererTraits();
		cout << "Sorcerer Traits:" << endl;
		cout << "Primary Ability: Wisdom" << endl;
		cout << "Uses a staff or quarterstaff to channel power." << endl;
		cout << "Can wear light or medium armor." << endl;
		cout << "Cannot use a shield." << endl;


		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}

	void sorcererTraits() {
		cout << "A spellcaster who draws on inherent magic from a gift or bloodline" << endl << endl;

	}
	void warriorIntro() {
		warriorTraits();
		cout << "Warrior Traits:" << endl;
		cout << "Primary Ability: Strength OR Agility" << endl;
		cout << "Uses melee weapons such as swords and axes." << endl;
		cout << "Can wear light, medium or heavy armor." << endl;
		cout << "Can use a shield." << endl;



		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}

	void warriorTraits() {
		cout << "A master of melee combat, skilled with a variety of melee weapons and armor" << endl << endl;
	}

	void initAllItemStats(Weapon currentWeapon, Armor currentArmor, Shield currentShield) {
		initWeaponStats(currentWeapon);
		initArmorStats(currentArmor);
		initShieldStats(currentShield);
	}
	void initWeaponStats(Weapon currentWeapon) {
		weaponType = currentWeapon.returnType();
		weaponName = currentWeapon.returnName();
		weaponDescription = currentWeapon.returnDescription();
		weaponAttack = currentWeapon.returnAttack();
		weaponRange = currentWeapon.returnRange();
	}
	void initArmorStats(Armor currentArmor) {
		armorType = currentArmor.returnType();
		armorName = currentArmor.returnName();
		armorDescription = currentArmor.returnDescription();
		armorDefense = currentArmor.returnDefense();
	}
	void initShieldStats(Shield currentShield) {
		shieldType = currentShield.returnType();
		shieldName = currentShield.returnName();
		shieldDefense = currentShield.returnDefense();
		hasShield = currentShield.returnhasShield();
	}

	void createWarrior() {
		Weapon bSword("Sword", "Bronze Sword", "A basic bronze sword, suitable for every occassion. Slightly rusty, though.", 5, 1);
		//Armor
		Armor bPlate("Heavy", "Bronze Plate Armor", "A basic set of bronze plate armor, well-worn but still effective.", 5);
		//Shield(Melee)
		Shield bKite(true, "Kite", "A Bronze Kiteshield", "A basic bronze kiteshield, provides additional defense. Could use a polish.", 3);
		initAllItemStats(bSword, bPlate, bKite);
	}
	void createArcher() {
		Weapon sBow("Bow", "Shortbow", "A basic shortbow, matches the color of your tunic.", 3, 5);
		//Armor
		Armor bLeather("Medium", "Leather Armor", "A basic set of leather armor, slightly cracked", 3);
		//Shield(Melee)
		Shield noShield(false, "None", "No shield", "You do not have a shield.", 0);
		initAllItemStats(sBow, bLeather, noShield);
	}
	void createSorcerer() {
		Weapon sStaff("Staff", "Shortstaff", "A basic shortstaff, looks like a treebranch.", 3, 1);
		//Armor
		Armor bCloth("Light", "Cloth Armor", "What were you thinking, wearing robes for armor?", 1);
		//Shield(Melee)
		Shield noShield(false, "None", "No shield", "You do not have a shield.", 0);
		initAllItemStats(sStaff, bCloth, noShield);
	}

	void initHP() {
		calculateMaxHP();
		healAmount(maxHP);
	}
	void calculateMaxHP() {
		maxHP = 10 + (constitution * 5);
	}
	void healAmount(int healNum) {
		currentHP = currentHP + healNum;
		if (currentHP > maxHP) {
			currentHP = maxHP;
		}
	}

	string returnName() {
		return name;
	}
	string returnRace() {
		return race;
	}
	int returnMaxHP() {
		return maxHP;
	}
	int returnCurrentHP() {
		return currentHP;
	}
	int returnStrength() {
		return strength;
	}
	int returnAgility() {
		return agility;
	}
	int returnWisdom() {
		return wisdom;
	}
	int returnConstitution() {
		return constitution;
	}
	string returnSize() {
		return size;
	}
	int returnWeight() {
		return weight;
	}
	int returnAge() {
		return age;
	}
	int returnSpeed() {
		return speed;
	}

	void printName() {
		cout << "Name: " << name << endl;
	}
	void printRace() {
		cout << "Race: " << race << endl;
	}
	void printHP() {
		cout << "HP: " << currentHP << "/" << maxHP << endl;
	}
	void printAttributes() {
		cout << "Your attributes are..." << endl;
		cout << "Strength: " << strength << endl;
		cout << "Agility: " << agility << endl;
		cout << "Wisdom: " << wisdom << endl;
		cout << "Constitution: " << constitution << endl;
		cout << "Luck: " << luck << endl;
	}
	void printTraits() {
		cout << "Your traits are..." << endl;
		cout << "Size: " << size << endl;
		cout << "Weight: " << weight << " pounds " << endl;
		cout << "Age: " << age << " years " << endl;
		cout << "Speed: " << speed << endl;
	}
	void printCombatClass() {
		cout << "Combat Class: " << combatClass << endl;
	}
	void printWeapon() {
		cout << "Weapon Stats: " << endl;
		cout << "Type: " << weaponType << endl;
		cout << "Name: " << weaponName << endl;
		cout << "Description: " << weaponDescription << endl;
		cout << "Attack: " << weaponAttack << endl;
		cout << "Range: " << weaponRange << endl;
	}
	void printArmor() {
		cout << "Armor Stats: " << endl;
		cout << "Type: " << armorType << endl;
		cout << "Name:" << armorName << endl;
		cout << "Description: " << armorDescription << endl;
		cout << "Defense: " << armorDefense << endl;

	}
	void printShield() {
		if (hasShield == true) {
			cout << "Shield Stats: " << endl;
			cout << "Type: " << shieldType << endl;
			cout << "Name:" << shieldName << endl;
			cout << "Description: " << shieldDescription << endl;
			cout << "Defense: " << shieldDefense << endl;
		}
		else {
			cout << "You have no shield." << endl;
		}
	}

	void printStory() {
		cout << "From the " << race << "-ish realm comes a " << combatClass << " by the name of " << name << ". " << endl;
		cout << race << "s are a " << size << " ed folk, and " << name << " weighs around " << weight << " pounds - the average weight of their race." << endl;
		cout << "Having " << age << " years of experience, there's little that " << name << " does not know. " << endl;
		cout << name << " is a " << combatClass << ", a master of the " << weaponType << ". " << endl;
		cout << "Wielding a " << weaponName << ", " << name << " strikes fear into the hearts of all his/her foes." << endl;
		cout << name << " wears " << armorName << "  - " << " a " << armorType << "armor, and carries " << shieldName << "." << endl;
		cout << "Let the evil-doers of this world cower and tremble, for " << name << " is coming to smite the wicked!" << endl;
	}
	void printAllStats() {
		system("CLS");
		printName();
		cout << endl;
		printRace();
		cout << endl;
		printHP();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printAttributes();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printTraits();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printCombatClass();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printWeapon();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printArmor();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printShield();
		cout << endl;
		cout << "These are your stats." << endl;
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
		printStory();
		cout << endl << flush;
		system("PAUSE");
		system("CLS");
	}
private:
	//Stats
	string name;
	string race;
	//HP
	int maxHP = 10;
	int currentHP = 10;
	//Attributes
	int strength = 10;
	int agility = 10;
	int wisdom = 10;
	int constitution = 5;
	int luck = 5;
	//Traits
	string size;
	int weight;
	int age;
	int speed;

	string combatClass;
	//Weapons
	string weaponType;
	string weaponName;
	string weaponDescription;
	int weaponAttack;
	int weaponRange;
	//Armor
	string armorType;
	string armorName;
	string armorDescription;
	int armorDefense;
	//Shield(Melee)
	int shieldDefense;
	string shieldType;
	string shieldName;
	string shieldDescription;
	bool hasShield;
};




void intro() {

	cout << "An app that demonstrates a (very) basic character creation design for an RPG such as Zork." << endl;
	cout << "Basically... Well, I overestimated myself." << endl;
	cout << "Unfortunately, there's no visual art in this program. " << endl;
	cout << "But, for now, I present to you..." << endl;
	cout << "A character creation program that lets you choose your name, race, and combat class." << endl;
	cout << "Not the most interactive -- nor is it a super well-polished one." << endl;
	cout << endl << flush;
	system("PAUSE");
	system("CLS");
}

int main()
{
	intro();
	PlayerClass newPlayer;
	newPlayer.createPlayer();
}
