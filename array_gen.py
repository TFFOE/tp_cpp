from random import randint
import sys

f = open("build/test.arr", "w")
n = randint(100, 1000)

if len(sys.argv)> 1:
    n = int(sys.argv[1])

f.write(str(n)+'\n')

for _ in range(n):
    f.write(str(randint(0, 12032030)) + '\n')