
class Solution:

	    def containsDuplicate(self, nums: List[int]) -> bool:

	        n = len(nums)

	 

	        for i in range(n):

	            for j in range(i+1, n):

	                if nums[i] == nums[j]:

	                    return True

	        return False

	        # Time Complexity: O(n^2)

	        # Space Complexity: O(1)

	        