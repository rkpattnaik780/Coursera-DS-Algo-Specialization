#include<iostream>

using namespace std ;

int get_change(int price){
    int total = 0 ;
    while(price > 0){
        if(price / 10 > 0){
            total += price / 10 ;
            price -= ((price/10) * 10) ;
        }
        else if(price / 5 > 0){
            total += price / 5 ;
            price -= ((price/5) * 5) ; 
        }
        else {
            total += price;
            break;
        }
    }
    return total ;
}

int main(){
    int price ;
    cin>>price;
    cout<<get_change(price);
    return 0 ;
}