def sss(n):  
    a = [1 for i in range(n)]  
    a[0], a[1], a[2] = 0, 0, 1  
    pl = []  
    t = s = 0  
    for i in range(2,n):  
        if a[i]:  
            s+=i  
            pl.append(i)  
            j=i*i  
            t+=1  
            while j<n:  
                a[j]=0  
                j+=i  
    return pl  
  
def check(x):  
    lis = [['1','2','3','4','5'],['1','2','3','4','5','6'],['1','2','3','4','5','6','7']]  
    x.sort()  
    if x in lis:  
        return 1  
    return 0  
  
  
def main():  
    max = 0  
    prime = sss(10000000)  
    for i in prime:  
        x = list(str(i))  
        if check(x):  
            max = i  
    print(max)  
  
if __name__ == '__main__':  
    main()  