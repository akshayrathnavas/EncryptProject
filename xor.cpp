//#pragma ONCE
//#pragma SPARK_NO_PREPROCESSOR

#include<fstream>
#include <iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<conio.h>

using namespace std;

int exor(int x, int y)
{
    int res = 0; // Initialize Result

    // Assuming 8-bit integer
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



