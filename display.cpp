#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

using namespace std;

void dispc(char *a, int m)
{


    int i=0,j=0;

  for(i=0;i<m;++i)
 {

            for(j=0;j<m;++j)
            {

                cout<< *(a+ i*m + j)<<"\t";

            }
                cout<<endl;

 }
 cout<<endl;
}

void dispi(int *a, int m)
{


    int i=0,j=0;


  for(i=0;i<m;++i)
 {

            for(j=0;j<m;++j)
            {

                cout<< *(a+ i*m + j)<<"\t";

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

        cout<<a[i]<<"\t";
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

        cout<<a[i]<<"\t";
    }
    cout<<endl;
    cout<<endl;
}

/*

int main(){
    char a[5][5];
    int b[5][5];
    int p=0;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j)
        {


            a[i][j]='a'+ p++;
            b[i][j]=i*j;
        }
    }

    dispc(a[0],5);
    dispi(b[0],5);

    getch();

}

*/


