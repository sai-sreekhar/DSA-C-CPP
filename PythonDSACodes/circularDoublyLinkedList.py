class node():
    def __init__(self,data,prev=None,next=None):
        self.data=data
        self.next=next
        self.prev=prev
    
class circularDoublyLinkedList():
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self,data):

        newNode = node(data,None,self.head)
        if self.head == None:
            self.head = newNode
            self.tail = newNode
            self.head.next = newNode
            self.head.prev = newNode

        elif self.head != None:
            self.head.prev = newNode
            self.head = newNode
            self.head.prev = self.tail
            self.tail.next = newNode

    
    def printCircularDoublyLinkedList(self):
        if self.head == None:
            print("Doubly Linked List is Empty")
            return

        itr = self.head
        doublyLinkedListStr = "" 
        while itr:
            doublyLinkedListStr += str(itr.data) + " ↔ "
            if itr.next == self.head:
                break
            else:
                itr = itr.next
        
        print(doublyLinkedListStr)

    def insert_at_end(self,data):
        if self.head == None or self.tail == None:
            self.head = node(data,None,None)
            self.tail = self.head
            self.head.prev = self.head
            self.head.next = self.head
            return

        elif self.head != None:
            itr = self.head
            while itr:
                if itr.next == self.head:
                    newnode = node(data,self.tail,self.head)
                    itr.next = newnode
                    self.head.prev = newnode
                    self.tail = newnode
                    break
                itr = itr.next
    
    def printCircularDoublyLinkedListReverse(self):
        if self.tail == None:
            print("Doubly Linked List is Empty")
            return

        itr = self.tail
        doublyLinkedListStr = "" 
        while itr:
            doublyLinkedListStr += str(itr.data) + " ↔ "
            if itr.prev == self.tail:
                break
            else:
                itr = itr.prev
        
        print(doublyLinkedListStr)

l = circularDoublyLinkedList()
l.insert_at_end(9)
l.insert_at_end(2)
# l.insert_at_beginning(3)
# l.insert_at_beginning(4)
l.insert_at_end(10)
# l.insert_at_end(11)
# l.insert_at_end(12)
# l.insert_at_beginning(5)


l.printCircularDoublyLinkedList()
print(l.head.data)
print(l.head.next.data)
print(l.head.next.next.data)
# print(l.head.next.next.next.data)
# print(l.head.next.next.next.next.data)
# print(l.head.next.next.next.next.next.data)
l.printCircularDoublyLinkedListReverse()
print(l.tail.data)
print(l.tail.prev.data)
print(l.tail.prev.prev.data)
print(l.tail.prev.prev.prev.data)
print(l.tail.prev.prev.prev.prev.data)
print(l.tail.prev.prev.prev.prev.prev.data)
