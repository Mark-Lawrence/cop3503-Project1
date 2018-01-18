//
//  Header.h
//  Assignment_1
//
//  Created by Mark Lawrence on 9/24/17.
//  Copyright © 2017 Mark Lawrence. All rights reserved.
//

#ifndef Header_h
#define Header_h

int** createMagicSquare(int** magicSquare, int arraySize);
void printSquare(int** magicSquare, int arraySize, int numberTimePrinted);
void checkMath(int** magicSquare, int arraySize);

int arraySize;
bool validInput = false;
int **magicSquare = new int*[arraySize];
int altRow = 0;
int altCol = 0;
int calculation = 0;



#endif /* Header_h */
