class node:
    def __init__(self,data,next=None):
        self.data=data
        self.next=next

class circularLinkedList():
    def __init__(self):
        self.head = None
    
    def insert_at_beginning(self,data):
        newNode = node(data,self.head)
        if self.head == None:
            self.head = newNode
            self.head.next = newNode
        else: 
            itr = self.head
            while itr:
                if itr.next == self.head:
                    self.head = newNode
                    itr.next = self.head
                    break
                itr = itr.next
    
    def printCircularLinkedList(self):
        if self.head == None:
            print("Linked List is Empty ")
            return
        
        itr = self.head
        listStr = ""

        while itr:
            listStr += str(itr.data) + "-->"
            if itr.next == self.head:
                break
            else:
                itr = itr.next

        print(listStr)
    
    def insert_at_end(self,data):
        if self.head == None:
            newNode = node(data)
            self.head = newNode
            self.head.next = newNode
            return
        
        itr = self.head
        while itr.next:
            if itr.next == self.head:
                itr.next = node(data,self.head)
                break
            itr = itr.next
        
    def remove_at(self,index):
        if index<0:
            raise Exception("Invalid Index")

        if self.head == None:
            print("Linked List is Empty")
            return
        
        if index == 0 and self.head.next == self.head:
            self.head = None
            return

        if index==0 and self.head.next != self.head:
            itr = self.head
            while itr:
                if itr.next == self.head:
                    itr.next = self.head.next
                    self.head = self.head.next
                    break

                itr = itr.next

            return

        # count = 0
        # itr = self.head
        # while itr:
        #     if count == index - 1 and itr.next.next == self.head:
        #         currentNode = itr
        #         # nodeToDel = itr.next
        #         currentNode.next = self.head
        #         break
        #     if count == index - 1:
        #         currentNode = itr
        #         # nodeToDel = itr.next
        #         nextNode = itr.next.next
        #         currentNode.next = nextNode
        #         break
            
        #     itr = itr.next
        #     count+=1
    

l =circularLinkedList()
l.insert_at_end(3)
l.insert_at_end(4)
l.insert_at_end(6)
l.insert_at_beginning(0)
l.insert_at_beginning(7)
l.printCircularLinkedList()
l.remove_at(9)
l.printCircularLinkedList()
print(l.head.data)
print(l.head.next.data)
print(l.head.next.next.data)
print(l.head.next.next.next.data)
print(l.head.next.next.next.next.data)
print(l.head.next.next.next.next.next.data)
