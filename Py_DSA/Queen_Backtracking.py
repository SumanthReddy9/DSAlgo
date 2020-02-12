arr = []


def issafe(n, row, col):
    for i in range(n):
        if arr[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1)), range(col, -1, -1):
        if arr[i][j] == 1:
            return False
    for i, j in zip(range(row, n, 1)), range(col, -1, -1):
        if arr[i][j] == 1:
            return False
    return True


def nqueens(n, col):
    if col > n:
        return True
    for i in range(n):
        if issafe(n, i, col):
            arr[i][col] = 1
            if nqueens(n, col + 1):
                for j in range(n):
                    for k in range(n):
                        print(arr[j][k], end="")
                    print()
                print()
            arr[i][col] = 0
    return False


if __name__ == "__main__":
    n = int(input())
    temparr = []
    for i in range(n):
        for j in range(n):
            temparr.append(0)
        arr.append(temparr)
        temparr = []
    nqueens(n, 0)
    # print(arr)
