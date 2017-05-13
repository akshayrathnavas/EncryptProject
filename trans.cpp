#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

int z=0;

int fNoD(int sum)
{
    int i=0;
    while(sum!=0)
    {
        sum/=10;
        ++i;
    }
    return i;
}

char* trans(char K[], int L, int sum)
{
    const int D=fNoD(sum);
    char temp;
    int i=0, j=0;
    int S[D];

    for(i=D-1;i>=0;--i)
    {
        S[i]=sum%10;
        sum/=10;
    }

    i=0;
    j=0;
    while(L)
    {
        j=S[i%D]-1;
        temp=K[i];
        K[i]=K[j];
        K[j]=temp;
        ++i;
        --L;
    }
    dispCC(K,9);
}
/*

int main()
{

    char a[9];
     a[0]=93; a[1]=7; a[2]=91; a[3]=4; a[4]=24; a[5]=116; a[6]=91; a[7]=23; a[8]=93;

    dispCC(a,9);
    trans(a,9,3437);
    getch();

}
*/
