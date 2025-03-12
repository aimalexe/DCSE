import sys

previousWord = None
currentCount = 0
count = 0

for line in sys.stdin:
    line = line.strip()
    word, count = line.split('\t', 1)

    count = int(count)

    if previousWord == word:
        currentCount += count
    else:
        if previousWord:
            print('%s\t%s'%(previousWord, currentCount))
        
        currentCount = count
        previousWord = word

if previousWord == word:
    print('%s\t%s'%(previousWord, currentCount))