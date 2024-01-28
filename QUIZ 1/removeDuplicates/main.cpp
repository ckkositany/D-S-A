#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int L = 1;

        for (int r = 1; r < nums.size(); ++r) {
            if (nums[r] != nums[r - 1]) {
                nums[L] = nums[r];
                ++L;
            }
        }

        return L;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = solution.removeDuplicates(nums);

    // Displaying the modified vector and the new length
    cout << "Modified vector: ";
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << "\nNew length: " << newLength << endl;

    return 0;
}
