def sort(list):
    i = 0
    while i<len(list)-1:
        j = 0
        while j<len(list)-1:
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
            j += 1
        i += 1
    return list

list = [5, 3, 8, 6, 7, 2]
print(sort(list))

