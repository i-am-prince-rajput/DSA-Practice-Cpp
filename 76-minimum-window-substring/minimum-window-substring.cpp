class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mpp;

        for (char c : t) {
            mpp[c]++;
        }

        int l = 0, r = 0;
        int count = 0;
        int minlen = INT_MAX;
        int sindex = -1;

        while (r < n) {
            if (mpp[s[r]] > 0) {
                count++;
            }
            mpp[s[r]]--;

            while (count == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }

                mpp[s[l]]++;
                if (mpp[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        if (sindex == -1) return "";
        return s.substr(sindex, minlen);
    }
};