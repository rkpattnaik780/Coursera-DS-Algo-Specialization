#include<iostream>

using namespace std;

long long pow_naive(int num, int n){
    long long ans = 1;
    if(n == 0) return ans;
    for(int i = 0; i < n; i ++){
        ans *= num;
    }
    return ans;
}

long long dac_pow(int num, int n){
    if(n == 0){
        return 1;
    }
    return num * dac_pow(num, n - 1);
}

long long dac_pow_by_2(int num, int n){
    if(n == 0) return 1;
    if(n == 1) return num;
    else if(n % 2 == 0){
        return dac_pow_by_2(num, n/2) * dac_pow_by_2(num, n/2);
    } else {
        return dac_pow_by_2(num, n/2 + 1) * dac_pow_by_2(num, n/2);
    }
}

int main(){

    int num, exp = 0;

    cin >> num >> exp;

    cout << pow_naive(num, exp) << endl;

    cout << dac_pow(num, exp) << endl;

    cout << dac_pow_by_2(num, exp) << endl;

    return 0;
}