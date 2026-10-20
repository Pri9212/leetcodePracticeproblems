class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int ans=-1;
        while(left<right){
            int wid=right-left;
         int   ht=min(height[left],height[right]);
         int area=wid*ht;
         ans=max(ans,area);
         if(height[left]<height[right]){
            left++;
         }
         else{
            right--;
         }
        }
        return ans;
    }
};