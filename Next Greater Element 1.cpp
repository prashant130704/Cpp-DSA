class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        unordered_map<int,int> mp;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                st.push(nums2[i]);
                mp[nums2[i]] = -1;   
            }
            else {
                while (!st.empty() && nums2[i] >= st.top()) { 
                    st.pop();
                }

                if (st.empty()) {
                    mp[nums2[i]] = -1;
                } else {
                    mp[nums2[i]] = st.top();
                }
                st.push(nums2[i]);
            }
        }

        for (int x : nums1) {
            arr.push_back(mp[x]);
        }
        return arr;
    }
};
