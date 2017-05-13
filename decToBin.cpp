#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

using namespace std;


unsigned int bin;


void decToBin(int n)
{
    if (n / 2 != 0)
    {
        decToBin(n / 2);
    }
    bin=(bin*10)+(n%2);
}

unsigned int ConvertToBinary(int n)
{
    decToBin(n);
    return bin;

}

