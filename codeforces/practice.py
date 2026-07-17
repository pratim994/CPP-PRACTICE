import sys
import os 
import pathlib
import shutils


class Solution:
    def __init__(self):
        self.value = value

#question number 1 solution

    @evaluate
    def addList(ls):
        lst = []
        for i in range(len(ls)):
            for c in range(n-1,-1,-1):
                if ls[c] != ls[i]:

                    lst.append(ls[c])

        return lst


    
#question 2

    def maxTuple(tp):

        sorted(tp, key=True)

        return max(tp)

#q3 

    def maxNumber(n : list[list[]]) -> int:

        m = -sys.maxsize -1

        for ch in n:
            for c in ch:
                m = max(m,c)



        return m


#q4

    def uniqueDict(ls):

        ans = {}
        ls = []

        for ch in ls.values():
            ls.append(ch)

            for c in ls:

                if c.value() not in ls:

                    ans.append(c)

        return ans


#q5 
    def advPalindrome(s: str) -> bool:

        s.tolower()

        s.remove(" ")

        s = re.compile(r'/s+')

        for i in range(1, len(s)):
            for j in range(len(s)-1,-1,-1):

                if s[i] != s[j]:

                    return False


        return True


        

