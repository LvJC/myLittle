对建立好的图像数据库进行一些预处理：
- 清洗损坏图像
- 去重
- 标准化

### 清洗损坏
```
# -----------Example: python codes to move corrupted images
from os import listdir, systemimport os
from PIL import Image

rpath = '/data/jincheng.lyu/data/nude_sexy_safe_v1_x320/training/safe/'
for filename in listdir(rpath):
    if filename.endswith('.jpg'):
        try:
            img = Image.open(rpath+filename) # open the image file            
            img.verify() # verify that it is, in fact an image        
        except (IOError, SyntaxError) as e:            
            print('Bad file:', filename) # print out the names of corrupt files
            filepath = os.path.join(rpath, filename)
            system("mv {} /data/jincheng.lyu/data/nude_sexy_safe_v1_x320_corrupted_collection/training/safe/".format(filepath))
```

### 去重
```
# Removing duplicates
fdupes -rdN ./
```

### 标准化
固定一条边长度为320像素
```
# Resizing
mogrify -geometry x320 *
```
