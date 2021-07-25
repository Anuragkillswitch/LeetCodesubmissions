// https://leetcode.com/problems/create-target-array-in-the-given-order

class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        ArrayList<Integer> list = new ArrayList<>();
		
		for(int i = 0; i < nums.length; i++) {
			list.add(index[i], nums[i]);
		}
		
		int result[] = new int[nums.length];
		for(int i = 0; i < result.length; i++) {
			result[i] = list.get(i);
		}
		
		return result;
    }
}