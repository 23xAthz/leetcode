class Solution {
    public int countBinarySubstrings(String s) {
        int[] groups = new int[s.length()];
        int t = 0;              // index for groups array
        groups[0] = 1;         // first character starts first group

        // Build the groups array
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                groups[++t] = 1;   // new group starts
            } else {
                groups[t]++;       // same group continues
            }
        }

        // Sum min of adjacent groups
        int ans = 0;
        for (int i = 1; i <= t; i++) {
            ans += Math.min(groups[i - 1], groups[i]);
        }

        return ans;
    }
}
