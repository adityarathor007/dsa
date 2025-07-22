# # PS: given an array and target and we need to say true or false whether a subset's sum is possible or not
# def checkSubsetSum(arr,i,target,dp):
#     if target==0:
#         return 1

#     if i==0:
#         return 1 if arr[i]==target else 0

#     if dp[i][target]!=-1:
#         return dp[i][target]


#     notTake=checkSubsetSum(arr,i-1,target,dp)

#     take=False
#     if arr[i]<=target:
#         take=checkSubsetSum(arr,i-1,target-arr[i],dp)


#     if notTake or take:
#         dp[i][target]=1
#     else:
#         dp[i][target]=0

#     return dp[i][target]



# t=int(input())

# for _ in range(t):
#     arr=list(map(int,input().split()))
#     target=int(input())
#     n=len(arr)

#     # # memoization
#     # dp=[[-1]*(target+1) for _ in range(n)]


#     # if checkSubsetSum(arr,n-1,target,dp)==1:
#     #     print("Target possible to achieve")
#     # else:
#     #     print("Target not possible to be achieved by any subset's sum")


#     # tabulation

#     dp=[[False]*(target+1) for _ in range(n)]

#     # base case
#     for i in range(n):
#         dp[i][0]=True

#     if arr[0]<=target:
#         dp[0][arr[0]]=True

#     for i in range(1,n):
#         for k in range(1,target+1):
#             notTake=dp[i-1][k]
#             take=False
#             if arr[i]<=k:
#                 take=dp[i-1][k-arr[i]]

#             dp[i][k]= notTake or take



#     if dp[n-1][target]:
#         print("target possible to be achieved")
#     else:
#         print("Target not possible to be achieved by any subset's sum")




# Now instead of telling present or not we need to count the subsets


# def countSubsets(arr,i,target,dp):

    # !!! memoization !!!

    ## !!!! fails when 0s are present in the arr !!!!
    # if target==0:
    #     return 1

    # if i==0:
    #     return int(arr[0]==target)

    # !!!! -------- !!!!

    # if i==0:
    #     if target==0 and arr[i]==0:
    #         return 2
    #     if target==0 or target==arr[i]:
    #         return 1
    #     return 0


    # if dp[i][target]!=-1:
    #     return dp[i][target]


    # s1=countSubsets(arr,i-1,target,dp)
    # s2=0
    # if arr[i]<=target:
    #     s2=countSubsets(arr,i-1,target-arr[i],dp)

    # dp[i][target]=s1+s2
    # return dp[i][target]


    # !!! tabulation !!!

def countSubsets(arr,i,target):
    n=len(arr)
    dp=[[0]*(target+1) for _ in range(n)]


    # !!!! fails if the arr contains zeros  !!!!
    # for i in range(n):
    #     dp[i][0]=1

    # if arr[0]<=target:
    #     dp[0][arr[0]]=1

    # #  !!!! ---------- !!!!

    if arr[0]==0:
        dp[0][0]=2
    else:
        dp[0][0]=1

    if nums[0]!=0 and nums[0]<=target:
        dp[0][nums[0]]=1

    for i in range(1,n):
        for k in range(target+1):
            notTake=dp[i-1][k]
            take=0
            if arr[i]<=k:
                take=dp[i-1][k-arr[i]]

            dp[i][k]=notTake+take

    return dp[n-1][target]




t=int(input())
for _ in range(t):
    nums=list(map(int,input().split()))
    target=int(input())
    n=len(nums)


    # dp=[[-1]*(target+1) for _ in range(n)] # for memoization
    # print(countSubsets(nums,n-1,target,dp))

    print(countSubsets(nums,n-1,target))
