num= []

for x in open("/home/adityar/Documents/CODE2/Py/input.txt"):
    num.append(int(x))

count= 0

current_sum= 0
for i in range(1997):
    current_sum= num[i] + num[i+1] + num[i+2]
    if ((num[i+1] + num[i+2] + num[i+3]) > current_sum ):
        count += 1
        print(current_sum, num[i+1] + num[i+2] + num[i+3])

print(count)