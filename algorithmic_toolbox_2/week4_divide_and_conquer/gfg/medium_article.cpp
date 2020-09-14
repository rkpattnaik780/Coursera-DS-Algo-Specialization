// https://medium.com/@daniel.oliver.king/learning-to-think-with-recursion-part-2-887bd4c41274

#include<iostream>

using namespace std;

void printArr(int arr[], int beg, int size){
    if(beg == size - 1) {
        cout << arr[beg];
    }
    else {
        cout << arr[beg] << " ";
        printArr(arr, beg + 1, size);
    }
    
}

int main(){

    int n;
    
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    printArr(arr, 0, n);

    cout << endl;

    return 0;
}