#include "compressing.h"
#include <stdlib.h>
#include<stdio.h>


unsigned char* compressBoard(unsigned char board[][SIZE]){
    unsigned char* strBoard = (unsigned char*)malloc(sizeof(unsigned char) * SIZE * SIZE / 4);
    unsigned char i, j;
    for(i = 0, j = 0; i < SIZE * SIZE; i+=1, j+=2){
        if(board[i/SIZE][i%SIZE] == ' '){//EMPTY
            //RESET_BIT(strBoard, j);
            //RESET_BIT(strBoard, (j + 1));            
        }else if(board[i/SIZE][i%SIZE] == 'o'){//BOAT
            SET_BIT(strBoard, j);
            //RESET_BIT(strBoard, (j + 1));                    
        }else if(board[i/SIZE][i%SIZE] == 'x'){//MISS
            //RESET_BIT(strBoard, j);
            SET_BIT(strBoard, (j + 1));           
        }else if(board[i/SIZE][i%SIZE] == '+'){//SINK
            SET_BIT(strBoard, j);
            SET_BIT(strBoard, (j + 1));                
        }
    }

    return strBoard;
}

unsigned char** decompressBoard(unsigned char *strBoard){
    unsigned char **board = (unsigned char**)malloc(sizeof(unsigned char) * SIZE);
    unsigned char i, j;
    for(i = 0; i < SIZE; i++){
        board[i] = (unsigned char*)malloc(sizeof(unsigned char) * SIZE);
    }

    for(i = 0, j = 0; i < SIZE * SIZE; i+=1, j+=2){
        unsigned char field = READ_BIT(strBoard, (j + 1));  // Read the value at position j + 1
        field <<= 1;  // Shift the rightmost bit one position to the left
        field |= READ_BIT(strBoard, (j));  // Perform a bitwise OR with the previous bit

        if(field == EMPTY){
            board[i/SIZE][i%SIZE] = ' ';
        }else if(field == BOAT){
            board[i/SIZE][i%SIZE] = 'o';
        }else if(field == MISS){
            board[i/SIZE][i%SIZE] = 'x';
        }else if(field == SINK){
            board[i/SIZE][i%SIZE] = '+';
        }
    }

    return board;
}