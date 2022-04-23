def merge_sort(values, first, last):
    if first < last:
        middle = (first + last) // 2
        merge_sort(values, first, middle)
        merge_sort(values, middle+1, last)
        merge(values, first, middle, middle+1, last)

def merge(values, leftFirst, leftLast, rightFirst, rightLast):
    tmp_arr = [None] * 1000
    indx = leftFirst
    save_1st = leftFirst

    while (leftFirst <= leftLast) and (rightFirst <= rightLast):
        if values[leftFirst] < values[rightFirst]:
            tmp_arr[indx] =  values[leftFirst]
            leftFirst += 1
        else:
            tmp_arr[indx] = values[rightFirst]
            rightFirst += 1
        indx += 1
    
    while leftFirst <= leftLast:
        tmp_arr[indx] = values[leftFirst]
        leftFirst += 1
        indx += 1
    
    while rightFirst <= rightLast:
        tmp_arr[indx] = values[rightFirst]
        rightFirst += 1
        indx += 1

    for indx in range(save_1st, rightLast+1):
        values[indx] = tmp_arr[indx]