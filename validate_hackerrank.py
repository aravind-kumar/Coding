# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
patternStart = r'^hackerrank.*'
patternEnd = r'.*hackerrank$'
n = input()
for i in range(int(n)):
    inputString = input()
    startMatch = re.match(patternStart,inputString)
    endMatch = re.match(patternEnd,inputString)
    if startMatch and endMatch:
        print("0")
    elif startMatch:
        print("1")
    elif endMatch:
        print("2")
    else:
        print("-1")


