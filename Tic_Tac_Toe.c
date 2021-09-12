#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <time.h>

void print_board(char board[3][3]); // Printing the board as 3x3 Grid
void play(char number, char board[3][3], char player); // board moification
bool is_digit(int number); //Input 1 -> 9
bool validate_input(int number, char board[3][3]); // Input validation
int remain_number(char board[3][3]); // Give the remaining number of Cell's Available
char *remain_char(char board[3][3], int counter); // Give the remaining Cell's Available
bool check_winner(char board[3][3]); //check if someone winning
bool winner(char score1[3], char score2[3]); //Printing the winner

int main(int argc, char *argv[])
{
    //Board Creation
    char board[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            board[i][x] = (char) ((i * 3) + x) + 49;
        }
    }

    //Starting Statment
    printf("It's A Tic Tac Toe Game, Type Cell number to put your O in & I'll will play with X\n");
    printf("Note: I'm so stupid beacuse my creator didn't learn AI yet :'(\n");
    print_board(board);

    int counter = 1;
    char number;
    char player;
    char *Residual;
    bool check;

    do
    {
        if (counter%2 != 0)
        {
            do
            {
                number = get_char("\nPick a number:");
                check = validate_input((int) number, board);
                player = 'O';
            }
            while (!check);
        }

        else
        {
            srand(time(NULL));
            int no = remain_number(board);
            Residual = remain_char(board, no);
            number = Residual[(rand() % no)];
            printf("I pick: %c\n", number);
            player = 'X';
        }
        counter++;
        play(number, board, player);
        print_board(board);
    }
    while (check_winner(board));

    return 0;
}



void print_board(char board[3][3])
{
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            printf("| %c ", board[i][x]);
        }
        printf("|\n-------------\n");
    }
    return;
}

bool is_digit(int number) //1 -> 9
{
    if (number < 49 || number > 57)
    {
        return false;
    }

    return true;
}

bool validate_input(int number, char board[3][3])
{
    if (is_digit(number))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int x = 0; x < 3; x++)
            {
                if (board[i][x] == (char) number)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

void play(char number, char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (board[i][x] == number)
            {
                board[i][x] = player;
                break;
            }
        }
    }
    return;
}

int remain_number(char board[3][3])
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            if ((int) board[i][x] >= 49 && (int) board[i][x] <= 57)
            {
                counter++;
            }
        }
    }
    return counter;
}

char *remain_char(char board[3][3], int counter)
{
    char s[counter];
    int c = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            if ((int) board[i][x] >= 49 && (int) board[i][x] <= 57)
            {
                s[(i * 3) + x - c] = board[i][x];
            }
            else
            {
                c++;
            }
        }
    }

    char *t = s;

    return t;
}

bool check_winner(char board[3][3])
{
    char score_v[3];
    char score_h[3];
    char diagnol_x[3];
    char diagnol_y[3];

    for (int i = 0; i < 3; i++)
    {
        for (int x = 0; x < 3; x++)
        {
            //Assigning Vertical & Horizontal values
            score_v[x] = board[i][x];
            score_h[x] = board[x][i];
        }

        //check Vertical & Horizontal
        if (winner(score_v, score_h))
        {
            return false;
        }

        //Assigning Diagnol values
        diagnol_x[i] = board[i][i];
        diagnol_y[i] = board[i][2 - i];
    }

    //check Diagnol
    if (winner(diagnol_x, diagnol_y))
    {
        return false;
    }

    if (remain_number(board) == 0)
    {
        printf("Draw\n");
    }

    return true;
}

bool winner(char score1[3], char score2[3])
{
    if ((score1[0] == 'O' && score1[1] == 'O' && score1[2] == 'O') ||
        (score2[0] == 'O' && score2[1] == 'O' && score2[2] == 'O'))
    {
        printf("you win\n");
        return true;
    }
    else if ((score1[0] == 'X' && score1[1] == 'X' && score1[2] == 'X') ||
            (score2[0] == 'X' && score2[1] == 'X' && score2[2] == 'X'))
    {
        printf("PC Win\n");
        return true;
    }

    return false;
}