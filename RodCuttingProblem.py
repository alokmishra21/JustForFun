class MaxRevenueByRodCutting:
    
    def __init__(self, p):
        self.r = [0]*(len(p)+1)
        self.size = len(p)
        self.price = p
        
    def btmUpMaxRevenue(self, n):
        '''
            This function returns the maximum
            revenue from cutting a rod of length
            size and the way to cut it
        '''
        s = [0]*(n+1)
        for length in range(n+1):
            if length is 0:
                    continue
            q = -1
            for cut in range(length+1):
                if cut is 0:
                    continue
                if q < self.price[cut] + self.r[ length - cut ]:
                    q = self.price[cut] + self.r[ length - cut ]
                    s[length] = cut
            self.r[length] = q
            
        return self.r[n],s
    
    def wayToCut(self, length):
        '''
            This function returns the way to
            cut the rod in such a way that it
            generates maximum revenue 
        '''
        maxRevenue, way = self.btmUpMaxRevenue(length)
        print("maximum revenue for cutting rod of length {}  is {} ".format(length, maxRevenue))
        
        while length > 0:
            print("cut at : ",way[length])
            length = length - way[length]
            
        self.printTables(way)
            
    def printTables(self, s):
        print("printing the revenue table: ")
        for i in range(len(s)):
            print("{} ".format(self.r[i]),end="")
        print()
        print("printing the optimal cut table: ")
        for i in range(len(s)):
            print("{} ".format(s[i]),end="")
        
#------------------------------------------------            
# price table for length of different sizes
p = [0,1,5,8,9,10,17,17,20,24,30]
#------------------------------------------------            
obj = MaxRevenueByRodCutting(p)

obj.wayToCut(6)

