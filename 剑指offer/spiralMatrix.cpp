// https://leetcode-cn.com/problems/spiral-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (1==matrix.size() && 1==matrix[0].size())
            return {matrix[0][0]};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int left = 0,
            right = n-1,
            top = 0,
            bottom = m-1;

        while(left <= right && top <= bottom)
        {
            //分成四部分
            for (int i = left; i <= right; ++ i)
                res.push_back(matrix[top][i]);
            if (top < bottom)
                for (int i = top+1; i <= bottom; ++ i)
                    res.push_back(matrix[i][right]);
            if (top < bottom && left < right)
                for (int i = right-1; i >= left; -- i)
                    res.push_back(matrix[bottom][i]);
            if (top < bottom - 1 && left < right)
                for (int i = bottom - 1; i > top; -- i)
                    res.push_back(matrix[i][left]);

            left ++; right --;
            top ++; bottom --;

        }
        return res;
    }
};
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (1==matrix.size() && 1==matrix[0].size())
            return {matrix[0][0]};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int left = 0,
            right = n-1,
            top = 0,
            bottom = m-1;

        while(left < m && top < n)
        {
            //分成四部分
            for (int i = left; i <= right; ++ i)
                res.push_back(matrix[top][i]);
            if (top < bottom)
                for (int i = top+1; i <= bottom; ++ i)
                    res.push_back(matrix[i][right]);
            if (top < bottom && left < right)
                for (int i = right-1; i >= left; -- i)
                    res.push_back(matrix[bottom][i]);
            if (top < bottom - 1)
                for (int i = bottom - 1; i > top; -- i)
                    res.push_back(matrix[i][left]);

            left ++; right --;
            top ++; bottom --;

        }
        return res;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    auto res = sol.printMatrix(mat);
    for (auto x :res)   cout <<x <<" ";
    return 0;
}
