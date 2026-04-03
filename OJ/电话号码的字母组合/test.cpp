class Solution {
    string* s = new string[10]{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    // string s[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void Combine(string digits, size_t level, string combineStr, vector<string>& v)
    {
        if (level == digits.size())
        {
            v.push_back(combineStr);
            return;
        }
        size_t num = digits[level] - '0';
        string str = s[num];
        for (size_t i = 0; i < str.size(); i++)
        {
            Combine(digits, level + 1, combineStr + str[i], v);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if (digits.empty())
            return v;
        Combine(digits, 0, "", v);
        return v;
    }
};