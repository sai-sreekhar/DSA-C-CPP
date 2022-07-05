size = int(input())
list = input().split()
stack = []

def isNum(value):
    try:
        x = int(value)
        return True
    except:
        return False

def calc():
    for element in list:
        if isNum(element):
            stack.append(int(element))
        elif len(stack) > 1:
            if element == '/':
                a = stack.pop()
                b = stack.pop()
                try:
                    stack.append(b/a)
                except Exception as e:
                    return e 
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
            return "Invalid Expression"
        
    if len(stack)!=1:
        return "Invalid Expression"   
    else:   
        return stack.pop()

print(calc())

    

