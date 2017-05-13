#pragma once
#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

using namespace std;

void Dec (int m)
{
    ifstream EF,DE;
    EF.open("OUT1.txt");
    DE.open("k.txt");
    int i=0,a=0,R=0,c=0;;

    string ct;
    string tk;
    string PT;

    if(m==1)
    {
       cout<<endl<<"Last Cipher Text"<<endl;



/*
       for(i=0;(!EF.eof());++i)
        {   EF>>ct[i];
            EF.seekg(1);
        }
*/
        i=0;
        while (EF >> a)
        {
            ct[i++]=a;
            cout<<ct[i-1]<<"\t";
        }


        cout<<endl;
        cout<<ct;

        const int size=i;
               int cti[size];
                   R=size/2;



            cout<<endl<<"Length: "<<size<<endl;

        for(i=0;i<size;++i)
            cti[i]=ct[i];
        dispII(cti,size);
    }
    else
    {
        cout<<"\t\t\t Enter The Text To Be Decrypted: ";
        cin>>ct;
    }

    cout<<endl<<"R "<<R<<endl;

    while(R>-1)
    {
        cout<<endl<<"Round "<<R-(ct.length())<<endl;

        i=0;
        while((DE>>c)!="\n")
            tk[i]=c;

        cout<<endl<<"Key "<<tk<<endl;

         for(i=0;i<ct.length();++i)
            {
                PT[i]=exor(ct[i],tk[i]);
                ct[i]=PT[i];
            }

        --R;
    }



cout<<endl<<"Deciphered Text"<<endl;
cout<<PT;

}
