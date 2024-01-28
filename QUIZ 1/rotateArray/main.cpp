#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    solution.rotate(nums, k);

    // Displaying the rotated vector
    cout << "Rotated vector: ";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
