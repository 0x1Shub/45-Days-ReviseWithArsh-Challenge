class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int max_area = 0;
        while (start < end)
        {
            int sh = height[start];
            int eh = height[end];
            int min_height = min(sh, eh);
            int area = min_height * (end - start);
            max_area = max(max_area, area);
            if (sh < eh)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return max_area;
    }
};