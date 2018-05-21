 tri=set([x*(x+1)/2 for x in xrange(1,100)])   
 ans=0   
 for x in word:  
    tmp=0  
    for i in x:  
        tmp+=ord(i)-ord('A')+1  
    if tmp in tri:  
        ans+=1 