class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            if(n==101){
                n--;
                break;
            }
            int prod=1;
            int k=n;
            while(k!=0){
                prod*=(k%10);
                k/=10;
            }
            if(prod%t==0) return n;
            else n++;
        }
        return n;
    }
};