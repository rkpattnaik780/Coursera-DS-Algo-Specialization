#include <iostream>
#include <vector>
#include <cstdlib>

using std::swap;
using std::vector;
using namespace std;

vector<int> partition2(vector<int> &a, int l, int r)
{
  int x = a[l];
  int i = l, left = l, right = r;
  vector<int> indices(2);
  while (i <= right)
  {
    if (a[i] < x)
    {
      swap(a[left], a[i]);
      left++;
      i++;
    }
    else if (a[i] == x)
    {
      i++;
    }
    else
    {
      swap(a[i], a[right]);
      right--;
    }
    indices[0] = left;
    indices[1] = right;
  }
  return indices;
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
  {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m = partition2(a, l, r);

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    cout << a[i] << ' ';
  }
}
