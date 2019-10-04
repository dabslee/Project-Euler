def sumdiv(n):
    num = 0
    # square number case
    if (n ** 0.5 == int(n ** 0.5)):
        for f in range(1, 1+int(n ** 0.5)):
            if (n % f == 0):
                num += f + n//f
        num -= int(n ** 0.5)
        return num - n
    else:
        for f in range(1, 1+int(n ** 0.5)):
            if (n % f == 0):
                num += f + n//f
        return num - n

proper = []
for i in range(2, 10000):
    j = sumdiv(i)
    if j in proper:
        continue
    if (i == j):
        continue
    if (i==sumdiv(j)):
        proper.append(i)
        proper.append(j)

print(sum(proper))
