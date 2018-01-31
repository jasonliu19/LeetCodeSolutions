class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> charIndex;
        for(int i = 0; i <s.length(); i++){
            if(charIndex.count(s[i])){
                charIndex[s[i]] = -1;
            } else{
                charIndex[s[i]] = i;
            }
            
        }
        
        int lowest = s.length();
        for(auto it = charIndex.begin(); it != charIndex.end(); it++){
            if(it->second != -1 && it->second < lowest){
                lowest = it->second;
            }
        }
        
        if(lowest == s.length()){
            return -1;
        }
        
        return lowest;
    }
};