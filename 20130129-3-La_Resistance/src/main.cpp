// CodinGame - Session du 29/01/2013 - Test 3

#include <iostream>
#include <string>
#include <stdlib.h>

#define MAX_MORSE 100000
#define MAX_WORD 100000
#define MAX_WORD_LENGTH 20
#define M

using namespace std;

string morse_conversion(string sWord);


string morse_conversion(string sWord)
{
    return sWord;
}

int main()
{
    string morseInput,word;
    int nWord=0;


    cin >> morseInput;
    cin.ignore();

    // Etape 1 : Génération d'un arbre de lettres à partir du morse

    // Etape 2: Parcours de l'arbre de lettres avec les mots du dictionnaire pour identifier les combinaisons
    // (pour une première lettre, penser à tester chaque mot qui commence par cette lettre)

    cin >> nWord;
    cin.ignore();
    for (int i=0;i<nWord;i++)
    {
        cin >> word;
        cin.ignore();
        morse_conversion(word);
        cout << i << "=" << word << endl;
    }
    return 0;
}
