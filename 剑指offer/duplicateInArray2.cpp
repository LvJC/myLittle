//不修改数组找出重复的数字
//给定一个长度为 n+1 的数组nums，
//数组中所有的数均在 1∼n 的范围内，其中 n≥1。
//请找出数组中任意一个重复的数，但不能修改输入的数组。
//样例：
//给定 nums = [2, 3, 5, 4, 3, 2, 6, 7]。
//返回 2 或 3。
//要求空间复杂度为 O(1)。

class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size(); //n+1
        int l = 1, r = n-1;  //[1,n]
        while(l<r){
            int mid = l + r >> 1;
            //统计在区间[l, mid]的数的个数
            int cnt = 0;
            for (auto a: nums){
                if (a>=l && a<=mid)
                    ++cnt;
            }
            //当在区间[l, mid]的数的个数大于mid-l+1，
            //说明区间[l, mid]有重复的数
            if(cnt>mid-l+1)    r = mid;
            else               l = mid+1;
        }
        return r;
    }
};
