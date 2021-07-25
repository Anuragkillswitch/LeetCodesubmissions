// https://leetcode.com/problems/minimum-time-difference

class Solution {
    public int findMinDifference(List<String> timePoints) {
        boolean[] visited = new boolean[24 * 60];
        for (String time : timePoints) {
            int h = Integer.parseInt(time.substring(0, 2));
            int m = Integer.parseInt(time.substring(3));
            if (visited[h * 60 + m]) return 0; // if visited before return 0 
            visited[h * 60 + m] = true; // mark as visited
        }
        
        int prev = 0, min = Integer.MAX_VALUE;
        int first = 0, last = 0;
        int idx = visited.length - 1; // find last first, so idx points to the end
        
        // find the last true from the back, or the last number(max minutes)
        while(!visited[idx])
            idx--;  
        last = idx;
        
        // find the first true, or the first number(min minutes)
        idx = 0;
        while(!visited[idx])
            idx++;
        first = idx;
        
        prev = first;
        for(int i = first + 1; i <= last; i++){
            if(visited[i]){
                min = Math.min(min, i - prev);
                prev = i;
            }
        }
        
        // since every two consectutive are compared, we also need to
        // compare the diff between first one and the last
        min = Math.min(min, (24 * 60 - last + first));
        return min;
    }
}