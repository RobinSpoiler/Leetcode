#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Find the smallest word would reduce iterations in some cases
int indexSmallestWord(vector<string> arr)
{
    int indSmallestWord = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].size() < arr[indSmallestWord].size())
        {
            indSmallestWord = i;
        }
    }
    return indSmallestWord;
};

string findLargestSubstring(vector<string> arr)
{
    // cout << arr[indexSmallestWord(arr)] << endl;
    string smallestWord = arr[indexSmallestWord(arr)];
    string largestSubstring = smallestWord;

    bool flag = false;
    while (largestSubstring != "")
    {
        for (int i = 0; i < arr.size(); i++)
        {
            size_t found = arr[i].find(largestSubstring);
            if (found != string::npos && found == 0) // Finds substring at the begining of the word
            {
                // cout << found << endl; lo encuentra al inicio (prefijo)
                flag = true; //flag will remain true unless there's a mismatch
            }
            else
            {
                largestSubstring = largestSubstring.substr(0, largestSubstring.size() - 1);
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return largestSubstring;
        }
    }
    return "";
}

string findLargestSubstringRefactored(vector<string> arr)
{
    string largestPrefix = arr[indexSmallestWord(arr)];
    // Por cada elemento del arreglo de strings vas a checar si el largest prefix esta en la palabra
    for (int i = 0; i < arr.size(); i++)
    {
        size_t found = arr[i].find(largestPrefix);
        //Mientras no lo encuentre el subs sigue quitando | si quita todas las letras no va a entrar nunca al while y retornará el string vacio
        while (found == string::npos || ((found != string::npos) && (found != 0))) // No encuentra o lo encuentra pero no al inicio
        {
            largestPrefix = largestPrefix.substr(0, largestPrefix.size() - 1);
            found = arr[i].find(largestPrefix);
        }

    }
    return largestPrefix;
}

//Big O analysis
/* 
for where n represents the size of the array
while where m represents the size of the smallest or first word
O(n*m)
*/

int main()
{
    // el prefijo tiene que estar al inicio
    // otra cosa que estaria bien seria ver cual es la palabra msa pequena
    // y store el substring hsta el momento

    // puede venir un string de palabras vacio? zi, retornar ""
    vector<string> arr{"flower", "flow", "flight"};
    vector<string> arr2{"dog", "car", "flight"};
    vector<string> arr3{"cor", "co", "clown"};
    vector<string> arr4{"a", "ba", "bca"};

    if (arr4.size() > 1)
    {
        cout << findLargestSubstringRefactored(arr4) << endl;
    }
    else
    {
        cout << "symbolic empty string" << endl;
    }

    // recibe la palabra mas pequeña y el arr de palabras

    return 0;
}