#pragma once
#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include "display.cpp"
#include "xor.cpp"
#include "kGen.cpp"
#include "keySel.cpp"

using namespace std;


//void dispc(char a[m][m], int m); // Display Character Array/Matrix
//void dispi(int a[m][m], int m); // Display Integer Array/Matrix
//unsigned int ConvertToBinary(int n);

void randKeyGen(char K[], int len)
 {
     static int i, j, k, p, q, a[100],sum, M, n;
     const int L=len;
     char r_Key[L];

     const int m=sqrt(L);

     cout<<endl<<"L= "<<L<<" m= "<<m<<endl;


     char key1[m][m], r_Key1[m][m]; //String Matrix And Its Reverse
     int Ki[L], r_Keyi[L], key1i[m][m], r_Key1i[m][m]; //Integer Matrix And Its Reverse

     char key2[m][m], k2[L];
     int key2i[m][m];

//strcpy(r_Key,K);
    //  cout<<endl<<"Original Key Copied To Reverse"<<endl;
    // dispCC(r_Key,L);


        j=L-1;
        for(i = 0; i < L; ++i)
        {
            r_Key[i] = K[j];
         //   cout<<endl<<K[j]<<"  "<<r_Key[i]<<endl;

            --j;
        }



        for(i=0;i<L;++i)
        {
            Ki[i]=K[i];
            r_Keyi[i]=r_Key[i];
        }


    cout<<endl<<"Original Key"<<endl;
     dispCC(K,L);
     cout<<endl<<"Original Key Integer"<<endl;
     dispII(Ki,L);
    cout<<endl<<"Reverse Key"<<endl;
     dispCC(r_Key,L);
     cout<<endl<<"Reverse Key Integer"<<endl;
     dispII(r_Keyi,L);

     for(i=0;i<L;++i)
     {
        a[i]=K[i];
        sum+=a[i]*(i+1);
     }


        M=sum%L;


        for(i=0;i<m;++i)
        {

            for(j=0;j<m;++j)
            {
                key1[i][j]=K[p++];
                key1i[i][j]=key1[i][j];

                r_Key1[i][j]=r_Key[q++];
                r_Key1i[i][j]=r_Key1[i][j];
            }
        }

    cout<<endl<<"Original Matrix"<<endl;

dispc(key1[0],m);
    cout<<endl<<"Original Matrix Integer"<<endl;

dispi(key1i[0],m);
    cout<<endl<<"Reverse Matrix"<<endl;

dispc(r_Key1[0],m);
    cout<<endl<<"Reverse Matrix Integer"<<endl;

dispi(r_Key1i[0],m);


  for(i=0;i<m;++i)
  {
            for(j=0;j<m;++j)
            {

                key1i[i][j]=key1[i][j]+M;
            }
  }

dispi(key1i[0],m);

for(i=0;i<m;++i)
{

            for(j=0;j<m;++j)
            {

                key2i[i][j]=exor(key1i[i][j],r_Key1i[i][j]);
                key2[i][j]=key2i[i][j];
                k2[n++]=key2[i][j];

            }
}

    cout<<endl<<"Key 2 Matrix Integer"<<endl;

dispi(key2i[0],m);
    cout<<endl<<"Key 2 Matrix"<<endl;

dispc(key2[0],m);
    cout<<endl<<"Key 2"<<endl;

dispCC(k2,L);

char* fP=kSel(K, k2, L, M);
char fKey[L];

 p=0;

    for(i=0;i<L;++i)
    {
        fKey[i]= fP[p++];

    }


/*

for(i=0;i<L;++i)
    =*(fP+i);

*/




dispCC(fKey,L);






getch();




}





int main()
{
    int i=0;
    //char ch[10]="ahc5i90w4";
   int  c=rK();
  //int c=9;
    const int s=c;
    char* K=Gen(c);
    char KK[s];
    int p=0;

    for(i=0;i<c;++i)
    {
        KK[i]= K[p++];

    }

   // cout<<endl<<"Original Key "<<endl;
  //  dispCC(KK,s);

    int L=strlen(K);

    randKeyGen(KK,s);


    return 0;

}
