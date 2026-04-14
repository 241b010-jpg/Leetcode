class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If already computed
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> result;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                string leftExpr = expression.substr(0, i);
                string rightExpr = expression.substr(i + 1);

                vector<int> left = diffWaysToCompute(leftExpr);
                vector<int> right = diffWaysToCompute(rightExpr);

                for (int l : left) {
                    for (int r : right) {
                        if (op == '+') result.push_back(l + r);
                        else if (op == '-') result.push_back(l - r);
                        else if (op == '*') result.push_back(l * r);
                    }
                }
            }
        }

       
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return memo[expression] = result;
    }
};