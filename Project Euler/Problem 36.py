def check(x):
    tp=str(x)
    for i in range(len(tp)//2):
        if tp[i]!=tp[len(tp)-1-i]:
            return False
    return True

def binary(x):
    f=[]
    t=x
    while(t>0):
        f.append(t%2)
        t=t//2
    n=0
    res=''
    while(n<len(f)):
        res+=str(f[n])
        n+=1
    return res

sum=0
for i in range(1000000):
    x=i
    y=binary(x)
    if(check(x)==True and check(y)==True):
        sum+=x
        print(x,' ',y)
print(sum)