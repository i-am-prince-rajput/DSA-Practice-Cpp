class Solution {
public:
    bool canJump(vector<int>& nums) {
        int naxsize=0;
        for(int i=0;i<nums.size();i++){
            if(i>naxsize){
                return false;
            }
            naxsize=max(naxsize,i+nums[i]);
        }
        return true;
        
    }
};