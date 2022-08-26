#include "tic_tac_toe_v2.h"

int main()
{
    int PlayerNo;
    printf("RULES FOR TIC-TAC-TOE\n");
    printf("1. The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("2. Players take turns putting their marks in empty squares.\n");
    printf("3. The first player to get 3 of thier marks in a row (up, down, across, or diagonally) is the winner.\n");
    printf("4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n");
    
    printf("Enter number of players\n");
    scanf("%d",&PlayerNo);
    switch(PlayerNo)
    {
        case 1:
            printf("Player vs Computer\n");
            printf("You are player 1 and the computer is player 2\n");
            sleep(2);
            single_player();
            break;

        case 2:
            printf("Player vs Player\n");
            sleep(1);
            double_player();
            break;

        default:
            printf("Invalid number of players\n");
            break;
    }
    board_status();
    result();
    return 0;
    
}
