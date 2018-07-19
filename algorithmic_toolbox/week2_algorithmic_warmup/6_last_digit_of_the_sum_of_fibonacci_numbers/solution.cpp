#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n < 2)
    {
        cout << n ;
    }
    else
    {   int temp = 1 ;
        long long i = 2;
        int t1 = 0 , t2 = 1 , t3;
        while( i <= n){
            t3 = t2 + t1 ;
            temp += (t3%10);
            i++;
            if(i > n) break;
            t1 = t3 + t2;
            temp += (t1%10);
            i++;
            if(i > n) break;
            t2 = t1 + t3;
            temp += (t2%10);
            i++;
            if(i > n) break;
            cout<<i<<" ";
        }
        cout<<temp % 10;
    }
}