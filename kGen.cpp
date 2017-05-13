#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include <cstdlib>
#include<time.h>
//#include "display.cpp"

using namespace std;

static int size;

char* Gen(int s)
{
    const int a=s;

   int t=1000,p=0, i=0;

   char K[a];
   int Ki[a];

    srand((int) time(0));

   for(i=0;i<s;++i)
   {
        t=rand()%256;
        while(!((t<256)&&(t!=0)))
        {
            t=rand()%256;
        }
        K[p++]=t;
        Ki[(p-1)]=t;

        t=rand()%256;
   }
/*
cout<<endl<<"Original Key"<<endl;
   dispCC(K,s);
cout<<endl<<"Original Key integer"<<endl;
  dispII(Ki,s);
  */

    char* k_pointer=K;
    return k_pointer;


}
int rK()
{

 int i=0,j=0,s=0;
     size=rand()%10;

   while(!(size>2 && (size <10)))
   {
        srand (time(NULL));
        size=rand()%10;
   }
   cout<<size*size<<endl;
 s =size*size;
 return s;
}
/*
int main()
{
        int  c=rK();
    Gen(c);
    getch();
    return 0;
}
*/

