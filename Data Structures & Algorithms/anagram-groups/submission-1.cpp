class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupAnagStrVec;
        unordered_map<string, vector<string>> groupAnagStrMap;
        if(strs.size() == 0){
            return groupAnagStrVec;
        }
        for(auto& s: strs){
            string key = s;
            sort(key.begin(),key.end());
            groupAnagStrMap[key].emplace_back(s);
        }
        for(auto& mapEl : groupAnagStrMap){
            groupAnagStrVec.emplace_back(mapEl.second);
        }
        return groupAnagStrVec;
    }
};