#include <bits/stdc++.h>

using namespace std;
int jumpSearch(int arr[], int x, int n)
{
    // Finding block size to be jumped
    int jump_step = sqrt(n);

    // Finding the block where element is
    // present (if it is present)
    int prev = 0;
    while (arr[min(jump_step, n)-1] < x)
    {
        prev = jump_step;
        jump_step *=2;
        // in case of prev is bigger than n that
        // means the value not found
        if (prev >= n)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;
        // If we reached next block or end of
        // array, element is not present.
        if (prev == min(jump_step, n))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;

    return -1;
}
int main()
{
 int arr[] = { 0, 1, 3, 5, 8, 13, 21,34, 55};
    int x = 8;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, x, n);

    cout << " umber is at index " << index;     return 0;
}
