class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = (n * (n + 1)) / 2;
        int x = sqrt(totalSum);
        if (x * x == totalSum) {
            return x;
        }
        return -1;
    }
};