class Solution {
public:
    long long sum = 0;        // sum of top k element
    set<pair<int, int>> main; // contains top-x freq, elements
    set<pair<int, int>> sec;  // contains remaining freq, leements

    void insertInSet(const pair<int, int>& p, int x) {
        if (main.size() < x || p > *main.begin()) {
            sum += p.first * 1LL * p.second;
            main.insert(p);
            if (main.size() > x) {
                auto smallest = *main.begin();
                sum -= smallest.first * 1LL * smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }

    void removeFromSet(const pair<int, int>& p, int x) {

        if (main.find(p) != main.end()) {
            sum -= p.first * 1LL * p.second;
            main.erase(p);
            if (!sec.empty()) {
                auto largest = *sec.rbegin();
                sec.erase(largest);
                main.insert(largest);
                sum += 1LL * largest.first * largest.second;
            }
        } else {
            sec.erase(p);
        }
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans;
        int i = 0;
        int j = 0;
        unordered_map<int, int> m; // element, freq
        while (j < n) {
            if (m[nums[j]] > 0) {
                removeFromSet({m[nums[j]], nums[j]}, x);
            }
            m[nums[j]]++;
            insertInSet({m[nums[j]], nums[j]}, x);

            if (j - i + 1 == k) {
                ans.push_back(sum);

                removeFromSet({m[nums[i]], nums[i]}, x);
                m[nums[i]]--;
                if (m[nums[i]] == 0) {
                    m.erase(nums[i]);
                } else {
                    insertInSet({m[nums[i]], nums[i]}, x);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};