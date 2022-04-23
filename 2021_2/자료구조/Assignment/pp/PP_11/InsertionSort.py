def insert_item(values, start, end):
    finished = False
    curr = end
    moreToSearch = (curr != start)

    while moreToSearch and not finished:
        if values[curr] < values[curr-1]:
            values[curr], values[curr-1] = values[curr-1], values[curr]
            curr -= 1
            moreToSearch = (curr != start)
        else:
            finished = True

def insertion_sort(values):
    num_val = len(values)
    for count in range(0, num_val):
        insert_item(values, 0, count)
    
