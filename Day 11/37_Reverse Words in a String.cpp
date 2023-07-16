class Solution
{
public:
    string reverseWords(string s)
    {
        string result = "";
        int n = s.size();
        int i = 0;
        while (i < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            int j = i;
            while (j < n && s[j] != ' ')
                j++;
            string str = s.substr(i, j - i);
            if (result.size() == 0)
                result = str;
            else
                result = str + " " + result;
            i = j + 1;
        }
        return result;
    }
};