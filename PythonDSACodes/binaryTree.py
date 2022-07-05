class BinarySearchTreeNode:
    def __init__(self,data,level):
        self.data = data
        self.left = None
        self.right = None
        self.level = level

    def add_child(self,data,level):
        if data ==  self.data:
            return
        if data < self.data:
            if self.left:
                self.left.add_child(data,level+1)
            else:
                self.left = BinarySearchTreeNode(data,level)
        else:
            if self.right:
                self.right.add_child(data,level+1)
            else:
                self.right= BinarySearchTreeNode(data,level+1)
   
    def in_order_traversal(self):
        elements = []

        if self.left:
            elements += self.left.in_order_traversal()

        elements.append(self.data)

        if self.right :
            elements += self.right.in_order_traversal()

        return elements
    
    def search(self,val):
        if self.data == val:
            return True, self.level
        if val < self.data:
            if self.left:
                return self.left.search(val)
            else:
                return False
        if val > self.data:
            if self.right:
                return self.right.search(val)
            else:
                return False

    def height_of_node(self,val):
        pass

    def find_max(self):
        if self.right is None:
            return self.data
        return self.right.find_max()

    def find_min(self):
        if self.left is None:
            return self.data
        return self.left .find_min()

    def delete(self,val):
        if val < self.data:
            if self.left:
                self.left = self.left.delete(val)
        elif val > self.data:
            if self.right:
                self.right = self.right.delete(val)
        else:
            if self.left is None and self.right is None:
                return None
            elif self.left is None:
                return self.right
            elif self.right is None:
                return self.left
            
            min_val = self.right.find_min()
            self.data = min_val
            self.right = self.right.delete(min_val)

        return self

    def in_order_traversal_using_stack(self):
        current = self
        stack = []
        done = 0
        while True:
            if current is not None:
                stack.append(current)
                current = current.left
            elif (stack):
                current = stack.pop()
                print(current.data,end = " ")
                current = current.right
            else:
                break
    
def build_tree(elements):
    root = BinarySearchTreeNode(elements[0],0)

    for i in range(1,len(elements)):
        root.add_child(elements[i],1)

    return root

numbers = [8,3,10,1,6,14,4,7,13]
numbers_tree = build_tree(numbers)
print(numbers_tree.in_order_traversal())
# print(numbers_tree.search(1))
# numbers_tree.delete(10)
# print(numbers_tree.in_order_traversal())
numbers_tree.in_order_traversal_using_stack()
