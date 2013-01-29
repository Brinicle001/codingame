// CodinGame - Session du 29/01/2013 - Test 2

#include <iostream>
#include <string>
#include <stdlib.h>

#define MAX_INPUT 100000
#define MAX_BEGIN_DAY 1000000
#define MAX_DURATION 1000

using namespace std;

int main()
{
    int nInput=0;
    int startDate,duration,endDate;
    unsigned short *tabDay;
    int bOK=1;
    int nTest=0;

    cin >> nInput;
    cin.ignore();

    // Etape 1 : Stockage dans un map<int>

    // Etape 2 : Tri par date de début

    // Etape 3 : Filtre des doublons sur date de début (ne sont conservé que les durées les plus courtes)

    // Etape 4 : Pondération des périodes

    // Etape 5 : Filtre des périodes en chevauchement (ne sont conservé que celles qui ont le moins d'impact)

    // Etape 6 : comptage d'occurrences

    /*
    for(int i=0;i<nInput;i++)
    {
        cin >> startDate >> duration;
        endDate = startDate + duration -1;
        cin.ignore();
        bOK=1;
        for (int j=startDate;j<endDate;j++)
        {
            if (tabDay[j]!=0)
            {
                bOK=0;
                break;
            }
        };
        if (bOK)
        {
            for (int j=startDate;j<endDate;j++)
            {
                tabDay[j]=1;
            }
            nTest++;
        }
    }
    */
    cout << nTest << endl;
    return 0;
}
