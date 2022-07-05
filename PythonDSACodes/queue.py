Q_SIZE = 100
queue = [0]*Q_SIZE
rearIdx = -1
frontIdx = -1

def enqueue(num):
    global rearIdx
    global frontIdx
    if rearIdx == Q_SIZE-1:
        print("Overflow")
    elif frontIdx == -1 and rearIdx == -1:
        frontIdx=rearIdx=0
        queue[rearIdx]=num
    else:
        rearIdx += 1
        queue[rearIdx]=num
       
def dequeue():
    global rearIdx
    global frontIdx
    if frontIdx == -1 and rearIdx == -1:
        print("Empty")
    elif frontIdx == rearIdx:
        print(queue[frontIdx])
        frontIdx = rearIdx = -1
    else:
        print(queue[frontIdx])
        frontIdx += 1

enqueue(1)
enqueue(2)
enqueue(3)
print(queue)
dequeue()
dequeue()