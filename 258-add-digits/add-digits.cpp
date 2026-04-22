class Solution {
public:
    int addDigits(int num) {
        // int ans = 0;
        bool b = true;
        while(num >= 10)
        {
            int ans = 0;
            while(num > 0)
            {
                ans = ans + num % 10;
                num /= 10;
            }
            num = ans;
        }
    return num;
    }
};