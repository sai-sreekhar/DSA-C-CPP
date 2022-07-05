class node:
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = next

class linkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_at_beginning(self,data):
        newNode = node(data,self.head)
        self.head = newNode

        if self.tail == None:
            self.tail = newNode
        
    def printLinkedList(self):
        if self.head == None:
            print("Linked List is Emptu")
            return
        
        itr = self.head
        listStr = ""

        while itr:
            listStr += str(itr.data) + "-->"
            itr = itr.next

        print(listStr)
    
    def insert_at_end(self,data):
        if self.head == None or self.tail == None:
            self.head = node(data,None)
            self.tail = self.head
            return

        itr = self.head

        while itr.next:
            itr = itr.next  

        itr.next = node(data,None)
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

    def remove_at(self, index):
        if index<0 or index>=self.get_length():
            raise Exception("Invalid Index")

        if self.head == None or self.tail == None:
            print("Linked List is Empty")
            return
        
        if index == 0 and self.head == self.tail:
            self.head = None
            self.tail= None
            return

        if index==0 and self.head != self.tail:
            self.head = self.head.next
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1 and itr.next == self.tail:
                currentNode = itr
                # nodeToDel = itr.next
                currentNode.next = None
                self.tail = currentNode
                break
            if count == index - 1:
                currentNode = itr
                nodeToDel = itr.next
                nextNode = itr.next.next
                currentNode.next = nextNode
                break
            
        itr = itr.next
        count+=1

    def insert_at(self, index, data):

        if index<0 or index>self.get_length():
            raise Exception("Invalid Index")

        if index==0:
            self.insert_at_beginning(data)
            return

        count = 0
        itr = self.head
        while itr:
            if count == index - 1:
                newNode = node(data, itr.next)
                itr.next = newNode
                break

            itr = itr.next
            count += 1

    def remove(self,val):
        if self.head == None:
            print("No Element in linked list")
        if self.head == self.tail and self.head.data == val:
            self.head = None
            self.tail= None
            return
        if self.head.next != None and self.head.data == val:
            # currentNode = self.head
            # nodeToDel = self.head
            nextNode = self.head.next
            self.head = nextNode

        itr = self.head
        valueFound = False
        while itr:  
            if itr.data == val:
                valueFound = True
                if itr.next == None:
                    prev.next = None
                    self.tail = prev
                    
                else:
                    prev.next = itr.next
                    

            prev = itr
            itr = itr.next

        if valueFound == False:
            print("Value not found")

l = linkedList()
l.insert_at_beginning(7)
l.insert_at_end(5)
l.insert_at_end(5)
l.insert_at_end(0)
l.insert_at(2,99)
l.insert_at_end(80)
l.printLinkedList()
l.remove(5)
l.printLinkedList()
print(l.tail.data)