class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        int maxFreq = 0;
        for (auto& [c, f] : freq) maxFreq = max(maxFreq, f);

        int maxCount = 0;
        for (auto& [c, f] : freq) if (f == maxFreq) maxCount++;

        int frameBased = (maxFreq - 1) * (n + 1) + maxCount;
        return max((int)tasks.size(), frameBased);
    }
};