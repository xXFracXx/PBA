// #pragma once
#include <iostream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <fstream>

#include "D3DGraphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Sound.h"

using namespace std;

const char PLAY=16;                                                             //Arrow Pinting Right (Play)
const char STOP=-2;                                                             //Square Block (Stop)
const char BLOCK=-37;                                                           //Solid Block
const char UP=72;                                                               //Keyboard Button Up
const char DOWN=80;                                                             //Keyboard Button Down
const char LEFT=75;                                                             //Keyboard Button Left
const char RIGHT=77;                                                            //Keyboard Button Right
const char ENTER=13;                                                            //Keyboard Button Enter
const char SPACE=32;                                                            //Keyboard Button Space

enum ptype {NUL, NORMAL, FIRE, FIGHTING, WATER, FLYING, GRASS, POISON, ELECTRIC, GROUND, PSYCHIC, ROCK, ICE, BUG, DRAGON, GHOST, DARK, STEEL};
enum pcolor {Red, Blue, Green, Yellow, Purple, Pink, Brown, Black, Grey, White};
enum pegggroup{Monster, Water1, Bug, Flying, Field, Fairy, Grass, HumanLike, Water3, Mineral, Amorphous, Water2, Ditto, Dragon, Undiscovered};
enum pmove {Regular, Status, Special, RegularStatus, MultipleHits, MultipleTurns, Stat, Recoil, RegularStat, Charge, Recharge, Recover, OHKO, SelfDestruct, Drain, DrainMultiple, Specific, Flee};
enum pstat {Attack, Defense, Accuracy, Speed, SpecialAttack, SpecialDefense};
enum pstatusailment {Burn, Freeze, Paralysis, Poison, Asleep, Confusion, Flinch};
enum evolutionmethod {LevelUp, Stone, Trade, Branched, None};
enum evolutionarystone {FireStone, WaterStone, ThunderStone, LeafStone, MoonStone, NoneStone};

void coutptype(ptype x);			//Type of the Pokemon/Move
void coutpcolor(pcolor x);                                                       //Pokemon colours, as per the Pokedex
void coutpegggroup(pegggroup x);                                                 //Egg groups for breeding


class _move                                                                     //Moves
{
public:
	int number;                                                        //Move Index No. (used in learnsets)
	char name[100];
	ptype type;                                                        //Move type
	int basepower;                                                     //Base Power
	int accuracy;                                                      //Accuracy
	pmove category;                                                    //Move Effect Type
	int critratio;                                                     //0 if low, 1 if high
	int basepp;

	pstatusailment status;                                             //If the move may/will inflict a status ailment, which one will it be?
	int percent;                                                       //Percent of receiving a status ailment, recoil, flinch, etc
	int rangelower;                                                    //Lowest no of turns or hits for a move
	int rangeupper;                                                    //Highest no of turns or hits for a move
	pstat stat;                                                        //If the move may/will lower an opponents stat/increase yours, which one will it be?
	int whosstat;                                                      //Who's stat? 1- Users, 2-Opponents
	
	_move();
	void setup(int a, char z[], ptype b, int c, int d, pmove e, int g, int pp);
	void setup2(pstatusailment x);
	void setup2(pstatusailment x, int y);
	void setup2(int x, int y);
	void setup2(pstat x, int y);
	void setup2(int x);
	void setup2(pstat x, int y, int z);
	void setup2(int x, int y, int z);
};

class _progress                                                                  //Saves your progress
{
public:
	string name;
	int gender;                                                        //1 for male, 2 for female

	_progress()
	{
		name = "RED";
	}
};

class _basicpokemon                                                              //Pokemon Structure with variables that do not change for pokemon of the same species
{
public:
	struct _learn                                                                    //Learnsets
	{
		int level;                                                                //Level Learnt (0=Start)
		int moveno;                                                               //Move index no.
	} learnset[101];                                               //Learnset for moves

	int no;                                                            //Pokedex No.
	char name[15];                                                     //Name
	string dexno;                                                      //Pokedex No. in 3 Digit format
	ptype type1;                                                       //1st Type
	ptype type2;                                                       //2nd Type
	string species;                                                    //Species Name
	string height;                                                     //Height
	string weight;                                                     //Weight
	pcolor color;                                                      //Colour as per Pokedex
	float catchrate;                                                   //Variable to determine Catch Rate
	float male;                                                        //Percentage of males in the wild
	float female;                                                      //Percentage of females in the wild
	pegggroup egggroup1;                                               //First breeding group
	pegggroup egggroup2;                                               //Second breeding group
	int eggcycle;                                                      //No. of egg cycles to hatch
	string dexinfo;                                                    //Pokedex info
	int basehp;                                                        //Base HP
	int baseatt;                                                       //Base Attack Stat
	int basedef;                                                       //Base Defense Stat
	int basespatt;                                                     //Base Special Attack Stat
	int basespdef;                                                     //Base Special Defense Stat
	int basespd;                                                       //Base Speed Stat

	evolutionmethod evolutionarymethod;
	int levelofevolution;
	evolutionarystone stoneofevolution;
	int evolvesinto;

	_basicpokemon();
	void setup(int a, char b[], string c, ptype d, ptype e, string f, string g, string h, pcolor i, float j, float k, float l, pegggroup m, pegggroup n, int o, string p, evolutionmethod r, int s, int t);
	void setup(int a, char b[], string c, ptype d, ptype e, string f, string g, string h, pcolor i, float j, float k, float l, pegggroup m, pegggroup n, int o, string p, int q, evolutionmethod r, evolutionarystone s, int t);
	void setup2(int x, int y);
	void setup3(int q, int r, int s, int t, int u, int v);
};

class _pokemon : public _basicpokemon                                             //Pokemon class with variables that change for pokemon of the same species
{
public:
	int level;                                                         //Level reached
	int hp;                                                            //HP
	int curhp;                                                         //Current HP
	int attack;                                                        //Attack Stat
	int defense;                                                       //Defense Stat
	int specialattack;                                                 //Special Attack Stat
	int specialdefense;                                                //Special Defense Stat
	int speed;                                                         //Speed Stat
	_move moves[4];                                                     //Moves learnt
	int ot;                                                            //Original Trainer ID
	int outsider;
                                                      //Checks if the Pokemon was originally the trainer's, or was traded in
	_pokemon();
	int hppercentcalc();
	void setup(int a);
	void createmoveset();
};

class _settings                                                                  //Settings like textspeed, dimensions, etc
{
public:
	int textspeed;

	_settings();
	void typewriter(char s[]);
	void colorchange(int c, int a=0);
	int menu(char pretext[], int n, char ch[][15]);
	void gotoxy(short x, short y);
};

class _battle
{
public:
	_battle();
	int beginbattle(D3DGraphics& gfx, Font& fixedSys);
	int damagecalc(_pokemon a, _pokemon b, _move m);                    //Calculates damage done with one attack
	float typeeffectcalc(ptype movetype, ptype type1, ptype type2);
};

void initPokemon();
void initMoveSet();