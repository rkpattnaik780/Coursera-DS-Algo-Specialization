#include <iostream>

using namespace std;

long long getpisanoperiod(long long d)
{
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < d * d; i++)
    {
        c = (a + b) % d;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
}

int main()
{
    long long n, d, period, remainder, a = 0, b = 1, c = a + b;
    cin >> n >> d;
    period = getpisanoperiod(d);
    remainder = n % period;
    if (remainder == 0)
        cout << 0;
    else if (remainder == 1)
        cout << 1;
    else
    {
        for (long long i = 2 ; i <= remainder ; i++)
        {
            c = (a + b) % d;
            a = b;
            b = c;    
        }
        cout<<c;
    }
}