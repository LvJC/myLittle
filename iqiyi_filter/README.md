筛选出无效视频和带有“音乐”标签的视频
1. 利用 `mete.xlsx`，先得到所有包含 url 的文档，这一步就不需要写程序实现了，生成 `allurls.txt`
1. 运行 `python test.py` ，利用 `allurls.txt`，生成 `404.txt` 和 `notmusic.txt`
2. 运行 `python process.py` 生成 `processed_mete.xlsx`
