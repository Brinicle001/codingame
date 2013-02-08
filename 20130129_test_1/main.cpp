// CodinGame - Session du 29/01/2013 - Test 1

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

ostream &chuck_conversion(ostream &out, const unsigned char c, unsigned char &tBit);
ostream &chuck_conversion(ostream &out, istream &in);


ostream &chuck_conversion(ostream &out, const unsigned char c, unsigned char &tBit)
{
    string bitView;

    bitView = bitset<sizeof(unsigned char)*7>(c).to_string();
    for(int i=0; i<7; i++)
    {
        if (tBit!=(unsigned char)bitView[i])
        {
            if ((tBit=='0') || (tBit=='1'))
            {
                out << " ";
            }
            tBit=(unsigned char)bitView[i];
            if (tBit=='1')
            {
                out << "0 ";
            }
            else
            {
                out << "00 ";
            }

        }
        out << "0";
    }
    return out;
}

ostream &chuck_conversion(ostream &out, istream &in)
{
    unsigned char c,tBit='\n';
    while(!in.eof())
    {
        c = in.get();
        if ((in.good()) && (c!='\n'))
        {
            chuck_conversion(out, c,tBit);
        }
    }
    return out;
}

int main()
{
    chuck_conversion(cout, cin);
    cout << endl;
    return 0;
}
