#include<iostream>
using namespace std;

int *partition (int arr[], int low, int high)
{
    int pivot = arr[high] , temp;  
    int ans[2] = {0,0};
    int i = (low - 1) , ni = 0 ;
    cout<<"partition called";
    for (int j = low; j <= high- 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if(arr[j] == pivot){
                ni ++ ;
            }
        }
    }
    //swap(arr[i + 1], arr[high]);
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    ans[0] = i + 1 ;
    ans[1] = i + ni ;
    return ans;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi[2] = {0 , 0 }; 
        pi[0] = partition(arr, low, high)[0];
        pi[1] = partition(arr, low, high)[1];
 
        quickSort(arr, low, pi[0] - 1);
        quickSort(arr, pi[1] + 1, high);
    }
}

int main(){
    int n ; 
    cin >> n ;
    int arr[n];
    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for(int i = 0 ; i < 5 ; i ++){
        cout << "arr[i]" << " ";
    }
    return 0;
}