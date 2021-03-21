import math
import itertools
from sympy import *
z = Symbol('z')

def g(z):
    return 1, cos(z)

def h(z):
    return sin(z)



def lied(eta):
    ltemp=h(z)
    for i in list(eta[::-1]):
        ltemp=diff(ltemp,z,1)*g(z)[i]
    return ltemp


def liedvec(etalist):
    liedvectmp=[]
    for i in etalist:
        liedvectmp.append(lied(i))
    return liedvectmp

def liedvecf(J):
    m=len(g(t))-1
    liedvecftmp=[]
    for i in getalletas(m,J):
        liedvecftmp.append(liedvec(i))
    return liedvecftmp


def liedvecfv(J,z0):
    liedvecfvtmp=[]
    for i in liedvecf(J):
        for j in i:   
            liedvecfvtmp.append(j)
    return liedvecfvtmp

v=liedvecfv(2,0)

def liedveval(v,z0):
    liedvevaltmp=[]
    for i in v:
        liedvevaltmp.append(i.subs({z:z0}).evalf())
    return liedvevaltmp
     


print(lied([0,0]))

print(liedvec([[0,0],[1,1]]))

print(liedvecf(2))

print(liedveval(v,1))
