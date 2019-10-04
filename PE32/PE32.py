# make the list of permutations
def permutation(lst):
    if len(lst) == 0: 
        return [] 
    if len(lst) == 1: 
        return [lst] 
    l = []
    for i in range(len(lst)): 
       m = lst[i] 
       remLst = lst[:i] + lst[i+1:] 
       for p in permutation(remLst): 
           l.append([m] + p) 
    return l

permlists = permutation([1, 2, 3, 4, 5, 6, 7, 8, 9])
permstrs = []

for lst in permlists:
    tempstr = ""
    for i in lst:
        tempstr += str(i)
    permstrs.append(tempstr)

# for each of the permutations, try adding the x and the =
myset = set()
for perm in permstrs:
    for x in range(9):
        for e in range(x+1, 8):
            #print(perm[:x+1])
            #print(perm[x+1:e+1])
            #print(perm[e+1:])
            #print()
            if (int(perm[:x+1])*int(perm[x+1:e+1])==int(perm[e+1:])):
                myset.add(int(perm[e+1:]))

print(sum(myset))
