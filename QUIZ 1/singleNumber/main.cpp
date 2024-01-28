#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};

int main() {
    Solution solution;

    // Example usage:
    vector<int> nums = {4, 2, 1, 2, 1};
    int result = solution.singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}
