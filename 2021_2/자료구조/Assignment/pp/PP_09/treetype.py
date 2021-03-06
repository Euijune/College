# -*- coding: utf-8 -*-
"""TreeType.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1C6b70Xk1R78oST8jtjRFMi8-QJGo1fMk

# **TreeType.py**
"""

class TreeNode:

    def __init__(self, info):
        self.info = info
        self.left = None
        self.right = None
    
class BST():

    def __init__(self):
        self.root = None
        self.order_list = []
    
    def is_empty(self):
        return (self.root == None)
    
    def count_nodes(self, tree):
        if tree == None:
            return 0
        else:
            return self.count_nodes(tree.left) + self.count_nodes(tree.right) + 1

    def length_is(self):
        return self.count_nodes(self.root)

    def insert(self, item):
        self.root = self.insert_item(self.root, item)

    def insert_item(self, node, item):
        if node == None:
            node = TreeNode(item)
        else:
            if item < node.info:
                node.left = self.insert_item(node.left, item)
            else:
                node.right = self.insert_item(node.right, item)
        
        return node

  
    def inorder(self, node):
        if node != None:
            self.inorder(node.left)
            self.order_list.append(node.info)
            self.inorder( node.right) 
    
    def preorder(self, node):
        if node != None:
            self.order_list.append(node.info)
            self.preorder(node.left)
            self.preorder(node.right)
    
    def postorder(self, node):
        if node != None:
            self.postorder(node.left)
            self.postorder(node.right)
            self.order_list.append(node.info)

    def delete(self, item):
        self.root = self.delete_node(self.root, item)
    
    def delete_node(self, current, item):
        if item < current.info:
            current.left = self.delete_node(current.left, item)
        elif item > current.info:
            current.right = self.delete_node(current.right, item)
        else:
            if current.left == None:
                current = current.right
            elif current.right == None:
                current = current.left
            else:
                data = get_predecessor(current.right, data)
                current.info = data
        
        return current

    def get_predecessor(tree, data):
        while tree.right != None:
            tree = tree.right
        data = tree.info

        return data