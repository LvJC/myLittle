import pandas as pd

def search_url(urls_txt_path):
    all_urls = []
    with open(urls_txt_path,"r") as f :
        for each in f:
            each = each.replace('\n','')
            each = each.replace('\r','')
            all_urls.append(each)
    return all_urls

global all_urls
urls_txt_path1 = "/Users/lvjincheng/Desktop/iqiyi/404.txt"
urls_txt_path2 = "/Users/lvjincheng/Desktop/iqiyi/notmusic.txt"
all_urls = search_url(urls_txt_path1)+search_url(urls_txt_path2)

df = pd.read_excel('/Users/lvjincheng/Desktop/iqiyi/mete.xlsx')
urls = df['database__|__url']
newurls=urls.fillna('') #fill NaN value with ''
processed_df = df.copy()

for url in all_urls:
    #find the index of the specific url
    bool=newurls.str.contains(url)
    #import pdb;pdb.set_trace()
    if not newurls[bool].index.values:
        continue
    url_index = newurls[bool].index.values[0]
    #keep find the next url and locate the indexes between the two urls
    new_bool = newurls[url_index:].str.contains('http')
    next_index = newurls[url_index:][new_bool].index.values[1]
    #remove data between `new_bool` and `next_index`
    processed_df.drop(range(url_index, next_index),inplace=True)
    processed_urls = processed_df['database__|__url']

print processed_df
import pdb; pdb.set_trace()
processed_df.to_excel('processed_mete_01.xlsx',index=False)