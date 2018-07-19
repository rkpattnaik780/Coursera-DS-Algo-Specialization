#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << n ;
    }
    else
    {
        int feeb_arr[n];
        feeb_arr[0] = 0;
        feeb_arr[1] = 1;
        for (int i = 2; i <= n ; i ++){
            feeb_arr[i] = feeb_arr[i-1] + feeb_arr[i-2];
        }
        cout<<feeb_arr[n];
    }
}