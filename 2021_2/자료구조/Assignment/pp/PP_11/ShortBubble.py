# bubble_up : short bubble sort, bubble_up2 = bubble sort
def short_bubble(values, numValues):
    curr = 0
    sorted = False
    while curr < numValues-1 and not sorted:
        sorted = bubble_up(values, curr, numValues-1, sorted)
        curr += 1

def bubble_up(values, startIndex, endIndex, sort):
    sort = True
    for indx in range(endIndex, startIndex, -1):
        if values[indx] < values[indx-1]:
            values[indx], values[indx-1] = values[indx-1], values[indx]
            sort = False

    return sort
