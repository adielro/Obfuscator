#include"VarObfuscator.h"

// Method replace between 2 strings 
void
VarObfuscator::ReplaceString (string & str, string search, string replace)
{
  int pos = str.find (search);
  if (pos != string::npos)
    {
      str.replace (pos, search.length (), replace);
    }
};


/* Var obfuscator receive a file name and converting it into an array of strings
 The obfuscator choose one random int and change it name to a random name and goes all over the code and change it in all the places it appear
 Finaly, take the obfuscated code (array of strings) and convert it to a new file.
 */
void
VarObfuscator::obfuscate (string fileName)
{
  string *toObfuscate = parseFile (fileName);
  string integers[100];
  int count = 0;
  for (int i = 0; toObfuscate[i] != "endArr"; i++)
    {
      int found = toObfuscate[i].find ("int ");
      int found2 = toObfuscate[i].find ("for");
      int found3 = toObfuscate[i].find ("main");
      if (found != string::npos && found2 == string::npos && found3 == string::npos)
	{
	  integers[count] =
	    toObfuscate[i].substr (toObfuscate[i].find ("int ") + 4,
				   toObfuscate[i].find (";") - 7);
	  int equalMark = integers[count].find("=");
	  if (equalMark != string::npos){
	      integers[count] = integers[count].substr (0, equalMark);
	  }
	  count++;
	}
    }
  int randomNum = rand () % count;
  string randomVar = integers[randomNum];
  string newRandomVar = generateRandomVar ();
  for (int i = 0; i < count; i++)
    {

      for (int i = 0; toObfuscate[i] != "endArr"; i++)
	ReplaceString (toObfuscate[i], randomVar, newRandomVar);
    }
  writeToFile (toObfuscate);
};
