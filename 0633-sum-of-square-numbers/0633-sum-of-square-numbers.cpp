class Solution {
public:
    bool judgeSquareSum(int c) {
        long long lo = 0;
        long long hi = sqrt(c);
        while(lo<=hi){
            long long sum = (lo*lo)+ (hi*hi);
            if(sum==c) return true;
            else if(sum>c) hi--;
            else lo++;
        }
        return false;
    }
};


