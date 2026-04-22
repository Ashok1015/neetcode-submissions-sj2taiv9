class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupAnagStrVec;
        unordered_map<string, vector<string>> groupAnagStrMap;
        for(auto& s: strs){
        int count[26] = {0};
        string key;
            for(char& c: s){
                count[c - 'a']++;
            }
            for(int i=0; i<26; i++){
                key+= to_string(count[i]) + "$";
            }
            groupAnagStrMap[key].emplace_back(s);
        }
        for(auto& mapEl : groupAnagStrMap){
            groupAnagStrVec.emplace_back(mapEl.second);
        }
        return groupAnagStrVec;
    }
};