// Given heights of n towers and a value k. We need to either increase or
// decrease height of every tower by k (only once) where k > 0. The task is to
// minimize the difference between the heights of the longest and the shortest
// tower after modifications, and output this difference.

#include <iostream>
#include <vector>

using namespace std;

int getMinDiff(int arr[], int n, int k) {
    // There should be at least two elements
    if (n <= 1)
        return 0;

    // Sort array in increasing order
    sort(arr, arr+n);

    // Initialize maximum and minimum
    int maxe = arr[n-1];
    int mine = arr[0];

    // If k is more than difference between maximum 
    // and minimum, add/subtract k to all elements
    // as k cannot decrease the difference
    if (k >= maxe - mine) {
        for (int i=0; i<n; i++)
            arr[i] += k; // Subtract would also work
        return (maxe - mine);
    }

    // In sorted array, first element is minimum
    // and last is maximum, we must add k to minium
    // and subtract k from maximum
    arr[0]   += k;
    arr[n-1] -= k;

    // Initialize max and min of modified array (only
    // two elements have been finalized)
    int new_max = max(arr[0], arr[n-1]);
    int new_min = min(arr[0], arr[n-1]);

    // Finalize middle n-2 elements
    for (int j=1; j<n-2; j++) {
        // If current element is less than min of
        // modified array, add k.
        if (arr[j] < new_min)
            arr[j] += k;

        // If current element is more than max of
        // modified array, subtract k.
        else if (arr[j] > new_max)
            arr[j] -= k;

        // arr[j] is between new_min and new_max
        // If arr[j] is closer to new_max, subtract k
        else if ((arr[j] - new_min) > (new_max - arr[j]))
            arr[j] -= k;

        // Else add k
        else
            arr[j] += k;

        // Update new_max and new_min if required
        new_max = max(arr[j], new_max);
        new_min = min(arr[j], new_min);
    }

    // Returns difference between new_max and new_min
    return (new_max - new_min);
}
 
int main() {
    int arr[] = {4, 6, 7, 9, 11, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 10;
    cout << "Maximum difference is: " << getMinDiff(arr, n, k) << endl;

    return 0;
}

// end of file
