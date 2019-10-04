def cyclelen (d):
    rems = set()
    count = 1
    i = 1
    while (i*10 % d not in rems):
        rems.add(i*10%d)
        i = i*10 % d
        count += 1
        if (i*10 % d == 0):
            return 0
    return count-1

maximum = 0
maxd = 0
for d in range(2, 1000):
    if (cyclelen(d)>maximum):
        maximum = cyclelen(d)
        maxd = d

print(maxd)
