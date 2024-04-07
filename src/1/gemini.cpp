#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(const vector<int>& nums) {
        unordered_map<int, vector<int>> hash_table;

        for (int i = 0; i < nums.size(); ++i) {
            hash_table[nums[i]].push_back(i);
        }

        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int target = -nums[i] - nums[j];

                if (hash_table.count(target)) {
                    for (int k : hash_table[target]) {
                        if (k > j) {
                            result.push_back({nums[i], nums[j], nums[k]});
                        }
                    }
                }
            }
        }

        return result;
    }
};