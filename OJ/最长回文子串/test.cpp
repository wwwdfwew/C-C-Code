class Solution {
public:
    bool _parlindrome(string& s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int end = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (_parlindrome(s, j, i) && (end - left < i - j))
                {
                    left = j;
                    end = i;
                }
            }
        }
        return s.substr(left, end - left + 1);
    }

};