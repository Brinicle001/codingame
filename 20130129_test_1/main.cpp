// CodinGame - Session du 29/01/2013 - Test 1

#include <iostream>
#include <string>
#include <stdlib.h>

#define MAX_INPUT 100
using namespace std;


int main()
{
    unsigned short bFlags=0x00;
    unsigned short bMask=0x40;
    char oneCar;
    int nBit=0,tBit=1;

    cin >> oneCar;
    for(int i=0; i<7; i++)
    {
         if (((tBit & 0x01) != (oneCar & bMask)) || (i == 0))
            {
            if (i > 0){
                if (tBit == 1)
                {
                    cout << "0 ";
                }
                else
                {
                    cout << "00 ";
                }
                for(int j=0; j<nBit; j++)
                {
                    cout << "0";
                }
            }
                if (oneCar & bMask)
                {
                    tBit=1;
                }else{
                    tBit=0;
                }
                nBit=1;
            }
        }
        else
        {
            nBit++;
        }
        oneCar=oneCar<< 1;
    }
    return 0;
}
