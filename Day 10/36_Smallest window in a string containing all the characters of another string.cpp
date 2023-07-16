//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        int len1 = s.length();
        int len2 = p.length();
        if (len2 > len1)
            return "-1";
        vector<int> smp(26, 0);
        vector<int> pmp(26, 0);
        for (int i = 0; i < len2; i++)
        {
            char ch = p[i];
            pmp[ch - 'a']++;
        }
        int start = 0;
        int cnt = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;
        for (int i = 0; i < len1; i++)
        {
            char ch = s[i];
            smp[ch - 'a']++;
            if (smp[ch - 'a'] <= pmp[ch - 'a'])
            {
                cnt++;
            }
            if (cnt == len2)
            {
                // window is ready
                // minimize the window
                while (smp[s[start] - 'a'] > pmp[s[start] - 'a'] || pmp[s[start] - 'a'] == 0)
                {

                    if (smp[s[start] - 'a'] > pmp[s[start] - 'a'])
                    {
                        smp[s[start] - 'a']--;
                    }
                    start++;
                }
                // ans update
                int length = i - start + 1;
                if (length < ansLen)
                {
                    ansLen = length;
                    ansIndex = start;
                }
            }
        }
        if (ansIndex == -1)
            return "-1";
        return s.substr(ansIndex, ansLen);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends