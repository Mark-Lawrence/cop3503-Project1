//
//  main.cpp
//  Assignment_1
//
//  Created by Mark Lawrence on 9/20/17.
//  Copyright © 2017 Mark Lawrence. All rights reserved.
//

#include <iostream>
#include "pa1.h"

int main(int argc, const char * argv[]) {
//    int arraySize;
//    bool validInput = false;
    
    //Checks for a valid input (size of the magic square) it needs to be an odd number from 3-15
    do {
        std::cout<<"Enter the size of a magic square: ";
        std::cin>>arraySize;
        if (arraySize%2 != 0){
            if (arraySize <= 15){
                if (arraySize != 1){
                    if (arraySize >0){
                        validInput = true;
                    }
                }
            }
        }
    } while (validInput == false);
    
    for (int i = 0; i != 5; i++) {
        std::cout<<"\nMagic Square #"<<i+1<<" is:\n";
        int **magicSquare = new int*[arraySize];
        magicSquare = createMagicSquare(magicSquare, arraySize);
        printSquare(magicSquare, arraySize, i+1);
        checkMath(magicSquare, arraySize);
        std::cout<<"\n";
    }
    
}

int** createMagicSquare(int** magicSquare, int arraySize){
    //Creates a 2D array the size that the user entered (It has previously been confirmed that this number is within
    //the scope of the project (odd 3-15 int)
    for (int i = 0; i!=arraySize; i++) {
        magicSquare[i] = new int [arraySize];
    }
    //Initiates the 2D array to make all ints 0
    for (int i = 0; i!=arraySize; i++) {
        for (int j = 0; j!=arraySize; j++) {
            magicSquare[i][j]=0;
        }
    }
    
    //Starts the row and column to be the top row of the center column
    int count = 1;
    int row = 0;
    int col = arraySize/2;
    
    //Loops through the for loop arraySize^2 to go through the loop for each number to add to the magic square
    for (int i = 0; i != arraySize*arraySize; i++) {
        //If the number in the next row and column is not 0 and is already taken by a different number
        if (magicSquare[row][col] != 0){
            
            //Instead of putting the next number up and to the right one, move it down one
            if (row +2 < arraySize){
                row= row+2;
            }
            //If the last number to be added was in the top left corner, put the next number one below it
            else{
                row = 1;
            }
            
            if (col -1 !=-1){
                col--;
            }
            else{
                col = arraySize-1;
            }
        }
        
        //Add the next number to the magic square in teh calculated row and column
        magicSquare[row][col] = count;
        //Set up the row and coloum for the next integer, move it up and right one.
        if (row - 1 != -1){
            row--;
        }
        //If it is the top row, rotate back to the bottom row
        else{
            row = arraySize-1;
        }
        
        if (col + 1 != arraySize){
            col++;
        }
        //If it is in the right column, rotate back to teh first column
        else{
            col =0;
        }
        count++;
    }
    
    return magicSquare;
}

void printSquare(int** magicSquare, int arraySize, int numberTimePrinted){
    int altRow = 0;
    int altCol = 0;
    
    //Loop through the array and print each int
    if (numberTimePrinted == 1){
        for (int i = 0; i != arraySize; i++) {
            for (int j=0; j!= arraySize; j++) {
                std::cout<<magicSquare[i][j]<<"\t";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    //Next 4 if statements reorder the way the integers are printed out to create four new magic squares
    if (numberTimePrinted == 2){
        for (int i = 0; i != arraySize; i++) {
            for (int j=0; j!= arraySize; j++) {
                std::cout<<magicSquare[j][i]<<"\t";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    
    if (numberTimePrinted == 3){
        for (int i = 0; i != arraySize; i++) {
            for (int j=0; j!= arraySize; j++) {
                altRow = arraySize-1 - i;
                std::cout<<magicSquare[altRow][j]<<"\t";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    
    if (numberTimePrinted == 4){
        for (int i = 0; i != arraySize; i++) {
            for (int j=0; j!= arraySize; j++) {
                altCol = arraySize-1 -j;
                std::cout<<magicSquare[i][altCol]<<"\t";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    
    if (numberTimePrinted == 5){
        for (int i = 0; i != arraySize; i++) {
            for (int j=0; j!= arraySize; j++) {
                altRow = arraySize-1 - i;
                altCol = arraySize-1 -j;
                std::cout<<magicSquare[altRow][altCol]<<"\t";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
}

void checkMath(int** magicSquare, int arraySize){
    //check rows
    std::cout<<"Checking the sums of every row:\t";
    
    int calculation = 0;
    for (int i = 0; i < arraySize; i++) {
        for (int j=0; j < arraySize; j++) {
            calculation += magicSquare[i][j];
        }
        std::cout<<calculation<<" ";
        calculation = 0;
    }
    
    //Check colums
    std::cout<<"\nChecking the sums of every column:\t";
    for (int i = 0; i < arraySize; i++) {
        for (int j=0; j < arraySize; j++) {
            calculation += magicSquare[j][i];
        }
        std::cout<<calculation<<" ";
        calculation = 0;
    }
    
    //Check diagonals
    std::cout<<"\nChecking the sums of every diagnoal:\t";
    for (int i = 0; i < arraySize; i++) {
        calculation += magicSquare[i][i];
    }
    std::cout<<calculation<<" ";
    calculation = 0;
    int j = 0;
    for (int i=arraySize-1; i != -1; i--) {
        calculation += magicSquare[i][j];
        j += 1;
    }
    std::cout<<calculation<<" ";
    calculation = 0;
    
}



