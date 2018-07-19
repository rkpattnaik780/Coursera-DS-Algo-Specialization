#include <iostream>

using namespace std;

long long sumupton(long long n)
{
    long long remainder, a = 0, b = 1, c = a + b;
    remainder = (n + 2) % 60;
    if (remainder == 0)
        return 9;
    else if (remainder == 1)
        return 0;
    else
    {
        for (long long i = 2; i <= remainder; i++)
        {
            c = (a + b) % 10;
            a = b;
            b = c;
        }
        if (c == 0)
            return 9;
        else
            return c - 1;
    }
}

int subtraction(long long high, long long low)
{
    if (high >= low)
    {
        return high - low;
    }
    else
    {
        return 10 + high - low;
    }
}

int main()
{
    long long low, high, sumlow, sumhigh;
    cin >> low >> high;

    sumlow = sumupton(low - 1);
    sumhigh = sumupton(high);
    cout << subtraction(sumhigh, sumlow);

    return 0;
}