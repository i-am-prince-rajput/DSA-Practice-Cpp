class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> leftMax(n), rightMax(n);
        
        // fill left max
        leftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        // fill right max
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        int total = 0;
        
        // calculate water
        for(int i = 0; i < n; i++){
            total += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return total;
    }
};