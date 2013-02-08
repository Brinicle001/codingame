// CodinGame - Session du 29/01/2013 - Test 1

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <bitset>

#define MAX_INPUT 100
using namespace std;

string chuck_conversion(const unsigned char* buffer, const size_t size);
string chuck_conversion(const string buffer);

string chuck_conversion(const unsigned char* buffer, const size_t size)
{
    ostringstream oss;
    string bitView;
    char tBit='\0';

    for(size_t i=0; i<size; i++)
    {
        bitView = bitset<sizeof(unsigned char)*7>(buffer[i]).to_string();
        for(int i=0; i<7; i++)
        {
            if (tBit!=(char)bitView[i])
            {
                if (tBit!='\0')
                {
                    oss <<" ";
                }
                tBit=(char)bitView[i];
                if (tBit=='1')
                {
                    oss <<"0 ";
                }
                else
                {
                    oss <<"00 ";
                }

            }
            oss<<"0";
        }
    }
    return oss.str();
}

string chuck_conversion(const string buffer)
{
    return chuck_conversion((unsigned char*)buffer.c_str(),buffer.size());
}


int main()
{
    string in;
    cin >> in;
    cout << chuck_conversion((unsigned char*)in.c_str(),in.size()) << endl;
    return 0;
}
