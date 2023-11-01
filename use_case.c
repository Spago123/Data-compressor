#include<stdio.h>
#include "compressing.h"
#include<stdlib.h>


void printBoard(unsigned char board[][SIZE]){
    unsigned char i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void printingBoard(unsigned char **board){
    unsigned char i, j;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }    
}

int main(){
    unsigned char board[SIZE][SIZE];
    unsigned char i, j;
    printf("Type in a board\n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            scanf("%c", &board[i][j]);
        }
    }
    printf("Board that you've typed in\n");
    printBoard(board);

    unsigned char* strBoard = compressBoard(board);
    printf("\nCompresssed board is:\n", strBoard);
    for(i = 0; i < SIZE*SIZE/4; i++){
        printf("0x%x ", strBoard[i]);
    }
    printf("\nUncompress board is:\n");
    unsigned char **decompress = decompressBoard(strBoard);
    printingBoard(decompress);
    free(strBoard);
    for(i = 0; i < SIZE; i++){
        free(decompress[i]);
    }
    free(decompress);
    return 0;
}