#!/usr/bin/env python
# coding: utf-8

MAX_ITEMS = 100

class StackType:
    def __init__(self):
        self.info = []

    def is_empty(self):
        return len(self.info) == 0
        
    def is_full(self):
        return len(self.info) == MAX_ITEMS
        
    def push(self, item):
        if (self.is_full()):
            print('Stack is full.')
        else:
            self.info.append(item)

    def pop(self):
        if (self.is_empty()):
            print('Stack is empty.')
        else:    
            self.info.pop(-1)

    def top(self):
        if (self.is_empty()):
            return 'Stack is empty.'
        else:
            return self.info[-1]