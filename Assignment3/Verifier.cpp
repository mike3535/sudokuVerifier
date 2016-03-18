
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Verifier.h"

using std::ios;
using std::ifstream;
using std::endl;
using std::cout;
using std::setw;

/****************************************************************
 
 FUNCTION:   Verifier()
 
 ARGUMENTS:  N/A
 
 RETURNS:    N/A
 
 NOTES:      constructor that set all of the elements of the 
                grid array to 0.
 ****************************************************************/

Verifier::Verifier()
{
    for (int i = 0; i < 9; ++i)  //if row is less than 9 add one to row
    {
        for (int j = 0; j < 9; ++j)  //if column is less than 9 add one to column
            
            grid[i][j]= {0};
    }
}

/****************************************************************
 
 FUNCTION:   void readGrid(const char* filename)
 
 ARGUMENTS:  cont char* filename - a constant character that points
                                    to a file name
 
 RETURNS:    void
 
 NOTES:      read the contents of the input file into the
                elements of the grid array.
 ****************************************************************/


void Verifier::readGrid(const char* filename)
{
    
    ifstream inFile;   // Declare an input file stream variable
    
    inFile.open((filename),ios::in);  // Open the file stream
    
    
    if (inFile.is_open())     //check if file opened succesfully
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            
                inFile>>grid[i][j];      //put numbers in file into grid
            
        }
        
    }
    else
        
        cout<<"error opening file"<<endl;
    
    inFile.close(); //close file stream
    
}

/****************************************************************
 
 FUNCTION:   printGrid()
 
 ARGUMENTS:  N/a
 
 RETURNS:   void
 
 NOTES:       print the Sudoku grid array to the screen as 9 rows
                of 9 columns
 ****************************************************************/

void Verifier::printGrid()
{
    
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            
            cout << grid[i][j] << ' ';
        }
        cout <<endl;
    }
}

   


/****************************************************************
 
 FUNCTION:   verifySolution()
 
 ARGUMENTS:  N/A
 
 RETURNS:    boolean value stating weather the solution is verified
 
 NOTES:      checks if the sodoku grid array is a valid solution
 ****************************************************************/

bool Verifier::verifySolution()
{

    
    char temp;       //temperary storage to match row, column, and box with
    int dup = 0;  //counter to check for duplicates
    
    /* verify columns*/
    for ( int row = 0 ; row < 9 ; row++)   //loop through row
    {
        for ( int col = 0 ; col < 9 ; col++)  //loop through every column for each row
        {
            dup = 0;           //set count to zero
            temp = grid[row][col];  //set temp to equal each row
            
            
                for ( int k = 0 ; k < 9 ; k++ )     //loop through column to compare
                {
                    if (grid[row][k] == temp)      //check for duplicate numbers in each row
                        dup++;
                }
            
            if (dup >= 2)    //if a number is repeated
            {
        
                
                return false;  //return false
                
    
            }
        }
    }
    
    
    /* verify rows*/
    
    for ( int col = 0 ; col < 9 ; col++)     //loop through numbers in column
    {
        for ( int row = 0 ; row < 9 ; row++)   //loop through numbers in row for each column
        {
            dup = 0;               //set count equal to 0
            temp = grid[row][col];  //set temp to equal each column
            
            for ( int k = 0 ; k < 9 ; k++ ) //loop through row to compare
            {
                    if (grid[k][col] == temp)  //check for duplicate numbers in each column
                        dup++;
                
            }
            if (dup >= 2)  //if number is repeated
            
                return false;  //return false
            
        }
    }
    
     /*verify box*/
    
    
    for (int i = 0; i < 9; i++)  //loop through each box
    {
      
        
        for (int j = 0; j < 3; j++) //loop through fist three elements in row
        {
            
            for (int k = 0; k < 3; k++)  // loop through first three elements column
            {
                dup = 0;    //set count equal to zero
                temp = grid[ j + (i % 3) * 3 ] [ k + (i % 3) * 3 ]; // make each box by looping through first three elements in each row and first three elements in that rows column, divide by three and times by three to get to next box
                
                    for (int m = 0; m < 3; m++) // loop through first three elements in row to compare
                {
                    
                    for (int n = 0; n < 3; n++) // loop through first three elements in column for the rows
                    {
                        
                        if ( grid[ m + (i % 3) * 3 ][ n + (i % 3) * 3 ] == temp) //loop through box to compare
                            dup++;
                        
                        if (dup >= 2)  // if number in box is repeated
                            
                            return false;  //return false
                        
                    }
                    
                }
            
            }
            
        }
    }

    return true;
}





