#include<iostream>

using namespace std;

int power(int num, int n){
    if(n == 0) return 1;
    else{
        return num * power(num, n-1);
    }
}

int main(){

    int num, n;

    cin >> num >> n;

    cout << power(num, n) << endl;

    return 0;
}