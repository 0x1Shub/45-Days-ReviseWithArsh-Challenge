//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
private:
    vector<int> nextSmallerElements(int *arr, int size)
    {

        vector<int> ans(size);

        stack<int> st;
        st.push(-1);

        for (int i = size - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] >= curr)
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElements(int *arr, int size)
    {

        vector<int> ans(size);

        stack<int> st;
        st.push(-1);

        for (int i = 0; i < size; i++)
        {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] >= curr)
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    int largestRectangle(int *heights, int size)
    {

        vector<int> next(size);
        next = nextSmallerElements(heights, size);
        vector<int> prev(size);
        prev = prevSmallerElements(heights, size);

        int area = INT_MIN;

        for (int i = 0; i < size; i++)
        {
            int len = heights[i];

            if (next[i] == -1)
            {
                next[i] = size;
            }
            int breadth = next[i] - prev[i] - 1;
            int newArea = len * breadth;
            area = max(area, newArea);
        }

        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here

        int area = largestRectangle(M[0], m);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] != 0)
                {
                    M[i][j] = M[i][j] + M[i - 1][j];
                }
                else
                {
                    M[i][j] = 0;
                }
            }
            int newArea = largestRectangle(M[i], m);
            area = max(area, newArea);
        }

        return area;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends