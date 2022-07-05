class node:
    def __init__(self,data,prev=None,next=None):
        self.data=data
        self.next=next
        self.prev=prev
    
class doublyLinkedList():
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self,data):

        newNode = node(data,None,self.head)
        if self.head == None:
            self.head = newNode

        elif self.head != None:
            self.head.prev = newNode
            self.head = newNode

        if self.tail == None:
            self.tail = newNode
    
    def printLinkedList(self):
        if self.head == None:
            print("Doubly Linked List is Empty")
            return

        itr = self.head
        doublyLinkedListStr = "" 
        while itr:
            doublyLinkedListStr += str(itr.data) + " ↔ "
            itr = itr.next
        
        print(doublyLinkedListStr)

    def insert_at_end(self,data):
        if self.head == None or self.tail == None:
            self.head = node(data,None,None)
            self.tail = self.head
            return

        itr = self.head
        while itr.next:
            itr = itr.next
        
        itr.next = node(data,itr,None)
        self.tail = itr.next

    def insert_values(self, data_list):
        for data in data_list:
            self.insert_at_end(data)

    def get_length(self):
        count = 0
        itr = self.head

        while itr:
            count+=1
            itr = itr.next
        return count

    def insert_at(self, index, data):

        if index<0 or index>=self.get_length():
            raise Exception("Invalid Index")

        if index==0:
            self.insert_at_beginning(data)
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                newNode = node(data,itr,itr.next)
                itr.next.prev = newNode
                itr.next = newNode
                break

            itr = itr.next
            count+=1
        
    def printLinkedListReverse(self):
        if self.tail == None:
            print("Doubly Linked List is Empty")
            return

        itr = self.tail
        doublyLinkedListStr = "" 
        while itr:
            doublyLinkedListStr += str(itr.data) + " ↔ "
            itr = itr.prev
        
        print(doublyLinkedListStr)

    def remove_at(self,index):
        if index < 0:
            print("Invalid Index")
            return
        if self.head == None or self.tail == None:
            print("Doubly Linked List is Empty")
            return
        if index == 0 and self.head == self.tail:
            self.head = None
            self.tail= None
            return
        if index==0 and self.head != self.tail:
            # currentNode = self.head
            # nodeToDel = self.head
            nextNode = self.head.next
            nextNode.prev = None
            self.head = nextNode
            return
        count = 0
        itr = self.head
        while itr:
            if count == index - 1 and itr.next == self.tail:
                # currentNode = itr
                # nodeToDel = itr.next
                itr.next = None
                self.tail = itr
                break
            if count == index-1:
                currentNode = itr
                # nodeToDel = itr.next
                nextNode = itr.next.next
                currentNode.next = nextNode
                nextNode.prev = currentNode
                break

            itr = itr.next
            count+=1    

    def remove(self,val):
        if self.head == None or self.tail == None:
                print("No Element in doubly lined list")
        if self.head == self.tail and self.head.data == val:
                 self.head = None
                 self.tail= None
                 return
        if self.head != self.tail and self.head.data == val:
             # currentNode = self.head
            # nodeToDel = self.head
            nextNode = self.head.next
            nextNode.prev = None
            self.head = nextNode
        
        itr = self.head
        valueFound = False
        while itr:        
            if itr.data == val:
                valueFound = True
                if itr == self.tail:
                    # currentNode = itr
                    previousNode = itr.prev
                    previousNode.next = None
                    self.tail = previousNode
                else:
                    # currentNode = itr
                    nextNode = itr.next
                    previousNode = itr.prev
                    previousNode.next = nextNode
                    nextNode.prev = previousNode
                    
            itr = itr.next

        if valueFound == False:
            print("Value not found")

    def remove_by_head(self,val):
        if self.head == None:
                print("No Element in doubly lined list")
        if self.head.next == None and self.head.data == val:
            self.head = None
            self.tail= None
            return
        if self.head.next != None and self.head.data == val:
            # currentNode = self.head
            # nodeToDel = self.head
            nextNode = self.head.next
            nextNode.prev = None
            self.head = nextNode

        itr = self.head
        while itr:        
            if itr.data == val:
                if itr.next == None:
                    # currentNode = itr
                    previousNode = itr.prev
                    previousNode.next = None
                    self.tail = previousNode
                else:
                    # currentNode = itr
                    nextNode = itr.next
                    previousNode = itr.prev
                    previousNode.next = nextNode
                    nextNode.prev = previousNode
                    
            itr = itr.next
        if itr == None:
            print("Value not found")

l = doublyLinkedList()
# l.insert_at_end(6)
# l.insert_at_end(8)
# l.insert_at_beginning(88)
# l.insert_at_beginning(89)
# l.insert_values(["4","5","0"])
# l.insert_at(4,9)
l.insert_at_beginning(2)
l.insert_at_beginning(2)
l.insert_at_beginning(5)
l.insert_at_end(9)
l.insert_at(0,10)
# print(l.get_length())
l.insert_at(4,2)
# l.insert_at(2,77)
# # l.printLinkedList()
# # l.printLinkedListReverse()
# # l.remove_at(0)
# # l.remove_at(3)
# # l.remove_at(4)
l.printLinkedList()
l.printLinkedListReverse()
l.remove(2)
l.printLinkedList()
l.printLinkedListReverse()
