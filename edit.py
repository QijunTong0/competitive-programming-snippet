import numpy as np
n = int(input())
ans = 0
for i in range(100):
    ans += ((i+1) % n == 0)
print(100-ans)
