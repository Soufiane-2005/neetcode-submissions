class Solution {
public:
    int lengthOfLongestSubstring(string s) {



        int n = s.size();

        if (n == 0) return 0;

        int best = 0;

        int left = 0;
        int right = 0;

        unordered_set<char> seen;

        while (right < n) {

            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left++;
            }  

            seen.insert(s[right]);

            best = max(best, right - left + 1);

            right++;
        }

        return best;
        }
};
