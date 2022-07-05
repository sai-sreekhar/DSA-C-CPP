def sort(nums):

    for i in range(5):
        minpos = i
        for j in range(i+1,6):
            if nums[j] < nums[minpos]:
                minpos = j


        nums[i],nums[minpos] = nums[minpos],nums[i]
        
    print(nums)  


nums = [5, 3, 8, 6, 7, 2]
sort(nums)