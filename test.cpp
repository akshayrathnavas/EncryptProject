//#pragma ONCE
//#pragma SPARK_NO_PREPROCESSOR

#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>
#include "decToBin.cpp"

using namespace std;

int rev(int n);
int exor(int x, int y)
{
    int res = 0; // Initialize Result

    // Assuming 8-bit Integer
    for (int i = 8; i >= 0; i--)
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
       cout<<b1<<"\t"<<b2<<endl;

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);
        cout<<xoredBit<<endl;

        // Update Result
        res <<= 1;
        cout<<res<<endl;
        res |= xoredBit;
        cout<<res<<endl;

    }
    return res;
}



