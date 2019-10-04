# ( ͡° ͜ʖ ͡°)

import datetime

# You know what's up

numsuns = 0
for year in range(1901, 2000+1):
    for month in range(1, 12+1):
        if (datetime.date(year, month, 1).weekday()==6):
            numsuns += 1
print(numsuns)
