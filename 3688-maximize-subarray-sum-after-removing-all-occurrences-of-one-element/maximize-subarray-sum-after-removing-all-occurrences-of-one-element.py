import collections

class Solution:
    def maxSubarraySum(self, nums):
        # Dictionary to store prefix sums with default value 0
        prefix_sums = collections.defaultdict(lambda: 0)
        prefix_sums[0] = 0

        res = float('-inf')  # Initialize the result with negative infinity
        pre_sum = 0          # Running sum of the subarray
        lowest = 0           # The lowest prefix sum encountered so far

        for num in nums:
            pre_sum += num  # Update the running sum
            # Calculate the maximum subarray sum using the current running sum and the lowest prefix sum
            res = max(res, pre_sum - lowest)

            if num < 0:
                # Update the prefix sum for negative numbers to include the minimum of the previous values
                prefix_sums[num] = num + min(prefix_sums.get(num, 0), prefix_sums[0])
                lowest = min(lowest, prefix_sums[num])

            # Update the prefix sum for 0 (used to track the smallest running sum encountered)
            neg_pre_sum = prefix_sums[0]
            prefix_sums[0] = min(neg_pre_sum, pre_sum)
            lowest = min(lowest, neg_pre_sum)

        return res
