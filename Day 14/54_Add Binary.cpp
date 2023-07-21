class Solution
{
public:
    string addBinary(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        string s;
        if (n > m)
        {
            b = s.append(n - m, '0') + b;
        }
        else if (m > n)
        {
            a = s.append(m - n, '0') + a;
        }

        int carry = 0;
        string ans;

        for (int i = a.size() - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            ans = to_string(sum % 2) + ans;
            carry = sum / 2;
        }

        if (carry != 0)
        {
            ans = "1" + ans;
        }

        return ans;
    }
};