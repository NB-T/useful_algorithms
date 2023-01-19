#include <vector>

// returns maximum subarray sum
int kadane(const vector<int>& nums) {
	int ans = INT_MIN;
	int s = 0;
	for (int i : nums)
	{
		s = max(i, s + i);
		ans = max(ans, s);
	}
	return ans;
}
