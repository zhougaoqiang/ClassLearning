//tabtenn1.cpp -- cimple base-class methods

#include "pch.h"
#include "tabtenn1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) :
	firstname(fn), lastname(ln), hasTable(ht) {};   //new partten

void TableTennisPlayer::Name() const
{
	std::cout << lastname << ", " << firstname;
}

//RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht) :
	TableTennisPlayer(fn, ln, ht) 
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) :
	TableTennisPlayer(tp), rating(r)
{
}

void usett1() {
	using std::cout;
	using std::endl;

	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();       //derived object uses base methods
	if (rplayer1.HasTable())
		cout << ": has a table. \n";
	else
		cout << ": hasn't a table. \n";
	cout << "Name: ";

	player1.Name();    //base object uses base methods
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	cout << "Name: ";
	rplayer1.Name();
	cout << "; Rating: " << rplayer1.Rating() << endl;
	//initialize RatedPlayer using TableTennisPlayer object
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; Rating: " << rplayer2.Rating() << endl;
}