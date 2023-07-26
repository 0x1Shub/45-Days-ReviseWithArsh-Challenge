//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int countInv(int arr[], int l, int r)
    {
        int res = 0;
        if (l < r)
        {
            int m = l + (r - l) / 2;
            res += countInv(arr, l, m);
            res += countInv(arr, m + 1, r);
            res += countAmerge(arr, m, l, r);
        }
        return res;
    }
    int countAmerge(int arr[], int m, int l, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int left[n1];
        int right[n2];
        for (int i = 0; i < n1; i++)
        {
            left[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++)
        {
            right[i] = arr[m + 1 + i];
        }
        int res = 0, i = 0;
        int j = 0;
        int k = l;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
                res = res + (n1 - i);
            }

            k++;
        }
        while (i < n1)
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
        return res;
    }

    int countSwaps(int arr[], int n)
    {
        return countInv(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.countSwaps(arr, n);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends