//implementation for bartender class
#include<iostream>
#include<fstream>
#include "bartender.h"

using namespace std;

drink:: drink()
{
};

drink::drink(string name, string ingredients, string description, string directions, string glass)
{
  this->name = name;
  this->ingredients= ingredients;
  this->description = description;
  this->directions = directions;
  glassType = glass;
};

void drink:: printDrink()
{
  cout<< "_____"<< name << "_____"  << endl 
      << "--Glass Type: " << glassType << endl 
      << "--Details: " << description << endl 
      << "--What you need: " << ingredients << endl 
      << "--Mixing Instructions: " << directions << endl << endl;
  return;
}

Bartender:: Bartender()
{
  return;
};

void Bartender:: print()
{
  for(int i = 0; i < drinks.size(); i++)
    {
      drinks[i].printDrink();
    }
}

void Bartender:: init()
{
  ifstream myfile;
  myfile.open("mixes.txt");
  string name,ingredients,description,directions,glass;
  if(myfile.is_open())
    {
      //cout<< "file open" << endl;
      while(!myfile.eof())
	{
	  getline(myfile,name);
	  if(name[0]!= '/' && name[0] != '\0')
	    {
	      getline(myfile,ingredients);
	      getline(myfile,description);
	      getline(myfile,glass);
	      getline(myfile,directions);
	      //entry gathered input into drink class
	      drink temp (name, ingredients, description, 
			  directions, glass);
	      drinks.push_back(temp);

	    }

	}
      //cout<< "reached end of file" << endl;
    }  
};
