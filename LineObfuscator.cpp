#include"LineObfuscator.h"

/*  Line obfuscator create a variable with random name and insert it in a random place and initialize it with a random sum of two random numbers and insert the initialize in a random place in the code
    Finaly, take the obfuscated code (array of strings) and convert it to a new file.
*/
void
LineObfuscator::obfuscate (string fileName)
{
  string *toObfuscate = parseFile (fileName);
  int count = 0;
  string main = "main";
  int mainLine = 0;
  for (int i = 0; toObfuscate[i] != "endArr"; i++)
    {
      count++;
      int found = toObfuscate[i].find (main);
      if (found != string::npos)
	mainLine = i;
    }

  int randomLine = rand () % (count - 2);
  while (randomLine < mainLine + 1)
    {
      randomLine = rand () % (count - 2);
      if (randomLine > 1)
	{
	  int forFound = toObfuscate[randomLine - 1].find ("for");
	  if (forFound != string::npos)
	    randomLine = mainLine;
	}
    }
  string randomVar = generateRandomVar ();
  toObfuscate[mainLine + 1] += "\nint " + randomVar + ";";
  toObfuscate[randomLine] +=
    "\n" + randomVar + " = " + to_string ((rand () % 1000)) + " + " +
    to_string ((rand () % 1000)) + ";";
  writeToFile (toObfuscate);
};

