################################ Q1 ######################################
######################## print function #####################################
def printMatrix(d): # 정수로 이루어진 행렬의 0행 0열부터 출력한다.
    m = len(d)      # row
    n = len(d[0])   # col

    for i in range(0, m):
        for j in range(0, n):
            print(f'{d[i][j]:4d}', end = " ")
        print()

def printMatrixF(d): # 실수로 이루어진 행렬의 0행 0열부터 출력한다.
    m = len(d)      # row
    n = len(d[0])   # col

    for i in range(0, m):
        for j in range(0, n):
            print(f'{d[i][j]:5.2f}', end = " ")
        print()

def print_inOrder(root):
    if not root:
        return
    print_inOrder(root.left)
    print(root.data)
    print_inOrder(root.right)

def print_preOrder(root):
    if not root:
        return
    print(root.data)
    print_preOrder(root.left)
    print_preOrder(root.right)

######################## Optimal Binary Search Tree #####################################
def optsearchtree(n, p, a, r):
    '''
    n is the number of key (key_1, key_2, ..., key_n)
    p[i] is probability that key_i is a search key, p[0] = 0 (padding).
    a, r must be the zero matrix.
    a[i][j] is the Optimal search time from key_i to key_j
    r[i][j] is the root of the tree created from key_i to key_j
    '''

    # set diagonal 1
    for i in range(1, n+1):
        a[i][i] = p[i]  # c_i = 1
        r[i][i] = i

    for diag in range(1, n):
        for i in range(1, n-diag+1):
            j = i + diag

            #initial value (k=i)
            a[i][j] = a[i][i-1] + a[i+1][j] 
            r[i][j] = i

            for k in range(i, j):
                search_time = a[i][k-1] + a[k+1][j]
                if search_time < a[i][j]:
                    a[i][j] = search_time
                    r[i][j] = k
                
            for m in range(i, j+1):
                a[i][j] += p[m]

    return a[1][n]

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def tree(key, r, i, j):
    k = r[i][j]
    if k == 0:
        return
    else:
        p = Node(key[k])
        p.left = tree(key, r, i, k-1)
        p.right = tree(key, r, k+1, j)
        return p

print('################################ Q1 ######################################')
######################## data1 ##############################
key = ["A", "B", "C", "D", "E"]
p = [1/15, 2/15, 3/15, 4/15, 5/15]

# python index는 0부터 시작함. 그러나 우리의 최적이진검색트리 알고리즘은 1부터 시작한다. 따라서 key, p의 맨 앞에 padding 추가.
key = [""] + key
p = [0] + p
n = len(p)-1

a = [[0 for j in range(0, n+2)] for  i in range(n+2)]   # a[i][j] : Key_i 부터 Key_j 까지의 최적 검색 시간
r = [[0 for j in range(0, n+2)] for  i in range(n+2)]

optimal_search_time = optsearchtree(n, p, a, r)

print('######################## data1 #############################')
print(f"optimal search time from key_1 to key_n is {optimal_search_time:.2f}")
print()
printMatrixF(a)
print()
printMatrix(r)
print()

root = tree(key, r, 1, n)
print_inOrder(root)
print()
print_preOrder(root)

######################## data2 ##############################
key = ["A", "B", "C", "D", "E", "F", "G", "H"]
p = [1/8] * 8

# python index는 0부터 시작함. 그러나 우리의 최적이진검색트리 알고리즘은 1부터 시작한다. 따라서 key, p의 맨 앞에 padding 추가.
key = [""] + key
p = [0] + p
n = len(p)-1

a = [[0 for j in range(0, n+2)] for  i in range(n+2)]   # a[i][j] : Key_i 부터 Key_j 까지의 최적 검색 시간
r = [[0 for j in range(0, n+2)] for  i in range(n+2)]

optimal_search_time = optsearchtree(n, p, a, r)

print('\n######################## data2 #############################')
print(f"optimal search time from key_1 to key_n is {optimal_search_time:.2f}")
print()
printMatrixF(a)
print()
printMatrix(r)
print()

root = tree(key, r, 1, n)
print_inOrder(root)
print()
print_preOrder(root)

################################ Q2 ######################################
def penalty(i, j, x, y):  # x[i]와 y[j]의 일치 여부에 의한 패널티
    if x[i] == y[j]:
        return 0
    return 1    # mismatch cost

def opt(i, j, x, y):
    '''
    x and y are nucleotide sequences.
    m, n is len(x) and len(y)
    return value - table[i][j] is the best fit cost of subsequences x[i..m] and  y[j...n]
    return value - minindex[i][j] is
    cost of the gap = 2
    mismatch cost = 1

    '''
    cost_gap = 2
    m = len(x)
    n = len(y)
    table = [[0 for j in range(n+1)] for i in range(m+1)]
    minindex = [[(0, 0) for j in range(n+1)] for i in range(m+1)]

    # 틈 행과 틈 열을 채운다 
    for j in range(n-1, -1, -1):
        table[m][j] = table[m][j+1] + cost_gap

    for i in range(m-1, -1, -1):
        table[i][n] = table[i+1][n] + cost_gap


    '''
    글로 쓰기엔 한계가 있어 그림을 첨부하였습니다.
    pdf를 참고해주시기 바랍니다.
    '''
    offset = max(m, n) - min(m, n)
    # (부분 1)
    for diag in range(1, min(m, n)+1):
        for c, p in enumerate(range(m-diag, m)):
            q = n - (c+1)
            table[p][q] = min(table[p+1][q+1] + penalty(p, q, x, y),
                              table[p+1][q] + cost_gap,
                              table[p][q+1] + cost_gap)

    # (부분 2)
    # m = n 인 경우는 부분 2가 생기지 않는다.
    if m > n:
        for diag in range(offset-1, 0, -1):
            for c, p in enumerate(range(0+diag, min(m, n)+diag)):
                q = min(m, n) - (c+1)
                table[p][q] = min(table[p+1][q+1] + penalty(p, q, x, y),
                              table[p+1][q] + cost_gap,
                              table[p][q+1] + cost_gap)
    elif m < n:
        for diag in range(offset-1, 0, -1):
            for c, p in enumerate(range(0, min(m, n))):
                q = min(m, n) - (c+1) + diag
                table[p][q] = min(table[p+1][q+1] + penalty(p, q, x, y),
                              table[p+1][q] + cost_gap,
                              table[p][q+1] + cost_gap)
            

    # (부분 3)
    for diag in range(1, min(m, n)+1):
        for c, p in enumerate(range(0, min(m, n)-diag+1)):
            q = min(m, n) - diag - c
            if table[p][q] == 0:   # m = n 인 경우, [0][n] 부터 [m][0]까지의 대각선이 두 번 계산되는 경우를 회피
                table[p][q] = min(table[p+1][q+1] + penalty(p, q, x, y),
                                table[p+1][q] + cost_gap,
                                table[p][q+1] + cost_gap)

    # fill in minindex
    drow = [0, 1, 1]
    dcol = [1, 0, 1]
    for i in range(m):
        for j in range(n):
            for dr, dc in zip(drow, dcol):   # 3가지 가능성을 조사한다.
                nr = i+dr
                nc = j+dc
                cost = penalty(i, j, x, y) if dr == dc else cost_gap
                if table[i][j] == (table[nr][nc] + cost):
                    minindex[i][j] = (nr, nc)
                    break
    
    return table, minindex

a = ['G','A','C','T','T','A','C','C']
b = ['C','A','C','G','T','C','C','A','C','C']

# make table
table, minindex = opt(0, 0, a, b)

print('\n################################ Q2 ######################################')
printMatrix(table)
x = 0
y = 0

# 최적 서열 맞춤을 찾아가는 과정
m = len(a)
n = len(b)
A = []
B = []
print()
while (x<m and y<n):
    tx, ty = x, y
    print(minindex[x][y])
    (x, y) = minindex[x][y]

    # 최적배열의 오른쪽 맨 아래 구성에서 시작하여 [i][j] 칸으로 이동
    if x == tx+1 and y == ty+1:     # 대각선으로 이동하는 경우, 틈 문자는 넣지 않는다.
        A.append(a[tx])
        B.append(b[ty])
    elif x == tx and y == ty+1:     # 왼쪽으로 이동한다면 틈 문자를 x서열에 넣는다
        A.append("-")
        B.append(b[ty])
    else:                           # 위로 이동한다면 틈 문자를 y서열에 넣는다
        A.append(a[tx])
        B.append("-")

# x 또는 y가 남은 경우 ( x<m or y<n )
if x < m:
    while(x<m):
        A.append(a[x])
        B.append("-")
        x = x+1
elif y < n:
    while(y<n):
        A.append("-")
        B.append(b[y])
        y = y+1

print()
print(" ".join(A))
print(" ".join(B))