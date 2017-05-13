#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include <cstdlib>
#include<time.h>
#include<stdio.h>

using namespace std;

static int size;




void clrscr()
{

    system("cls");
}
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

    for(i=0;i<m;++i)
    {

        cout<<a[i]<<"\t";
    }
    cout<<endl;
    cout<<endl;
}



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
cout<<endl<<"Original Key Integer"<<endl;
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




int exor(int x, int y)
{
    int res = 0; // Initialize Result

    // Assuming 8-bit Integer
    for (int i = 8; i >= 0; --i)
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

        // Update Result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}




int z=0;

int fNoD(int sum)
{
    int i=0;
    while(sum!=0)
    {
        sum/=10;
        ++i;
    }
    return i;
}

char* trans(char K[], int L, int sum)
{
    const int D=fNoD(sum);
    char temp;
    int i=0, j=0;
    int S[D];

    for(i=D-1;i>=0;--i)
    {
        S[i]=sum%10;
        sum/=10;
    }

    i=0;
    j=0;
    while(L)
    {
        j=S[i%D]-1;
        temp=K[i];
        K[i]=K[j];
        K[j]=temp;
        ++i;
        --L;
    }
    return K;
}


char* randKeyGen(char K[], int len, int sum)
 {
     static int i, j, k, p, q, a[100], M, n;
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


    cout<<endl<<"Original Matrix Integer"<<endl;

dispi(key1i[0],m);

n=0;
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



/*

for(i=0;i<L;++i)
    =*(fP+i);

*/



return k2;


}




int sum=0;
int findMod(char K[], int L)
{
    int sum0=0, p=0;
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

int choose()
{
     int e;
     cout<<"\t\t\t 1. Encrpytion"<<endl<<"\t\t\t 2. Decryption"<<endl<<"\t\t\t 3. Exit"<<endl<<"\t\t\t Enter Your Choice: ";
     cin>>e;
     return e;

}


char* decrypt(int L, int m)
{
    ifstream DE;
    DE.open("k.txt");
    static int len=L;

    char pt[L];




}

int main()
{
    int i=0;
    //char ch[10]="ahc5i90w4";
  // int  c=rK();
  //int c=9;

   // const int s=c;
   ofstream EK;
   EK.open("k.txt");

   int c;

   int e=choose();

   if(e==3)
    exit(0);

  while((e<1)||(e>3))
  {
      cout<<endl<<"\t\t\t Wrong Option. Try Again"<<endl;
      clrscr();
      e=choose();
  }

   if(e==1)
    {
   cout<<"\t\t\t Enter The Size Of The Key (Squares) (9-81): ";
   cin>>c;
        const int s=c;


        char PT[s]="abcdefgh";

         cout<<endl<<endl<<"\t\t\tEnter The Plain Text (Size "<<c<<"): ";
         cin.getline(PT,s);

        char CT[s];
        int PTi[s];
        int CTi[s];

        PT[0]=-24;
        PT[1]=70;
        PT[2]=-120;
        PT[3]=85;
        PT[4]=-105;
        PT[5]=3;
        PT[6]=50;
        PT[7]=108;
      //  PT[8]=123;


         cout<<"Enter The Plain Text: ";
         cin.getline(PT,s);




    char* K=Gen(s);
    char* k2;
    char key1[s],key2[s];
    int p=0;
    int M;

    for(i=0;i<c;++i)
    {
        key1[i]= K[p++];

    }
    cout<<endl<<"Plain Text"<<endl;
    dispCC(PT,9);

   // cout<<endl<<"Original Key "<<endl;
  //  dispCC(KK,s);

    //const int L=strlen(K);
            const int L=c;

    int R=0;

    char* fP;
    char* fPT;
    char fKey[L], fKeyT[L];






while(R<=L/2)
{
         cout<<endl<<"=======================================================Round "<<R;
         cout<<"============================================================="<<endl;

    M=findMod(key1,s);
    cout<<endl<<"Sum= "<<sum<<"\t"<<"MOD= "<<M<<endl;

    k2=randKeyGen(key1,s, sum);
    p=0;

     for(i=0;i<L;++i)
    {
        key2[i]= k2[p++];

    }



    fP=kSel(key1, key2, L, M);


    p=0;

    for(i=0;i<L;++i)
    {
        fKey[i]= fP[p++];
        key1[i]=fKey[i];

    }
        dispCC(fKey,L);


    fPT=trans(fKey,L,sum);

    p=0;
    for(i=0;i<L;++i)
    {
        fKeyT[i]= fPT[p++];

    }

    ++R;




    cout<<endl<<"Final Key After Transposition"<<endl;
        dispCC(fKeyT,L);

        EK<<




        cout<<endl<<"Selected Key Copied"<<endl;
    dispCC(key1,L);

     cout<<endl<<"Plain Text"<<endl;
    dispCC(PT,L);


     for(i=0;i<L;++i)
            {

                CT[i]=exor(PT[i],fKeyT[i]);

                PT[i]=CT[i];

                CTi[i]=CT[i];


            }



    cout<<endl<<"Cipher Text"<<endl;
    dispCC(CT,L);



}


ofstream FW,EN;
FW.open("OUT1.txt");
for(i=0;i<9;++i)
FW<<CTi[i]<<endl;
FW.close();


    EN.open("O.txt");
    EN<<CT;

    EN.close();

    }

   getch();

    return 0;

}



