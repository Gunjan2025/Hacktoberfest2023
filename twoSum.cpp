#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    public: 
    vector<int> twoSum(vector<int>& nums, int target) {
        // find indices
        vector<int> result_indices;
        unordered_set<int> partial_sums;
        unordered_map<int, int> indices_map;

        // iterate once over all elements in nums
        for (size_t i = 0; i < nums.size(); i++) {
            int n = nums.at(i);
            // check if the target minus the current element is in the set sums
            // if that is the case a solution has been found because:
            // n + (target - n) == target
            const bool is_in = partial_sums.find(target - n) != partial_sums.end();
            if (is_in) {
                result_indices.push_back(i);
                result_indices.push_back(indices_map.at(target - n));
            }
            partial_sums.insert(n);
            indices_map.insert({n, i});
        }       

        return result_indices;
    }
};
