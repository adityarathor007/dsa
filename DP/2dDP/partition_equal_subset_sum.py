# parition array into 2 subsets such that the sum of both them is equal

def checkSubsetSum(arr,target):
    n=len(arr)
    dp=[[False]*(target+1) for _ in range(n)]

    for i in range(n):
        dp[i][0]=True

    if arr[0]<=target:
        dp[0][arr[0]]=True


    for i in range(1,n):
        for k in range(1,target+1):
            notTake=dp[i-1][k]
            take=False
            if arr[i]<=k:
                take=dp[i-1][k-arr[i]]

            dp[i][k]=notTake or take


    return dp[n-1][target]



def canPartition(arr):
    arr_sum=sum(arr)

    if arr_sum%2:
        return False

    reqd_sum=arr_sum//2



    return checkSubsetSum(arr,reqd_sum)


t=int(input())

for _ in range(t):
    arr=list(map(int,input().split()))

    if canPartition(arr):
        print("Yes possible to partition in 2 subsets of equal sum")
    else:
        print("Not possible")
