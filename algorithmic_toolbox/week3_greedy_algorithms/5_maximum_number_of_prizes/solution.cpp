#include<iostream>

using namespace std ;

int main(){
    long long counter = 1 , final_num = 0;
    long long n ;
    cin >> n ; 
    while(n > 0){
        if ( n >= counter + counter + 1){
            n -= counter ;
            counter ++ ;
        }
        else{
            final_num = n ;
            n = 0 ;
            break ;
        }

    }
    cout<<counter<<endl ;
    for(long long i = 1 ; i < counter  ; i ++ ){
        cout<<i<<" ";
    }
    cout<<final_num;
    return 0;
}