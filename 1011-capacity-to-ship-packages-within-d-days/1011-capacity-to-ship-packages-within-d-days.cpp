class Solution {
public:
    int noOfdays(vector<int>& weights, int capacity){     // suppose  if i have given capacity then how much days will it take to ship the product
        int load = 0;
        int days = 1;
        for(int i=0;i<weights.size();i++){
            if(load + weights[i] > capacity){
                days++;
                load = weights[i];
            }
            else load += weights[i];
        }
        return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(),0);
        while(lo <=hi){
            int mid = lo + (hi-lo)/2;
            int reqdays = noOfdays(weights,mid);
            if(reqdays <=days){
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return lo;
    }
};