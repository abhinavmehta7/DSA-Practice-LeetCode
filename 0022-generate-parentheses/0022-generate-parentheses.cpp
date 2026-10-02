class Solution {
public:
vector<string> v;
    void parenthesis(string &t,int a,int b){
        if(a==0 && b==0){
            v.push_back(t);
            return;
        }
        if(a>0){
            t.push_back('(');
            parenthesis(t,a-1,b);
            t.pop_back();
        }
        if(b>a & b>0 ){
            t.push_back(')');
            parenthesis(t,a,b-1);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string t;
        parenthesis(t,n,n);
        return v;
    }
};