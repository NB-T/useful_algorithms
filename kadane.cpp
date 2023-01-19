#include <vector>

// returns maximum subarray sum
int kadane(const vector<int>& nums) {
	int ans = -10001;
	int s = 0;
	for (int i : nums)
	{
		s = max(i, s + i);
		ans = max(ans, s);
	}
	return ans;
}
