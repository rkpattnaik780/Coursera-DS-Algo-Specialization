#include<iostream>

using namespace std;

bool checkPallindrom(string s, int beg, int end) {

    if(beg >= end){
        return true;
    }

    if(s[beg] == s[end]){
        return checkPallindrom(s, beg + 1, end - 1);
    }

    return false;

}

int main() {
    string name;

    cin >> name;

    cout << checkPallindrom(name, 0, name.length() - 1) << endl;

    return 0;
}