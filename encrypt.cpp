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
    sum=0;
    int i=0;
    int a[L];
    int M;

     for(i=0;i<L;++i)
     {
        a[i]=K[i];
        sum+=a[i]*(i+1);
     }
    M=sum%L;
    return M;
}





int main()
{
    int i=0;
    //char ch[10]="ahc5i90w4";
   int  c=rK();
  //int c=9;
    const int s=c;
    char* K=Gen(c);
    char* k2;
    char key1[s],key2[s];
    int p=0;
    int M;

    for(i=0;i<c;++i)
    {
        key1[i]= K[p++];

    }

   // cout<<endl<<"Original Key "<<endl;
  //  dispCC(KK,s);

    const int L=strlen(K);

    int R=0;

    char* fP;
    char* fPT;
    char fKey[L], fKeyT[L];




while(R<=L/2)
{
         cout<<endl<<"=======================================================Round "<<R;
         cout<<"============================================================="<<endl;

    M=findMod(key1,s);

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

    }
        dispCC(fKey,L);


    fPT=trans(fKey,L,sum);

    p=0;
    for(i=0;i<L;++i)
    {
        fKeyT[i]= fPT[p++];

    }

    ++R;


        for(i=0;i<L;++i)
        {
            key1[i]=fKeyT[i];

        }

    cout<<endl<<"Final Key After Transposition"<<endl;
        dispCC(fKeyT,L);


        cout<<endl<<"Copied Key After Transposition"<<endl;
    dispCC(key1,L);



}




    getch();

    return 0;

}



