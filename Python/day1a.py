
nums = []
for i in open("/home/adityar/Documents/CODE2/Py/input.txt"):
    nums.append(int(i))

count = 0
for T in range(1999):
    if(nums[T+1]>nums[T]):
        count+=1

print(count)            
