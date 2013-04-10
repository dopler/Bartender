//header file for bartender class
#ifndef __BARTENDER_H__
#define __BARTENDER_H__

#include <string>
#include <vector>
#include<string>
//#include "bartender.cpp"
using namespace std;

class drink
{
 private:
  string name;
  string ingredients;
  //enum drinkType;
  string glassType;
  string description;
  string directions; // possible vector to indicate steps?
 public:
  drink();
  drink(string, string, string, string, string);
  void printDrink();
};


class Bartender
{
 private:
  vector<drink> drinks;
 public:
  Bartender(); 
  void init();
  void print();

  
};

#endif
