//Minimum Window Substring
//Tags: Hashtable, two pointers
/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in
  T in complexity O(n).

For example,S = "ADOBECODEBANC", T = "ABC"   Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum 
window in S. 
*/

//Solution in C++:

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> table(128, 0);
        int required = t.size();
        //Count frequency of the string T letters
        //When table[x] < 0, it means it is not required letter. Then do nothing.
        for (int i = 0; i < required; i++) table[t[i]]++;
        //2 pointers init
        int minLen = INT_MAX;  //for the convience of returning s.substr(left, minLen)
        int start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {  //Make sure the iterator and startpoint don't exceed
            //if we still need letters from s
            if(required) {
                if (i == s.size()) break; //Not found
                table[s[i]]--;  //that charater in map - 1     
                if(table[s[i]] >= 0)required--; //if it is >=0, it means we have reached one more step to the target, then required -1
                i++;
            } else { //required = 0 means we have alread reach a possible substring, which still needs to be proven
                if (i - start < minLen) {
                    minLen = i -start;
                    left = start;
                }
                table[s[start]]++; //start moves a step left
                if (table[s[start]] > 0) required++;
                start++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(left, minLen);
    }
};