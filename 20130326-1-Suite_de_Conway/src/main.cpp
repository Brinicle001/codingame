// Read inputs from stdin. Write outputs to stdout.
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string &traduction(string &out, string &in);
bool recursive_trad(string &out, string &in, int depth);

bool recursive_trad(string &out, string &in, int depth)
{
    string tmp;

    if (depth > 0)
    {
        recursive_trad(out, traduction(tmp, in), --depth);
    } else
    {
        out = in;
    }
}

string &traduction(string &out, string &in)
{
    int n=0, m=0;
    unsigned char c, cur='\0';
    ostringstream oss;
    for(int i=0; i <=in.length(); i++)
    {
        c=in[i];
        if ((c!='\n') && (c!=' '))
        {
            if ((cur!='\0') && (cur!=c))
            {
                if (m > 0)
                {
                    oss << ' ';
                }
                oss << n << ' ' << cur;
                n=0;
                m++;
            }
            cur=c;
            n++;
        }
    }
    if (cur!='\0')
    {
        if (m > 0)
        {
            oss << ' ';
        }
        oss << n << ' ' << cur;
    }
    out = oss.str();
    return out;
}

int main()
{
    string start, output;
    int depth;

	cin >> start;
    cin.ignore();
    cin >> depth;
    recursive_trad(output, start, --depth);
    cout << output << endl;

	return 0;
}
