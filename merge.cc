#include <iostream>

void merge(int arr[], int s, int m, int e)
{
    int* temp = new int[e - s + 1];
    int mm = m + 1;
    int ss = s;
    int count = 0;
    while(ss <= m && mm <= e)
    {
        if(arr[ss] < arr[mm])
        {
            temp[count++] = arr[ss++];
        }
        else
        {
            temp[count++] = arr[mm++];
        }
    }

    while(ss <= m) temp[count++] = arr[ss++];
    while(mm <= e ) temp[count++] = arr[mm++];

    memcpy(&arr[s], temp, sizeof(int) * (e - s + 1));
    delete[] (temp);
}

void merge_sort(int* arr, int s, int e)
{
    if(e > s)
    {
        int m = ((e - s) / 2) + s;
        merge_sort(arr, s, m);
        merge_sort(arr, m + 1, e);
        merge(arr, s, m, e);
    }
}

int main(int argc, char* argv[])
{
    int arr[] = { -1, 4, 2, 6, 8, 0};
    merge_sort(arr, 0, 5);
    for(int i = 0; i < 6; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
    return 0;
}