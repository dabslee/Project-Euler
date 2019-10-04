f = 1
fp = 1

s = 0
while (f <= 4000000):
    if (f % 2 == 0):
        s += f
    temp = f
    f += fp
    fp = temp

print (s)
