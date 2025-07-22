# top down dp
def findMaxProfit(i,max_w,wts,prices,dp):
    if i==0:
        if wts[i]<=max_w:
            return prices[0]
        else:
            return 0

    if dp[i][max_w]!=-1:
        return dp[i][max_w]

    exc=findMaxProfit(i-1,max_w,wts,prices,dp)
    inc=0
    if wts[i]<=max_w:
        inc=prices[i]+findMaxProfit(i-1,max_w-wts[i],wts,prices,dp)

    dp[i][max_w]=max(exc,inc)
    return dp[i][max_w]


def findMaxProfit(n,max_w,wts,prices):
    # dp=[[0]*(max_w+1) for _ in range(n)]
    #space optimization
    prev=[0]*(max_w+1)
    curr=[0]*(max_w+1)

    # base case
    for wt in range(wts[0],max_w+1):
        # dp[0][wt]=prices[0]
        prev[wt]=prices[0]

    for i in range(1,n):
        for wt in range(1,max_w+1):
            # exc=dp[i-1][wt]
            exc=prev[wt]
            inc=0
            if wts[i]<=wt:
                # inc=prices[i]+dp[i-1][wt-wts[i]]
                inc=prices[i]+prev[wt]

            # dp[i][wt]=max(exc,inc)
            curr[wt]=max(exc,inc)

        prev=curr


    # return dp[n-1][max_w]
    return prev[max_w]

t=int(input())
for _ in range(t):
    n,max_w=list(map(int,input().split()))
    wts=list(map(int,input().split()))
    prices=list(map(int,input().split()))


    # dp=[[-1]*(max_w+1) for _ in range(n)]

    # print(findMaxProfit(n-1,max_w,wts,prices,dp))


    print(findMaxProfit(n,max_w,wts,prices))
