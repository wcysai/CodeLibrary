for i in range(1,100000):
    for j in range(i*i+1,i*i+2*i+1):
        if ((i*i*i*i)%j==0):
            p=j-i*i
            q=i*i-int(i*i*i*i/j)i
            print(i,p,q)
            break

