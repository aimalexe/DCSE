import sys

for line in sys.stdin:
    line = line.strip()
    words = line.split()

    for word in words:
        word = word.lower()
        print("%s\t%s"%(word,1))