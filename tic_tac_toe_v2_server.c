#include "tic_tac_toe_v2.h"
int Choice, Check, Flag;
int Player = 1;
int ChosenNo[9];
char Mark = 'X';
char Mark2 = 'O';
char Board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void blue()
{
    printf("\033[0;34m");
}

void green()
{
    printf("\033[0;32m");
}

void white()
{
    printf("\033[0;37m");
}
void yellow()
{
    printf("\033[0;33m");
}

void board_status()
{
    system("cls");
    printf("\033[0;35m");
    printf("------------TIC TAC TOE------------\n");
    green();
    printf("\nPlayer 1: 'X'");
    blue();
    printf(" Player 2: 'O'\n");
    white();
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", Board[1], Board[2], Board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", Board[4], Board[5], Board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", Board[7], Board[8], Board[9]);
    printf("     |     |     \n");
}

int check_win()
{
    for (int i = 1; i <= 3; i++)
    {
        
        if (Board[i] == Board[i + 3] && Board[i + 3] == Board[i + 6]) //Vertical win
            return 1;
    }
    for(int i=1;i<=7;i+=3)
    {
        if (Board[i] == Board[i + 1] && Board[i + 1] == Board[i + 2]) //Horizontal win
            return 1;
    }
    if (Board[1] == Board[5] && Board[5] == Board[9]) //Diagonal win
        return 1;

    else if (Board[3] == Board[5] && Board[5] == Board[7]) //Diagonal win
        return 1;

    else if (Board[1] != '1' && Board[2] != '2' && Board[3] != '3' && Board[4] != '4' && Board[5] != '5' && Board[6] != '6' 
             && Board[7] != '7' && Board[8] != '8' && Board[9] != '9')
        return 0;
    else
        return -1;
}

void single_player()
{
    do
    {
        Player = (Player % 2) ? 1 : 2;
        Flag = 1;
        board_status();
        if (Player == 1)
        {
            printf("Player 1, Enter position: \n");
            scanf("%d", &Choice);
            if (Choice < 1 || Choice > 9)
            {
                printf("Invalid Choice\n");
                sleep(2);
                Player--;
            }
            else
            {
                for (int i = 1; i <= 9; i++)
                {
                    if (Choice == i && Board[i] == i + '0') //Checking whether the chosen square is available
                    {
                        Board[i] = Mark;
                        Flag=0;
                    }
                }
                if(Flag!=0)
                {
                    printf("Invalid Choice\n");
                    sleep(1);
                    Player--;
                }
            }
        }
        else
        {
            while (Flag != 0)
            {

                srand(time(NULL));//Setting seed 

                Choice = 1 + (rand() % 9);
                for (int i = 1; i < 10; i++)
                {
                    if (Choice == i && Board[i] == i + '0')
                    {
                        Board[i] = Mark2;
                        Flag = 0;
                    }
                }
            }
        }
        Check = check_win();
        Player++;
    } while (Check == -1);
}

void double_player()
{
    do
    {
        Flag=1;
        board_status();
        Player = (Player % 2) ? 1 : 2;
        printf("Player %d, Enter position: \n", Player);
        scanf("%d", &Choice);
        Mark = (Player % 2) ? 'X' : 'O';
        if (Choice < 1 || Choice > 9)
        {
            printf("Invalid Choice\n");
            sleep(1);
            Player--;
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (Choice == i && Board[i] == i + '0')
                {
                    Board[i] = Mark;
                    Flag=0;
                }
            }
            if(Flag!=0)
            {
                printf("Invalid Choice\n");
                sleep(2);
                Player--;
            }
        }
        Check = check_win();
        Player++;
    } while (Check == -1);
}

void result()
{
    if (Check == 1)
    {
        if (--Player == 1)
        {
            green();
            printf("-------> Player 1 is THE WINNER <--------");
        }
        else
        {
            blue();
            printf("-------> Player 2 is THE WINNER <--------");
        }
    }
    else
    {
        yellow();
        printf("It's a draw!");
    }
    white();
}