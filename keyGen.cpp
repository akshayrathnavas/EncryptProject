#pragma once
#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include "display.cpp"
#include "xor.cpp"

using namespace std;


//void dispc(char a[3][3], int m); // Display Character Array/Matrix
//void dispi(int a[3][3], int m); // Display Integer Array/Matrix
//unsigned int ConvertToBinary(int n);

void randKeyGen(char K[])
 {
     static int L, i, j, p, q, a[100],sum, M, n;
     char r_Key[100];

     L=strlen(K);
     const int m=sqrt(L);


     char key1[3][3], r_Key1[3][3]; //String Matrix And Its Reverse
     int key1i[3][3], r_Key1i[3][3]; //Integer Matrix And Its Reverse

     char key2[3][3], k2[9];
     int key2i[3][3];

     strcpy(r_Key,K);
     strrev(r_Key);

     dispCC(K,L);
     dispCC(r_Key,L);

     for(i=0;i<L;++i)
     {
        a[i]=K[i];
        sum+=a[i]*(i+1);
     }


        M=sum%L;


        for(i=0;i<3;++i)
        {

            for(j=0;j<3;++j)
            {
                key1[i][j]=K[p++];
                key1i[i][j]=key1[i][j];

                r_Key1[i][j]=r_Key[q++];
                r_Key1i[i][j]=r_Key1[i][j];
            }
        }


dispc(key1,m);
dispi(key1i,m);
dispc(r_Key1,m);
dispi(r_Key1i,m);


  for(i=0;i<3;++i)
  {
            for(j=0;j<3;++j)
            {

                key1i[i][j]=key1[i][j]+M;
            }
  }

dispi(key1i,m);

for(i=0;i<3;++i)
{

            for(j=0;j<3;++j)
            {

                key2i[i][j]=exor(key1i[i][j],r_Key1i[i][j]);
                key2[i][j]=key2i[i][j];
                k2[n++]=key2[i][j];

            }
}
 ofstream outfile;
   outfile.open("afile.txt");
      outfile << k2 << endl;

dispi(key2i,m);
dispc(key2,m);
dispCC(k2,L);
getch();


}





int main()
{
    char ch[10]="ahc5i90w4";
    randKeyGen(ch);


    return 0;

}