#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isValid(string s)
{
    // Wrong approach but smart workaround
    bool isValid = false;

    unordered_map<char, int> map = {
        {'{', 0},
        {'(', 0},
        {'[', 0},
        {'}', 0},
        {')', 0},
        {']', 0}};

    for (int i = 0; i < s.size(); i++)
    {
        // cout << s[i] << endl;
        map.at(s[i]) += 1;
    }
    if (map.at('{') == map.at('{') && (map.at('(') == map.at(')')) && map.at('[') == map.at(']'))
    {
        isValid = true;
    }
    // for (auto&x : map)
    // {
    //     cout << x.first << " ";
    //     cout << x.second << endl;
    // }
    return isValid;
}

// Passed tests but got runtime error, I think I'm accessing something wrong
bool isValidLeetcode(string s)
{
    bool isValid = false;
    string stack = ""; // es mas facil sacar substring i guess
    unordered_map<char, char> map = {{'}', '{'}, {')', '('}, {']', '['}};
    if (s.size() == 1)
    {
        return isValid;
    }
    int i = 1;
    int counter = 0;
    int n = s.size();
    while (s != "" && counter < n)
    {
        if (map.find(s[i]) != map.end() && (s[i - 1] == map.at(s[i]))) // si cierra y el anterior es su abre
        {
            s.erase(i - 1, 2);
            i = i - 2;
        }
        i++;
        counter++;
    }
    if (s == "")
    {
        isValid = true;
    }
    return isValid;
}

//Correct approach
bool isValidFast(string s)
{
    bool isValid = false;
    vector<char> stack;
    unordered_map<char, char> map = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] =='{'){
            stack.push_back(s[i]);
        }else{
            //cout <<map.at(stack[stack.size()-1]) << endl;
            if(!stack.empty() && map[stack[stack.size()-1]] == s[i]){//ultimo elemento añadido
                stack.pop_back();
            }else{
                return isValid;
            } 
        }
    }
    if(stack.size() == 0){
        isValid = true;
    }
    return isValid;
}

int main()
{

    string s = "(){}[]";  // true
    string s1 = "({[]})"; // true
    string s2 = "(]";     // false
    string s3 = "(])[";   // should return false
    string s4 = ")(){}";  // should return false

    cout << isValidFast(s) << endl;

    return 0;
}