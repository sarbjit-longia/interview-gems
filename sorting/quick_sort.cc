#include <iostream>

int partition(int arr[], int s, int e)
{
    int m = (( e - s)/ 2 )+ s;

    std::swap(arr[m], arr[s]);

    int ss = s + 1;
    int ee = e;

    while(ss <= ee)
    {
        while(ss <= ee && arr[ss] <= arr[s]) ss++;
        while(ss <= ee && arr[ee] > arr[s]) ee--;
        
        if( ss< ee) std::swap(arr[ss], arr[ee]);
    }
    std::swap(arr[ss-1], arr[s]);
    return ss-1;
}

void quick_sort(int arr[], int s, int e)
{
    if (s >= e) return;
    auto p = partition(arr, s, e);
    quick_sort(arr, s, p - 1);
    quick_sort(arr, p + 1, e);
}

int main(int argc, char* argv[])
{
    int arr[] = { 5, 2, -1, 0, 10, 23};
    quick_sort(arr, 0, 5);
    for(int i = 0; i < 6; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}