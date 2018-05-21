import re  

ans=0  
for line in open("p089_roman.txt"):  
    a=len(line)  
    line=re.sub('DCCCC|LXXXX|VIIII|CCCC|XXXX|IIII','aa',line)  
    b=len(line)  
    ans=ans+a-b 
    
print(ans)  