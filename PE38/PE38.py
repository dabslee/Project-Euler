def checkpan(nstr):
    if not len(nstr)==9:
        return False
    for i in range(1,10):
        if str(i) not in nstr:
            return False
    return True

mymax = 0
for i in range(10000):
    for n in range(1,10):
        concated = ""
        for j in range(1, n+1):
            concated += str(i*j)
        if (checkpan(concated)):
            mymax = max(int(concated),mymax)

print(mymax)
