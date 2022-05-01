/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include "Obfuscator.h"
#include "LineObfuscator.h"
#include "VarObfuscator.h"
#include "CommentObfuscator.h"
using namespace std;
int main()
{
srand (time(NULL));
     Obfuscator* obfs[3];
    obfs[0] = new VarObfuscator();
    obfs[1] = new LineObfuscator();
    obfs[2] = new CommentObfuscator();
    obfs[0]->obfuscate("Test.txt");
    for(int i = 1; i < 3; i++) 
	obfs[i]->obfuscate(obfs[i-1]->OUT);


    return 0;
}
