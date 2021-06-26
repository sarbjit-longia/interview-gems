//https://www.geeksforgeeks.org/count-the-number-of-sub-arrays-such-that-the-average-of-elements-present-in-the-sub-array-is-greater-than-that-not-present-in-the-sub-array/
/*
Given an array of integers arr[], the task is to count the number of sub-arrays
such that the average of elements present in the sub-array is greater than the average
of elements that are not present in the sub-array.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to return the count of sub-arrays
// such that the average of elements present
// in the sub-array is greater than the
// average of the elements not present
// in the sub-array
int countSubarrays(int a[], int n)
{
    // Initialize the count variable
    int count = 0;

    // Initialize prefix sum array
    int pre[n + 1] = { 0 };

    // Preprocessing prefix sum
    for (int i = 1; i < n + 1; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = i; j < n + 1; j++) {

            // Calculating sum and count
            // to calculate averages
            int sum1 = pre[j] - pre[i - 1], count1 = j - i + 1;
            int sum2 = pre[n] - sum1, count2 = ((n - count1) == 0) ? 1 : (n - count1);

            // Calculating averages
            int includ = sum1 / count1;
            int exclud = sum2 / count2;

            // Increment count if including avg
            // is greater than excluding avg
            if (includ > exclud)
                count++;
        }
    }

    return count;
}

// Driver code
int main()
{
    int arr[] = { 6, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countSubarrays(arr, n);

    return 0;
}