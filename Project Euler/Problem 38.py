ans=0  
for i in range(10000):  
    tmp=''  
    j=1  
    while len(tmp) <9:  
        tmp=tmp+str(j*i)  
        j+=1  
    if len(tmp)==9 and not '0' in tmp and len(set(tmp))==9 and int(tmp)>ans:  
        ans=int(tmp)  
print(ans)