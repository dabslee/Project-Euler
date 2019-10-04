def sumofsq (n):
    s = 0
    for i in range(1, n+1):
        s += i**2
    return s

def sqofsum (n):
    return (((n+1)*n/2)**2)

n = 100
ans = (int)(abs(sumofsq(n)-sqofsum(n)))
print (ans)
