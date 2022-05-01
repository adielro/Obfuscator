#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H
#include <string>


using namespace std;
class Obfuscator
{
public:
 virtual void obfuscate (string fileName) = 0;
  const std::string OUT = "newCode.c";
  string generateRandomVar ();
  string *parseFile (string filename);
  void writeToFile (string * codeArray);
private:
  char randomChar (bool invalidPlace);
};

#endif
