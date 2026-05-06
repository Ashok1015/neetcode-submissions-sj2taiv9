class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int length= 1;
        int longest= 0;
        for(int i=1; i < nums.size(); i++){
            if(nums[i] == nums [i-1]) continue;
            else if(nums[i] == nums[i-1] + 1)
            {
                length++;
            }else{
                length= 1;
            }
            longest= std::max(longest,length);
        }
        if(nums.size())
            return max(longest,length);
        else
            return longest;
    }
};
