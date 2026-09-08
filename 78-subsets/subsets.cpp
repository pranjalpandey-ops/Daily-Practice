class Solution {
public:
    void getSubsets(vector<int>nums, vector<int>ans,int i, vector<vector<int>>&final){
        if(i==nums.size()){
            final.push_back(ans);
            return ;
        }
        ans.push_back(nums[i]);
        getSubsets(nums,ans,i+1,final);

        ans.pop_back(); //backtrack
        getSubsets(nums,ans,i+1,final);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>final;
        vector<int>ans;
        getSubsets(nums,ans,0,final);
        return final;
    }
};