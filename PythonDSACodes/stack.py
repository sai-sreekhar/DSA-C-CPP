stack1 = [0]*256
count = 0

def push(x):
    global count
    if count==256:
        print('There is no space in stack')
        return
    else:    
        stack1[count] = x
        count += 1
        return

def pop():
    global count
    if count==0 :
        return -1
    result = stack1[count-1]
    count-=1
    return result
 

for i in range(0,270):
        push(i)
        
for j in range(0,270):
    popedVal = pop()
    if(popedVal == -1):
        print('stack is empty')
    else:
        print(popedVal)

