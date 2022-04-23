#!/usr/bin/env python
# coding: utf-8
from enum import Enum

MAX_ITEMS = 100

class Compare(Enum):
    LESS = 0
    GREATER = 1
    EQUAL = 2

class ItemType:
    """ Item Type """

    def __init__(self, val):
        self.value = val

    def compared_to(self, otherItem):
        if self.value < otherItem.value:
            return Compare.LESS
        elif self.value > otherItem.value:
            return Compare.GREATER
        return Compare.EQUAL
    
    def __str__(self):
        return str(self.value)

class SortedType:
    """ Chapter 3: Sorted List """

    def __init__(self):
        self.length = 0
        self.info = []
        self.current_pos = -1

    def make_empty(self):
        self.length = 0

    def length_is(self):
        return self.length

    def is_full(self):
        if self.length == MAX_ITEMS:
            return True
        return False

    def insert_item(self, item):
        location = 0
        moreToSearch = (location < self.length)
        
        while moreToSearch:
            compare = item.compared_to(self.info[location])
            if compare == Compare.LESS:
                moreToSearch = False
            elif compare == Compare.GREATER:
                location += 1
                moreToSearch = (location < self.length)
        
        for indx in range(self.length, location, -1):
            if (indx == self.length):
                self.info.append(self.info[indx-1])
            else:
                self.info[indx] = self.info[indx-1]
        
        if (self.length == 0 or location == self.length): # index outrange
            self.info.append(item)
        else:
            self.info[location] = item
        self.length += 1            

    def retrieve_item(self, item): # Binary Search
        midPoint = -1
        first = 0
        last = self.length - 1
        moreToSearch = (first <= last)
        
        while moreToSearch :
            midPoint = int((first + last) / 2)
            compare = item.compared_to(self.info[midPoint])
            
            if compare == Compare.LESS:
                last = midPoint - 1
                moreToSearch = (first <= last)
            elif compare == Compare.GREATER:
                first = midPoint + 1
                moreToSearch = (first <= last)
            elif compare == Compare.EQUAL:
                item = self.info[midPoint]
                return True
            
        return False

    def delete_item(self, item):
        location = 0
        compare = item.compared_to(self.info[location])
        
        while compare != Compare.EQUAL:
            location += 1
            compare = item.compared_to(self.info[location])
            
        for indx in range (location + 1, self.length):
            self.info[indx-1] = self.info[indx]
        self.length -= 1

    def reset_list(self):
        self.current_pos = -1

    def get_next_item(self):
        self.current_pos += 1
        return self.info[self.current_pos]

    def __str__(self):
        self.reset_list()
        
        print_list = []
        
        for i in range (self.length):
            print_list.append(str(self.get_next_item()))
            
        return str(" ".join(print_list))