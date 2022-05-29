#include <stdio.h>

int main()
{
    char crd;
    printf("Enter the letter of your card:\n>> ");
    scanf("%c", &crd);

    switch(crd)
    {
        case 'A':
            puts("Value is 12");
            break;
        case 'K':
            puts("Value is 11");
            break;
        case 'Q':
            puts("Value is 10");
            break;
        default:
            puts("Value unknown...\n");
            break;
    }
}
