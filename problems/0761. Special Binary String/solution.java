class Solution {
    public String makeLargestSpecial(String s) {
        int count = 0, i = 0;
        List<String> specials = new ArrayList<>();

        for (int j = 0; j < s.length(); j++) {
            count += s.charAt(j) == '1' ? 1 : -1;

            if (count == 0) {
                String inner = makeLargestSpecial(s.substring(i + 1, j));
                specials.add("1" + inner + "0");
                i = j + 1;
            }
        }

        specials.sort(Collections.reverseOrder());
        return String.join("", specials);
    }
}
