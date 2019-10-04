myfile = open("PE13.txt", "r")
intlist = []

for i in range(100):
    intlist.append(int(myfile.readline().strip()))

print(str(sum(intlist))[:10])
