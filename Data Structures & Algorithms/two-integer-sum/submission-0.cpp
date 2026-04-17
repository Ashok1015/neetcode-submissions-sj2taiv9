class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> mapOfNum_Pos;
        vector<int> ret;
        for(auto it= nums.begin(); it!= nums.end(); ++it){
            int complement= target- *it;
                if(mapOfNum_Pos.find(complement) != mapOfNum_Pos.end())
                {
                    
                    ret.push_back(std::distance(nums.begin(), it));
                    ret.push_back(mapOfNum_Pos.find(complement)-> second);
                    std::sort(ret.begin(), ret.end());
                    return ret;
                }
                 mapOfNum_Pos.insert({*it,std::distance(nums.begin(), it)});
        }
        return ret;
    }
};
