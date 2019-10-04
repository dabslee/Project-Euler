# ib10 = integer base 10
# ib2 = integer base 2

def toib2(ib10):
    return int(bin(ib10)[2:])

def check10(ib10):
    return (str(ib10) == str(ib10)[::-1])

def check2(ib10):
    ib2 = toib2(ib10)
    return (str(ib2) == str(ib2)[::-1])

mysum = 0
for i in range(1, 1000000):
    if (check10(i) and check2(i)):
        mysum += i
print(mysum)
