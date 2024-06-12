# cook your dish here
from numpy import random

t=int(input())

while t:
    t -= 1
    n=int(input())

    while(True):
        arr=random.randint(100, size=(n))
        print(arr)  

        if(n==1):
            break
        
        i=0
        ans_p=arr[i]
        for i in range(1, n):
            ans_p=arr[i]&ans_p
            if(ans_p<(~ans_p)):
                break
        
        j=n-1
        ans_s=arr[j]
        
        for j in range(n-2, -1, -1):
            ans_s=ans_s&arr[j]
            if(ans_s>(~ans_s)):
                break
            
        print(i)
        print(j)
        if i==n-1 and j==0:
            break
    
    print(arr)

   
