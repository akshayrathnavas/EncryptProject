#pragma once
#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include<bitset>

using namespace std;


char* kSel(char a[], char b[], int L, int M)
{
    int i=0, j=0;
    char aa[L], bb[L];
     char* k_pointer;

     for(i=0;i<L;++i)
     {
         aa[i]=a[i];
         bb[i]=b[i];
     }

    for(i=0;i<L;++i)
    {
        aa[i]*=M;
        bb[i]*=M;

    }

    if(bitset<8>(aa[i])==bitset<8>(bb[i]))
    {
            k_pointer=a;
            i=1;
    }
    else
    {
            k_pointer=b;
            i=2;
    }
    cout<<endl<<"Selected Key is Key "<<i<<endl;


    return k_pointer;


}
