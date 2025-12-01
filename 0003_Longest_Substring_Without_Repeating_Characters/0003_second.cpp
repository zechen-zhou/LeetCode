#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm> // for std::max


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Create a dynamic array (vector)
        // vector of size s.length(), all elements initialized to 0
        vector<int> len(s.length(), 0);

        // Store the maximum length
        vector<int> maxlen(s.length(), 0);

        // Store the index where character appeared last time
        std::unordered_map<char, int> last;

        int start = 0;

        if (s.length() == 0) {
            return 0;
        }

        for (int i = 0; i < s.length(); i++) {  
            if (i == 0) {
                len[i] = 1;
                maxlen[i] = len[i];
            } 
            // if i>=1 and key s[i] doesn't exist (s[i] hasn't appeared in current substring)
            else if (i >= 1 && last.find(s[i]) == last.end()) {
                len[i] = 1 + len[i-1];

                // Update the maximum length
                maxlen[i] = std::max(maxlen[i-1], len[i]);
            } else {
                if (last[s[i]] >= start) {
                    start = last[s[i]] + 1;
                }

                len[i] = i - start + 1;

                maxlen[i] = std::max(maxlen[i-1], len[i]);
            }

            // store the character (s[i]) index 
            last[s[i]] = i;
        }
        return maxlen[s.length()-1];
    }
};