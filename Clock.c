#include <stdio.h>
#include <windows.h>



int main()
{
    int h,m,s;
    char half='P';
    int d=1000; // 1000 milliseconds to use in delay function
    printf("Set time : \n");
    scanf("%d%d%d", &h, &m,&s);

    if(h>12 || m>60 || s>60)
    {
        printf("Error! \n");
        exit(0);
    }
    while(1) // infinite loop
    {
        system("cls");
        s++;
        if(s>59)
        {
            m++;
            s=0;
        }
        if(m>59)
        {
            h++;
            m=0;
        }
        if (h==12 && m ==0 && s ==0)
        {
            if(half=='A')
            {
                half='P';
            }
            if(half=='P')
            {
                half = 'A';
            }
        }
        if (h>12)
        {
            h=1;
        }
        printf("+---------------------------------------------+\n");
        printf("|                   Clock :                   |\n");
        printf("|                 %02d:%02d:%02d %cM                 |\n",h,m,s,half); //formats time as 00:00:00
        printf("|                                             |\n");
        printf("+---------------------------------------------+");
        Sleep(d); //slows loop to one second

    }
}
