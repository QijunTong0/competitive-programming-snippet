import numpy as n
from scipy.ndimage.morphology import binary_dilation as f
h, w = map(int, input().split())
s = n.where(n.array(eval("list(input()),"*h)) == '.', 1, 0)
k = n.ones((3, 3))
t = f(s, k)
e = "possible"
p = print
if n.all(s == (1-f(1-t, k))):
    p(e)
    [p(*q, sep="") for q in n.where(t, ".", "#")]
else:
    p("im"+e)
