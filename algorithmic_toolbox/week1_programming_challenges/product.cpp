#include<iostream>
using namespace std;

int main(){
    int n , g1 = 0 , t = 0;
    long long temp = 0; 
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i ++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < n ; i ++){
        if(temp<arr[i]){
            temp = arr[i];
            g1 = i;
        }
    }
    t = arr[g1];
    arr[g1] = arr[n-1];
    arr[n-1] = t;
    temp = 0;
    for(int i = 0 ; i < n-1 ; i ++){
        if(temp < arr[i]){
            temp = arr[i];
        }
    }
    cout<<temp*arr[n-1];
    return 0;
}