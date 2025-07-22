def brute_force(list):
    # take every element and count it in entire array which will be O(n^2)
    pass


def hash_table(list):
    # storing the count using hash table(dictionary)
    dict_table={}
    for i in list:
        if i in dict_table:
            dict_table[i]+=1
        else:
            dict_table[i]=1


    # this will be just one number as for it to be >n/2 so after cancelling by other numbers it is still having some value
    for i in dict.keys:
        if i>int(n/2):
            print(dict[i])




def moore_voting_algo(list):
    # moore voting algorithm (cancel out using different element for the potential candidate)
    el=-1
    cnt=0
    for i in list:
        if cnt==0:
            cnt=1
            el=i
        elif i==el:
            cnt+=1
        else:
            cnt-=1

    # verfication is needed as the potential candidate (in list of all unique it will give cnt of each as 1 which is not correct)
    cnt1=0
    for i in list:
        if el==i:
            cnt1+=1

    if cnt1>int(n/2):
        print(el)
    else:
        print(-1)





list=[2,2,1,3,1,1,3,1,1]
n=len(list)

# hash_table(list)

moore_voting_algo(list)
