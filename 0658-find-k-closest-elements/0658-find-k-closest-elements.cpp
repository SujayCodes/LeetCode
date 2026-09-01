class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int,int>> pq;     //     <dist,ele>
        for(int ele : arr){
            int dist = abs(x-ele);
            pq.push({dist,ele});
            if(pq.size()>k) pq.pop();
        }
        
        while(pq.size()!=0){
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};