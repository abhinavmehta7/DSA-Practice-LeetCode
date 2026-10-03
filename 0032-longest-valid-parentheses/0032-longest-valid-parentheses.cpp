class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> stack = {-1};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') stack.push_back(i);
            else {
                stack.pop_back();
                if (stack.empty()) stack.push_back(i);
                else ans = max(ans, i - stack.back());
            }
        }
        return ans;
    }
};