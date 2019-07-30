// 输入矩阵带方括号和逗号
// 如：[[0,0,0,0],[1,0,0,1],[1,1,1,0]]
def input():
  import sys
  import numpy as np
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
