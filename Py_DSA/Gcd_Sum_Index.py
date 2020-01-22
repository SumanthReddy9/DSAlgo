MAX = 500001
A = [0]*MAX
G = [0]*MAX
arr = [0]*1000000007
def etoitent():
    for i in range(1, MAX):
        A[i] = i
    for i in range(2, MAX):
        if A[i] == i:
            A[i] = i-1
            for j in range(2*i, MAX, i):
                A[j] = (A[j]//i)*(i-1)

def pillaiAlgorithm():
    for i in range(1, MAX):
        G[i] = i
    
    for i in range(1, MAX):
        for j in range(2*i, MAX, i):
            G[j] = G[j] + A[j//i]*i

def update(idx, t, n):
    while idx <= n:
        arr[idx] = arr[idx] + t
        idx = idx + (idx&-idx)

def query(idx):
    ans = 0
    while idx != 0:
        ans = ans + arr[idx]
        idx = idx - (idx & -idx)
    return ans

etoitent()
pillaiAlgorithm()

