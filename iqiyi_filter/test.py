#!/usr/bin/python
# -*- coding: utf8 -*-
"""
Created by PyCharm.
File:               LinuxBashShellScriptForOps:testNoHttpResponseException,testHttpHostAvailability.py
User:               Guodong
Create Date:        2016/10/26
Create Time:        12:09

Function:
    test Http Host Availability

Some helpful message:
    For CentOS: yum -y install python-devel python-pip; pip install gevent
    For Ubuntu: apt-get -y install python-dev python-pip; pip install gevent
    For Windows: pip install gevent
"""
import signal
import time
import sys
reload(sys)
sys.setdefaultencoding('utf8') 
#  execute some operations concurrently using python
from gevent import monkey

monkey.patch_all()
import gevent
import urllib2

urls_txt_path = "/Users/lvjincheng/Desktop/iqiyi/allurls.txt"
#hosts = ['https://www.iqiyi.com/v_19rrk49usc.html', ]

def search_url(urls_txt_path):
    all_urls = []
    with open(urls_txt_path,"r") as f :
        for each in f:
            each = each.replace('\n','')
            each = each.replace('\r','')
            all_urls.append(each)
    return all_urls

global all_urls 
all_urls = search_url(urls_txt_path)
print(all_urls,len(all_urls))
time.sleep(5)

errorStopCounts = 10

quit_flag = False
statistics = dict()
notmusicstatistics = dict()

def changeQuit_flag(signum, frame):
    del signum, frame
    global quit_flag
    quit_flag = True
    print "Canceled task on their own by the user."


def testNoHttpResponseException(url):
    tryFlag = True
    global quit_flag
    errorCounts = 0
    notmusicCounts = 0
    tryCounts = 0
    global statistics
    global notmusicstatistics
    globalStartTime = time.time()
    while tryFlag:
        if not quit_flag:
            tryCounts += 1
            #print('GET: %s' % url)
            try:
                startTime = time.time()
                resp = urllib2.urlopen(url)  # using module 'request' will be better, request will return header info..
                endTime = time.time()
                data = resp.read()
                import requests
                res = requests.get(url)
                res.encoding = 'utf-8'
                text = res.text
                keystr_ind = text.index('\"categories\":\"')# 找到带有标签的字段
                keystr_list = text[keystr_ind:keystr_ind+30].split('\"')[3].split(',')
                if '音乐' not in keystr_list:
                    notmusicCounts += 1
                    notmusicstatistics[url] = notmusicCounts
                    globalEndTime = time.time()
                    tryFlag = False

                responseTime = endTime - startTime
                #print '%d bytes received from %s. response time is: %s' % (len(data), url, responseTime)
                #print "data received from %s at %d try is: %s" % (url, tryCounts, data)
                gevent.sleep(2)
            except urllib2.HTTPError as e:
                errorCounts += 1
                statistics[url] = errorCounts
                currentTime = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
                #print "HTTPError occurred, %s, and this is %d times(total) occurs on %s at %s." % (
                #    e, statistics[url], url, currentTime)

                if errorCounts >= errorStopCounts:
                    globalEndTime = time.time()
                    tryFlag = False

            except Exception as e:
                # Exception, such as 'error: [Errno 104] Connection reset by peer'
                #print "Error occurred, %s on %s" % (e, url)
                time.sleep(2)
        else:
            globalEndTime = time.time()
            break

    #import pdb;pdb.set_trace()
    error_urls=[]
    for url in statistics:
        print "Total error counts is %d on %s" % (statistics[url], url)
        if url in all_urls:
            all_urls.remove(url)
        if url not in error_urls:
            error_urls.append(url)
    notmusic_urls=[]
    for url in notmusicstatistics:
        print "Total notmusic counts is %d on %s" % (notmusicstatistics[url], url)
        if url in all_urls:
            all_urls.remove(url)
        if url not in notmusic_urls:
            notmusic_urls.append(url)
    for url in all_urls:
        print "Total error counts is 0 on %s" % url
    globalUsedTime = globalEndTime - globalStartTime
    print "Total time use is %s" % globalUsedTime

    #print('hello')
    print(error_urls,len(error_urls))
    error_txt_path = "/Users/lvjincheng/Desktop/iqiyi/404.txt"
    with open(error_txt_path,"w+") as f :
        for error in error_urls:
            f.write(error)
            f.write('\n')

    print(notmusic_urls,len(notmusic_urls))
    notmusic_txt_path = "/Users/lvjincheng/Desktop/iqiyi/notmusic.txt"
    with open(notmusic_txt_path,"w+") as f :
        for each in notmusic_urls:
            f.write(each)
            f.write('\n')
    sys.exit(0)

try:
    # Even if the user cancelled the task,
    # it also can statistics the number of errors and the consumption of time for each host.
    signal.signal(signal.SIGINT, changeQuit_flag)
    gevent.joinall([gevent.spawn(testNoHttpResponseException, host) for host in all_urls])
except KeyboardInterrupt:
    # Note: this line can NOT be reached, because signal has been captured!
    print "Canceled task on their own by the user."
    sys.exit(0)

