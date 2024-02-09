#include <iostream>
#include <vector>

using namespace std;

int strStr(string haystack, string needle){
    size_t found = haystack.find(needle);
    return found;
}
int main(){

    cout << strStr("leetcode", "leet") << endl;
    
    return 0;
}