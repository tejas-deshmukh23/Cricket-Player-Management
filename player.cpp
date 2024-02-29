#include"player.h"
#include<string.h>
#include<iostream>
using namespace std;

//Constructor

Player::Player()
{
	this->jersyno=0;
	strcpy(this->name,"NA");
	this->runs=0;
	this->wickets=0;
	this->noofmatches=0;
}

Player::Player(int jersyNo,char* name,int runs,int wickets,int noOfMatches)
{
	this->jersyno=jersyNo;
	strcpy(this->name,name);
	this->runs=runs;
	this->wickets=wickets;
	this->noofmatches=noOfMatches;
}
	
//getters and setters

void Player::setJersyNo(int jersyNo)
{
	this->jersyno=jersyNo;
}
void Player::setName(char* name)
{
	strcpy(this->name,name);
}

void Player::setRuns(int runs)
{
	this->runs=runs;
}
void Player::setWickets(int wickets)
{
	this->wickets=wickets;
}
void Player::setNoOfMatches(int noOfMatches)
{
	this->noofmatches=noOfMatches;
}

//getters---->

int Player::getJersyNo()
{
	return this->jersyno;
}
char* Player::getName()
{
	return this->name;
}
int Player::getRuns()
{
	return this->runs;
}
int Player::getWickets()
{
	return this->wickets;
}
int Player::getNoOfMatches()
{
	return this->noofmatches;
}

//Functions

void Player:: display()
	{
		
		cout<<"-------------------------------------------------------------------------\n";
		cout<<this->getJersyNo()<<"\t|"<<this->getName()<<"\t|"<<this->getRuns()<<"\t|"<<this->getWickets()<<"\t|"<<this->getNoOfMatches()<<"\n";
	}
	
//search player



