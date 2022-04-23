
def reheap_down(elements, root, bottom):
    leftChild = root*2 + 1
    rightChild = root*2 + 2

    if leftChild <= bottom:
        if leftChild == bottom:
            maxChild = leftChild
        else:
            if elements[leftChild] <= elements[rightChild]:
                maxChild = rightChild
            else:
                maxChild = leftChild
        if elements[root] < elements[maxChild]:
            elements[root], elements[maxChild] = elements[maxChild], elements[root]
            reheap_down(elements, maxChild, bottom)

def heap_sort(values, numValues):
    for indx in range(numValues//2  -1, -1, -1):
        reheap_down(values, indx, numValues-1)

    for indx in range(numValues-1, 0, -1):
        values[0], values[indx] = values[indx], values[0]
        reheap_down(values, 0, indx-1)
