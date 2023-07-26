//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    // Function to find minimum number of pages.
    bool isAllocationPossible(int barrier, int arr[], int n, int students)
    {
        int allocatedStudents = 1, pages = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > barrier)
                return false;
            if (pages + arr[i] > barrier)
            {
                allocatedStudents++;
                pages = arr[i];
            }
            else
                pages += arr[i];
        }
        if (allocatedStudents > students)
            return false;
        return true;
    }

    int findPages(int arr[], int n, int students)
    {
        if (n < students)
            return -1;
        int low = arr[0], high = 0;
        for (int i = 0; i < n; i++)
        {
            high += arr[i];
            if (arr[i] < low)
                low = arr[i];
        }

        int mid, res = -1;
        while (low <= high)
        {
            mid = (low + high) >> 1;

            if (isAllocationPossible(mid, arr, n, students))
            {
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends