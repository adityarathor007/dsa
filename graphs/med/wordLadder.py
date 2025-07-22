class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        queue=deque()
        queue.append((beginWord,1))


        while queue:
            cw,cl=queue.popleft()
            if cw==endWord:
                return cl
            wl=len(cw)

            for i in range(wl):
                for j in range(26):
                    tw=cw
                    new_char=chr(97 + j)
                    tw = tw[:i] + new_char + tw[i+1:]
                    if tw in wordSet and tw!=cw:
                        queue.append((tw,cl+1))
                        wordSet.remove(tw)
        
        return 0    