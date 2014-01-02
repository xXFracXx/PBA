/*
  Name:				 Pok�mon Battle Arena
  Copyright:         WildRide, INC.
					 Phoenix Enterprises
					 Zugzwang
					 Sushmeister INC.
  Authors:           Vedant Nayar, Shashank Pincha, Susheel Nath & Sudharsan SUrya
  Date Started:      04/07/13 17:46
  Version:           Release Candidate 1.3
  Credits:			 Satoshi Tajiri, rest of PKMN Red/Blue Staff
					 nescity.neshq.com: Nintendo Logo
					 patorjk.com: WildRide Studios logo  (interesting site. check it out)
					 Surya
					 Showbhik
					 Harish P.
					 Harish B.
					 Roney
					 Shubham
					 Varun
*/

#include "pokemon.h"
#include "D3DGraphics.h"

_move Move[166];
_progress progress;
_basicpokemon basicpokemon[152];
_settings settings;
_battle battle;


void coutptype(ptype x)                                                         //Type of the Pokemon/Move
{
	switch (x)
	{
	case NORMAL:
		cout<<"NORMAL";
		break;
	case FIRE:
		cout<<"FIRE";
		break;
	case FIGHTING:
		cout<<"FIGHTING";
		break;
	case WATER:
		cout<<"WATER";
		break;
	case FLYING:
		cout<<"FLYING";
		break;
	case GRASS:
		cout<<"GRASS";
		break;
	case POISON:
		cout<<"POISON";
		break;
	case ELECTRIC:
		cout<<"ELECTRIC";
		break;
	case GROUND:
		cout<<"GROUND";
		break;
	case PSYCHIC:
		cout<<"PSYCHIC";
		break;
	case ROCK:
		cout<<"ROCK";
		break;
	case ICE:
		cout<<"ICE";
		break;
	case BUG:
		cout<<"BUG";
		break;
	case DRAGON:
		cout<<"DRAGON";
		break;
	case GHOST:
		cout<<"GHOST";
		break;
	case DARK:
		cout<<"DARK";
		break;
	case STEEL:
		cout<<"STEEL";
		break;
	default:
		cout<<"Invalid Type";
		break;
	}
}

void coutpcolor(pcolor x)                                                       //Pokemon colours, as per the Pokedex
{
	switch (x)
	{
	case Red:
		cout<<"Red";
		break;
	case Blue:
		cout<<"Blue";
		break;
	case Green:
		cout<<"Green";
		break;
	case Yellow:
		cout<<"Yellow";
		break;
	case Purple:
		cout<<"Purple";
		break;
	case Pink:
		cout<<"Pink";
		break;
	case Brown:
		cout<<"Brown";
		break;
	case Black:
		cout<<"Black";
		break;
	case Grey:
		cout<<"Grey";
		break;
	case White:
		cout<<"White";
		break;
	default:
		cout<<"Invalid Colour";
		break;
	}
}

void coutpegggroup(pegggroup x)                                                 //Egg groups for breeding
{
	switch (x)
	{
	case Monster:
		cout<<"Monster";
		break;
	case Water1:
		cout<<"Water1";
		break;
	case Bug:
		cout<<"Bug";
		break;
	case Flying:
		cout<<"Flying";
		break;
	case Field:
		cout<<"Field";
		break;
	case Fairy:
		cout<<"Fairy";
		break;
	case Grass:
		cout<<"Grass";
		break;
	case HumanLike:
		cout<<"HumanLike";
		break;
	case Water3:
		cout<<"Water3";
		break;
	case Mineral:
		cout<<"Mineral";
		break;
	case Amorphous:
		cout<<"Amorphous";
		break;
	case Water2:
		cout<<"Water2";
		break;
	case Ditto:
		cout<<"Ditto";
		break;
	case Dragon:
		cout<<"Dragon";
		break;
	case Undiscovered:
		cout<<"Undiscovered";
		break;
	default:
		cout<<"Invalid EggGroup";
		break;
	}
}


_move::_move()
{
	setup( 0, "Hop", WATER, 0, 0, Regular, 0, 0 );
}

void _move::setup(int a, char z[], ptype b, int c, int d, pmove e, int g, int pp)
{
	number = a;
	strcpy( name, z );
	type = b;
	basepower = c;
	accuracy = d;
	category = e;
	critratio = g;
	basepp = pp;
}

void _move::setup2(pstatusailment x)
{
	if (category == Status)
		status = x;
	else
		cout << "Error detected @ " << number << " " << name;
}

void _move::setup2(pstatusailment x, int y)
{
	if (category == RegularStatus)
	{
		status = x;
		percent = y;
	}
	else
		cout << "Error detected @ " << number << " " << name;
}

void _move::setup2(int x, int y)
{
	if (category == MultipleHits || category == MultipleTurns)
	{
		rangelower = x;
		rangeupper = y;
	}
	else
		cout << "Error detected @ " << number << " " << name;
}

void _move::setup2(pstat x, int y)
{
	if (category == Stat)
	{
		stat = x;
		whosstat = y;

		if (y!=1 && y!=2)
			cout << "Error detected @ " << number << " " << name;
	}
	else
		cout << "Error detected @ " << number << " " << name;
}

void _move::setup2(int x)
{
	if (category == Recoil || category == Recover || category == Drain || category == Specific)
		percent = x;
	else
		cout << "Error detected @ " << number << " " << name;
}

void _move::setup2(pstat x, int y, int z)
{
	if (category == Stat)
	{
		stat = x;
		whosstat = y;
		percent = z;

		if (y!=1 && y!=2)
			cout << "Error detected @ " << number << " " << name;
	}
	else if (category == RegularStat)
	{
		stat = x;
		whosstat = z;
		percent = y;

		if (z!=1 && z!=2)
			cout << "Error detected @ " << number << " " << name;
	}
	else
		cout << "Error detected @ " << number << " " << name;
}

void _move::setup2(int x, int y, int z)
{
	if (category == DrainMultiple)
	{
		percent = x;
		rangelower = y;
		rangeupper = z;
	}
	else
		cout << "Error detected @ " << number << " " << name;
}


_basicpokemon::_basicpokemon()
{
	no = 0;
	strcpy( name, "MISSINGNO" );
	dexno = "000";
	type1 = FIRE;
	type2 = FIRE;
	species = "Glitch Pokemon";
	height = "0'0\"";
	weight = "0 lbs";
	color = Black;
	catchrate = 0;
	male = 50;
	female = 50;
	egggroup1 = Undiscovered;
	egggroup2 = Undiscovered;
	eggcycle = 100;
	dexinfo = "This is a glitch Pokemon. I have no idea how this appeared, but please report this bug.";
	basehp = 0;
	baseatt = 0;
	basedef = 0;
	basespatt = 0;
	basespdef = 0;
	basespd = 0;

	for (int i = 0; i <= 101; i++)
	{
		int level = 100;
		int moveno = 0;
	}

	evolutionarymethod = None;
	levelofevolution = 0;
	stoneofevolution = NoneStone;
	evolvesinto = 0;
}

void _basicpokemon::setup(int a, char b[], string c, ptype d, ptype e, string f, string g, string h, pcolor i, float j, float k, float l, pegggroup m, pegggroup n, int o, string p, evolutionmethod r, int s, int t)
{
	no = a;
	strcpy( name, b );
	dexno = c;
	type1 = d;
	type2 = e;
	species = f;
	height = g;
	weight = h;
	color = i;
	catchrate = j;
	male = k;
	female = l;
	egggroup1 = m;
	egggroup2 = n;
	eggcycle = o;
	dexinfo = p;
	evolutionarymethod = r;
	levelofevolution = s;
	evolvesinto = t;
}

void _basicpokemon::setup(int a, char b[], string c, ptype d, ptype e, string f, string g, string h, pcolor i, float j, float k, float l, pegggroup m, pegggroup n, int o, string p, int q, evolutionmethod r, evolutionarystone s, int t)
{
	no = a;
	strcpy( name, b );
	dexno = c;
	type1 = d;
	type2 = e;
	species = f;
	height = g;
	weight = h;
	color = i;
	catchrate = j;
	male = k;
	female = l;
	egggroup1 = m;
	egggroup2 = n;
	eggcycle = o;
	dexinfo = p;
	evolutionarymethod = r;
	stoneofevolution = s;
	evolvesinto = t;
}

void _basicpokemon::setup2(int x, int y)
{
	learnset[x].level = x;
	learnset[x].moveno = y;
}

void _basicpokemon::setup3(int q, int r, int s, int t, int u, int v)
{
	basehp = q;
	baseatt = r;
	basedef = s;
	basespatt = t;
	basespdef = u;
	basespd = v;
}


_pokemon::_pokemon()
{
	level = 0;
	hp = 10;
	curhp = 3;
	attack = 0;
	defense = 0;
	specialattack = 0;
	specialdefense = 0;
	speed = 0;
	moves[4];	// <-- wut? o.O
	ot = 0;
	outsider = 0;
 }

int _pokemon::hppercentcalc()
{
	int x;

	if (hp==0)
		x=10;
	else
		x=((curhp*100)/hp);
	return x;
}

void _pokemon::setup(int a, int lvl)
{
    no = basicpokemon[a].no;
    strcpy( name, basicpokemon[a].name );
    dexno = basicpokemon[a].dexno;
    type1 = basicpokemon[a].type1;
    type2 = basicpokemon[a].type2;
    species = basicpokemon[a].species;
    height = basicpokemon[a].height;
    weight = basicpokemon[a].weight;
    color = basicpokemon[a].color;
    catchrate = basicpokemon[a].catchrate;
    male = basicpokemon[a].male;
    female = basicpokemon[a].female;
    egggroup1 = basicpokemon[a].egggroup1;
    egggroup2 = basicpokemon[a].egggroup2;
    eggcycle = basicpokemon[a].eggcycle;
    dexinfo = basicpokemon[a].dexinfo;
    basehp = basicpokemon[a].basehp;
    baseatt = basicpokemon[a].baseatt;
    basedef = basicpokemon[a].basedef;
    basespatt = basicpokemon[a].basespatt;
    basespdef = basicpokemon[a].basedef;
    basespd = basicpokemon[a].basespd;

    level=lvl;
	if((level < 50)&&(level > 44)) {
		basehpf=basehp*2.5;
		hp = basehpf;
	}
	else if(level == 50) {
		hp=basehp*3;
	}
	else if((level < 56)&&(level > 50)) {
		basehpf=basehp*3.5;
		hp = basehpf;
	}
	else {
		hp=basehp*3;
	}
    curhp=hp;
    attack=baseatt*2;
    defense=basedef*2;
    specialattack=basespatt*2;
    specialdefense=basespdef*2;
    speed=basespd*2;
    //ot=j; Line removed, 'cos I don't give a fu... crap. I meant crap.

    createmoveset();
}

void _pokemon::createmoveset()
{
	int a, b, c, d;

	switch (no)
	{
		case 1:                         
			a=33;                                     //tackle
			b=22;                      		  //vine whip
			c=75;					  //razor leaf
			d=0;
			break;
		case 2:                         
			a=33;
			b=22;
			c=75;
			d=0;
			break;
		case 3:                         
			a=33;
			b=22;
			c=75;
			d=0;
			break;
		case 4:                         
			a=10;                   		   //scratch
			b=163;					   //slash 
			c=0;
			d=0;
			break;
		case 5:                         
			a=10;
			b=163;
			c=0;
			d=0;
			break;
		case 6:                         
			a=10;
			b=163;
			c=0;
			d=0;
			break;
		case 7:                         
			a=33;					
			b=55;					   //water gun
			c=56;					   //hydro pump
			d=0;					   
			break;
		case 8:                         
			a=33;
			b=55;
			c=56;
			d=0;
			break;
		case 9:                         
			a=33;
			b=55;
			c=56;
			d=0;
			break;
		case 10:                         
			a=33;
			b=0;
			c=0;
			d=0;
			break;
		case 11:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 12:                         
			a=16;					   //gust
			b=0;
			c=0;
			d=0;
			break;
		case 13:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 14:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 15:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 16:                         
			a=16;
			b=17;					   //wing attack
			c=0;
			d=0;
			break;
		case 17:                         
			a=16;
			b=17;
			c=0;
			d=0;
			break;
		case 18:                         
			a=16;
			b=17;
			c=0;
			d=0;
			break;
		case 19:                         
			a=33;
			b=0;
			c=0;
			d=0;
			break;
		case 20:                         
			a=33;
			b=0;
			c=0;
			d=0;
			break;
		case 21:                         
			a=64;					   //peck
			b=65;					   //drill peck
			c=0;
			d=0;
			break;
		case 22:                         
			a=64;
			b=65;
			c=0;
			d=0;
			break;
		case 23:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 24:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 25:                         
			a=21;					   //slam
			b=129;					   //swift
			c=0;
			d=0;
			break;
		case 26:                         
			a=0;
			b=0;
			c=0;
			d=0;
			break;
		case 27:                         
			a=10;
			b=163;
			c=129;
			d=0;
			break;
		case 28:                         
			a=10;
			b=163;
			c=129;
			d=0;
			break;
		case 29:                         
			a=33;
			b=10;
			c=0;
			d=0;
			break;
		case 30:                         
			a=33;
			b=10;
			c=0;
			d=0;
			break;
		case 31:                         
			a=33;
			b=10;
			c=0;
			d=0;
			break;
		case 32:                         
			a=33;
			b=30;					   //horn attack
			c=0;
			d=0;
			break;
		case 33:                         
			a=33;
			b=30;
			c=0;
			d=0;
			break;
		case 34:                         
			a=33;
			b=30;
			c=0;
			d=0;
			break;
	}

	//THIS NEEDS CHECKING! AND NOW THE CATEGORY "OHKO" has been coded in.

	while((a==0)||(Move[a].category != Regular)||(((Move[a].type != type1)&&(Move[a].type != type2))&&(Move[a].type != NORMAL)) || (a == 9000))
	{
		a = rand() % 165 + 1;
	}
	while(((b==0)||(Move[b].category != Regular)||(((Move[b].type != type1)&&(Move[b].type != type2))&&(Move[b].type != NORMAL)))||(a==b) || (b == 9000))
	{
		b = rand() % 165 + 1;
	}
	while(((c==0)||(Move[c].category != Regular)||(((Move[c].type != type1)&&(Move[c].type != type2))&&(Move[c].type != NORMAL)))||(a==c)||(b==c) || (c == 9000))
	{
		c = rand() % 165 + 1;
	}
	while(((d==0)||(Move[d].category != Regular)||(((Move[d].type != type1)&&(Move[d].type != type2))&&(Move[d].type != NORMAL)))||(a==d)||(b==d)||(c==d) || (d == 9000))
	{
		d = rand() % 165 + 1;
	}
                  
	moves[0] = Move[a];
	moves[1] = Move[b];
	moves[2] = Move[c];
	moves[3] = Move[d];
}


_settings::_settings()
{
	//Fullscreen
	HANDLE hConsole;
	COORD size;
	HWND hWnd;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	size = GetLargestConsoleWindowSize(hConsole);
	SetConsoleScreenBufferSize(hConsole,size);
	SetConsoleTitle(L"Pokemon: Fan Version - The battle begins!");
	hWnd = FindWindow(NULL,L"Pokemon: Fan Version - The battle begins!");
	ShowWindow(hWnd,SW_MAXIMIZE);

	//Hiding Cursor
	CONSOLE_CURSOR_INFO CursoInfo;
	CursoInfo.dwSize = 1;
	CursoInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &CursoInfo);

	textspeed = 50;
}

void _settings::typewriter(char s[])
{
	int i;

	for (i=0; s[i] != '\0'; i++)
	{
		cout << s[i];
		Sleep(textspeed);
	}
}

void _settings::colorchange(int c, int a)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);

	if (a==1)
		system("cls");
}

int _settings::menu(char pretext[], int n, char ch[][15])
{
	int x=1, i;
	char a=0;

	while (a!=ENTER)
	{
		system("cls");
		cout << pretext;

		for (i=1; i<=n; i++)
		{
			if (x==i)
				cout<<PLAY<<" "<<ch[i-1]<<endl;
			else
				cout<<"  "<<ch[i-1]<<endl;
		}

		a = getch();

		if (a==UP && x>1)
			x--;
		else if (a==DOWN && x<n)
			x++;
	}
	return x;
}

void _settings::gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

_battle::_battle()
{

}

/*int _battle::beginbattle()
{
}*/

int _battle::damagecalc(_pokemon a, _pokemon b, _move m)                    //Calculates damage done with one attack
{
	float damage;                                                 //Net Damage done
	float level;                                                  //Level of the attacker
	float attack;                                                 //Attack stat of the attacker
	float defense;                                                //Defense stat of the attacked
	float base;                                                   //Base damage of the attack
	float modifier;                                               //Formula as below

	float stab;                                                   //Same Type Attack Bonus (1.5 if the user has the same type as the attcker, 1 otherwise)
	float type;                                                   //Type Effectiveness (Can be 0, 0.25, 0.5, 1, 2, or 4 depending on types)
	float critical;                                               //Critical Ratio. See table at http://bulbapedia.bulbagarden.net/wiki/Damage_modification#Generation_II_onwards
	float other;                                                  //Accounts for held items, such as increrasing power of a certain move
	float randomnum;                                              //A number from 0.85 to 1.00

	level = a.level;
	attack = a.attack;
	defense = b.defense;
	base = m.basepower;

	if (a.type1 == m.type)
		stab = 1.5;
	else if (a.type2 == m.type)
		stab = 1.5;
	else
		stab = 1;

	type = typeeffectcalc(m.type, b.type1, b.type2);

	if (m.critratio = 0)
		critical = 1;
	else
		critical = 1.5;

	int temp = ((rand()%16)+80);

	randomnum = (float)temp/100;

	modifier = stab * type * critical * randomnum;								// Formula for modifier

	damage = ((((2*level)+10)/250)*(attack/defense)*(base)+2)*modifier;	// Formula (It's harder than it looks)
	
	if (m.category==OHKO)
	{
		if (a.speed>b.speed)
		return 10000;
		else return 0;
	}
	
	return (int)damage;		// Returns net damage
}

float _battle::typeeffectcalc(ptype movetype, ptype type1, ptype type2)
{
	float multiplier=1;

	if (movetype==NORMAL)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=0.5;
		else if (type1==BUG)
			multiplier*=1;
		else if (type1==GHOST)
			multiplier*=0;
		else if (type1==STEEL)
			multiplier*=0.5;
		else if (type1==FIRE)
			multiplier*=1;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=1;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==FIGHTING)
	{
		if (type1==NORMAL)
			multiplier*=2;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=0.5;
		else if (type1==POISON)
			multiplier*=0.5;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=2;
		else if (type1==BUG)
			multiplier*=0.5;
		else if (type1==GHOST)
			multiplier*=0;
		else if (type1==STEEL)
			multiplier*=2;
		else if (type1==FIRE)
			multiplier*=1;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=1;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=0.5;
		else if (type1==ICE)
			multiplier*=2;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=2;
	}

	else if (movetype==FLYING)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=2;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=0.5;
		else if (type1==BUG)
			multiplier*=2;
		else if (type1==GHOST)
			multiplier*=1;
		else if (type1==STEEL)
			multiplier*=0.5;
		else if (type1==FIRE)
			multiplier*=1;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=2;
		else if (type1==ELECTRIC)
			multiplier*=0.5;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==POISON)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=0.5;
		else if (type1==GROUND)
			multiplier*=0.5;
		else if (type1==ROCK)
			multiplier*=0.5;
		else if (type1==BUG)
			multiplier*=1;
		else if (type1==GHOST)
			multiplier*=0.5;
		else if (type1==STEEL)
			multiplier*=0;
		else if (type1==FIRE)
			multiplier*=1;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=2;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==GROUND)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=0;
		else if (type1==POISON)
			multiplier*=2;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=2;
		else if (type1==BUG)
			multiplier*=0.5;
		else if (type1==GHOST)
			multiplier*=1;
		else if (type1==STEEL)
			multiplier*=2;
		else if (type1==FIRE)
			multiplier*=2;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=0.5;
		else if (type1==ELECTRIC)
			multiplier*=2;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==ROCK)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=0.5;
		else if (type1==FLYING)
			multiplier*=2;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=0.5;
		else if (type1==ROCK)
			multiplier*=1;
		else if (type1==BUG)
			multiplier*=2;
		else if (type1==GHOST)
			multiplier*=1;
		else if (type1==STEEL)
			multiplier*=0.5;
		else if (type1==FIRE)
			multiplier*=2;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=1;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=2;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==BUG)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=0.5;
		else if (type1==FLYING)
			multiplier*=0.5;
		else if (type1==POISON)
			multiplier*=0.5;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=1;
		else if (type1==BUG)
			multiplier*=1;
		else if (type1==GHOST)
			multiplier*=0.5;
		else if (type1==STEEL)
			multiplier*=0.5;
		else if (type1==FIRE)
			multiplier*=0.5;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=2;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=2;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=2;
	}

	else if (movetype==GHOST)
	{
		if (type1==NORMAL)
			multiplier*=0;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=1;
		else if (type1==BUG)
			multiplier*=1;
		else if (type1==GHOST)
			multiplier*=2;
		else if (type1==STEEL)
			multiplier*=0.5;
		else if (type1==FIRE)
			multiplier*=1;
		else if (type1==WATER)
			multiplier*=1;
		else if (type1==GRASS)
			multiplier*=1;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=2;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=0.5;
	}

	else if (movetype==STEEL)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=2;
		else if (type1==BUG)
			multiplier*=1;
		else if (type1==GHOST)
			multiplier*=1;
		else if (type1==STEEL)
			multiplier*=0.5;
		else if (type1==FIRE)
			multiplier*=0.5;
		else if (type1==WATER)
			multiplier*=0.5;
		else if (type1==GRASS)
			multiplier*=1;
		else if (type1==ELECTRIC)
			multiplier*=0.5;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=2;
		else if (type1==DRAGON)
			multiplier*=1;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==FIRE)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=1;
		else if (type1==ROCK)
			multiplier*=0.5;
		else if (type1==BUG)
			multiplier*=2;
		else if (type1==GHOST)
			multiplier*=1;
		else if (type1==STEEL)
			multiplier*=2;
		else if (type1==FIRE)
			multiplier*=0.5;
		else if (type1==WATER)
			multiplier*=0.5;
		else if (type1==GRASS)
			multiplier*=2;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=2;
		else if (type1==DRAGON)
			multiplier*=0.5;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==WATER)
	{
		if (type1==NORMAL)
			multiplier*=1;
		else if (type1==FIGHTING)
			multiplier*=1;
		else if (type1==FLYING)
			multiplier*=1;
		else if (type1==POISON)
			multiplier*=1;
		else if (type1==GROUND)
			multiplier*=2;
		else if (type1==ROCK)
			multiplier*=2;
		else if (type1==BUG)
			multiplier*=1;
		else if (type1==GHOST)
			multiplier*=1;
		else if (type1==STEEL)
			multiplier*=1;
		else if (type1==FIRE)
			multiplier*=2;
		else if (type1==WATER)
			multiplier*=0.5;
		else if (type1==GRASS)
			multiplier*=0.5;
		else if (type1==ELECTRIC)
			multiplier*=1;
		else if (type1==PSYCHIC)
			multiplier*=1;
		else if (type1==ICE)
			multiplier*=1;
		else if (type1==DRAGON)
			multiplier*=0.5;
		else if (type1==DARK)
			multiplier*=1;
	}

	else if (movetype==GRASS)
	{
		if (type1==NORMAL)
		multiplier*=1;
		else if (type1==FIGHTING)
		multiplier*=1;
		else if (type1==FLYING)
		multiplier*=0.5;
		else if (type1==POISON)
		multiplier*=0.5;
		else if (type1==GROUND)
		multiplier*=2;
		else if (type1==ROCK)
		multiplier*=2;
		else if (type1==BUG)
		multiplier*=0.5;
		else if (type1==GHOST)
		multiplier*=1;
		else if (type1==STEEL)
		multiplier*=0.5;
		else if (type1==FIRE)
		multiplier*=0.5;
		else if (type1==WATER)
		multiplier*=2;
		else if (type1==GRASS)
		multiplier*=0.5;
		else if (type1==ELECTRIC)
		multiplier*=1;
		else if (type1==PSYCHIC)
		multiplier*=1;
		else if (type1==ICE)
		multiplier*=1;
		else if (type1==DRAGON)
		multiplier*=0.5;
		else if (type1==DARK)
		multiplier*=1;
	}

	else if (movetype==ELECTRIC)
	{
		if (type1==NORMAL)
		multiplier*=1;
		else if (type1==FIGHTING)
		multiplier*=1;
		else if (type1==FLYING)
		multiplier*=2;
		else if (type1==POISON)
		multiplier*=1;
		else if (type1==GROUND)
		multiplier*=0;
		else if (type1==ROCK)
		multiplier*=1;
		else if (type1==BUG)
		multiplier*=1;
		else if (type1==GHOST)
		multiplier*=1;
		else if (type1==STEEL)
		multiplier*=1;
		else if (type1==FIRE)
		multiplier*=1;
		else if (type1==WATER)
		multiplier*=2;
		else if (type1==GRASS)
		multiplier*=0.5;
		else if (type1==ELECTRIC)
		multiplier*=0.5;
		else if (type1==PSYCHIC)
		multiplier*=1;
		else if (type1==ICE)
		multiplier*=1;
		else if (type1==DRAGON)
		multiplier*=0.5;
		else if (type1==DARK)
		multiplier*=1;
	}

	else if (movetype==PSYCHIC)
	{
		if (type1==NORMAL)
		multiplier*=1;
		else if (type1==FIGHTING)
		multiplier*=2;
		else if (type1==FLYING)
		multiplier*=1;
		else if (type1==POISON)
		multiplier*=2;
		else if (type1==GROUND)
		multiplier*=1;
		else if (type1==ROCK)
		multiplier*=1;
		else if (type1==BUG)
		multiplier*=1;
		else if (type1==GHOST)
		multiplier*=1;
		else if (type1==STEEL)
		multiplier*=0.5;
		else if (type1==FIRE)
		multiplier*=1;
		else if (type1==WATER)
		multiplier*=1;
		else if (type1==GRASS)
		multiplier*=1;
		else if (type1==ELECTRIC)
		multiplier*=1;
		else if (type1==PSYCHIC)
		multiplier*=0.5;
		else if (type1==ICE)
		multiplier*=1;
		else if (type1==DRAGON)
		multiplier*=1;
		else if (type1==DARK)
		multiplier*=0;
	}

	else if (movetype==ICE)
	{
		if (type1==NORMAL)
		multiplier*=1;
		else if (type1==FIGHTING)
		multiplier*=1;
		else if (type1==FLYING)
		multiplier*=2;
		else if (type1==POISON)
		multiplier*=1;
		else if (type1==GROUND)
		multiplier*=2;
		else if (type1==ROCK)
		multiplier*=1;
		else if (type1==BUG)
		multiplier*=1;
		else if (type1==GHOST)
		multiplier*=1;
		else if (type1==STEEL)
		multiplier*=0.5;
		else if (type1==FIRE)
		multiplier*=0.5;
		else if (type1==WATER)
		multiplier*=0.5;
		else if (type1==GRASS)
		multiplier*=2;
		else if (type1==ELECTRIC)
		multiplier*=1;
		else if (type1==PSYCHIC)
		multiplier*=1;
		else if (type1==ICE)
		multiplier*=0.5;
		else if (type1==DRAGON)
		multiplier*=2;
		else if (type1==DARK)
		multiplier*=1;
	}

	else if (movetype==DRAGON)
	{
		if (type1==NORMAL)
		multiplier*=1;
		else if (type1==FIGHTING)
		multiplier*=1;
		else if (type1==FLYING)
		multiplier*=1;
		else if (type1==POISON)
		multiplier*=1;
		else if (type1==GROUND)
		multiplier*=1;
		else if (type1==ROCK)
		multiplier*=1;
		else if (type1==BUG)
		multiplier*=1;
		else if (type1==GHOST)
		multiplier*=1;
		else if (type1==STEEL)
		multiplier*=0.5;
		else if (type1==FIRE)
		multiplier*=1;
		else if (type1==WATER)
		multiplier*=1;
		else if (type1==GRASS)
		multiplier*=1;
		else if (type1==ELECTRIC)
		multiplier*=1;
		else if (type1==PSYCHIC)
		multiplier*=1;
		else if (type1==ICE)
		multiplier*=1;
		else if (type1==DRAGON)
		multiplier*=2;
		else if (type1==DARK)
		multiplier*=1;
	}

	else if (movetype==DARK)
	{
		if (type1==NORMAL)
		multiplier*=1;
		else if (type1==FIGHTING)
		multiplier*=0.5;
		else if (type1==FLYING)
		multiplier*=1;
		else if (type1==POISON)
		multiplier*=1;
		else if (type1==GROUND)
		multiplier*=1;
		else if (type1==ROCK)
		multiplier*=1;
		else if (type1==BUG)
		multiplier*=1;
		else if (type1==GHOST)
		multiplier*=2;
		else if (type1==STEEL)
		multiplier*=0.5;
		else if (type1==FIRE)
		multiplier*=1;
		else if (type1==WATER)
		multiplier*=1;
		else if (type1==GRASS)
		multiplier*=1;
		else if (type1==ELECTRIC)
		multiplier*=1;
		else if (type1==PSYCHIC)
		multiplier*=2;
		else if (type1==ICE)
		multiplier*=1;
		else if (type1==DRAGON)
		multiplier*=1;
		else if (type1==DARK)
		multiplier*=0.5;
	}

	if (movetype==NORMAL)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=0.5;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=0;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==FIGHTING)
	{
		if (type2==NORMAL)
		multiplier*=2;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=0.5;
		else if (type2==POISON)
		multiplier*=0.5;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=2;
		else if (type2==BUG)
		multiplier*=0.5;
		else if (type2==GHOST)
		multiplier*=0;
		else if (type2==STEEL)
		multiplier*=2;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=0.5;
		else if (type2==ICE)
		multiplier*=2;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=2;
	}

	else if (movetype==FLYING)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=2;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=0.5;
		else if (type2==BUG)
		multiplier*=2;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=2;
		else if (type2==ELECTRIC)
		multiplier*=0.5;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==POISON)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=0.5;
		else if (type2==GROUND)
		multiplier*=0.5;
		else if (type2==ROCK)
		multiplier*=0.5;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=0.5;
		else if (type2==STEEL)
		multiplier*=0;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=2;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==GROUND)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=0;
		else if (type2==POISON)
		multiplier*=2;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=2;
		else if (type2==BUG)
		multiplier*=0.5;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=2;
		else if (type2==FIRE)
		multiplier*=2;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=0.5;
		else if (type2==ELECTRIC)
		multiplier*=2;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==ROCK)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=0.5;
		else if (type2==FLYING)
		multiplier*=2;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=0.5;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=2;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=2;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=2;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==BUG)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=0.5;
		else if (type2==FLYING)
		multiplier*=0.5;
		else if (type2==POISON)
		multiplier*=0.5;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=0.5;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=0.5;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=2;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=2;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=2;
	}

	else if (movetype==GHOST)
	{
		if (type2==NORMAL)
		multiplier*=0;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=2;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=2;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=0.5;
	}

	else if (movetype==STEEL)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=2;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=0.5;
		else if (type2==WATER)
		multiplier*=0.5;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=0.5;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=2;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==FIRE)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=0.5;
		else if (type2==BUG)
		multiplier*=2;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=2;
		else if (type2==FIRE)
		multiplier*=0.5;
		else if (type2==WATER)
		multiplier*=0.5;
		else if (type2==GRASS)
		multiplier*=2;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=2;
		else if (type2==DRAGON)
		multiplier*=0.5;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==WATER)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=2;
		else if (type2==ROCK)
		multiplier*=2;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=1;
		else if (type2==FIRE)
		multiplier*=2;
		else if (type2==WATER)
		multiplier*=0.5;
		else if (type2==GRASS)
		multiplier*=0.5;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=0.5;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==GRASS)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=0.5;
		else if (type2==POISON)
		multiplier*=0.5;
		else if (type2==GROUND)
		multiplier*=2;
		else if (type2==ROCK)
		multiplier*=2;
		else if (type2==BUG)
		multiplier*=0.5;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=0.5;
		else if (type2==WATER)
		multiplier*=2;
		else if (type2==GRASS)
		multiplier*=0.5;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=0.5;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==ELECTRIC)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=2;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=0;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=1;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=2;
		else if (type2==GRASS)
		multiplier*=0.5;
		else if (type2==ELECTRIC)
		multiplier*=0.5;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=0.5;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==PSYCHIC)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=2;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=2;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=0.5;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=0;
	}

	else if (movetype==ICE)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=2;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=2;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=0.5;
		else if (type2==WATER)
		multiplier*=0.5;
		else if (type2==GRASS)
		multiplier*=2;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=0.5;
		else if (type2==DRAGON)
		multiplier*=2;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==DRAGON)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=1;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=1;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=1;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=2;
		else if (type2==DARK)
		multiplier*=1;
	}

	else if (movetype==DARK)
	{
		if (type2==NORMAL)
		multiplier*=1;
		else if (type2==FIGHTING)
		multiplier*=0.5;
		else if (type2==FLYING)
		multiplier*=1;
		else if (type2==POISON)
		multiplier*=1;
		else if (type2==GROUND)
		multiplier*=1;
		else if (type2==ROCK)
		multiplier*=1;
		else if (type2==BUG)
		multiplier*=1;
		else if (type2==GHOST)
		multiplier*=2;
		else if (type2==STEEL)
		multiplier*=0.5;
		else if (type2==FIRE)
		multiplier*=1;
		else if (type2==WATER)
		multiplier*=1;
		else if (type2==GRASS)
		multiplier*=1;
		else if (type2==ELECTRIC)
		multiplier*=1;
		else if (type2==PSYCHIC)
		multiplier*=2;
		else if (type2==ICE)
		multiplier*=1;
		else if (type2==DRAGON)
		multiplier*=1;
		else if (type2==DARK)
		multiplier*=0.5;
	}
	return multiplier;
}

void initMoveSet()
{
	Move[0].setup(0, "Hop", WATER, 0, 0, Regular, 0, 0);
	Move[1].setup(1, "Pound", NORMAL, 40, 100, Regular, 0, 35);
	Move[2].setup(2, "Karate Chop", NORMAL, 50, 100, Regular, 1, 25);
	Move[3].setup(3, "Double Slap", NORMAL, 15, 85, MultipleHits, 0, 10);           /*DoubleSlap inflicts damage, hitting 2-5 times per use. There is a 37.5% chance that it will hit 2 times, a 37.5% chance that it will hit 3 times, a 12.5% chance that it will hit 4 times, and a 12.5% chance that it will hit 5 times. Stops if breaks substit*/
		Move[3].setup2(2,5);
	Move[4].setup(4, "Comet Punch", NORMAL, 18, 85, MultipleHits, 0, 15);           /*Comet Punch inflicts damage, hitting 2-5 times per use. There is a 37.5% chance that it will hit 2 times, a 37.5% chance that it will hit 3 times, a 12.5% chance that it will hit 4 times, and a 12.5% chance that it will hit 5 times. Ends if breaks substit*/
		Move[4].setup2(2,5);
	Move[5].setup(5, "Mega Punch", NORMAL, 80, 85, Regular, 0, 20);
	Move[6].setup(6, "Pay Day", NORMAL, 40, 100, Special, 0, 20);                   /*Pay Day does damage, and scatters coins on the ground with a value equal to five times the user's level for each time it's used. These coins are picked up afterwards if the player wins the battle.*/
	//SPECIAL SETUP
	Move[7].setup(7, "Fire Punch", FIRE, 75, 100, RegularStatus, 0, 15);            /*10% chance of a burn*/
		Move[7].setup2(Burn,10);
	Move[8].setup(8, "Ice Punch", ICE, 75, 100, RegularStatus, 0, 15);              /*10% chance of freeze*/
		Move[8].setup2(Freeze,10);
	Move[9].setup(9, "Thunder Punch", ELECTRIC, 75, 100, RegularStatus, 0, 15);     /*10% chance of paralysis*/
		Move[7].setup2(Paralysis,10);
	Move[10].setup(10, "Scratch", NORMAL, 40, 100, Regular, 0, 35);
	Move[11].setup(11, "Vice Grip", NORMAL, 55, 100, Regular, 0, 30);
	Move[12].setup(12, "Guillotine", NORMAL, 0, 30, OHKO, 0, 5);                    /*Cannot hit an opponent of higher speed. Always KO's an opponent or substitutee*/
	Move[13].setup(13, "Razor Wind", NORMAL, 80, 75, Charge, 1, 10);                /*Razor Wind does nothing on the turn it is selected, other than saying "<Pok�mon> made a whirlwind!". On the following turn, Razor Wind inflicts damage.*/
	Move[14].setup(14, "Swords Dance", NORMAL, 0, 0, Stat, 0, 30);                  /*Increases attack by two stages*/
		Move[14].setup2(Attack, 1);
	Move[15].setup(15, "Cut", NORMAL, 50, 95, Regular, 0, 30);
	Move[16].setup(16, "Gust", NORMAL, 40, 100, Regular, 0, 35);
	Move[17].setup(17, "Wing Attack", FLYING, 35, 100, Regular, 0, 35);
	Move[18].setup(18, "Whirlwind", NORMAL, 0, 100, Flee, 0, 20);                   /*Whirlwind can be used to automatically end wild Pok�mon battles and has normal priority. Even if a wild Pok�mon uses the Move, the battle will end. However, it has no effect in a Trainer battle.*/
	Move[19].setup(19, "Fly", FLYING, 70, 95, Charge, 0, 15);
	Move[20].setup(20, "Bind", NORMAL, 15, 75, MultipleTurns, 0, 20);               /*Bind does damage for 2-5 turns. There is a 37.5% chance that it will attack for 2 turns, a 37.5% chance that it will attack for 3 turns, a 12.5% chance that it will attack for 4 turns, and a 12.5% chance that it will attack for 5 turns.*/
		Move[20].setup2(2,5);
	Move[21].setup(21, "Slam", NORMAL, 80, 75, Regular, 0, 80);
	Move[22].setup(22, "Vine Whip", GRASS, 35, 100, Regular, 0, 10);
	Move[23].setup(23, "Stomp", NORMAL, 65, 100, RegularStatus, 0, 20);             /*Stomp inflicts damage and has a 30% chance of causing the target to flinch. Stomp cannot make a target with a substitute flinch.*/
		Move[23].setup2(Flinch, 30);
	Move[24].setup(24, "Double Kick", FIGHTING, 30, 100, MultipleHits, 0, 30);      /*Double Kick inflicts damage, striking twice per use. Although only the first hit can be a critical hit, the second hit will deal the same amount of damage. Double Kick will not hit twice if the first hit breaks a substitute.*/
		Move[24].setup2(2,2);
	Move[25].setup(25, "Mega Kick", NORMAL, 120, 75, Regular, 0, 5);
	Move[26].setup(26, "Jump Kick", FIGHTING, 70, 95, Special, 0, 25);              /*Jump Kick does damage. If it misses, the user will take crash damage of 50%. If used against a Ghost-type, it always counts as a miss.*/
	//SPECIAL SETUP
	Move[27].setup(27, "Rolling Kick", FIGHTING, 60, 85, RegularStatus, 0, 15);     /*Rolling Kick does damage and has a 30% chance of causing the target to flinch. Rolling Kick can't make a target with a substitute flinch.*/
		Move[27].setup2(Flinch, 30);
	Move[28].setup(28, "Sand Attack", NORMAL, 0, 100, Stat, 0, 15);                 /*Sand-Attack decreases the target's accuracy stat by one stage.*/
		Move[28].setup2(Attack, 2);
	Move[29].setup(29, "Headbutt", NORMAL, 70, 100, RegularStatus, 0, 15);          /*30% chance of causing the target to flinch.*/
		Move[29].setup2(Flinch, 30);
	Move[30].setup(30, "Horn Attack", NORMAL, 65, 100, Regular, 0, 25);
	Move[31].setup(31, "Fury Attack", NORMAL, 15, 85, MultipleHits, 0, 20);         /*Fury Attack inflicts damage, hitting 2-5 times per use. There is a 37.5% chance that it will hit 2 times, a 37.5% chance that it will hit 3 times, a 12.5% chance that it will hit 4 times, and a 12.5% chance that it will hit 5 times.*/
		Move[31].setup2(2,5);
	Move[32].setup(32, "Horn Drill", NORMAL, 0, 30, OHKO, 0, 5);                    /*Horn Drill has 30% accuracy and inflicts damage equal to the target's current HP. Horn Drill will break a substitute if it hits. Horn Drill will not affect a target whose current Speed stat is greater than the user's current Speed stat.*/
	Move[33].setup(33, "Tackle", NORMAL, 35, 95, Regular, 0, 35);
	Move[34].setup(34, "Body Slam", NORMAL, 85, 100, RegularStatus, 0, 15);         /*30% chance of paralyzing the target.*/
		Move[34].setup2(Paralysis,30);
	Move[35].setup(35, "Wrap", NORMAL, 15, 85, MultipleTurns, 0, 20);               /*Wrap inflicts damage for 2-5 turns. There is a 37.5% chance that it will attack for 2 turns, a 37.5% chance that it will attack for 3 turns, a 12.5% chance that it will attack for 4 turns, and a 12.5% chance that it will attack for 5 turns.*/
	Move[36].setup(36, "Take Down", NORMAL, 90, 85, Recoil, 0, 20);                 /*Take Down does damage, and the user receives recoil damage equal to 25% of the damage done to the opponent. If Take Down breaks a substitute, the user will take no recoil damage.*/
		Move[36].setup2(25);
	Move[37].setup(37, "Thrash", NORMAL, 90, 100, MultipleTurns, 0, 20);            /*It does damage for 3-4 (chosen randomly) turns. Once used (even if it misses on the turn of its use), the user will only be able to use Thrash, and will not be able to switch out. At the end of this duration, the user will become confused.*/
		Move[37].setup2(3,4);
	Move[38].setup(38, "Double-Edge", NORMAL, 100, 100, Recoil, 0, 15);             /*Double-Edge inflicts damage and the user receives recoil damage equal to 25% of the damage done to the target.*/
		Move[38].setup2(25);
	Move[39].setup(39, "Tail Whip", NORMAL, 0, 100, Stat, 0, 30);                   /*Tail Whip decreases the target's Defense stat by one stage.*/
		Move[39].setup2(Defense, 2);
	Move[40].setup(40, "Poison Sting", POISON, 15, 100, RegularStatus, 0, 35);      /*30% chance of poisoning the target.*/
		Move[40].setup2(Poison, 30);
	Move[41].setup(41, "Twineedle", BUG, 25, 100, Special, 0, 35);                  /*Twineedle inflicts damage, striking twice per use. Each hit has a 20% chance of poisoning the target. Twineedle will not hit twice if the first hit breaks a substitute.*/
	//SPECIAL SETUP
	Move[42].setup(42, "Pin Missile", BUG, 14, 85, MultipleHits, 0, 20);            /*Pin Missile inflicts damage, hitting 2-5 times per use. There is a 37.5% chance that it will hit 2 times, a 37.5% chance that it will hit 3 times, a 12.5% chance that it will hit 4 times, and a 12.5% chance that it will hit 5 times. Ends if hits sub*/
		Move[42].setup2(2,5);
	Move[43].setup(43, "Leer", NORMAL, 0, 100, Stat, 0, 30);                        /*Decreases the target's Defense stat by one stage.*/
		Move[43].setup2(Defense, 2);
	Move[44].setup(44, "Bite", NORMAL, 60, 100, RegularStatus, 0, 25);              /*Has a 10% chance of causing the target to flinch.*/
		Move[44].setup2(Flinch, 10);
	Move[45].setup(45, "Growl", NORMAL, 0, 100, Stat, 0, 40);                       /*Decreases the opponent's Attack by one stage.*/
		Move[45].setup2(Attack, 2);
	Move[46].setup(46, "Roar", NORMAL, 0, 100, Flee, 0, 20);                        /*Roar can be used to automatically end wild Pok�mon battles. No effect in a Trainer battle.*/
	Move[47].setup(47, "Sing", NORMAL, 0, 55, Status, 0, 15);                       /*Puts the target to sleep.*/
		Move[47].setup2(Asleep);
	Move[48].setup(48, "Supersonic", NORMAL, 0, 55, Status, 0, 20);                 /*Supersonic causes the target to become confused. Supersonic will fail if the target has a substitute, or is already confused.*/
		Move[48].setup2(Confusion);
	Move[49].setup(49, "Sonic Boom", NORMAL, 0, 90, Specific, 0, 20);                /*Does 20 damage, no matter what*/
		Move[49].setup2(20);
	Move[50].setup(50, "Disable", NORMAL, 0, 80, Special, 0, 30);                   /*Disable randomly selects one Move that is in the target's current Move set and whose current PP is greater than 0, and gives it a randomly chosen disable duration length of 0-6, which is reduced by 1 each time the Pok�mon attempts to execute an attack.*/
	//SPECIAL SETUP
	Move[51].setup(51, "Acid", POISON, 40, 100, RegularStat, 0, 25);                /*Acid does damage and has a 10% chance of lowering the target's Defense by one stage.*/
		Move[51].setup2(Defense, 10, 2);
	Move[52].setup(52, "Ember", FIRE, 40, 100, RegularStatus, 0, 15);               /*Ember does damage and has a 10% chance of burning the target.*/
		Move[52].setup2(Burn, 10);
	Move[53].setup(53, "Flamethrower", FIRE, 95, 100, RegularStatus, 0, 15);        /*Flamethrower does damage and has a 10% chance of burning the target.*/
		Move[53].setup2(Burn, 10);
	Move[54].setup(54, "Mist", ICE, 0, 0, Special, 0, 30);                          /*Mist protects the user from stat modifications inflicted by the opponent until it switches out. Moves used by the opponent that only cause a stat change will fail; Moves that deal damage and lower an opponent's stat still do damage.*/
	//SPECIAL SETUP
	Move[55].setup(55, "Water Gun", WATER, 40, 100, Regular, 0, 25);
	Move[56].setup(56, "Hydro Pump", WATER, 120, 80, Regular, 0, 5);
	Move[57].setup(57, "Surf", WATER, 95, 100, Regular, 0, 15);
	Move[58].setup(58, "Ice Beam", ICE, 0, 100, RegularStatus, 0, 10);              /*Ice Beam inflicts damage and has a 10% chance of freezing the target.*/
		Move[58].setup2(Freeze, 10);
	Move[59].setup(59, "Blizzard", ICE, 120, 90, RegularStatus, 0, 5);              /*Blizzard does damage and has a 10% chance of freezing the target.*/
		Move[59].setup2(Freeze, 10);
	Move[60].setup(60, "Psybeam", PSYCHIC, 65, 100, RegularStatus, 0, 20);          /*Psybeam does damage and has a 10% chance of confusing the target.*/
		Move[60].setup2(Confusion, 10);
	Move[61].setup(61, "Bubble Beam", WATER, 65, 100, RegularStat, 0, 20);          /*BubbleBeam does damage and has a 10% chance of lowering the target's speed by one stage.*/
		Move[61].setup2(Defense, 10, 2);
	Move[62].setup(62, "Aurora Beam", ICE, 65, 100, RegularStat, 0, 20);            /*Aurora Beam does damage and has a 10% chance of lowering the target's Attack stat by one stage.*/
		Move[62].setup2(Attack, 10, 2);
	Move[63].setup(63, "Hyper Beam", NORMAL, 150, 90, Recharge, 0, 5);              /*Hyper Beam inflicts damage. A recharge turn is required on the turn after damage is done, during which no action may be performed. Hyper Beam will not require a recharge turn if it misses, breaks a substitute.*/
	Move[64].setup(64, "Peck", FLYING, 35, 100, Regular, 0, 35);
	Move[65].setup(65, "Drill Peck", FLYING, 80, 100, Regular, 0, 20);
	Move[66].setup(66, "Submission", FIGHTING, 80, 80, Recoil, 0, 25);              /*Submission does damage, and the user receives recoil damage equal to 25% of the damage done to the target.*/
		Move[66].setup2(25);
	Move[67].setup(67, "Low Kick", FIGHTING, 50, 90, RegularStatus, 0, 20);         /*30% chance of causing the target to flinch.*/
		Move[67].setup2(Flinch, 30);
	Move[68].setup(68, "Counter", FIGHTING, 0, 100, Special, 0, 20);                /*If the last amount of damage done before the use of Counter is greater than 0 and was dealt by a Normal-type or Fighting-type attack, Counter will do twice as much damage to the opponent.*/
	//SPECIAL SETUP
	Move[69].setup(69, "Seismic Toss", FIGHTING, 0, 100, Special, 0, 20);           /*Seismic Toss inflicts damage equal to the user's level, for example, if the using Pok�mon is Level 25 the opposing Pok�mon will take 25 HP of direct damage. The damage is not altered by weakness or resistance, except when a Pok�mon is immune. No STAB.*/
	//SPECIAL SETUP
	Move[70].setup(70, "Strength", NORMAL, 80, 100, Regular, 0, 15);
	Move[71].setup(71, "Absorb", GRASS, 20, 100, Drain, 0, 20);                     /*Absorb does damage, and up to 50% of the damage done to the target is restored to the user, rounded up. If Absorb breaks a substitute, no HP will be restored to the user. Does not exceed max HP of user.*/
		Move[71].setup2(50);
	Move[72].setup(72, "Mega Drain", GRASS, 40, 100, Drain, 0, 10);                 /*Mega Drain inflicts damage, and 50% of the damage dealt to the target is restored to the user. If Mega Drain breaks a substitute, no HP will be restored to the user. Does not exceed max hp.*/
		Move[72].setup2(50);
	Move[73].setup(73, "Leech Seed", GRASS, 0, 90, DrainMultiple, 0, 10);           /*At the end of each turn that the target is under the effect of Leech Seed, 1/16 of the target's HP will be drained, and the same amount of HP will be restored to the target's opponent (even if it was not the Pok�mon that originally used the attack).*/
	Move[74].setup(74, "Growth", NORMAL, 0, 0, Stat, 0, 40);                        /*Growth increases the user's Special attack stat by one stage.*/
	Move[75].setup(75, "Razor Leaf", GRASS, 55, 95, Regular, 1, 25);
	Move[76].setup(76, "Solar Beam", GRASS, 120, 100, Charge, 0, 10);               /*SolarBeam does nothing on the turn it is selected, other than state that the user has taken in sunlight. On the following turn, SolarBeam will inflict damage, PP will be deducted from it, and it will count as the last Move used.*/
	Move[77].setup(77, "Poison Powder", POISON, 0, 75, Status, 0, 35);              /*PoisonPowder poisons the target.*/
	Move[78].setup(78, "Stun Spore", GRASS, 0, 75, Status, 0, 30);                  /*Stun Spore paralyzes the target.*/
	Move[79].setup(79, "Sleep Powder", GRASS, 0, 75, Status, 0, 15);                /*Sleep Powder puts the target to sleep.*/
	Move[80].setup(80, "Petal Dance", GRASS, 70, 100, MultipleTurns, 0, 20);        /*Petal Dance inflicts damage for 3 to 4 turns (chosen at random). Once selected, even if it misses, the user will only be able to use Petal Dance, and will not be able to switch out. At the end of this duration, the user will become confused.*/
	Move[81].setup(81, "String Shot", BUG, 0, 95, Stat, 0, 40);                     /*String Shot decreases the target's Speed stat by one stage.*/
	Move[82].setup(82, "Dragon Rage", DRAGON, 0, 100, Specific, 0, 10);              /*Always 40 damage, no matter what*/
	Move[83].setup(83, "Fire Spin", FIRE, 15, 70, MultipleTurns, 0, 15);            /*Fire Spin inflicts damage and traps the target for 2-5 turns, damaging the target at the end of each turn. There is a 37.5% chance that it will attack for 2 turns, a 37.5% chance for 3 turns, a 12.5% chance for 4 turns, and a 12.5% chance for 5 turns.*/
	Move[84].setup(84, "Thunder Shock", ELECTRIC, 40, 100, RegularStatus, 0, 30);   /*ThunderShock inflicts damage and has a 10% chance of paralyzing the target.*/
	Move[85].setup(85, "Thunderbolt", ELECTRIC, 95, 100, RegularStatus, 0, 15);     /*Thunderbolt does damage and has a 10% chance of paralyzing the target.*/
	Move[86].setup(86, "Thunder Wave", ELECTRIC, 0, 100, Status, 0, 20);            /*Thunder Wave paralyzes the target.*/
	Move[87].setup(87, "Thunder", ELECTRIC, 120, 70, RegularStatus, 0, 10);         /*Thunder deals damage and has a 10% chance of paralyzing the target.*/
	Move[88].setup(88, "Rock Throw", ROCK, 50, 65, Regular, 0, 15);
	Move[89].setup(89, "Earthquake", GROUND, 100, 100, Regular, 0, 10);
	Move[90].setup(90, "Fissure", GROUND, 0, 0, OHKO, 0, 5);                        /*Defeats opponent, or breaks sub.*/
	Move[91].setup(91, "Dig", GROUND, 100, 100, Charge, 0, 10);                     /*On the turn that Dig is selected, the user will dig underground, where the only attacks it cannot avoid are Bide, Swift, and Transform. On the following turn, Dig will do damage.*/
	Move[92].setup(92, "Toxic", POISON, 0, 85, Special, 0, 10);                     /*Toxic badly poisons the target, and has an accuracy of 85. Each time the target takes recurrent damage, the damage will equal N max (1, int (0.0625 � Max HP))*/
	Move[93].setup(93, "Confusion", PSYCHIC, 50, 100, RegularStatus, 0, 25);        /*Confusion does damage and has a 10% chance of confusing the target.*/
	Move[94].setup(94, "Psychic", PSYCHIC, 90, 100, RegularStat, 0, 10);            /*Psychic does damage and has a 30% chance of lowering the target's Special by one stage.*/
	Move[95].setup(95, "Hypnosis", PSYCHIC, 0, 60, Status, 0, 20);                  /*Hypnosis puts the target to sleep.*/
	Move[96].setup(96, "Meditate", PSYCHIC, 0, 0, Stat, 0, 40);                     /*Meditate increases the user's Attack by one level.*/
	Move[97].setup(97, "Agility", PSYCHIC, 0, 0, Stat, 0, 30);                      /*Agility increases the user's Speed by two stages.*/
	Move[98].setup(98, "Quick Attack", NORMAL, 40, 100, Special, 0, 30);            /*Quick Attack inflicts damage, and is an increased priority Move.*/
	Move[99].setup(99, "Rage", NORMAL, 20, 100, Special, 0, 20);                    /*It will not be possible for the user to do anything other than let the user continue to use Rage, and it will not stop using Rage. Every time user is damaged, Attack stat will increase by 1 stage. Rage will use 1 PP, but not use any PP thereafter.*/
	Move[100].setup(100, "Teleport", PSYCHIC, 0, 0, Flee, 0, 20);                   /*Teleport can be used to flee wild Pok�mon battles. In Trainer battles, Teleport always fails. Teleport will also fail if the user is under the effect of a partially trapping Move such as Wrap or Whirlpool.*/
	Move[101].setup(101, "Night Shade", GHOST, 0, 100, Special, 0, 15);             /*Night Shade inflicts damage equal to the user's level. Although Night Shade deals Ghost-type damage, its type does not alter the amount of damage it inflicts.*/
	Move[102].setup(102, "Mimic", NORMAL, 0, 100, Special, 0, 10);                  /*Mimic allows the user to select one of the target's Moves to copy, as well as the Move's maximum PP. The user will retain the copied attack in Mimic's place until it faints or is switched out, or the battle ends. Mimic can't copy Struggle.*/
	Move[103].setup(103, "Screech", NORMAL, 0, 85, Stat, 0, 40);                    /*Screech decreases the target's Defense stat by two stat levels.*/
	Move[104].setup(104, "Double Team", NORMAL, 0, 0, Stat, 0, 15);                 /*Double Team increases the user's evasion by one stage.*/
	Move[105].setup(105, "Recover", NORMAL, 0, 0, Recover, 0, 20);                  /*Restores 50% of Max HP*/
	Move[106].setup(106, "Harden", NORMAL, 0, 0, Stat, 0, 30);                      /*Harden increases the user's Defense stat by one stage.*/
	Move[107].setup(107, "Minimize", NORMAL, 0, 0, Stat, 0, 20);                    /*Minimize raises the user's evasion stat by one stage.*/
	Move[108].setup(108, "Smoke Screen", NORMAL, 0, 100, Stat, 0, 20);              /*SmokeScreen lowers the target's accuracy stat by one stage.*/
	Move[109].setup(109, "Confuse Ray", GHOST, 0, 100, Status, 0, 10);              /*Confuse Ray causes the target to become confused. Confuse Ray will fail if the target has a substitute, is already confused, or has the Ability Own Tempo. Although it is a ghost type Move, it will work on Normal types, disregarding immunity.*/
	Move[110].setup(110, "Withdraw", WATER, 0, 0, Stat, 0, 40);                     /*Withdraw increases the user's Defense by 1 stage.*/
	Move[111].setup(111, "Defense Curl", NORMAL, 0, 0, Stat, 0, 40);                /*Defense Curl increases the user's Defense by 1 stage.*/
	Move[112].setup(112, "Barrier", PSYCHIC, 0, 0, Stat, 0, 30);                    /*Barrier increases the user's Defense by two stages.*/
	Move[113].setup(113, "Light Screen", PSYCHIC, 0, 0, Stat, 0, 30);               /*Light Screen doubles the user's Special when the opponent damages the user with a special Move.*/
	Move[114].setup(114, "Haze", ICE, 0, 0, Special, 0, 30);                        /*Resets battle, except HP. This means all stat mods, leech seed, toxic, etc are negated.*/
	Move[115].setup(115, "Reflect", PSYCHIC, 0, 0, Stat, 0, 20);                    /*Reflect doubles the user's Defense when the opponent damages the user with a physical Move.*/
	Move[116].setup(116, "Focus Energy", NORMAL, 0, 0, Special, 0, 30);             /*Quadruples Crit Hit Ratio*/
	Move[117].setup(117, "Bide", NORMAL, 0, 100, Special, 0, 10);                   /*Stores damage dealt for 2-3 turns, and returns the favour with twice as much damage*/
	Move[118].setup(118, "Metronome", NORMAL, 0, 0, Special, 0, 10);                /*Metronome randomly selects a Move and fully executes the attack.*/
	Move[119].setup(119, "Mirror Move", FLYING, 0, 0, Special, 0, 20);              /*Mirror Move causes the user to use the last Move that the target used. WATCH OUT FOR MIRRORCEPTION!*/
	Move[120].setup(120, "Selfdestruct", NORMAL, 260, 100, SelfDestruct, 0, 5);     /*Selfdestruct inflicts damage, and causes the user to faint.*/
	Move[121].setup(121, "Egg Bomb", NORMAL, 100, 75, Regular, 0, 10);
	Move[122].setup(122, "Lick", GHOST, 20, 100, RegularStatus, 0, 30);             /*30% chance of paralyzing the target.*/
	Move[123].setup(123, "Smog", POISON, 20, 70, RegularStatus, 0, 20);             /*40% chance of poisoning the target.*/
	Move[124].setup(124, "Sludge", POISON, 65, 100, RegularStatus, 0, 20);          /*30% chance of poisoning the target.*/
	Move[125].setup(125, "Bone Club", GROUND, 65, 85, RegularStatus, 0, 20);        /*10% chance of causing the target to flinch. Bone Club cannot cause a target with a substitute to flinch.*/
	Move[126].setup(126, "Fire Blast", FIRE, 120, 85, RegularStatus, 0, 5);         /*30% chance of burning the target.*/
	Move[127].setup(127, "Waterfall", WATER, 80, 100, Regular, 0, 15);
	Move[128].setup(128, "Clamp", WATER, 35, 75, MultipleTurns, 0, 10);             /*Clamp inflicts damage for 2-5 turns and has an Accuracy of 75. Refer to previous Moves.*/
	Move[129].setup(129, "Swift", NORMAL, 60, 100, Regular, 0, 20);
	Move[130].setup(130, "Skull Bash", NORMAL, 100, 100, Charge, 0, 15);            /*Skull Bash does nothing on the turn it is selected, other than say that the user lowered its head. On the following turn, Skull Bash will do damage, PP will be deducted from it.*/
	Move[131].setup(131, "Spike Cannon", NORMAL, 20, 100, MultipleHits, 0, 15);     /*Spike Cannon inflicts damage, hitting 2-5 times per use. Refer to previous Moves*/
	Move[132].setup(132, "Constrict", NORMAL, 10, 100, RegularStat, 0, 35);         /*10% chance of lowering the target's Speed stat by one stat level.*/
	Move[133].setup(133, "Amnesia", PSYCHIC, 0, 0, Stat, 0, 20);                    /*Amnesia increases the user's Special by two stages.*/
	Move[134].setup(134, "Kinesis", PSYCHIC, 0, 80, Stat, 0, 15);                   /*Kinesis decreases the target's accuracy stat by one stage.*/
	Move[135].setup(135, "Softboiled", NORMAL, 0, 0, Recover, 0, 10);               /*Softboiled restores up to 50% of the user's current HP.*/
		Move[135].setup2(50);
	Move[136].setup(136, "Hi Jump Kick", FIGHTING, 85, 90, Special, 0, 20);         /*If it misses, the user takes crash damage of half the damage it would have dealt if it had hit.*/
	//SPECIAL SETUP
	Move[137].setup(137, "Glare", NORMAL, 0, 75, Status, 0, 30);                    /*Paralyzes the target*/
		Move[137].setup2(Paralysis);
	Move[138].setup(138, "Dream Eater", PSYCHIC, 100, 100, Special, 0, 15);         /*Dream Eater only works if the target is asleep. Dream Eater inflicts damage and 50% of the damage dealt is restored to the user as HP.*/
	//SPECIAL SETUP
	Move[139].setup(139, "Poison Gas", POISON, 0, 55, Status, 0, 40);               /*Poisons the opponent*/
		Move[139].setup2(Poison);
	Move[140].setup(140, "Barrage", NORMAL, 15, 85, MultipleHits, 0, 20);           /*Barrage inflicts damage, hitting 2-5 times per use. (Yeah, again)*/
		Move[140].setup2(2,5);
	Move[141].setup(141, "Leech Life", BUG, 20, 100, Drain, 0, 15);                 /*Leech Life inflicts damage, and up to 50% of the damage dealt to the target is restored to the user as HP.*/
		Move[141].setup2(50);
	Move[142].setup(142, "Lovely Kiss", NORMAL, 0, 75, Status, 0, 10);              /*Causes the target to fall asleep*/
		Move[142].setup2(Asleep);
	Move[143].setup(143, "Sky Attack", FLYING, 140, 90, Charge, 0, 5);              /*Sky Attack does nothing on the turn it is selected, other than say that the user is glowing. On the following turn, Sky Attack will deal damage, PP will be deducted from it.*/
	Move[144].setup(144, "Transform", NORMAL, 0, 0, Special, 0, 10);                /*Transform changes the user's current type, current stats, current stat modifications, current Moves, current species, and current cry to that of the target's.*/
	//SPECIAL SETUP
	Move[145].setup(145, "Bubble", WATER, 20, 100, RegularStat, 0, 30);             /*10% chance of lowering the target's Speed stat by one stage.*/
		Move[145].setup2(Speed,10,2);
	Move[146].setup(146, "Dizzy Punch", NORMAL, 70, 100, Regular, 0, 10);
	Move[147].setup(147, "Spore", GRASS, 0, 100, Status, 0, 15);                    /*Puts the target to sleep*/
		Move[147].setup2(Asleep);
	Move[148].setup(148, "Flash", NORMAL, 0, 70, Stat, 0, 20);                      /*Flash decreases the target's accuracy stat by one stage.*/
		Move[148].setup2(Accuracy,2);
	Move[149].setup(149, "Psywave", PSYCHIC, 0, 80, Special, 0, 15);                /*Psywave inflicts a random amount of damage, varying between 0.5� and 1.5� the user's level. The damage can be calculated using the following formula, where X is a randomly generated number between 0 and 10: (X + 5) � (User's level / 10)*/
	//SPECIAL SETUP
	Move[150].setup(150, "Splash", NORMAL, 0, 0, Regular, 0, 40);                   /*Splash has no effect whatsoever.*/
	Move[151].setup(151, "Acid Armor", POISON, 0, 0, Stat, 0, 40);                  /*Increases the user's Defense by two stages.*/
		Move[151].setup2(Defense, 1);
	Move[152].setup(152, "Crabhammer", WATER, 90, 85, Regular, 1, 10);
	Move[153].setup(153, "Explosion", NORMAL, 340, 100, SelfDestruct, 0, 5);        /*Explosion does damage, and causes the user to faint.*/
	Move[154].setup(154, "Fury Swipes", NORMAL, 18, 80, MultipleHits, 0, 15);       /*Fury Swipes inflicts damage, hitting 2-5 times per use.*/
		Move[154].setup2(2,5);
	Move[155].setup(155, "Bonemerang", GROUND, 50, 90, MultipleHits, 0, 10);        /*Bonemerang inflicts damage, striking twice per use.*/
		Move[155].setup2(2,2);
	Move[156].setup(156, "Rest", PSYCHIC, 0, 0, Special, 0, 10);                    /*Rest causes the user to fall asleep, restoring its HP to its maximum amount. The user will then be asleep for three turns, and wake up on the third turn.*/
	//SPECIAL SETUP
	Move[157].setup(157, "Rock Slide", ROCK, 75, 90, Regular, 0, 10);
	Move[158].setup(158, "Hyper Fang", NORMAL, 80, 90, RegularStatus, 0, 15);       /*10% chance of causing the target to flinch.*/
		Move[158].setup2(Flinch, 10);
	Move[159].setup(159, "Sharpen", NORMAL, 0, 0, Stat, 0, 30);                     /*Sharpen increases the user's Attack stat by one stage.*/
		Move[159].setup2(Attack, 1);
	Move[160].setup(160, "Conversion", NORMAL, 0, 0, Special, 0, 30);               /*Conversion changes the user's current type(s) to the target's current type(s).*/
	Move[161].setup(161, "Tri Attack", NORMAL, 80, 100, Regular, 0, 10);
	Move[162].setup(162, "Super Fang", NORMAL, 0, 90, Special, 0, 10);              /*Super Fang does damage equal to 50% of the target's current HP. Although Super Fang does normal damage, its type does not alter the amount of damage it inflicts.*/
	Move[163].setup(163, "Slash", NORMAL, 70, 100, Regular, 1, 20);                 /*(For the next Move) Using 25% of its maximum HP, the user creates a substitute with 1 HP more than the amount of HP lost by the user. All attacks affect the sub.*/
	Move[164].setup(164, "Substitute", NORMAL, 0, 0, Special, 0, 10);               /*Struggle deals damage to the opponent and the user receives recoil damage. The user takes recoil damage equal to � of the damage the attack did to the opponent. Used when all attacks are out of PP.*/
	//SPECIAL SETUP
	Move[165].setup(165, "Struggle", NORMAL, 50, 100, Recoil, 0, 10);
		Move[165].setup2(50);
}

void initPokemon()
{
	basicpokemon[0].setup(0, "MISSINGNO", "000", FIRE, NUL, "Glitch", "0'0\"", "0 lbs.", Black, 0, 50, 50, Undiscovered, Undiscovered, 0, "This is a glitch Pokemon. REPORT THIS BUG!", None, 0, 0);
	basicpokemon[1].setup(1, "BULBASAUR", "001", GRASS, POISON, "Seed", "2'04\"", "15.2 lbs.", Green, 45, 87.5, 12.5, Monster, Grass, 0, "A strange seed was planted on its back at birth. The plant sprouts and grows with this Pok�mon.", LevelUp, 16, 2);
	basicpokemon[2].setup(2, "IVYSAUR", "002", GRASS, POISON, "Seed", "3'03\?", "28.7 lbs.", Green, 45, 87.5, 12.5, Monster, Grass, 0, "When the bulb on its back grows large, it appears to lose the ability to stand on its hind legs.", LevelUp, 32, 3);
	basicpokemon[3].setup(3, "VENUSAUR", "003", GRASS, POISON, "Seed", "6'07\"", "220.5 lbs.", Green, 45, 87.5, 12.5, Monster, Grass, 0, "The plant blooms when it is asorbing solar energy. It stays on the move to seek sunlight.", None, 0, 0);
	basicpokemon[4].setup(4, "CHARMANDER", "004", FIRE, NUL, "Lizard", "2'00\"", "18.7 lbs.", Red, 45, 87.5, 12.5, Monster, Dragon, 0, "Obviously prefers hot places. When it rains, steam is said to spout from the tip of its tail.", LevelUp, 16, 5);
	basicpokemon[5].setup(5, "CHARMELEON", "005", FIRE, NUL, "Flame", "3'07\"", "41.9 lbs.", Red, 45, 87.5, 12.5, Monster, Dragon, 0, "When it swings its burning tail, it elevates the temperature to unbearably high levels.", LevelUp, 36, 6);
	basicpokemon[6].setup(6, "CHARIZARD", "006", FIRE, FLYING, "Flame", "5'07\"", "199.5 lbs.", Red, 45, 87.5, 12.5, Monster, Dragon, 0, "It spits fire that is hot enough to melt boulders. Known to cause forest fires unintentionally.", None, 0, 0);
	basicpokemon[7].setup(7, "SQUIRTLE", "007", WATER, NUL, "Tiny Turtle", "1'08\"", "19.8 lbs.", Blue, 45, 87.5, 12.5, Monster, Water1, 0, "After birth, its back swells and hardens into a shell. Powerfully sprays foam from its mouth.", LevelUp, 16, 8);
	basicpokemon[8].setup(8, "WARTORTLE", "008", WATER, NUL, "Turtle", "3'03\"", "49.6 lbs.", Blue, 45, 87.5, 12.5, Monster, Water1, 0, "Often hides in water to stalk unwary prey. For swimming fast, it moves its ears to maintain balance.", LevelUp, 36, 9);
	basicpokemon[9].setup(9, "BLASTOISE", "009", WATER, NUL, "Shellfish", "5'03\"", "188.5 lbs.", Blue, 45, 87.5, 12.5, Monster, Water1, 0, "A brutal Pok�mon with pressurized water jets on its shell. They are used for high speed tackles.", None, 0, 0);
	basicpokemon[10].setup(10, "CATERPIE", "010", BUG, NUL, "Worm", "1'00\"", "6.4 lbs.", Green, 255, 50, 50, Bug, Undiscovered, 0, "Its short feet are tipped with suction pads that enable it to tirelessly climb slopes and walls.", LevelUp, 7, 11);
	basicpokemon[11].setup(11, "METAPOD", "011", BUG, NUL, "Cocoon", "2'04\"", "21.8 lbs.", Green, 120, 50, 50, Bug, Undiscovered, 0, "This Pok�mon is vulnerable to attack while its shell is soft, exposing its weak and tender body.", LevelUp, 10, 12);
	basicpokemon[12].setup(12, "BUTTERFREE", "012", BUG, FLYING, "Butterfly", "3'07\"", "70.5 lbs.", White, 45, 50, 50, Bug, Undiscovered, 0, "In battle, it flaps its wings at high speed, releasing highly toxic dust into the air.", None, 0, 0);
	basicpokemon[13].setup(13, "WEEDLE", "013", BUG, POISON, "Hairy Bug", "1'00\"", "7.1 lbs.", Brown, 255, 50, 50, Bug, Undiscovered, 0, "Often found in forests, eating leaves. It has a sharp, venomous stinger on its head.", LevelUp, 7, 14);
	basicpokemon[14].setup(14, "KAKUNA", "014", BUG, POISON, "Cocoon", "2'00\"", "22.0 lbs.", Yellow, 120, 50, 50, Bug, Undiscovered, 0, "Almost incapable of moving, this Pok�mon can only harden its shell to protect itself from predators.", LevelUp, 10, 15);
	basicpokemon[15].setup(15, "BEEDRILL", "015", BUG, POISON, "Poison Bee", "3'03\"", "65.0 lbs.", Yellow, 45, 50, 50, Bug, Undiscovered, 0, "Flies at high speed and attacks using its large venomous stingers on its forelegs and tail.", None, 0, 0);
	basicpokemon[16].setup(16, "PIDGEY", "016", NORMAL, FLYING, "Tiny Bird", "1'00\"", "4.0 lbs.", Brown, 255, 50, 50, Flying, Undiscovered, 0, "A common sight in forests and woods. It flaps its wings at ground level to kick up blinding sand. A common sight in forests and woods. It flaps its wings at ground level to kick up blinding sand.", LevelUp, 18, 17);
	basicpokemon[17].setup(17, "PIDGEOTTO", "017", NORMAL, FLYING, "Bird", "3'07\"", "66.1 lbs.", Brown, 120, 50, 50, Flying, Undiscovered, 0, "Very protective of its sprawling territory, this Pok�mon will fiercely peck at any intruder.", LevelUp, 36, 18);
	basicpokemon[18].setup(18, "PIDGEOT", "018", NORMAL, FLYING, "Bird", "4'11\"", "87.1 lbs.", Brown, 45, 50, 50, Flying, Undiscovered, 0, "When hunting, it skims the surface of water at high speed to pick off unwary prey such as Magikarp.", None, 0, 0);
	basicpokemon[19].setup(19, "RATTATA", "019", NORMAL, NUL, "Mouse", "1'00\"", "7.7 lbs.", Purple, 255, 50, 50, Field, Undiscovered, 0, "Bites anything when it attacks. Small and very quick, it is a common sight in many places.", LevelUp, 20, 20);
	basicpokemon[20].setup(20, "RATICATE", "020", NORMAL, NUL, "Mouse", "2'04\"", "40.8 lbs.", Brown, 127, 50, 50, Field, Undiscovered, 0, "It uses its whiskers to maintain its balance and will slow down if they are cut off.", None, 0, 0);
	basicpokemon[21].setup(21, "SPEAROW", "021", NORMAL, FLYING, "Tiny Bird", "1'00\"", "4.4 lbs.", Brown, 255, 50, 50, Flying, Undiscovered, 0, "Eats bugs in grassy areas. It has to flap its short wings at high speed to stay airborne.", LevelUp, 20, 22);
	basicpokemon[22].setup(22, "FEAROW", "022", NORMAL, FLYING, "Beak", "3'11\"", "83.8 lbs.", Brown, 90, 50, 50, Flying, Undiscovered, 0, "With its huge and magnificent wings, it can keep aloft without ever having to land for rest.", None, 0, 0);
	basicpokemon[23].setup(23, "EKANS", "023", POISON, NUL, "Snake", "6'07\"", "15.2 lbs.", Purple, 255, 50, 50, Field, Dragon, 0, "Moves silently and stealthily. Eats the eggs of birds, such as Pidgey and Spearow, whole.", LevelUp, 22, 24);
	basicpokemon[24].setup(24, "ARBOK", "024", POISON, NUL, "Cobra", "11'06\"", "143.3 lbs.", Purple, 90, 50, 50, Field, Dragon, 0, "It is rumored that the ferocious warning markings on its belly differ from area to area.", None, 0, 0);
	basicpokemon[25].setup(25, "PIKACHU", "025", ELECTRIC, NUL, "Mouse", "1'04\"", "13.2 lbs.", Yellow, 190, 50, 50, Field, Fairy, 0, "When several of these Pok�mon gather, their electricity could build and cause lightning storms.", Stone, ThunderStone, 26);
	basicpokemon[26].setup(26, "RAICHU", "026", ELECTRIC, NUL, "Mouse", "2'07\"", "66.1 lbs.", Yellow, 75, 50, 50, Field, Fairy, 0, "Its long tail serves as a ground to protect itself from its own high voltage power. Its long tail serves as a ground to protect itself from its own high voltage power.", None, 0, 0);
	basicpokemon[27].setup(27, "SANDSHREW", "027", GROUND, NUL, "Mouse", "2'00\"", "26.5 lbs.", Yellow, 255, 50, 50, Field, Undiscovered, 0, "Burrows deep underground in arid locations far from water. It only emerges to hunt for food.", LevelUp, 22, 28);
	basicpokemon[28].setup(28, "SANDSLASH", "028", GROUND, NUL, "Mouse", "3'03\"", "65.0 lbs.", Yellow, 90, 50, 50, Field, Undiscovered, 0, "Curls up into a spiny ball when threatened. It can roll while curled up to attack or escape.", None, 0, 0);
	basicpokemon[29].setup(29, "NIDORAN F", "029", POISON, NUL, "Poison Pin", "1'04\"", "15.4 lbs.", Blue, 235, 0, 100, Monster, Field, 0, "Although small, its venomous barbs render this Pok�mon dangerous. The female has smaller horns.", LevelUp, 16, 30);
	basicpokemon[30].setup(30, "NIDORINA", "030", POISON, NUL, "Poison Pin", "2'07\"", "44.1 lbs.", Blue, 120, 0, 100, Undiscovered, Undiscovered, 0, "The female's horn develops slowly. Prefers physical attacks such as clawing and biting.", Stone, MoonStone, 31);
	basicpokemon[31].setup(31, "NIDOQUEEN", "031", POISON, GROUND, "Drill", "4'03\"", "132.3 lbs.", Blue, 45, 0, 100, Undiscovered, Undiscovered, 0, "Its hard scales provide strong protection. It uses its hefty bulk to execute powerful moves.", None, 0, 0);
	basicpokemon[32].setup(32, "NIDORAN M", "032", POISON, NUL, "Poison Pin", "1'08\"", "19.8 lbs.", Purple, 235, 100, 0, Monster, Field, 0, "Stiffens its ears to sense danger. The larger its horns, the more powerful its secreted venom.", LevelUp, 16, 33);
	basicpokemon[33].setup(33, "NIDORINO", "033", POISON, NUL, "Poison Pin", "2'11\"", "43.0 lbs.", Purple, 120, 100, 0, Monster, Field, 0, "An aggressive Pok�mon that is quick to attack. The horn on its head secretes a powerful venom.", Stone, MoonStone, 34);
	basicpokemon[34].setup(34, "NIDOKING", "034", POISON, GROUND, "Drill", "4'07\"", "136.7 lbs.", Purple, 45, 100, 0, Monster, Field, 0, "It uses its powerful tail in battle to smash, constrict, then break the prey's bones.", None, 0, 0);


	basicpokemon[1].setup2(0,33);
	basicpokemon[1].setup2(1,45);
	basicpokemon[1].setup2(7,73);
	basicpokemon[1].setup2(13,22);
	basicpokemon[1].setup2(20,77);
	basicpokemon[1].setup2(27,75);
	basicpokemon[1].setup2(34,74);
	basicpokemon[1].setup2(41,79);
	basicpokemon[1].setup2(48,76);


	basicpokemon[2].setup2(0,33);
	basicpokemon[2].setup2(1,45);
	basicpokemon[2].setup2(2,73);
	basicpokemon[2].setup2(9,22);
	basicpokemon[2].setup2(22,77);
	basicpokemon[2].setup2(30,75);
	basicpokemon[2].setup2(38,74);
	basicpokemon[2].setup2(46,79);
	basicpokemon[2].setup2(54,76);

	basicpokemon[3].setup2(0,33);
	basicpokemon[3].setup2(1,45);
	basicpokemon[3].setup2(2,73);
	basicpokemon[3].setup2(3,22);
	basicpokemon[3].setup2(22,77);
	basicpokemon[3].setup2(30,75);
	basicpokemon[3].setup2(43,74);
	basicpokemon[3].setup2(55,79);
	basicpokemon[3].setup2(65,76);

	basicpokemon[4].setup2(0,10);
	basicpokemon[4].setup2(1,45);
	basicpokemon[4].setup2(9,52);
	basicpokemon[4].setup2(15,43);
	basicpokemon[4].setup2(22,99);
	basicpokemon[4].setup2(30,163);
	basicpokemon[4].setup2(38,53);
	basicpokemon[4].setup2(46,83);

	basicpokemon[5].setup2(0,33);
	basicpokemon[5].setup2(1,45);
	basicpokemon[5].setup2(2,52);
	basicpokemon[5].setup2(15,43);
	basicpokemon[5].setup2(24,99);
	basicpokemon[5].setup2(33,163);
	basicpokemon[5].setup2(42,53);
	basicpokemon[5].setup2(56,83);


	basicpokemon[6].setup2(0,33);
	basicpokemon[6].setup2(1,45);
	basicpokemon[6].setup2(2,52);
	basicpokemon[6].setup2(3,43);
	basicpokemon[6].setup2(24,99);
	basicpokemon[6].setup2(36,163);
	basicpokemon[6].setup2(46,53);
	basicpokemon[6].setup2(55,83);

	basicpokemon[7].setup2(0,33);
	basicpokemon[7].setup2(1,39);
	basicpokemon[7].setup2(8,145);
	basicpokemon[7].setup2(15,55);
	basicpokemon[7].setup2(22,44);
	basicpokemon[7].setup2(28,110);
	basicpokemon[7].setup2(35,130);
	basicpokemon[7].setup2(42,56);

	basicpokemon[8].setup2(0,33);
	basicpokemon[8].setup2(1,39);
	basicpokemon[8].setup2(2,145);
	basicpokemon[8].setup2(15,55);
	basicpokemon[8].setup2(24,44);
	basicpokemon[8].setup2(31,110);
	basicpokemon[8].setup2(39,130);
	basicpokemon[8].setup2(47,56);

	basicpokemon[9].setup2(0,33);
	basicpokemon[9].setup2(1,39);
	basicpokemon[9].setup2(2,145);
	basicpokemon[9].setup2(3,55);
	basicpokemon[9].setup2(24,44);
	basicpokemon[9].setup2(31,110);
	basicpokemon[9].setup2(42,130);
	basicpokemon[9].setup2(52,56);

	basicpokemon[10].setup2(0,33);
	basicpokemon[10].setup2(1,81);

	basicpokemon[11].setup2(0,106);
	basicpokemon[12].setup2 (12,93);
	basicpokemon[12].setup2 (28,16);
	basicpokemon[12].setup2 (15,77);
	basicpokemon[12].setup2 (32,60);
	basicpokemon[12].setup2 (17,79);
	basicpokemon[12].setup2 (16,78);
	basicpokemon[12].setup2 (21,48);
	basicpokemon[12].setup2 (26,18);

	basicpokemon[13].setup2 (0,40);
	basicpokemon[13].setup2 (1,81);

	basicpokemon[14].setup2 (0,106);

	basicpokemon[15].setup2 (0,31);
	basicpokemon[15].setup2 (16,116);
	basicpokemon[15].setup2 (20,41);
	basicpokemon[15].setup2 (25,99);
	basicpokemon[15].setup2 (30,42);
	basicpokemon[15].setup2 (35,97);

	basicpokemon[16].setup2 (0,16);
	basicpokemon[16].setup2 (5,28);
	basicpokemon[16].setup2 (12,98);
	basicpokemon[16].setup2 (19,18);
	basicpokemon[16].setup2 (28,17);
	basicpokemon[16].setup2 (36,97);
	basicpokemon[16].setup2 (44,119);

	basicpokemon[17].setup2 (0,16);
	basicpokemon[17].setup2 (1,28);
	basicpokemon[17].setup2 (12,98);
	basicpokemon[17].setup2 (21,18);
	basicpokemon[17].setup2 (31,17);
	basicpokemon[17].setup2 (40,97);
	basicpokemon[17].setup2 (49,119);

	basicpokemon[18].setup2 (0,16);
	basicpokemon[18].setup2 (1,28);
	basicpokemon[18].setup2 (2,98);
	basicpokemon[18].setup2 (21,18);
	basicpokemon[18].setup2 (31,17);
	basicpokemon[18].setup2 (44,97);
	basicpokemon[18].setup2 (54,119);

	basicpokemon[19].setup2 (0,33);
	basicpokemon[19].setup2 (1,39);
	basicpokemon[19].setup2 (7,98);
	basicpokemon[19].setup2 (14,158);
	basicpokemon[19].setup2 (23,116);
	basicpokemon[19].setup2 (34,162);

	basicpokemon[20].setup2 (0,33);
	basicpokemon[20].setup2 (1,39);
	basicpokemon[20].setup2 (2,98);
	basicpokemon[20].setup2 (14,158);
	basicpokemon[20].setup2 (27,116);
	basicpokemon[20].setup2 (41,162);

	basicpokemon[21].setup2 (0,64);
	basicpokemon[21].setup2 (1,45);
	basicpokemon[21].setup2 (9,43);
	basicpokemon[21].setup2 (15,31);
	basicpokemon[21].setup2 (22,119);
	basicpokemon[21].setup2 (29,65);
	basicpokemon[21].setup2 (36,97);

	basicpokemon[22].setup2 (0,64);
	basicpokemon[22].setup2 (1,45);
	basicpokemon[22].setup2 (2,43);
	basicpokemon[22].setup2 (15,31);
	basicpokemon[22].setup2 (25,119);
	basicpokemon[22].setup2 (34,65);
	basicpokemon[22].setup2 (43,97);

	basicpokemon[23].setup2 (0,35);
	basicpokemon[23].setup2 (1,43);
	basicpokemon[23].setup2 (10,40);
	basicpokemon[23].setup2 (17,44);
	basicpokemon[23].setup2 (24,137);
	basicpokemon[23].setup2 (31,103);
	basicpokemon[23].setup2 (38,51);

	basicpokemon[24].setup2 (0,35);
	basicpokemon[24].setup2 (1,43);
	basicpokemon[24].setup2 (2,40);
	basicpokemon[24].setup2 (17,44);
	basicpokemon[24].setup2 (27,137);
	basicpokemon[24].setup2 (36,103);
	basicpokemon[24].setup2 (47,51);

	basicpokemon[25].setup2 (0,84);
	basicpokemon[25].setup2 (1,45);
	basicpokemon[25].setup2 (9,86);
	basicpokemon[25].setup2 (16,98);
	basicpokemon[25].setup2 (26,129);
	basicpokemon[25].setup2 (33,97);
	basicpokemon[25].setup2 (43,87);

	basicpokemon[26].setup2 (0,84);
	basicpokemon[26].setup2 (1,45);
	basicpokemon[26].setup2 (2,86);

	basicpokemon[27].setup2 (0,10);
	basicpokemon[27].setup2 (10,28);
	basicpokemon[27].setup2 (17,163);
	basicpokemon[27].setup2 (24,40);
	basicpokemon[27].setup2 (31,129);
	basicpokemon[27].setup2 (38,154);

	basicpokemon[28].setup2 (0,10);
	basicpokemon[28].setup2 (1,28);
	basicpokemon[28].setup2 (17,163);
	basicpokemon[28].setup2 (27,40);
	basicpokemon[28].setup2 (36,129);
	basicpokemon[28].setup2 (47,154);

	basicpokemon[29].setup2 (0,45);
	basicpokemon[29].setup2 (1,33);
	basicpokemon[29].setup2 (8,10);
	basicpokemon[29].setup2 (14,40);
	basicpokemon[29].setup2 (21,39);
	basicpokemon[29].setup2 (29,44);
	basicpokemon[29].setup2 (36,154);
	basicpokemon[29].setup2 (43,24);

	basicpokemon[30].setup2 (0,45);
	basicpokemon[30].setup2 (1,33);
	basicpokemon[30].setup2 (2,10);
	basicpokemon[30].setup2 (14,40);
	basicpokemon[30].setup2 (23,39);
	basicpokemon[30].setup2 (32,44);
	basicpokemon[30].setup2 (41,154);
	basicpokemon[30].setup2 (50,24);

	basicpokemon[31].setup2 (0,33);
	basicpokemon[31].setup2 (1,10);
	basicpokemon[31].setup2 (2,39);
	basicpokemon[31].setup2 (3,34);
	basicpokemon[31].setup2 (14,40);

	basicpokemon[32].setup2 (0,43);
	basicpokemon[32].setup2 (1,33);
	basicpokemon[32].setup2 (8,30);
	basicpokemon[32].setup2 (14,40);
	basicpokemon[32].setup2 (21,116);
	basicpokemon[32].setup2 (29,31);
	basicpokemon[32].setup2 (36,32);
	basicpokemon[32].setup2 (43,24);

	basicpokemon[33].setup2 (0,43);
	basicpokemon[33].setup2 (1,33);
	basicpokemon[33].setup2 (2,30);
	basicpokemon[33].setup2 (14,40);
	basicpokemon[33].setup2 (23,116);
	basicpokemon[33].setup2 (32,31);
	basicpokemon[33].setup2 (41,32);
	basicpokemon[33].setup2 (50,24);

	basicpokemon[34].setup2 (0,33);
	basicpokemon[34].setup2 (1,30);
	basicpokemon[34].setup2 (2,40);
	basicpokemon[34].setup2 (3,37);


	basicpokemon[1].setup3 (45,49,49,65,65,45);
	basicpokemon[2].setup3 (60,62,62,80,80,60);
	basicpokemon[3].setup3 (80,82,83,100,100,80);
	basicpokemon[4].setup3 (39,52,43,60,50,65);
	basicpokemon[5].setup3 (58,64,58,80,65,80);
	basicpokemon[6].setup3 (78,84,78,109,85,100);
	basicpokemon[7].setup3 (44,48,65,50,64,43);
	basicpokemon[8].setup3 (59,63,80,65,80,58);
	basicpokemon[9].setup3 (73,83,100,85,105,78);
	basicpokemon[10].setup3 (45,30,35,20,20,45);
	basicpokemon[11].setup3 (50,20,55,25,25,30);
	basicpokemon[12].setup3 (60,45,50,80,80,70);
	basicpokemon[13].setup3 (40,35,50,20,20,50);
	basicpokemon[14].setup3 (45,25,50,25,25,35);
	basicpokemon[15].setup3 (65,80,40,45,80,75);
	basicpokemon[16].setup3 (40,45,40,35,35,56);
	basicpokemon[17].setup3 (63,60,55,50,50,71);
	basicpokemon[18].setup3 (83,80,75,70,70,91);
	basicpokemon[19].setup3 (30,56,35,25,35,72);
	basicpokemon[20].setup3 (55,81,60,50,70,97);
	basicpokemon[21].setup3 (40,60,30,31,31,70);
	basicpokemon[22].setup3 (65,90,65,61,61,100);
	basicpokemon[23].setup3 (35,60,44,40,54,55);
	basicpokemon[24].setup3 (60,85,69,65,79,80);
	basicpokemon[25].setup3 (35,55,30,50,40,90);
	basicpokemon[26].setup3 (60,90,55,90,80,100);
	basicpokemon[27].setup3 (50,75,85,20,30,40);
	basicpokemon[28].setup3 (75,100,110,45,55,65);
	basicpokemon[29].setup3 (55,47,52,40,40,41);
	basicpokemon[30].setup3 (70,62,67,55,55,56);
	basicpokemon[31].setup3 (90,82,87,75,85,76);
	basicpokemon[32].setup3 (46,57,40,40,40,50);
	basicpokemon[33].setup3 (61,72,57,55,55,65);
	basicpokemon[34].setup3 (81,92,77,85,75,85);
}

int main()
{}
