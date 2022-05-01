#ifndef VAROBFUSCATOR_H
#define VAROBFUSCATOR_H
#include "Obfuscator.h"

class VarObfuscator:public Obfuscator
{
private:
  void ReplaceString (string & str, string search, string replace);
public:
  void obfuscate (string fileName);
};

#endif
