//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;
        int val = 0;
        int mini = 1e9;
        for (int i = n - 2; i >= 0; i--)
        {
            val = 0;
            mini = 1e9;
            for (int j = i; j < n; j++)
            {
                val = val + nums[j];
                int gap = j - i;
                if (val + gap <= k && j < nums.size() - 1)
                {
                    int cost = pow(k - (val + gap), 2) + dp[j + 1];
                    mini = min(mini, cost);
                }
                else if (val + gap <= k && j == nums.size() - 1)
                {
                    dp[i] = 0;
                }
            }
            if (dp[i] != 0)
            {
                dp[i] = mini;
            }
        }
        return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends