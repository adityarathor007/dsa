class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """

        wordSet=set(wordList)
        wordSet.add(beginWord)

        queue=deque()
        queue.append([beginWord])

        ans=[]
        found=False

        while queue and not found:
           
            size = len(queue)
            current_level_words=set()

            for _ in range(size):
                words_till_cl=queue.popleft()
                current_word=words_till_cl[-1]
                
                if current_word==endWord:
                    ans.append(words_till_cl)
                    found=True
                    continue
                             

                for i in range(len(current_word)):
                    for j in range(26):
                        new_char=chr(97+j)
                        new_word=current_word[:i]+new_char+current_word[i+1:]

                        if new_word in wordSet and new_word!=current_word:
                            words_till_cl.append(new_word)
                            queue.append(words_till_cl[:])
                            current_level_words.add(new_word)
                            words_till_cl.pop()
            
            wordSet-=current_level_words
        return ans