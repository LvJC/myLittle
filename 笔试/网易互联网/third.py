# 数组中临近数字之和为奇数即可交换
# 求字典序最小的数组排列
# 第一行输入样例数n，后面n行输入每次的数组排列

# 解法：
# 数组中奇数偶数都有时，直接排序；全偶全奇就输出原有数组

#coding=utf-8
import sys
 
if __name__ == "__main__":
    # 读取第一行的n
    n = int(sys.stdin.readline().strip())
    line = sys.stdin.readline().strip()
    values = map(int, line.split())
    result = list()
    for v in values:
        result.append(v)
    temp1 = [x for x in result if x % 2 == 0]
    temp2 = [x for x in result if x %2 != 0]
    if temp1 != [] and temp2  != []:
        result.sort()
    result = [str(x) for x in result]
    print((' '.join(result)))
    
    
# 作者：daxiong88
# 链接：https://www.nowcoder.com/discuss/216249
# 来源：牛客网
