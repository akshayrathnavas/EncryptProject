//#pragma ONCE
//#pragma SPARK_NO_PREPROCESSOR

#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include<time.h>
#include <cstdlib>
#include "decToBin.cpp"
#include "display.cpp"

using namespace std;

int rev(int n);
int exor(int x, int y)
{
    int res = 0; // Initialize Result

    // Assuming 8-bit Integer
    for (int i = 8; i >= 0; i--)
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
       cout<<b1<<"\t"<<b2<<endl;

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
        cout<<xoredBit<<endl;

        // Update Result
        res <<= 1;
        cout<<res<<endl;
        res |= xoredBit;
        cout<<res<<endl;

    }
    return res;
}


int findMod(char K[], int L)
{
    int sum0=0, sum=0, p=0;
    const int len=L;
    int S[L];
    int i=0, t=0;
    int a[L];
    int M;

     for(i=0;i<L;++i)
     {
        a[i]=K[i];
        sum0+=a[i]*(i+1);
     }


    p=0;

   srand( time(0));
   for(i=0;i<9;++i)
   {
	t=rand()%sum0+1;
	S[p++]=t;
	sum+=t;
   }
dispII(S,9);
    M=sum%L;
    return M;
}

int main()
{
    char ch[10]="ahc5i90w4";

    int a=findMod(ch,9);
    cout<<endl<<"MOD= "<<a<<endl;
     getch();

}
