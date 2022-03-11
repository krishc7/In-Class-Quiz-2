#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// function prototypes
void showResult(int[][3]); 
void printArray(int[][3]); 
bool isMagicSquare(int[][3]);
bool checkSquare(int[][3]);

int main() {
    srand(time(NULL));
    
    int magicArray[3][3] = { { 8, 1, 6 },
                            { 3, 5, 7 },
                            { 4, 9, 2 } };

    int normalArray[3][3] = {{ 5, 2, 3 },
                            { 4, 9, 6 },
                            { 7, 1, 11 } };

    // this array will be populated with random numbers
    int randArray[3][3];
    int randNumber;
    // this array will be used to check previous values generated for the square
    int check[9];
    int squareCount = 0;

    printArray(normalArray);
    showResult(normalArray);

    printArray(magicArray);
    showResult(magicArray);

    do {
        memset(check, 0, sizeof(check));

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++ ){
                randNumber = rand () % 9 + 1; 
                if(check[randNumber - 1] == 0){ // if random number hasn't been used before
                    check[randNumber - 1] = 1;
                    randArray[i][j] = randNumber;
                }
                else {
                    j--; // go back one column if random number already used
                }
             }   
        }
        squareCount++; 
    } while (!checkSquare(randArray)); // Generate squares until a magic square is created
    printArray(randArray);

    printf("Number of squares generated before success: %d\n",squareCount--);
    
    return 0;
}

void showResult(int values[][3]) {

    // Check if square is a magic square and give output accordingly
    if (checkSquare(values)) {
        printf("This is a Lo Shu magic square.\n\n");
    }
    else {
        printf("This is not a Lo Shu magic square.\n\n");
    }

}

void printArray(int values[][3]) {

    // Increment through all the values in the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //Display values in row.
            printf("  %d", values[i][j]);
        }
        printf("\n");
    }
}

bool checkSquare(int values[][3]) {

    // check if all numbers in square fall between 1 and 9
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (values[i][j] < 1 || values[i][j] > 9) {
                return false;
            }
        }
    }

     // sum of top left to bottom right diag
    int diagSumOne = 0;
    for(int j = 0; j < 3; j++) {
        diagSumOne += values[j][j];
    }

    // sum of bottom left to top right diag
    int diagSumTwo = 0;
    int j = 3 - 1;
    for(int i = 0; i < 3; i++, j--) {
        diagSumTwo += values[j][i];
    }
    bool diagSum = (diagSumOne == diagSumTwo);

    bool colSum = true;

    // sum of first column
    int firstColumnSum = 0;
    for(int j = 0; j < 3; j++) {
        firstColumnSum += values[j][0];
    }
    // compare first column to remaining two columns
    for(int i = 1; i < 3; i++) {
        int columnSum = 0;
        for(int j = 0; j < 3; j++) {
            columnSum += values[j][i];
        }
        if(columnSum != firstColumnSum)
            colSum = false;
    }

    bool rowBool = true;

     // sum of first row
    int firstRowSum = 0;
    for(int j = 0; j < 3; j++) {
        firstRowSum += values[0][j];
    }
    // compare first row to remaining rows
    for(int i = 1; i < 3; i++) {
        int rowSum = 0;
        for(int j = 0; j < 3; j++) {
            rowSum += values[i][j];
        }
        if(rowSum != firstRowSum)
            rowBool = false;
    }
    return (diagSum && rowBool && colSum);
}