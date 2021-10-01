#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printSquare(int arr[][3]);
bool magicSquareTest(int arr[][3]);
int getRowTotal(int arr[][3], int rowNumber);
int getColumnTotal(int arr[][3], int columnNumber);
int getDiagonalLRTotal(int arr[][3]);
int getDiagonalRLTotal(int arr[][3]);


int main() {
int magicSquare[3][3] = {  //magic square
    {2,7,6},
    {9,5,1},
    {4,3,8}
};

int NOTMagicSquare[3][3] = {  //not a magic square
    {6,4,5},
    {1,3,7},
    {8,9.2}
};

time_t t;  

magicSquareTest(magicSquare);   //testing the two magic squares 
printSquare(magicSquare);  
magicSquareTest(NOTMagicSquare);
printSquare(NOTMagicSquare);

int test[3][3];
int randomNumsAdded = 0;   //variable that tracks the amt of numbers in a newly generated square
int squaresGenerated = 0;

char answer[3];
printf("\nStart the random search for a magic square? (enter y or n): ");
scanf("%s", answer);
if (strcmp(answer, "y") == 0) {

    srand((unsigned) time(&t));
    do {
        int test[3][3]= {
            {0,0,0},
            {0,0,0},  //initialize square
            {0,0,0}
        };
        int nums[9] = {0,0,0,0,0,0,0,0,0};  //initialize array of numbers added to square to avoid duplicates
        int check = 0;
        while (randomNumsAdded != 9) {
            check = 0;
            int randomNumber= rand() % 9;
            randomNumber++;  //random number b/w 1-9
            for (int i = 0; i < 9; i++) {
                if (randomNumber == nums[i]) {  //if randomNumber is already added to square (duplicate), don't add it 
                    break; //find a new random number that's not a duplicate
                }
                if (nums[i] == 0) {  //add random number to square 
                    nums[randomNumsAdded] = randomNumber;
                    randomNumsAdded++;
                    break; // find a new random number
                }
            }
        }
        int counter = 0;
        for (int i = 0; i < 3; i++) {     //convert 1D array to 2D 3x3 square array
            for (int j = 0; j < 3; j++) {
                test[i][j] = nums[counter];
                counter++;
            }
        }
        randomNumsAdded=0;  //reset the amt of numbers added to square in case the current square is not a magic square
        squaresGenerated++;
        printf("\nTotal squares generated: %d", squaresGenerated);
        
        printSquare(test);
        printf("^\n");   // "^" to symbolize an arrow that points to a square
    } while (magicSquareTest(test) == 0);   //loop until find magic square
}



}

void printSquare(int arr[][3]) {
    printf("\n[%d %d %d]", arr[0][0], arr[0][1], arr[0][2]);
    printf("\n[%d %d %d]", arr[1][0], arr[1][1], arr[1][2]);
    printf("\n[%d %d %d]\n", arr[2][0], arr[2][1], arr[2][2]);
}

bool magicSquareTest(int arr[][3]) {
    for (int i = 0; i < 3; i++) { 
        if (getRowTotal(arr, i) != 15 || getColumnTotal(arr,i) != 15)  {
            printf("This square is NOT a magic square");
            return false; //prints 0 if false
        }
        if (getDiagonalRLTotal(arr) != 15 || getDiagonalLRTotal(arr) != 15) {
            printf("This square is NOT a magic square");
            return false;  //prints 0 if false
        }
    }
    printf("This square IS a magic square");
    return true;  //prints 1 if true
} 

int getRowTotal(int arr[][3], int rowNumber) {
    int rowTotal = 0;
    for (int i = 0; i < 3; i++) {
        rowTotal += arr[rowNumber][i];
    }
    return rowTotal;
} 

int getColumnTotal(int arr[][3], int columnNumber) {  
    int columnTotal = 0;
    for (int i = 0; i < 3; i++) {
        columnTotal += arr[i][columnNumber];
    }
    return columnTotal;
} 

int getDiagonalLRTotal(int arr[][3]) {  //top left to bottom right total
    int diagonalLRTotal = 0;
    for (int i = 0; i < 3; i++) {
        diagonalLRTotal += arr[i][i];
    }
    return diagonalLRTotal;
}

int getDiagonalRLTotal(int arr[][3]) { //top right to bottom left total
    int diagonalRLTotal = 0;
    for (int i = 0; i < 3; i++) {
        diagonalRLTotal += arr[i][2-i];
    }
    return diagonalRLTotal;
    
}