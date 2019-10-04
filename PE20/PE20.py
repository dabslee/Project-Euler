fac = 1

for i in range(1, 100):
    fac *= i

facstr = str(fac)

mysum = 0
for s in facstr:
    mysum += ord(s) - ord('0')

print (mysum)
