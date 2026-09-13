class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;

        while (top <= bottom && left <= right && head != NULL) {

            // left -> right
            for (int i = left; i <= right && head != NULL; i++) {
                ans[top][i] = head->val;
                head = head->next;
            }
            top++;

            // top -> bottom
            for (int i = top; i <= bottom && head != NULL; i++) {
                ans[i][right] = head->val;
                head = head->next;
            }
            right--;

            // right -> left
            if (top <= bottom) {
                for (int i = right; i >= left && head != NULL; i--) {
                    ans[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            // bottom -> top
            if (left <= right) {
                for (int i = bottom; i >= top && head != NULL; i--) {
                    ans[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }

        return ans;
    }
};