# for this the maximum numbers possible can be 2 as if it was 3 then none of them will be > n/3
# for example if n=8 then we need freq of >=3 and if 3 numbers then it will be n=9 which is wrong


def moore_voting_algo(list):
    n=len(list)

    cnt1=0
    cnt2=0
    el1=float('-inf')
    el2=float('-inf')

    for num in list:
        if cnt1==0 and num!=el2:
            cnt1=1
            el1=num
        elif cnt2==0 and num!=el1:
            cnt2=1
            el2=num

        elif el1==num:
            cnt1+=1
        elif el2==num:
            cnt2+=1

        else:
            cnt1-=1
            cnt2-=1


    # checking potential candidate
    cnt_f1=0
    cnt_f2=0
    for num in list:
        if el1==num:
            cnt_f1+=1
        elif el2==num:
            cnt_f2+=1

    ans=[]
    if cnt_f1>n/3:
        ans.append(el1)

    if cnt_f2>n/3:
        ans.append(el2)


    return ans



list=[1,1,1,1,3,2,2,2]
print(moore_voting_algo(list))
