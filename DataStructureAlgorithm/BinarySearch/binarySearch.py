def BinarySearch(arr, value):
    left, mid, right, count = 0, 0, len(arr)-1, 0
    print("value({})-> ".format(value), end="")
    while left<=right:
        count+=1
        mid = int(left+(right-left)/2)
        if arr[mid]==value:
           print("ok, count: %d, " % count, end="")
           return mid
        elif arr[mid] < value:
            left = mid+1
        else:
            right = mid-1
    print("fail, count: %d, " % count, end="")
    return -1

if __name__=="__main__":
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
    for i in range(1, 12):
        r = BinarySearch(a, i)
        print("value index:", r)
