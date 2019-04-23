# 1.
def mergeSort(alist):
    if len(alist)<=1:
        return alist
    mid = len(alist)//2
    left = mergeSort(alist[:mid])
    right = mergeSort(alist[mid:])
    return merge(left, right)

def merge(left, right):
    newlist = []
    i=0
    j=0
    while i<len(left) and j<len(right):
        if left[i]<right[j]:
            newlist.append(left[i])
            i+=1
        else:
            newlist.append(right[j])
            j+=1
    newlist+=left[i:]
    newlist+=right[j:]
    return newlist


# 2. directly operate on `alist`
def mergeSort(alist):
    if len(alist) > 1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i = 0; j = 0; k = 0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k] = lefthalf[i]
                i += 1
            else:
                alist[k] = righthalf[j]
                j += 1
            k += 1

        while i < len(lefthalf):
            alist[k] = lefthalf[i]
            i += 1
            k += 1
        while j < len(righthalf):
            alist[k] = righthalf[j]
            j += 1
            k += 1

alist = [3,2,5,8,6,9,4,7,]
print mergeSort(alist)
