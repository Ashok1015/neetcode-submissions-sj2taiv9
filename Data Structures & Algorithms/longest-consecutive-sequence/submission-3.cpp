class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> seqSet(nums.begin(),nums.end());
    
       int longest= 0;
       for(int i: seqSet){
            int currentNum;
            int currentSeqLength;
            if(seqSet.find(i-1) == seqSet.end()){
                currentNum= i;
                currentSeqLength= 1;
                while(seqSet.find(currentNum+1) != seqSet.end()){
                    currentNum++;
                    currentSeqLength++;
                }
                longest= std::max(currentSeqLength,longest);
            }
       }
        return longest;
    }
};
