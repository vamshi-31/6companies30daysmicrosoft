class Solution{
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> divisible;
    for (int x : nums) {
        // Find the length of the largest divisible subset ending at x - 1
        int len = 0;
        for (int y : divisible) {
            if (y % x == 0) {
                len++;
            }
        }
        // Find the largest divisible subset ending at x - 1 such that x is divisible by the elements in the subset
        vector<int> temp;
        for (int y : divisible) {
            if (x % y == 0) {
                temp.push_back(y);
            }
        }
        // If the length of temp is greater than len, update divisible to be temp
        if (temp.size() > len) {
            divisible = temp;
        }
        // Add x to divisible
        divisible.push_back(x);
    }
    return divisible;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> divisible = largestDivisibleSubset(nums);
    for (int x : divisible) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
};
