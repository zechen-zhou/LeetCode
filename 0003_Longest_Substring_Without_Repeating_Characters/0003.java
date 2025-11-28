public int lengthOfLongestSubstring(String s) {
    int maxLen = 0;
    int currentLen = 0;

    if (s.length() == 0) {
        return 0;
    } else if (s.length() == 1) {
        return 1;
    }
    
    HashMap<Character, Integer> hashMap = new HashMap<Character, Integer>();
    
    for (int i = 0; i < s.length(); i++) {
        
        for (int j = i; j < s.length(); j++) {
            if (hashMap.containsKey(s.charAt(j))) {
                currentLen = j - i;

                if (currentLen > maxLen) {
                    maxLen = currentLen;
                }
                break;

            } else {
                // if no duplicated characters and it reaches the end
                if (j == s.length() - 1) {
                    currentLen = j - i + 1;

                    if (currentLen > maxLen) {
                        maxLen = currentLen;
                    }
                    break;
                } else {
                    hashMap.put(s.charAt(j), j);
                }
            }
        }
        hashMap.clear();
    }

    return maxLen;
}