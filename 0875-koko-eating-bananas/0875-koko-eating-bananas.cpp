class Solution {
public:
    long long findhours(vector<int>& piles, int k){    // provided with speed k , how much hour will koko take to finish
        long long hours = 0;
        for(int i=0;i<piles.size();i++){
            hours += (piles[i]+ k-1)/k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1; 
        long long hi = *max_element(piles.begin(), piles.end());
        while(lo<=hi){
            long long mid = lo +(hi-lo)/2;
            long long hourstaken = findhours(piles, mid);
            if(hourstaken<=h){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return lo;
    }
};