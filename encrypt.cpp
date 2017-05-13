#include<fstream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include "keyGen.cpp"
#include "trans.cpp"


/*
class Enc
{

private:
	char plainText[100];
	char key[100], key1[100], key2[100];
	int L;
	int R = 0;

	void Enc(char PT[], char k[])
	{
		strcpy(plainText, PT);
		strcpy(key1, k);

		L = strlen(key1);
		R = 0;

		strcpy(key1, trans(key1));


		while (R <= L / 2)
		{

			strcpy(key2, randKeyGen(key1));
			strcpy(key, randKeySel(key1, key2));

			strcpy(key, trans(key));

			R = R + 1;
		}

	}
};

*/

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




int main()
{
    int i=0;
    //char ch[10]="ahc5i90w4";
   int  c=rK();
  //int c=9;

   // const int s=c;
        const int s=9;

        char PT[s]="abcdefgh";
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
            const int L=9;

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


ofstream FW;
FW.open("OUT.txt");
for(i=0;i<9;++i)
FW<<CTi[i]<<endl;
FW.close();





    getch();

    return 0;

}



