// https://leetcode.com/problems/combination-sum-ii

class Solution {
    private int combinationSum2(int[] arr, int tar, int idx, List<Integer> smallAns, List<List<Integer>> res) {
        if (tar == 0 || idx >= arr.length) {
            if (tar == 0) {
                List<Integer> base = new ArrayList<>(smallAns);
                res.add(base);
                return 1;
            }
            return 0;
        }
            
        int count = 0;

        if (tar - arr[idx] >= 0) {
            smallAns.add(arr[idx]);
            count += combinationSum2(arr, tar - arr[idx], idx + 1, smallAns, res);
            smallAns.remove(smallAns.size() - 1);
        }

        idx++;
        while (idx < arr.length && arr[idx - 1] == arr[idx])
            idx++;

        count += combinationSum2(arr, tar, idx, smallAns, res);
        return count;
    }
    public List<List<Integer>> combinationSum2(int[] arr, int tar) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> smallAns = new ArrayList<>();
        Arrays.sort(arr);
        combinationSum2(arr, tar, 0, smallAns, res);
        return res;
    }
}