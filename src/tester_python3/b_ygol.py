#!/usr/bin/env python3
import math
epsilon_b = 0.01
epsilon_xy = 1e-10

def g_sincos(a,b,c):
    k = math.acos(a/math.sqrt(a*a+b*b))
    if (b/math.sqrt(a*a+b*b) >= 0):
        return k
    else:
        return (2*math.pi - k)

def min_0(a):
    if (math.fabs(a) < epsilon_xy):
        return 0
    else:
        return a

def makexy_b(h, g, bn):
    x = h * (math.tan(bn) - math.tan(bn - g))
    y = h * (math.tan(bn + g) - math.tan(bn))
    if (math.fabs(x - y) > epsilon_xy):
        b =(x*x-y*y)
        a = -2*(x*y*math.cos(2*g))
        c = x*x+y*y-2*(x+y)*(x+y)*math.sin(g)*math.sin(g)
        b1 = math.pi/2-math.asin(c/math.sqrt(a*a+b*b))
        #b2 = 
        s =c/(math.sqrt(a*a+b*b))
        d = a/(math.sqrt(a*a+b*b))
        b = (math.asin(s) - math.asin(d))/2
        print("b={0}({1}):c={6},g={5} x={2}, y={3}, h={4}".format( \
        math.degrees(min_0(b)), math.degrees(bn), x, y, h, math.degrees(g),\
        math.fabs(c/(math.sqrt(a*a+b*b))) ))
    else:
        print("b = 0")
    return 0

bn= 0
while (1):    
    a = [int(i) for i in input("Write h, g, b:\n").split()]
    h = a[0]
    g = math.radians(a[1])
    bn = math.radians(a[2])
    makexy_b(h, g, bn)
    

