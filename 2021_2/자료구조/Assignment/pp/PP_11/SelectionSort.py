def min_index(values, start, end):
    min_indx = start
    for indx in range(start+1, end+1):
        if values[indx] < values[min_indx]:
            min_indx = indx

    return min_indx

def selection_sort(values):
    num_val = len(values)
    end = num_val - 1
    for curr in range(0, end):
        min_indx = min_index(values, curr, end)
        values[curr], values[min_indx] = values[min_indx], values[curr]
