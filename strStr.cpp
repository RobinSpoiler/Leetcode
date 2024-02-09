#include <iostream>
#include <vector>

using namespace std;

int strStr(string haystack, string needle)
{
    size_t found = haystack.find(needle);
    return found;
}

int strStrHardCore(string haystack, string needle)
{   
    if(needle.size() > haystack.size()){
        return -1;
    }
    // cout <<  haystack.size() - needle.size()  << endl;
    for (int i = 0; i <= haystack.size() - needle.size(); i++)
    {
        string window = haystack.substr(i,needle.size());
        if (window == needle)
        {
            return i;
        }
    }
    return -1;
}
int main()
{

    // cout << strStr("leetcode", "leet") << endl;
    // cout << strStrHardCore("leetcode", "leet") << endl;
    cout << strStrHardCore("codeleet", "et") << endl;
    return 0;
}