// CodinGame - Entrainement 2

#include <iostream>
#include <string>
#include <stdlib.h>

#define MAX_TEMPERATURE 5526
#define MIN_TEMPERATURE -273
#define MAX_INPUT 10000
#define MIN_INPUT 0
using namespace std;

int main()
{
    int n=0;                        // The number of temperature
    int tmin=MAX_TEMPERATURE;       // The temperature closest of zero
    int tminplus=MAX_TEMPERATURE;   // The temperature closest of zero (absolute value)
    int t=0;                        // The current temperature
    int m=0;                        // The number of input read


    cin >> n;       // Read n
    if ((n < MIN_INPUT) || (n >MAX_INPUT)){
        cerr << "ERROR: The number of temperature must be between " << MIN_INPUT << " and " << MAX_INPUT << endl;
        return 1;
    }
    cin.ignore();   // this reads the '\n' just after n2

    // Read all the input
    for(int i=0; i<n; i++){
        cin >> t;
        if ((t < MIN_TEMPERATURE) || (t >MAX_TEMPERATURE)){
            cerr << "WARNING: The temperature " << t << " is off range ([" << MIN_INPUT << " ; " << MAX_INPUT << "])" << endl;
        } else {
            if(abs(t)<=tminplus){
                if ((t==tminplus) && (tmin<0))
                {
                    tminplus=t;
                    tmin=t;
                } else
                {
                    if (t<tminplus) {
                        tminplus=abs(t);
                        tmin=t;
                    }
                }
            }
            m++;
        }
    }

    if (m == 0) {
        // No temperature in input
        cout << 0 << endl;
    } else {
        if (m < n) {
            cerr << "WARNING: " << n << " input expected. Received only " << m << endl;
        }
        cout << tmin << endl;
    }

    return 0;
}
