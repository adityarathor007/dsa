def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans=[]
        for row in range(numRows):
            if row+1==1:
                ans.append([1])
            elif row+1==2:
                ans.append([1,1])
            else:
                vals=[1]
                for i in range(row-1):
                    vals.append(ans[row-1][i]+ans[row-1][i+1])
                vals.append(1)

                ans.append(vals)

        return ans  