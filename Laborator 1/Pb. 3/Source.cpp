#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    char s[100],sir[100],m[100][100];
    char* p;
    int n,k,i,j;
   
    scanf("%[^\n]%*c", s);

    p = strtok(s," ");

    k = 0;
    while (p)
    {
        k++;
        strcpy(m[k], p);
        p = strtok(NULL, " ");
    }

    n = k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strlen(m[i]) < strlen(m[j]))
            {
                strcpy(sir, m[i]);
                strcpy(m[i], m[j]);
                strcpy(m[j], sir);
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%s\n", m[i]);

    return 0;
}