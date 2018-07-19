#include <iostream>

using namespace std;

void selectionSort(long long beg[], long long end[], int n)
{
    int i, j, min_idx, temp1, temp2;
    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (beg[j] < beg[min_idx])
                min_idx = j;

        temp1 = beg[i];
        beg[i] = beg[min_idx];
        beg[min_idx] = temp1;

        temp2 = end[i];
        end[i] = end[min_idx];
        end[min_idx] = temp2;
    }
}

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int n, counter = 0, i = 0, j = 0;
    cin >> n;
    long long beg[n], end[n], points[n], start, finish, seg_end;
    for (i = 0; i < n; i++)
    {
        cin >> beg[i] >> end[i];
    }
    selectionSort(beg, end, n);
    i = 1 ;
    start = beg[0] ;
    finish = end[0] ;
    while(i < n - 1 ){
        if( finish >= beg[i]){
            finish = min(finish , end[i]);
            i ++ ;
        }
        else {
            cout<< "finish - " << finish<<endl;
            points[counter] = finish ;
            counter ++ ;
            finish = end[i] ;
            i ++ ;
        }
    }
    if(beg[i] > finish){
        cout<<"finish"<<finish<<endl;
        points[counter] = end[i];
        counter ++ ;
    }
    
    
    cout << counter + 1<< endl;
    for (int i = 0; i < counter; i++)
    {
        cout << points[i] << " ";
    }


    return 0;
}
