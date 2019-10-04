def numfac(n):
    # Square case
    if (n**0.5==int(n**0.5)):
        num = 0
        for i in range(1, int(n**0.5)):
            if (n % i == 0):
                num += 2
        num += 1
        return num
    # All other cases
    num = 0
    for i in range(1, int(n**0.5)+1):
        if (n % i == 0):
            num += 2
    return num

n = 1
while (numfac(n*(n+1)//2)<=500):
    n += 1

print (n*(n+1)//2)
