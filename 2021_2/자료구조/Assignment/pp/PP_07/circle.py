class NodeType:
    """ Node Type """
    def __init__(self, item):
        self.info = item
        self.next = None

class CircularLL:
    def __init__(self):
        self.listData = None
        self.length = 0
        self.currentPos = None

    def is_full(self):
        try:
            location = NodeType("test")
            return False
        except:
            return True

    def length_is(self):
        return self.length

    def make_empty(self):
        while self.listData != None:
            tempPtr = self.listData.next
            del self.listData
            self.listData = tempPtr
        self.length = 0

    def find_item(self, listData, item):

        '''[4]'''
    
    def insert_item(self, item):

        '''[5]'''


    def delete_item(self, item):

        '''[6]'''
   

    def reset_list(self):
        self.currentPos = None

    def get_next_item(self):
        if self.currentPos == None:
            self.currentPos = self.listData
        else:
            self.currentPos = self.currentPos.next
        return self.currentPos.info

    def __str__(self):
        self.reset_list()
        items = []
        for i in range(0, self.length):
            t = self.get_next_item()
            items.append(str(t))
        return " ".join(items)
