#include<iostream>

using namespace std;

int binarysearch(int x , int size , long arr[]);

int main (){
    int n , k ;
    cin >> n ;
    long arr[n] ;
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i] ;
    }
    cin >> k ; 
    long searches[k];
    for(int i = 0 ; i < k ; i ++){
        cin >> searches[i] ;
    }
    for( int i = 0 ; i < k ; i ++){
       cout<<binarysearch(searches[i] , n , arr) << " " ; 
       //cout<< arr[i];
    }

    return 0 ;
}

int binarysearch(int num , int size , long arr[]){
    int beg = 0 , end = size - 1 , mid;
    while(beg <= end){
        mid = beg + (end - beg)/2 ;
        if(num == arr[mid]){
             return mid ;
        }else if(num < arr[mid]){
            end = mid - 1;
        }else if(num > arr[mid]){
            beg = mid + 1;
        }    
    }
    if(beg > end){
        return -1 ;
    }
}