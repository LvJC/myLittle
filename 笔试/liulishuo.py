# 题目是寻找有向图是否成环
# 输入有向图范例：
# [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
# [[0, 0, 0, 1, 0], [1, 0, 0, 0, 0], [0, 0, 0, 1, 1], [0, 0, 0, 0, 0], [0, 1, 0, 0, 0]]
# 输出范例：
# 0
# 1
def dfs(G,i,color):
    r = len(G)
    color[i] = -1
    is_DAG = 1
    for j in range(r):
        if G[i][j] != 0:
            #print j
            if color[j] == -1:
                is_DAG = 0
            elif color[j] == 0:
                is_DAG = dfs(G,j,color)
    color[i] = 1
    return is_DAG
 
def findcircle(G):
    r = len(G)
    color = [0] * r
    for i in range(r):
        #print i
        if color[i] == 0:
            is_DAG = dfs(G,i,color)
            if is_DAG == 0:
                break
    return is_DAG
    
def input():
    import sys
    string = sys.stdin.readline().strip()
    arr = []
    count = 0
    for i in string:
        try:
            arr.append(int(i))
        except:
            if i == '[':
                count += 1
            pass
    cols = int(len(arr)/count)
    
    grid = []
    cur = []
    
    for i in arr:
        if len(cur)<=cols:
            cur.append(i)
        else:
            grid.append(cur)
            cur  = []
            cur.append(i)
    grid.append(cur)
    return grid
    
while(True):
    grid = input()
    print(findcircle(grid))

#[[0, 1, 0], [0, 0, 1], [1, 0, 0]]
#[[0, 0, 0, 1, 0], [1, 0, 0, 0, 0], [0, 0, 0, 1, 1], [0, 0, 0, 0, 0], [0, 1, 0, 0, 0]]
