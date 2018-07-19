#include <iostream>
#include <vector>

using std::vector;
using namespace std;

vector<int> intermediates(int n)
{

    vector<int> table(n + 1);
    vector<int> predecessor(n + 1);
    table[0] = 0;
    table[1] = 0;
    predecessor[0] = 0;
    predecessor[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int min = i;
        table[i] = i;
        if (i % 2 == 0)
        {
            if (min >= table[i / 2] + 1)
            {
                min = table[i / 2] + 1;
                predecessor[i] = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (min >= table[i / 3] + 1)
            {
                min = table[i / 3] + 1;
                predecessor[i] = i / 3;
            }
        }
        else
        {
            if (min >= table[i - 1] + 1)
            {
                min = table[i - 1] + 1;
                predecessor[i] = i - 1;
            }
        }
        table[i] = min;
    }

    vector<int> backtrack_arr;
    int backtrack = n;
    backtrack_arr.push_back(backtrack);
    while (backtrack != 1)
    {
        backtrack = predecessor[backtrack];
        backtrack_arr.push_back(backtrack);
    }

    return backtrack_arr;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> sequence = intermediates(n);
    std::cout << sequence.size() - 1 << std::endl;
    int backtrack = n;
    for (int i = sequence.size() - 1 ; i >= 0 ; --i) {
        std::cout << sequence[i] << " ";
    }
}
