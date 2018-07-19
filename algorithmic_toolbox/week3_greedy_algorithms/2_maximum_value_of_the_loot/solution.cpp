#include<iostream>
#include<iomanip>

using namespace std ;

void selectionSort(double values[], double weights[], int n)
{
    int i, j, min_idx, temp1, temp2;
    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if ( (double) (values[j] / weights[j]) > (double) (values[min_idx] / weights[min_idx]))
                min_idx = j;

        temp1 = values[i];
        values[i] = values[min_idx];
        values[min_idx] = temp1;

        temp2 = weights[i];
        weights[i] = weights[min_idx];
        weights[min_idx] = temp2;
    }
}

int main(){
    int n , capacity ;
    double total = 0 ;
    cin>>n>>capacity;
    double values[n] , weights[n] ;

    for(int i = 0 ; i < n ; i ++){
        cin>> values[i] >> weights[i] ;
    }

    selectionSort(values , weights , n);

    for(int i = 0 ; i < n ; i ++ ){
        if(weights[i] >= capacity){
            total += (double) ((capacity / weights[i]) * values[i]) ;
            break ;
        }
        else {
            capacity -= weights[i] ;
            total += values[i];
        }
    }
    
    cout << fixed << setprecision(4) << total ;

    return 0;
}