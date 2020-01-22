def msort(arr):
    if len(arr) > 1:
        m = len(arr)//2
        L = arr[:m]
        R = arr[m:]
        msort(L)
        msort(R)

        i = j = k = 0
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i = i + 1
            else:
                arr[k] = R[j]
                j = j + 1
            k = k + 1
        
        while i < len(L):
            arr[k] = L[i]
            i = i + 1
            k = k + 1
        while j < len(R):
            arr[k] = R[j]
            j = j + 1
            k = k + 1

arr = [5, 2, 24, 3, 10]

msort(arr)

print(arr)