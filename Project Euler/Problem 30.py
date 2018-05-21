sum=0
for i in range(2,3000000):
    x=0
    tp=i
    while(tp>0):
        s=tp%10
        x+=(s**5)
        tp=tp//10
    if i==x:
        sum+=x
print(sum)