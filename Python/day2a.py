
ans = []
for num in open("/home/adityar/Documents/CODE2/Py/2_input.txt"):
    data= num.split()
    data[1]= int(data[1])
    ans.append(data)
   

horizontal = 0
depth =0
for T in ans:
    if T[0]=='forward':
        horizontal+=T[1]
    elif T[0]=='up':
        depth-=T[1]
    elif T[0]=='down':
        depth+=T[1]    
    else:
        pass      

print(horizontal*depth)            
