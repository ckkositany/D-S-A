#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;

        for (int n : nums) {
            if (hashset.find(n) != hashset.end()) {
                return true;
            }
            hashset.insert(n);
        }

        return false;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {1, 2, 3, 4, 5, 2};
    bool hasDuplicates = solution.containsDuplicate(nums);

    if (hasDuplicates) {
        cout << "The array contains duplicates.\n";
    } else {
        cout << "The array does not contain duplicates.\n";
    }

    return 0;
}
