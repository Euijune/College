def printMatrix(d): # 1행 1열부터 출력한다.
    m = len(d)
    n = len(d[0])

    for i in range(1, m):
        for j in range(1, n):
            print(f'{d[i][j]:4d}', end = " ")
        print()

def order(p, i, j):
    if (i==j):
        print(f'A{i}', end="")
    else:
        k = p[i][j]
        print('(', end="")
        order(p, i, k)
        order(p, k+1, j)
        print(')', end="")

def minMult(n, d, m, p):
    '''
    n is the number of matrix (A1, A2, ..., An)
    d[i-1], d[i] represent the size of the matrix i.
    As an input parameter, m is the zero matrix.
    m[i][j] is the minimum value of the multiplication operation from matrices i to j.
    p[i][j] is the starting point at which matrices i to j diverge in optimal order.
    '''

    for diagonal in range(1, n):
        for i in range(1, n-diagonal+1):
            j = i + diagonal

            # initial value
            m[i][j] = m[i+1][j] + d[i-1]*d[i]*d[j]  # m[i][i] = 0
            p[i][j] = i

            for k in range(i, j):
                mul_count = m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j]
                if (m[i][j] > mul_count):
                    m[i][j] = mul_count
                    p[i][j] = k

    return m, p

d = [3, 5, 4, 6, 7, 2, 3, 4]
n = 7

#d = [5, 2, 3, 4, 6, 7, 8]
#n = 6

m = [[0 for j in range(1, n+2)] for  i in range(n+2)]
p = [[0 for j in range(1, n+2)] for  i in range(n+2)]

m, p = minMult(n, d, m, p)

printMatrix(m)
print()
printMatrix(p)
print()
order(p, 1, n)