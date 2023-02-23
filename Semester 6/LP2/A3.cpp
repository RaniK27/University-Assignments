#include<iostream>

using namespace std;

void SelectionSort(int ar[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if(ar[min] > ar[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int temp = ar[min];
            ar[min] = ar[i];
            ar[i] = temp;
        }
    }
}

int main()
{
    int n, num;
    cout<<"Selection Sort\n";
    cout<<"Please enter the size of the array.\nSize of Array: ";
    cin>>n;
    int ar[n];
    cout<<"\nPlease enter the elements of the array.";
    for(int i = 0; i < n; i++)
    {
        cout<<"\nElement: ";
        cin>>ar[i];
    }
    cout<<"\nUnsorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    SelectionSort(ar, n);
    cout<<"\nSorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    return 0;
}
