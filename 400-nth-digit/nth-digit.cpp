class Solution {
public:
    int findNthDigit(int n) {
        long long digitLength = 1;  
        long long count = 9;         
        long long start = 1;        

        
        while (n > digitLength * count) {
            n -= digitLength * count;
            digitLength++;
            count *= 10;
            start *= 10;
        }

        
        long long num = start + (n - 1) / digitLength;

        
        string s = to_string(num);
        return s[(n - 1) % digitLength] - '0';
    }
};
