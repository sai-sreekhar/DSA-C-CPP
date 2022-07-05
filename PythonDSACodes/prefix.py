size = int(input())
if size < 3:
    print("Invalid size")
    SystemExit
list = [0]*size
stack = []

for i in range(0,size):
    list[i] = input()

def isNum(value):
    try:
        x = int(value)
        return True
    except:
        return False
    

def calc():
    if isNum(list[size-1])==False or isNum(list[size-2])==False:
        return ("Invalid Expressions")
    
    for element in list[::-1]:
        if element == '/':
            a = stack.pop()
            b = stack.pop()
            stack.append(b/a)
        elif element == '*':
            a = stack.pop()
            b = stack.pop()
            stack.append(b*a)
        elif element == '+':
            a = stack.pop()
            b = stack.pop()
            stack.append(b+a)
        elif element == '-':
            a = stack.pop()
            b = stack.pop()
            stack.append(b-a)
        else:
            stack.append(int(element))
    if len(stack)!=1:
        return "Invalid Expression"   
    else:   
        return stack.pop()

print(calc())

    

