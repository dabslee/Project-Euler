def strval(s):
    val = 0
    for c in s:
        val += ord(c) - ord('A') + 1
    return val

f = open("names.txt", 'r')

fcomma = f.readline().split(",")
f.close()

mylist = []
for s in fcomma:
    mylist.append(s[1:len(s)-1])

mylist = sorted(mylist)

mysum = 0
i = 1
for s in mylist:
    mysum += i * strval(s)
    i += 1

print(mysum)
