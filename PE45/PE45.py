def pentagonal(p):
    return (1+(1+24*p)**0.5)%6==0

def hexagonal(h):
    return (1+(1+8*h)**0.5)%4==0

for n in range(1, 1000000):
    t = n*(n+1)/2
    if (pentagonal(t) and hexagonal(t)):
        print(int(t))
