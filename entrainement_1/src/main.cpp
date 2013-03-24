// CodinGame - Entrainement 1

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n1;
    int n2;
    string line;
    string w1;
    string w2;

    cin >> n1 >> n2;
    cin.ignore(); // this reads the '\n' just after n2

    getline(cin, line);

    cin >> w1 >> w2;

    // logic comes here...
    if (n1 + n2 == (int)line.size()) {
        cout << w1 << endl;
    } else {
        cout << w2 << endl;
    }

    return 0;
}
