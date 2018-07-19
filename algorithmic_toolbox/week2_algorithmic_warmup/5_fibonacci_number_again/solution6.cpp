#include <iostream>

using namespace std;



int main()
{
    long long n , remainder, a = 0, b = 1, c = a + b;
    cin >> n ;
    n = n + 2 ;
    remainder = n % 60 ;
    if (remainder == 0)
        cout << 9;
    else if (remainder == 1)
        cout << 0;
    else
    {
        for (long long i = 2 ; i <= remainder ; i++)
        {
            c = (a + b) % 10;
            a = b;
            b = c;    
        }
        if(c == 0) cout<< 9 ;
        else cout<< c - 1;
    }
}