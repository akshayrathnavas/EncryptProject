#pragma once
#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

using namespace std;

void Dec ()
{
    ifstream EF,DE;
    EF.open("OUT1.txt");
    DE.open("ki.txt");
    int i=0,a=0,R=0,c=0;;

    string ct;
    string tk;
    string PT;


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



            cout<<endl<<"Length: "<<size<<endl;

        for(i=0;i<size;++i)
            cti[i]=ct[i];
        dispII(cti,size);


        int len;
        ifstream T;
        T.open("KL.txt");
        T>>len;
        T.close();

    R=0;
    cout<<endl<<"R "<<R<<endl<<"Length "<<len<<endl;;

             static int aa,bb,cc;

    while(R<=len/2)
    {
        cout<<endl<<"Round "<<R<<endl;

        i=0;
        for(i=0;i<len;++i)
        {
            cout<<"tk["<<i<<"] ";
            DE>>c;
            tk[i]=c;
            cout<<c<<"\t";
        }
        cout<<endl;

        cout<<endl<<"Key "<<tk<<endl;
        for(i=0;i<len;++i)
            cout<<tk[i]<<"\t";
        cout<<endl;

         for(i=0;i<len;++i)
            {
                aa=ct[i];
                bb=tk[i];
                cc=exor(aa,bb);
                PT[i]=cc;
                ct[i]=PT[i];
                cout<<endl<<"A "<<aa<<"\t B "<<bb<<"\t C "<<cc<<endl;
            }
            cout<<endl<<"Ciphered Text After Round "<<R<<endl;
            for(i=0;i<len;++i)
                cout<<ct[i]<<"\t";
            cout<<endl;



        ++R;
    }



cout<<endl<<"Deciphered Text"<<endl;
cout<<PT;

EF.close();
DE.close();

}
