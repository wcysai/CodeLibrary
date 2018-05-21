s = set()
for a in range(2, 101):  
    tmp = a  
    now = 0  
    for b in range(2, 101):  
        tmp *= a  
        if tmp in s:  
            pass  
        else:  
            now += 1  
            s.add(tmp)  
    print(a, now)  
print(len(s))