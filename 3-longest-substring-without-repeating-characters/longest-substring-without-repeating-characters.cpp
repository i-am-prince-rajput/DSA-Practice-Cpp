class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int n = s.length();
        int l = 0;
        int maxlen = 0;

        for(int r = 0; r < n; r++) {
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);

            mpp[s[r]] = r;
        }

        return maxlen;
    }
};