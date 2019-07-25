//找出数组中重复的数字

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        if (n==0)    return -1;
        //先遍历一遍，看是否有超出范围的数
        for (int i = 0; i < n; i++){
            if (nums[i]<0 || nums[i]>n-1)   return -1;
        }
        //交换的判断条件：
        //1. nums[i]不在原来的位置
        //2. nums[nums[i]]和nums[i]不相等
        for (int i = 0; i < n; i++){
            int loc = nums[i];
            if (i!=loc && nums[loc]!=loc)
                swap(nums[i], nums[loc]);
            else if (i!=loc && nums[loc]==loc)
                return loc;
        }
        return -1;
    }
};
