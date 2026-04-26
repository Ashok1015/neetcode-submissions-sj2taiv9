class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> kFrequentNums;
        unordered_map<int, int> frequencyMap;
        for(int& i: nums)
            frequencyMap[i]++;
        auto cmp= [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);
        for (auto const& [val, freq]: frequencyMap){
            minHeap.push({freq,val});
            if(minHeap.size()> k){
                minHeap.pop();
            }
        }
        vector<int> result;
        while(!minHeap.empty()){
            result.emplace_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;
    }
};
