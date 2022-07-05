binarytree = [None]*20
def root(data):
    if binarytree[0] != None:
        print("Tree already has a root")
    else:
        binarytree[0] = data

def set_left(data,parent):
    if binarytree[parent] == None:
        print("Cant set a child at",(parent*2)+1,", no parent found")
    else:
        binarytree[2*parent+1] = data

def set_right(data,parent):
    if binarytree[parent] == None:
        print("Cant set a child at",(parent*2)+2,", no parent found")
    else:
        binarytree[2*parent+2] = data

def print_binarytree():
    for i in range(20):
        if binarytree[i] != None:
            print(binarytree[i], end=" ")
        else:
            print("-",end=" ")
    print()

root(8)
set_left(3,0)
set_right(10,0)
set_left(1,1)
set_right(6,1)
set_right(14,2)
set_left(4,4)
set_right(7,4)
set_left(13,6)
print_binarytree()
