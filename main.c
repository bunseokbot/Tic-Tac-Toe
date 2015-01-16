/*
 * Tic-Tac-Toe 3x3 Game
 * Author : bunseokbot@bob
 * Contacts : admin@smishing.kr
 * Blog : http://blog.smishing.kr
 */

#include <stdio.h>
#
#include <stdlib.h>

char board[3][3] = {
    {'O','O','O'},
    {'O','O','O'},
    {'O','O','O'}
}; //Initial Gameboard

int USER = 0;
char USER_DOL = 'A';
int COMPUTER = 1;
char COMPUTER_DOL = 'B';

void gameboard() {
    int i, j;
    printf("\n");
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tictactoeIntro() {
    printf("Welcome to Tic-Tac-Toe 3x3 Game?!\n");
    printf("Bug report to bunseokbot@bob\n\n");
    gameboard();
}

int checkEnd() {
    int i, j, k;
    
    //Cross Checking
    //ARMCoding ----> 귀찮아
    if (board[0][0] == board[1][1] == board[2][2] == USER_DOL) {
        printf("[*] User Win!\n");
        return 1;
    }
    
    if (board[0][0] == board[1][1] == board[2][2] == COMPUTER_DOL) {
        printf("[*] Computer Win!\n");
        return 1;
    }
    
    if (board[2][0] == board[1][1] == board[0][2] == USER_DOL) {
        printf("[*] User Win!\n");
        return 1;
    }
    
    if (board[2][0] == board[1][1] == board[0][2] == COMPUTER_DOL) {
        printf("[*] Computer Win!\n");
        return 1;
    }
    
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] != COMPUTER_DOL) {
                break;
            }
            
            if (j == 2) {
                printf("[*] Computer Win!\n");
                return 1;
            }
            
        }
    }
    
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] != USER_DOL) {
                break;
            }
            
            if (j == 2) {
                printf("[*] User Win!\n");
                return 1;
            }
            
        }
    }
    
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[j][i] != COMPUTER_DOL) {
                break;
            }
            
            if (j == 2) {
                printf("[*] Computer Win!\n");
                return 1;
            }
            
        }
    }
    
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[j][i] != USER_DOL) {
                break;
            }
            
            if (j == 2) {
                printf("[*] User Win!\n");
                return 1;
            }
            
        }
    }

    return 0;
}

void GameStart() {
    int count;
    int user = 0;
    int end;
    for (count = 0; count<9; count++) {
        int x = 0, y = 0;
        if (user == 0) {
            //user try
RETRY:      printf("Input (x, y) location : ");
            scanf("%d %d", &x, &y);
            if (board[x][y] != 'O') {
                //relocation?
                printf("잘못된 위치입니다, 다시 설정해 주세요\n");
                goto RETRY;
            } else {
                board[x][y] = USER_DOL;
                gameboard();
                end = checkEnd();
                if (end == 1) {
                    exit(0);
                }
                user = 1;
            }
        } else {
            //computer try
COMPUTER_RETRY:
            x = rand() % 3;
            y = rand() % 3;
            if (board[x][y] != 'O') {
                goto COMPUTER_RETRY;
            } else {
                board[x][y] = COMPUTER_DOL;
                printf("Computer Selected [x] = %d [y] = %d\n", x, y);
                gameboard();
                end = checkEnd();
                if (end == 1) {
                    exit(0);
                }
                user = 0;
            }
        }
        
    }
}

int main(void) {
    tictactoeIntro();
    GameStart();
    return 0;
}