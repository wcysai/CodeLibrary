x=''
for i in range(1,10000000):
    if len(x)>1000005:
        break
    x+=str(i)

print(len(x))
l=int(x[0])*int(x[9])*int(x[99])*int(x[999])*int(x[9999])*int(x[99999])*\
    int(x[999999])

print(l)