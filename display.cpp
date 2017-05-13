#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

using namespace std;

void dispc(char a[3][3], int m)
{


    int i=0,j=0;

  for(i=0;i<m;++i)
 {

            for(j=0;j<m;++j)
            {

                cout<<a[i][j]<<"\t";

            }
                cout<<endl;

 }
 cout<<endl;
}

void dispi(int a[3][3], int m)
{


    int i=0,j=0;


  for(i=0;i<m;++i)
 {

            for(j=0;j<m;++j)
            {

                cout<<a[i][j]<<"\t";

            }
                cout<<endl;

 }
 cout<<endl;
}


void dispCC(char a[], int m)
{
    int i=0;
  //  int l=strlen(a);

    for(i=0;i<m;++i)
    {

        cout<<a[i];
    }
    cout<<endl;
    cout<<endl;
}



void dispII(int a[], int m)
{
    int i=0;
  //  int l=(sizeof(a)/sizeof(a[0]));

    for(i=0;i<m;++i)
    {

        cout<<a[i];
    }
    cout<<endl;
    cout<<endl;
}


