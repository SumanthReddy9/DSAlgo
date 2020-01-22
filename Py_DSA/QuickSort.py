def partition(arr, l, r):
    pivot = arr[r]
    i = l-1
    for j in range(l, r):
        if arr[j] < pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i+1], arr[r] = arr[r], arr[i+1]
    return i+1

def qsort(arr, l, r):
    if(l < r):
        p  = partition(arr, l, r)
        qsort(arr, l, p-1)
        qsort(arr, p+1, r)

arr = [5, 10, 3, 24, 2]

qsort(arr, 0, len(arr)-1)

print(arr)