#include"Obfuscator.h"
#include<iostream>
#include <fstream>
#include <time.h>
using namespace std;


// Private function receive a boolean in order to know if the char is first or last char of the string, and return a random valid variable char.
char
Obfuscator::randomChar (bool invalidPlace)
{
  int randInt = rand ();
  if (invalidPlace == true)
    {
      char randChar = (randInt % 26) + 97;
      return randChar;
    }
  if ((randInt % 6) <= 2 && (randInt % 6) >= 0)
    {
      return (char) (randInt % 26) + 97;
    }
  if ((randInt % 6) <= 4 && (randInt % 6) >= 3)
    {
      char randChar = (randInt % 10) + 48;
      return randChar;
      if (randInt % 6 == 5)
	return '_';
    }
  return '_';
}

// Function generate a random variable name (using private function randomChar) and return it as a string.
string
Obfuscator::generateRandomVar ()
{
  char randChar;
  int randNum = (rand () % 10) + 1;
  string randomVar = "";
  bool invalidPlace = true;
  for (int i = 0; i < randNum; i++)
    {
      randomVar += randomChar (invalidPlace);
      invalidPlace = false;
      if (i == randNum - 2)
	invalidPlace = true;
    }
  return randomVar;
}


// Function receive a file name as a String, if the file cannot be open, exit(1), else -> reading each line and inserting it into array of string, finaly return the array.
string *
Obfuscator::parseFile (string filename)
{
  ifstream indata;
  indata.open (filename);
  if (!indata)
    {
      cout << "Cannot open file!" << endl;
      exit (1);
    }
  int length = 0;
  string line;
  while (getline (indata, line))
    {
      length++;
    }
  string *strArr = new string[length + 1];
  int i = 0;
  indata.clear ();
  indata.seekg (0);
  while (getline (indata, line))
    {
      strArr[i] = line;
      i++;
    }
  strArr[length] = "endArr";
  indata.close ();
  return strArr;
}
// Function receive a pointer to strings array and writing each string in a different line into a new file
void
Obfuscator::writeToFile (string * codeArray)
{
  ofstream outdata;
  outdata.open (OUT);
  int length = 0;
  for (int i = 0; codeArray[i] != "endArr"; i++)
    length++;
  for (int i = 0; i < length; i++)
    {
      outdata << codeArray[i] << endl;
    }
  outdata.close ();
  delete[] codeArray;
}

