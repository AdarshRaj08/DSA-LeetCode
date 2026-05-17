class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<char> letters;

        for(int i=0; i<n; i++)
        {
            letters.insert(s[i]);
        }

        int result = 0;

        for(char letter : letters)
        {
            int left_index  = -1;
            int right_index = -1;
            for(int i=0; i<n; i++)
            {
                if(s[i] == letter)
                {
                    if(left_index == -1)
                        left_index = i;
                    
                    right_index = i;
                }
            }
            unordered_set<char> count;
            for(int i=left_index+1; i <= right_index-1; i++)
            {
                count.insert(s[i]);
            }

            result += count.size();
        }
        return result;
    }
};