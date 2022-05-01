#include"CommentObfuscator.h"


/*  The obfuscator receive a file and convert it to a array of strings, then obfuscate the code by deleting all the comments in the file and adding random comments in random places in the fileName
    Finaly, take the obfuscated code (array of strings) and convert it to a new file.
*/
  void CommentObfuscator::obfuscate (string fileName)
  {
    int commentsAdded = 0;
    int mainLine = 0;
    string *toObfuscate = parseFile (fileName);
    string randomComments[5];
    randomComments[0] = "// This code will conquer the world.";
    randomComments[1] = "// Here, we have no clue how it worked.";
    randomComments[2] = "// Best code ever.";
    randomComments[3] = "// No way this is working.";
    randomComments[4] = "// // If true == false, the world we know has changed.";




    for (int i = 0; toObfuscate[i] != "endArr"; i++) {
        int found = toObfuscate[i].find("main");
        if (found != string::npos)
        mainLine = i;
    }

    for (int i = 0; toObfuscate[i] != "endArr"; i++)
      {
	int found = toObfuscate[i].find ("//");
	if (found != string::npos)
	    toObfuscate[i] = toObfuscate[i].substr (0, found);
      }


    while (commentsAdded == 0){
            int randCommentsAmout = (rand () % 10 )+ 1;
    for (int i = mainLine; i < randCommentsAmout; i++) {
        if ((rand() )% 3 == 0 && i > mainLine){
        toObfuscate[i] += randomComments[rand()%5];
            commentsAdded++;
        }
    }}

      writeToFile(toObfuscate);
  };
