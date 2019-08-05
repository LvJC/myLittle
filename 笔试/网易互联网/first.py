# 给出一个数组，求其字典序排序倒数第Q个排列
# 第一行输入n，第二行输入正数第Q个排列，如：
# 输入：
# 1
# 1 3 2
# 输出为 3 1 2
# 因为该数组的全排列为
# 1 2 3
# 1 3 2
# 2 1 3
# 2 3 1
# 3 1 2
# 3 2 1

#coding=utf-8
import sys
 
if __name__ == "__main__":
    # 读取第一行的n
    n = int(sys.stdin.readline().strip())
    line = sys.stdin.readline().strip()
    values = map(int, line.split())
    result = list()
    for v in values:
        result.append(n + 1 - v)
    result = [str(x) for x in result]
    print((' '.join(result)))
    
    
#作者：daxiong88
#链接：https://www.nowcoder.com/discuss/216249
#来源：牛客网
