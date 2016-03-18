/****************************************************************
 FILE:      Verifier.h
 AUTHOR:    Michael Rizza
 LOGON ID:  Z1035469
 DUE DATE:  2-27-15
 
 PURPOSE:   header file holds the class Verifier
 ****************************************************************/

#ifndef Assignment3_Verifier_h
#define Assignment3_Verifier_h

#include <iostream>

class Verifier
{
public:
    
    Verifier();
    
    void readGrid(const char* filename);
    void printGrid();
    bool verifySolution();
    
private:
    
    int grid[9][9];  //holds the soduko grid
    
};


#endif
