class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        for (int x : nums1) {
            int i = 0;

            while (nums2[i] != x)
                i++;

            i++;
            while (i < nums2.size() && nums2[i] < x)
                i++;

            if (i == nums2.size())
                ans.push_back(-1);
            else
                ans.push_back(nums2[i]);
        }

        return ans;
    }
};