from collections import deque,defaultdict

def find_toposort(adjList):
    queue=deque()

    indegree_arr={}

    for node,neighbours in adjList.items():
        if node not in indegree_arr:
            indegree_arr[node]=0
        for neighbour in neighbours:
            if neighbour not in indegree_arr:
                indegree_arr[neighbour]=0
            indegree_arr[neighbour]+=1


    for node in indegree_arr.keys():
        if indegree_arr[node]==0:
            queue.append(node)

    topoSort_order=[]
    while queue:
        cn=queue.popleft()
        topoSort_order.append(cn)
        for neighbour in adjList[cn]:
            indegree_arr[neighbour]-=1
            if indegree_arr[neighbour]==0:
                queue.append(neighbour)

    print(topoSort_order)

    if len(topoSort_order)!=len(adjList):
        return ""

    return topoSort_order


def find_dict(words):
    #create adjList
    adjList={}

    for word in words:
        for char in word:
            if char not in adjList:
                adjList[char]=[]


    # create adjList from the words
    for i in range(len(words)-1):
        if len(words[i])>len(words[i+1]) and words[i].startswith(words[i+1]):
            return ""
        for k in range(min(len(words[i]),len(words[i+1]))):
            if words[i][k]!=words[i+1][k]:
                adjList[words[i][k]].append(words[i+1][k])
                break


    # find TopoSort order
    print(adjList)

    return(find_toposort(adjList))





if __name__=="__main__":
    # words=["baa","abcd","abca","cab","cad"]
    # words=["addbb", "dabcc", "cda", "bc", "a", "a"]
    words=["abc","ab"]
    # words=["z", "x"]
    # words=["abd","abc"]
    print(find_dict(words))
