#include <iostream>
#include <string>

using namespace std;

int lenghtOfLastWord(string s){
    int last = 1;
    int count = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            count++;
        }else{
            last = count;
            //revisar si la palabra ya se acabo retornar last??
            count = 0;
        }
    }
    //si la palabra no se ha acabado y solo quedan espacios retornar count
    last = count;
    return last;
}

int main(){

    //cout << lenghtOfLastWord("Hello worldd    ") << endl;
    cout << lenghtOfLastWord("luffy is still joyboy") << endl;
    return 0;
}