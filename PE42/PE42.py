def value (s):
    mysum = 0
    for c in s:
        mysum += ord(c) - ord('A') + 1
    return mysum

triangles = []
for i in range(1000):
    triangles.append(i*(i+1)//2)

myfile = open("words.txt", 'r')
words = myfile.readline().rstrip().split(",")
for i in range(len(words)):
    words[i] = words[i].replace("\"", "")

count = 0
for word in words:
    if (value(word) in triangles):
        count += 1
print(count)
