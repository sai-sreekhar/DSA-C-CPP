Q_SIZE = 5
queue = [0]*Q_SIZE
rearIdx = -1
frontIdx = -1

def enqueue(num):
    global rearIdx
    global frontIdx
    if frontIdx == -1 and rearIdx == -1:
        frontIdx=rearIdx=0
        queue[rearIdx]=num
    elif frontIdx == (rearIdx+1) % Q_SIZE:
        print("Full")
    else:
        rearIdx = (rearIdx+1) % Q_SIZE
        queue[rearIdx] = num

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
        frontIdx = (frontIdx+1) % Q_SIZE

enqueue(1)
enqueue(2)
enqueue(3)
enqueue(4)
enqueue(5)
dequeue()
dequeue()
enqueue(6)
print(queue)
dequeue()