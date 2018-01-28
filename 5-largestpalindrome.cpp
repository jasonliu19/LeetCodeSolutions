class Solution {
public:
    bool isPalindrome(string s){
        for(int i = 0; i < s.length()/2; i++){
            if(s[i] != s[s.length() -1-i]){
                return false;
            }
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        string longest = "";
        for(int i = 0; i < s.length()-longest.length(); i++){
            for(int j = longest.length()+1; j <= s.length()-i; j++){
                string toTest = s.substr(i, j);
                if(isPalindrome(toTest)){
                    longest = toTest;
                }
            }
        }
        return longest;
    }
};
