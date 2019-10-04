f = 1
i = 1
fp = 0

while (len(str(f)) < 1000):
    i += 1
    temp = f
    f = fp + f
    fp = temp

print(i)
