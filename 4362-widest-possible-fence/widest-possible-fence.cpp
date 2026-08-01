class Solution {

    int help1(long long target, vector<int>& planks) {
    int i = 0;
    int j = planks.size() - 1;
    int ans = 0;

    while (i <= j) {

        // Too large, cannot be used.
        if (planks[j] > target) {
            j--;
        }

        // Use this plank alone.
        else if (planks[j] == target) {
            ans++;
            j--;
        }

        // Need to pair the largest remaining plank.
        else {
            if (i == j) break;

            long long sum = 1LL * planks[i] + planks[j];

            if (sum == target) {
                ans++;
                i++;
                j--;
            }
            else if (sum < target) {
                i++;
            }
            else { // sum > target
                j--;
            }
        }
    }

    return ans;
}

    int help(long long mid, vector<int>& planks) {

        int n = planks.size();
        int i = 0;
        int j = n - 1;

        int ans = 0;
        while (j > i && planks[j] > mid)
            j--;
        while (i < j) {

            if (1LL * planks[i] + planks[j] == mid) {
                ans++;
                i++;
                j--;
            } else if (planks[i] == mid) {
                i++;
                ans++;
            } else if (planks[j] == mid) {
                ans++;
                j--;
            } else if (1LL * planks[i] + planks[j] > mid) {
                j--;
            } else if (1LL * planks[i] + planks[j] < mid) {
                i++;
            }
        }

        if (i == j && planks[i] == mid) {
            ans++;
        }

        // cout << mid << " - " << ans << endl;

        return ans;
    }

public:
    int maximumWidth(vector<int>& planks) {

        sort(planks.begin(), planks.end());

        int n = planks.size();
        if (n == 1)
            return 1;
        if (planks[0] == planks[n - 1])
            return n;

        int ans = 1;

        // unordered_set<long long> spp;
        map<long long, int> mpp;
        // long long high = planks[n-1] * planks[n-2];

        for (int i = 0; i < n; i++) {
            mpp[planks[i]]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mpp[(planks[i] + planks[j])]++;
                ;
            }
        }

        vector<pair<int , long long> > arr;

        for (auto& [a, b] : mpp) {
            arr.push_back({b , a });
        }

        sort(arr.begin() , arr.end());
        int m = arr.size();

for (int i = m - 1; i >= 0; i--) {
    auto &[cnt, target] = arr[i];

    if (cnt <= ans)
        break;          // impossible to beat current answer

    ans = max(ans, help(target, planks));
}

        
        return ans;
    }
};