// https://leetcode.com/problems/jump-game-vi




class Solution {
    public int maxResult(int[] nums, int k) {
       Queue<int[]> pq = new PriorityQueue<>((a,b)->b[0]-a[0]);
        pq.offer(new int[]{nums[0],0});
        int max=nums[0];
        for(int i=1;i<nums.length;i++)
        {
            while(pq.peek()[1]<i-k)
            {
                pq.poll();
            }
            int[] cur = pq.peek();
            max=cur[0]+nums[i];
            pq.offer(new int[]{cur[0]+nums[i],i});
        }
        return max;
    }
}