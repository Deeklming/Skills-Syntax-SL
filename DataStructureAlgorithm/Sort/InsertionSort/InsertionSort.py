def InsertionSort(arr, opt):#opt가 True면 오름차순, False면 내림차순
    if opt:
        for i in range(1, len(arr)):
            j = i
            tmp = arr[i]
            while j>0 and arr[j-1]>tmp:
                arr[j] = arr[j-1]
                j -= 1
            arr[j] = tmp
    else:
        for i in range(1, len(arr)):
            j = i
            tmp = arr[i]
            while j>0 and arr[j-1]<tmp:
                arr[j] = arr[j-1]
                j -= 1
            arr[j] = tmp

li = [9,3,7,5,8,1,4,7,2,6,9,8,7,0,1,2,3,6]
print(f"before      sort: {li}")
InsertionSort(li, True)
print(f"ascending  order: {li}")
InsertionSort(li, False)
print(f"descending order: {li}")
