# finds sum of proper divisors
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

# first find all the abundant numbers
# then find all the sums that can be found using them

abundants = []
# find all the abundant numbers
for i in range(1, 28123+1):
    if (sumdiv(i)>i):
        abundants.append(i)

# find all the sums that can be found using them
sums = set()
for i in range(len(abundants)):
    for j in range(i, len(abundants)):
        if (abundants[i]+abundants[j] <= 28123):
            sums.add(abundants[i]+abundants[j])

# subtract out all the abundants
print(28123*(28123+1)//2 - sum(sums))
