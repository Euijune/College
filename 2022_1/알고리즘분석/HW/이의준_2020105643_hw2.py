from random import randrange


class Data():
    def __init__(self, size=128):
        # n = size, self.data = [s1,s2,...,sn], 1≤si≤n, si는 자연수, i=1,...,n
        self.data = sorted([randrange(1, size+1) for i in range(size)])
        self.size = size

    def binary_search(self, x):
        first = 0
        last = self.size - 1
        k = 0   # 데이터 비교 횟수

        while(first <= last):
            mid = int((first + last) / 2)

            if self.data[mid] == x:
                return mid, k
            elif self.data[mid] < x:
                first = mid + 1
            else:
                last = mid - 1
            
            k += 1

        return -1, k    # x를 찾을 수 없으면 -1 반환

# 이진 검색 작동확인
# A = Data(size=128)
# print(A.data)
# Loc, k = A.binary_search(10)
# print(Loc, k)

############################## A1 #########################################

C = []  # n값에 따른 1000개의 문제 p의 평균 데이터 비교 횟수

for n in [8, 16, 32, 64, 128, 256, 512, 1024]:
    S = Data(size=n)
    c = 0
    
    for i in range(1000):
        x = randrange(1, n+1) # 하나의 문제 pi를 생성
        loc, ki = S.binary_search(x)    # x를 찾을때까지의 비교 횟수 ki를 계산
        c += ki

    c = int(c/1000) # 평균 데이터 비교횟수 c
    C.append(c)

print(C)    # n=128, n=256, n=512일때의 c값

def merge(h, m, U, V, S):
    # U, V, S는 list여야 합니다.
    if not isinstance(U, list):
        raise Exception(f'{U}의 자료형은 list여야 합니다.')
    
    if not isinstance(V, list):
        raise Exception(f'{V}의 자료형은 list여야 합니다.')
    
    if not isinstance(S, list):
        raise Exception(f'{S}의 자료형은 list여야 합니다.')

    i = 0
    j = 0
    k = 0

    while i < h and j < m:
        if U[i] < V[j]:
            S[k] = U[i]
            i += 1
        else:
            S[k] = V[j]
            j += 1
        k += 1

    if i >= h:  # U, V 중 V에만 원소가 남은 경우
        S[k:] = V[j:]
    else:
        S[k:] = U[i:]

def _merge_sort(n, S, mem_size, ans):
    if not isinstance(S, list): # S는 list여야 합니다.
        raise Exception(f'{S}의 자료형은 list여야 합니다.')

    h = int(n/2)
    m = n-h
    mem_size += h+m
    ans[0] = max(mem_size, ans[0])

    if (n > 1):
        U = S[0:h]  # S[0] through S[h-1]
        V = S[h:n]  # S[h] thoough S[n-1]

        mem_size, _ = _merge_sort(h, U, mem_size, ans)  # 여기서는 상황별 필요로 하는 추가 메모리크기만 계산하면 되므로 최댓값은 버린다
        ans[0] = max(mem_size, ans[0])

        mem_size -= h  # 사용한 공간을 반납하는 과정

        mem_size, _ = _merge_sort(m, V, mem_size, ans)  # 여기서는 상황별 필요로 하는 추가 메모리크기만 계산하면 되므로 최댓값은 버린다
        ans[0] = max(mem_size, ans[0])

        mem_size -= m   # 사용한 공간을 반납하는 과정

        merge(h, m, U, V, S)

    return mem_size, ans

def merge_sort(S):
    mem_size = 0    # merge_sort를 호출할 때의 추가 메모리 크기
    ans = [0]   # 추가 메모리 크기의 최댓값 (≒2n), call by reference를 위해서 list안에 값을 넣었음
    _, ans = _merge_sort(len(S), S, mem_size, ans)  # 여기서는 추가 메모리 크기의 최댓값만 필요하므로 mem_size return값은 버린다.

    return ans[0]

########################## A2 #################################

# merge_sort 검증

data = [8, 3, 15, 2, 9, 1, 5, 7, 4, 16, 10, 11, 12, 13, 6, 14]
extra_mem_size = merge_sort(data)
print(data)
# 추가로 필요한 메모리의 크기
print(extra_mem_size)

# merge_sort 검증2

# data2 = [randrange(1, 101) for i in range(100)]
# print(data2)
# ems = merge_sort(data2)
# print(data2)
# print(ems)