class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;  // Added boundary variables
        vector<int> result;

        while (top <= bottom && left <= right) {  // Fixed: added loop condition
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);  // Fixed: push_back (was pushback)
                }
                top++;
            }
            if (dir == 1) {
                for (int i = top; i <= bottom; i++) {  // Fixed: bottom (was down)
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);  // Fixed: bottom (was down)
                }
                bottom--;  // Fixed: bottom-- (was down--)
            }
            if (dir == 3) {
                for (int i = bottom; i >= top; i--) {  // Fixed: bottom (was down)
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if (dir == 4) {
                dir = 0;
            }
        }
        return result;
    }
};