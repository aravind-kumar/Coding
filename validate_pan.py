# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
pattern = r'^[A-Z]{5}[0-9]{4}[A-Z]$'
n = input()
for i in range(int(n)):
    inputString = input()
    output = re.match(pattern,inputString)
    if output:
        print('YES')
    else:
        print('NO')
