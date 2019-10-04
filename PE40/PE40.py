dstring = "0"
for i in range(1, 200000):
    dstring += str(i)

myprod = 1
for i in range(7):
    myprod *= int(dstring[10**i])
    print(int(dstring[10**i]))

print(myprod)
