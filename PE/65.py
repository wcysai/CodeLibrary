arr = []  
arr.append(2)  
for i in range(1, 50):  
    arr.append(1)  
    arr.append(2 * i)  
    arr.append(1)  
up = 1  
now = 99  
down = arr[now]  
for i in range(now - 1, -1, -1):  
    ta = arr[i] * down + up  
    up = down  
    down = ta  
sum = 0  
up = down  
print(up)
print(sum)
while up:  
    sum+=up%10  
    up//=10  
print(sum)  