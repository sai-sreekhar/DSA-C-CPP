def insertionSort(arr):
  
    for i in range(1, len(arr)):
  
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j] :
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = key
    return arr

list = [12,45,23,51,19,8]

print(insertionSort(list))
