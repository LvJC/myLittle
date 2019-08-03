// 1.
// 第一行输入：n
// 第二行输入：长度为n的数组llist [int, int, ...]
import sys
try:
    while True:
        n = int(input())
        if n == '':
            break
        l = input()
        #if there are int numbers then use map(int,*)
        #ints = list(map(int, l)) #type(ints)==list(int1,int2,...)
        l = list(map(int, l.split(" ")))
except:
    pass


// 2.
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
