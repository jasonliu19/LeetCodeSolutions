class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char, int> licenseCount;
        for(int i = 0; i < licensePlate.length(); i++){
            if(licenseCount.count(licensePlate[i])){
                licenseCount[licensePlate[i]]++;
            } else{
                licenseCount[licensePlate[i]] =  0;
            }
        }

        unordered_map<char, int> thisWordCount;
        string shortest = "";
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                if(thisWordCount.count(words[i][j])){
                    thisWordCount[words[i][j]]++;
                } else{
                    thisWordCount[words[i][j]] =  0;
                }
            }

            bool valid = true;
            for(auto it = licenseCount.begin(); it != licenseCount.end(); ++it){
                if(thisWordCount[it->first] < it->second){
                    valid = false;
                    break;
                }
            }

            if(valid && (words[i].length() < shortest.length() || shortest.empty())){
                shortest = words[i];
            }
        }
        return shortest;
    }
};
