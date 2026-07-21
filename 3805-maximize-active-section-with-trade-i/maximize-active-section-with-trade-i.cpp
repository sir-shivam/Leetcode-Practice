class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;

        for (char c : s)
            if (c == '1')
                ones++;

        vector<int> zeroBlocks;

        int i = 0, n = s.size();

        while (i < n) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0')
                    j++;
                zeroBlocks.push_back(j - i);
                i = j;
            } else {
                while (i < n && s[i] == '1')
                    i++;
            }
        }

        if (zeroBlocks.size() < 2)
            return ones;

        int best = 0;

        for (int i = 0; i + 1 < zeroBlocks.size(); i++)
            best = max(best, zeroBlocks[i] + zeroBlocks[i + 1]);

        return ones + best;
    }
};