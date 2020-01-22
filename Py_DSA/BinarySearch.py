def bsearch(arr, s, e, val):
    if e >= s:
        m = (s+e)//2
        if arr[m] == val:
            return m
        elif arr[m] > val:
            return bsearch(arr, s, m-1, val)
        else:
            return bsearch(arr, m+1, e, val)
    else:
        return "-1"

if __name__ == "__main__":
    n = int(input())
    arr = []
    for i in range(0, n):
        ele = int(input())
        arr.append(ele)
    val = int(input())
    print(bsearch(arr, 0, n - 1, val))