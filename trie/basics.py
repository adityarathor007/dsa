class Node:
    def __init__(self):
        self.children=[None]*26
        self.is_end_of_word=False
        self.count=0
        self.prefixCount=0


class Trie:
    def __init__(self):
        self.root=Node()

    def insert(self,word):
        node=self.root
        for ch in word:
            idx=ord(ch)-ord('a')
            if not node.children[idx]:
                node.children[idx]=Node()

            node=node.children[idx]
            node.prefixCount+=1


        if not node.is_end_of_word:
            node.is_end_of_word=True

        node.count+=1

    def search_with_count(self,word):
        node=self.root
        for ch in word:
            idx=ord(ch)-ord('a')
            if not node.children[idx]:
                return False,0
            node=node.children[idx]

        return node.is_end_of_word,node.count

    def count_occu(self,word):
        present,count=self.search_with_count(word)
        return count


    def starts_with(self,prefix):
        node=self.root
        for ch in prefix:
            idx=ord(ch)-ord('a')
            if not node.children[idx]:
                return False,0

            node=node.children[idx]

        return True,node.prefixCount

    def countWordsStartingWith(self,prefix):
        possible,count=self.starts_with(prefix)
        return count

    def erase(self,word):
        possible,count=self.search_with_count(word)
        if not possible:
            print(f"Cant erase as the given string {word} not present in the trie")
            return

        node=self.root
        for ch in word:
            idx=ord(ch)-ord('a')
            node=node.children[idx]
            node.prefixCount-=1

        node.is_end_of_word=False
        node.count-=1

        print(f"Given word {word} deleted successfully")
        return

def checkWordPresent(trie,word):
    if trie.search(word):
        print("Word present in the trie")

    else:
        print("Word not present in the trie. It can be inserted via the insert function")


def checkPrefixPresent(trie,prefix):
    if trie.starts_with(prefix):
        print("Prefix present in the trie")

    else:
        print("Prefix not present in the trie")


trie=Trie()
# trie.insert('apple')
# trie.insert('axe')
# trie.insert('bat')

# checkWordPresent(trie,'apple')
# checkWordPresent(trie,'ap')
# checkPrefixPresent(trie,'ap')


trie.insert('abc')
trie.insert('book')
trie.insert('apple')
print(trie.count_occu('apple'))
trie.insert('abd')
trie.insert('abr')
# print(trie.countWordsStartingWith('ab'))
# trie.erase('abc')
# print(trie.countWordsStartingWith('ab'))
# print(trie.count_occu('abc'))
# print(trie.countWordsStartingWith('abc'))

# trie.insert('abp')
# print(trie.countWordsStartingWith('abc'))
# print(trie.countWordsStartingWith('abp'))

print(trie.countWordsStartingWith('ap'))
trie.erase('apple')
print(trie.countWordsStartingWith('ap'))
