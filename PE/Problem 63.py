cnt = 0  
for i in range(1, 10):  
    e = 1  
    while True:  
        if len(str(i**e)) != e:  
            break  
        e += 1  
        cnt += 1  
print (cnt) 