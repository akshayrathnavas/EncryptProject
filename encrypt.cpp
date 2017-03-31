#include<fstream>
#include<cstdio>
#include<cmath>
#include<string.h>
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


