class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int& sizeOf_nums= nums.size();
        //nums.size() is only known once the program is running (runtime), creating a stack-based array like bucket[n] is technically a "Variable Length Array." Clang/GCC allow it as an extension, but it's not standard C++ and can lead to stack overflows.
        unordered_map<int,int> valueToFrequencyMap;
        for(int& i: nums){
            valueToFrequencyMap[i]++;
        }
        vector<vector<int>> bucket(sizeOf_nums+1); 
        //n+1 since array index starts at 0 and last index should represent maximum possible count which is the size of nums and that is n
        //bucket[sizeOf_nums+1] allocates Stack memory
        //bucket(sizeOf_nums+1) allocates Heap memory
        for(auto const& [val, freq]: valueToFrequencyMap){
            bucket[freq].emplace_back(val);
        }
        vector<int> result;
        for(int i=sizeOf_nums; i>0 && result.size() < k; i--){
            for(const int& num: bucket[i])
                result.emplace_back(num);
        }
        return result;
    }
};
