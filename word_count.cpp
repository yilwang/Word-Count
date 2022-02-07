/***********************************************************************
* Program:
*    Project Word Count          
*
* Summary: 
*    This program will count the number of the words from the file and 
*    display the number of the words from the file.
*
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*******************************************
 * This function displays the results.
 ******************************************/
void display(int count, string filename)
{
   if (count == 0)
   {
      cout << "The file " << filename << " has no words.\n";
   } 
   else if ( count == 1)
   {
      cout << "There is 1 word in " << filename << ".\n";
   }
   else    
   {   
      cout << "There are " << count << " words in " << filename << ".\n";
   }
}


/************************************************
 * This function reads the file input from the user 
 * and counts the number of lines in a file.
 ***********************************************/
int countLines(string filename)
{
   // open the file
   ifstream fin(filename.c_str());

   // check if fails to read
   if (fin.fail())
      cout << "Error Reading!";

   // read the file and count the words
   string word;
   int count = -1;
   while (!fin.eof())
   {
      fin >> word;
      count++;
   }
   // close the file
   fin.close();
   
   return count;
}

/**************************************************
 * This function prompts the user for the filename.
 **************************************************/
string getFilename()
{
   string filename;
   cout << "Please enter the filename: ";
   cin  >> filename;
   return filename;
}

/**********************************************************************
 * This function main is where the computer starts to read.
 ***********************************************************************/
int main(int argc, char ** argv)
{
   string filename;
   if (argc == 2)
      filename = argv[1];
   else
      filename = getFilename();
   
   int count = countLines(filename);

   display(count, filename);
   
   return 0;
}
