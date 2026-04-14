class Solution {
public:
    int calculate(string s) {
        int num = 0, last = 0, result = 0;
        char op = '+';
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    result += last;
                    last = num;
                } 
                else if (op == '-') {
                    result += last;
                    last = -num;
                } 
                else if (op == '*') {
                    last = last * num;
                } 
                else if (op == '/') {
                    last = last / num;
                }
                
                op = c;
                num = 0;
            }
        }
        
        return result + last;
    }
};