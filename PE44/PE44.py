def is_pentagonal(n):
    return (1+(24*n+1)**0.5) % 6 == 0

flag = True
i = 1
while flag:
    for j in range(1, i):
        a = i*(3*i-1)/2
        b = j*(3*j-1)/2
        if is_pentagonal(a+b) and is_pentagonal(a-b):
            print (int(a-b))
            flag = False
            break
    i += 1
