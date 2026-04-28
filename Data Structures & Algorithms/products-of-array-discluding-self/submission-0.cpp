class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix= 1;
        vector<int> result(nums.size());
        for(int i=0; i< nums.size(); i++){
            result[i] = prefix;
            prefix *= nums[i];
            std::cout << "\nresult: " << result[i];
            std::cout << "\nprefix: " << prefix;
        }
        int postfix= 1;
        for(int i=nums.size()- 1; i>= 0; i--){
            result[i] *= postfix;
            postfix *= nums[i];
            std::cout << "\nresult: " << result[i];
            std::cout <<  "\npostfix: " << postfix;
        }
        return result;
    }
};
