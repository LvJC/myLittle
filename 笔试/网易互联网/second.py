# 圆环问题

#coding=utf-8
import sys
 
if __name__ == "__main__":
    # 读取第一行的n
    # t = int(sys.stdin.readline().strip())
    t = 1
    for i in range(t):
        nums = sys.stdin.readline().strip() 
        nums.sort()
        if nums[-1] < nums[-2] + nums[-3]:
            print("YES")
        else:
            print("NO")
 
# 核心点在于先将result排序


# -------------
# 作者：daxiong88
# 链接：https://www.nowcoder.com/discuss/216249
# 来源：牛客网
