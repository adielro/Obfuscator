#ifndef COMMENTOBFUSCATOR_H
#define COMMENTOBFUSCATOR_H
#include "Obfuscator.h"



class CommentObfuscator:public Obfuscator
{
public:
  void obfuscate (string fileName);
};


#endif