// https://medium.com/swlh/how-to-think-recursively-solving-recursion-problems-in-4-steps-95a6d07aa866


#include<iostream>

using namespace std;

int sumToN(int n){
    if(n == 1) return 1;

    return n + sumToN(n-1);
}

int main(){

    int n;

    cin >> n;

    cout << sumToN(n) << endl;

    return 0;
}