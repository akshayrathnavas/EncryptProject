#include<fstream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include "keyGen.cpp"
#include "trans.cpp"

int L;

void clrscr()
{
    system("cls");
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
     int e=0;
     cout<<"\t\t\t 1. Encrpytion"<<endl<<"\t\t\t 2. Decryption"<<endl<<"\t\t\t 3. Exit"<<endl<<"\t\t\t Enter Your Choice: ";
     cin>>e;
     return e;
}

int dChoose()
{
    int d=0;
    cout<<"\t\t\t 1. Decrypt Last Encrypted Text"<<endl<<"\t\t\t 2. Decrypt New Text"<<endl<<"\t\t\t 3.Exit"<<endl<<"\t\t\t Enter Your Choice: ";
    cin>>d;
    return d;
}


void decrypt(int L, int m)
{
    ifstream EF,DE;
    EF.open("o.txt");
    DE.open("k.txt");
    static int len=L;
    int i=0;

    char ct[len];
    char tk[len];
    char PT[len];

    if(m==1)
    {
       EF.getline(ct,L);
       cout<<endl<<"Last Cipher Text"<<endl;
       dispCC(ct,L);
    }
    else
        cout<<"\t\t\t Enter The Text To Be Decrypted: ";
        cin.getline(ct,L);

    int R=::L/2;

    while(R>0)
    {
        cout<<endl<<"Round "<<R-L<<endl;
        DE.getline(tk,L);

         for(i=0;i<L;++i)
            {
                PT[i]=exor(ct[i],tk[i]);
                ct[i]=PT[i];
            }

        --R;
    }


dispCC(ct,L);


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
   int d=0;

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
            const int L=s;
            ::L=L;

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

        cout<<endl<<"Writing To File"<<endl;

        for(i=0;i<L;++i)
        {
            EK<<fKeyT[i];
        }
        EK<<"\n";



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

EK.close();

ofstream FW,EN;
FW.open("OUT1.txt");
for(i=0;i<9;++i)
FW<<CTi[i]<<endl;
FW.close();


    EN.open("O.txt");
    EN<<CT;

    EN.close();

    }

    else if(e==2)
    {
        clrscr();

        d=dChoose();

    while((e<1)||(e>3))
    {
      cout<<endl<<"\t\t\t Wrong Option. Try Again"<<endl;
      clrscr();
      d=dChoose();
    }
        if(d!=3)
        decrypt(::L,d);

        else
            exit(0);


    }

   getch();

    return 0;

}





