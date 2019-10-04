ones = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
teens = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

# must be less than 100
def twodigit(n):
    if (n < 10):
        return ones[n]
    elif (n < 20):
        return teens[n-10]
    return tens[n//10] + ones[n%10]

def threedigit(n):
    if (n < 100):
        return twodigit(n)
    if (n == 1000):
        return "onethousand"
    if (n%100 != 0):
        return ones[n//100] + "hundredand" + twodigit(n%100)
    return ones[n//100] + "hundred"

mysum = 0
for i in range(1, 1000+1):
    mysum += len(threedigit(i))
print(mysum)
