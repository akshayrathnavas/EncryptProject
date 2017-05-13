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
        cout<<endl<<"Character 1= "<<aa[i-1]<<"\t"<<"Character 2= "<<bb[i-1]<<endl;

    bool a1=aa[i-1] & 1;
    bool b1=bb[i-1] & 1;
    cout<<endl<<"LSB of Key1= "<<a1<<endl;
    cout<<endl<<"LSB of Key2= "<<b1<<endl;

    if((aa[i-1] & 1)==(bb[i-1]) & 1)
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
