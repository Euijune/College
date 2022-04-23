
def bubble_up2(values, start, end):
    for indx in range(end, start, -1):
        if values[indx] < values[indx-1]:
            values[indx], values[indx-1] = values[indx-1], values[indx]

def bubble_sort(values):
    curr = 0
    num_val = len(values)
    while curr < num_val:
        bubble_up2(values, curr, num_val - 1)
        curr += 1



