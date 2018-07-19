#include<iostream>
using namespace std;

long long get_max(long long a ,long long b){
    return a >= b ? a : b ;
}

int lcs_length(long long a[] , long long b[] , int a_size , int b_size){
    int table[a_size+1][b_size+1];
    int i = 0 , j = 0 ;
    
    for( i = 0 ; i <= a_size ; i ++){
        for(j = 0 ; j <= b_size ; j ++){
            if(i == 0 || j == 0){
                table[i][j] = 0 ;
            }else if(a[i-1] == b[j-1]){
                table[i][j] = table[i-1][j-1] + 1;
            }else{
                table[i][j] = get_max(table[i-1][j] , table[i][j-1]);
            }
        }
    }

    /*for( i = 0 ; i <= a_size ; i ++){
        for(j = 0 ; j <= b_size ; j ++){
           cout<<table[i][j] << " ";
        }
        cout << "\n" ;
    }*/

    return table[a_size][b_size];
}

int main(){
    long long a[100] , b[100] ;
    int a_size , b_size ;
    cin >> a_size;
    for(int i = 0 ; i < a_size ; i ++ ){
        cin >> a[i];
    }
    cin >> b_size;
    for(int i = 0 ; i < b_size ; i ++){
        cin >> b[i];
    }
    cout << lcs_length( a, b , a_size , b_size);
    return 0;
}