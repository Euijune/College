def split(values, first, last):
    split_val = values[first]
    save_1st = first

    first += 1
    while True:
        onCorrectSide = True
        while onCorrectSide:
            if values[first] > split_val:
                onCorrectSide = False
            else:
                first += 1
                onCorrectSide = (first <= last)
        
        onCorrectSide = (first <= last)
        while (onCorrectSide):
            if values[last] <= split_val:
                onCorrectSide = False
            else:
                last -= 1
                onCorrectSide = (first <= last)

        if first < last:
            values[first], values[last] = values[last], values[first]
            first += 1
            last -= 1

        if first > last:
            break
    
    split_point = last
    values[save_1st], values[split_point] = values[split_point], values[save_1st]

    return split_point
    
def quick_sort(values, first, last):
    if first < last:
        split_point = split(values, first, last)
        quick_sort(values, first, split_point-1)
        quick_sort(values, split_point+1, last)