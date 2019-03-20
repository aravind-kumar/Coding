# Enter your code here. Read input from STDIN. Print output to STDOUT
import re 
pattern = r'[Hh][Ii]\s[^dD]'
n = input()
for i in range(int(n)):
    inputString = input()
    res = re.match(pattern,inputString)
    if res:
        print(inputString)
