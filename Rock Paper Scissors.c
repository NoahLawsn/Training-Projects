#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//Game Logic
int game(char choice, char cpu)
{
    // Tie
    if (choice == cpu)
    {
        return -1;
    }

    // Win
    else if ((choice == 'r' && cpu == 's') || (choice == 'p' && cpu == 'r') || (choice == 's' && cpu == 'p'))
    {
        return 1;
    }

    // Loss
    else
    {
        return 0;
    }
}


int main()
{
    // Inits
    int rnum;
    char choice, cpu, answer;

    // Welcome Banner
    system("cls");
    printf("----------------------------------------------------------------------------------\n");
    printf("\t\t\tWelcome to Rock Paper Scissors!\n");

    // Random CPU Selection
    srand(time(NULL));
    rnum = rand() % 100; // Makes random number less than 100
    if (rnum < 33)
    {
        cpu = 'r';
    }
    else if (rnum > 33 && rnum < 67)
    {
        cpu = 'p';
    }
    else
    {
        cpu = 's';
    }

    // Selection of (r || p || s)
    printf("\t\tRock = r\tPaper = p\tScissors = s\t\n");
    printf("----------------------------------------------------------------------------------\n");
    printf("\t\t\t    What's your choice? :\n\t\t\t    >> ");
    scanf("%c", &choice);
    printf("**********************************************************************************\n\n\t\t\t    ");

    // Display of Win/Loss
    answer = game(choice, cpu);
    if (answer == 1)
    {
        printf("Congrats! You won!");
    }
    else if (answer == -1)
    {
        printf("Draw!");
    }
    else
    {
        printf("Sorry, you lost...");
    }

    // Results
    printf("\n\n\t\t\t   You: %c\tComputer: %c", choice, cpu);
    Sleep(5000);
    return 0;
}