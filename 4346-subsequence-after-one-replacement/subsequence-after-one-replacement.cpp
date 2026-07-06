class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        if (n > m) return false;

        vector<int> pref(n), suff(n);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j == m) {
                pref[i] = m;
            } else {
                pref[i] = j;
                j++;
            }
        }

        if (pref[n - 1] != m) return true;

        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && t[j] != s[i]) j--;
            if (j < 0) {
                suff[i] = -1;
            } else {
                suff[i] = j;
                j--;
            }
        }

        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? -1 : pref[i - 1];
            int right = (i == n - 1) ? m : suff[i + 1];

            if (left < right - 1)
                return true;
        }

        return false;
    }
};