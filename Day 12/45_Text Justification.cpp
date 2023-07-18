class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        vector<vector<string>> lines;
        vector<int> spaces;

        vector<string> temp = {words[0]};
        int i = 1, prevLen = words[0].length();
        while (i < n)
        {
            int curWordLength = words[i].length();
            int prevLineSpaces = temp.size();
            if (prevLen + prevLineSpaces + curWordLength > maxWidth)
            {
                lines.push_back(temp);
                spaces.push_back(maxWidth - prevLen);
                prevLen = curWordLength;
                temp.clear();
                temp.push_back(words[i]);
            }
            else
            {
                prevLen += curWordLength;
                temp.push_back(words[i]);
            }
            i++;
        }
        lines.push_back(temp);
        spaces.push_back(maxWidth - prevLen);

        vector<string> ans;
        int sz = lines.size();
        for (int j = 0; j < sz; ++j)
        {
            int numberOfWords = lines[j].size();
            int sp = spaces[j];
            string cur;
            // if last line or contains a single character
            if (j == sz - 1 || numberOfWords == 1)
            {
                // left only justified
                for (int l = 0; l < numberOfWords; ++l)
                {
                    string s = lines[j][l];
                    cur += s;
                    if (sp)
                    {
                        cur += ' ';
                        sp--;
                    }
                }
                if (sp)
                    while (sp--)
                        cur += ' ';
            }
            else
            {
                int spExtra = sp % (numberOfWords - 1);
                sp = sp / (numberOfWords - 1);
                for (int l = 0; l < numberOfWords; ++l)
                {
                    string s = lines[j][l];
                    cur += s;
                    if (l != numberOfWords - 1)
                        for (int k = 0; k < sp; ++k)
                            cur += ' ';
                    if (spExtra)
                    {
                        cur += ' ';
                        spExtra--;
                    }
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }
};