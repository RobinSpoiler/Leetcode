#include <iostream>
#include <string>

using namespace std;

int lenghtOfLastWord(string s)
{
    int last = 1;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            count++;
        }
        else
        {

            if (count > 0)
            {
                last = count;
            }
            // revisar si la palabra ya se acabo retornar last??
            count = 0;
        }
    }
    // si la palabra no se ha acabado y solo quedan espacios retornar count
    if (count > 0)
    {
        last = count;
    }
    return last;
}

int lenghtOfLastWordOptimal(string s)
{
    int count = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && count >= 1)
        {
            return count;
        }
        if(s[i] != ' ')
        {
            count++;
        }
    }
    return count;
}

int main()
{

    // cout << lenghtOfLastWord("Hello worldd    ") << endl;
    // cout << lenghtOfLastWord("luffy is still joyboy") << endl;
    // cout << lenghtOfLastWord("   fly me   to   the moon  ") << endl;
    // cout << lenghtOfLastWord("Today is a nice day") << endl;
    //-----------------------------------------------------------
    cout << lenghtOfLastWordOptimal("luffy is still joyboy") << endl;
    cout << lenghtOfLastWordOptimal("   fly me   to   the moon  ") << endl;
    cout << lenghtOfLastWordOptimal("Today is a nice day") << endl;
    cout << lenghtOfLastWordOptimal("a ") << endl;
    return 0;
}