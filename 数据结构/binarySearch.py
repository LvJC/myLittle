def binSearch(alist, target):
    if len(alist)==0:
        return None

    mid = len(alist)//2
    if target>alist[mid]:
        return binSearch(alist[mid+1:], target)
    elif target<alist[mid]:
        return binSearch(alist[:mid], target)
    else:

        return True

testlist = [1, 2, 3, 8, 13, 17, 19, 32, 42,]
print(binSearch(testlist, 19))
