def reverse(s):
    ns = ""
    for i in s:
        ns = i + ns
    return ns

def isPalin(n):
    return (reverse(str(n))==str(n))

m = 0
for i in range(1, 1000):
    for j in range(1, 1000):
        if (isPalin(i*j) and i*j > m):
            m = i*j

print(m)
