class Solution {
public:

    // Returns the total number of hours
    // required when Koko eats k bananas/hour
    long long findHours(vector<int>& piles, int k) {

        long long hours = 0;

        for (int i = 0; i < piles.size(); i++) {

            // ceil(piles[i] / k)
            // = (piles[i] + k - 1) / k

            hours += (piles[i] + k - 1) / k;
        }

        return hours;
    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;

        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = findHours(piles, mid);

            if (hours <= h) {

                // mid works.
                // Try a smaller speed.
                high = mid - 1;

            } else {

                // mid is too slow.
                // Need a bigger speed.
                low = mid + 1;
            }
        }

        return low;
    }
};




/*

Example 2
piles = [30,11,23,4,20]
h = 5

There are 5 piles and only 5 hours.

Remember:

One pile always requires at least one hour.

Therefore, Koko essentially needs to finish each pile in exactly one hour.

The largest pile is:

30

Therefore:

k = 30

works:

30 → 1 hour
11 → 1 hour
23 → 1 hour
4  → 1 hour
20 → 1 hour

Total:

5 hours

So answer:

30
Example 3
piles = [30,11,23,4,20]
h = 6

Now Koko has 6 hours instead of 5.

Try:

k = 23

Calculate:

30 → ceil(30/23) = 2 hours
11 → ceil(11/23) = 1 hour
23 → ceil(23/23) = 1 hour
4  → ceil(4/23)  = 1 hour
20 → ceil(20/23) = 1 hour

Total:

2 + 1 + 1 + 1 + 1 = 6 hours

So 23 works.

Can we go slower?

Try 22:

30 → ceil(30/22) = 2
11 → 1
23 → 2
4  → 1
20 → 1

Total:

2 + 1 + 2 + 1 + 1 = 7

But only 6 hours are available.

So 22 doesn't work.

Therefore:

23 → works ✅
22 → doesn't work ❌

Answer:

23
🔥 The entire problem in one sentence

The problem is asking:

What is the smallest bananas-per-hour speed k such that the total number of hours required to finish every pile is at most h?

And for a given k:

Hours needed =
ceil(piles[0]/k)
+ ceil(piles[1]/k)
+ ...
+ ceil(piles[n-1]/k)

Then:

if total hours <= h
    k works → try smaller k

else
    k doesn't work → need bigger k

That's why this is a Binary Search on Answer problem.

*/