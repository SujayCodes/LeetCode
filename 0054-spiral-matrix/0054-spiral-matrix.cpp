class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int top = 0;
        int bottom = matrix.size() - 1;

        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {

            // 1. Traverse top row → 
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;


            // 2. Traverse right column ↓
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;


            // 3. Traverse bottom row ←
            // Check because the bottom row may already be traversed
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }


            // 4. Traverse left column ↑
            // Check because the left column may already be traversed
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};