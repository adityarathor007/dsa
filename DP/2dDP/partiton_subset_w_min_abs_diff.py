def minimumDifference(nums):
    nums_sum=sum(nums)
    n=len(nums)


    dp=[[False]*(nums_sum+1) for _ in range(n)]

    for i in range(n):
        dp[i][0]=True

    if nums[0]<=nums_sum:
        dp[0][nums[0]]=True

    for i in range(1,n):
        for k in range(1,nums_sum+1):
            notTake=dp[i-1][k]
            take=False
            if nums[i]<=k:
                take=dp[i-1][k-nums[i]]

            dp[i][k]=notTake or take


    min_diff=float('inf')

    for s1 in range(1,nums_sum//2+1):
        if dp[n-1][s1]:
            s2=nums_sum-s1
            min_diff=min(min_diff,abs(s2-s1))

    return min_diff


t=int(input())
for _ in range(t):
    arr=list(map(int,input().split))
    print(minimumDifference(arr))
    
