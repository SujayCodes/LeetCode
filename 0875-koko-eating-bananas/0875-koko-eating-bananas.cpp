class Solution {
public:

    // Calculate total hours needed if Koko eats k bananas/hour
    long long hourstaken(vector<int>& piles, int k) {

        long long hours = 0;                 // Stores total hours

        for(int i = 0; i < piles.size(); i++) { // Visit every banana pile

            // Hours for this pile = ceil(piles[i] / k)
            // (piles[i] + k - 1) / k performs ceiling division
            hours += (piles[i] + k - 1) / k;
        }

        return hours;                        // Return total hours needed
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int lo = 1;                          // Minimum possible speed = 1

        // Maximum possible useful speed = largest pile
        int hi = *max_element(piles.begin(), piles.end());


        // Binary search while search space is valid
        while(lo <= hi) {

            // Find middle eating speed
            int mid = lo + (hi - lo) / 2;

            // Calculate hours needed at speed = mid
            long long hr = hourstaken(piles, mid);


            // If Koko can finish within h hours
            if(hr <= h) {

                // mid works, but try an even smaller speed
                hi = mid - 1;
            }

            else {

                // mid is too slow, so increase the speed
                lo = mid + 1;
            }
        }

        // lo is the smallest speed that can finish within h hours
        return lo;
    }
};