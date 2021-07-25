// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
    public boolean isPossible(int[] target) {
        
        long sum = 0;
        PriorityQueue<Integer> maxHeap = new PriorityQueue<> ((a, b) -> b - a);
        
        for (int num : target) {
            sum += num;
            maxHeap.offer (num);
        }
        
        while (maxHeap.peek () != 1) {
            int curr = maxHeap.poll ();
            sum -= curr;
            if (sum == 1) {
                return true;
            }
            else if (sum == 0 || sum >= curr || curr % sum == 0) {
                return false;
            }
            
            curr %= sum;
            sum += curr;
            maxHeap.offer (curr);
        }
        
        return true;
    }
}