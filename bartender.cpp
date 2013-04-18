//implementation for bartender class
#include<iostream>
#include<fstream>
#include "bartender.h"

using namespace std;

drink:: drink()
{
};

drink::drink(string name, string ingredients, string directions, string glass)
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
  string line,name,ingredients,description,directions,glass;
  int beg, end, comm1, comm2, brac;
  beg = 2;
  end = 0;
  brac = 0;
   if(myfile.is_open())
    {
      int j = 0;


      //
      //file input limited to 13 drinks for basic testing purposes


      while(!myfile.eof() && j < 13)
	{
	  getline(myfile,line);
	  comm1 = 0;
	  comm2 = 0;
	  brac = 0;
	  end = line.size();
	  if(line[0] != '/' && line[0] != '\0')
	    {
	      // parse line for information
	      for(int i = 0; i < line.size();i++)
		{
		  if(line[i] == ',' && comm1 == 0) // find first comma
		    {
		      comm1 = i;
		    }
		  else if(line[i] == ',' && comm2 == 0) // find second comma
		    {
		      comm2 = i;
		    }
		  else if(line[i] == ']' && brac == 0) // find end of ingredients
		    {
		      brac = i;
		    }
		  else	      
		    {}
		}
	      // break string based on markers
	      name = line.substr( beg, (comm1-beg)-1);
	      glass = line.substr((comm1+3), (comm2-comm1)-4);
	      ingredients = line.substr((comm2+4),(brac - comm2)-5);
	      directions = line.substr((brac + 4), (end - brac)-6 );
	      drink temp (name, ingredients, directions, glass);
	      drinks.push_back(temp);

	      j++;
	    }
	  else
	    {}
	}
     cout<< "reached end of file" << endl;
    }  
};
