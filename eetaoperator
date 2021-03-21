import math
import itertools
from sympy import *

t = Symbol('t')

def u(t):
    return 1,sin(t),cos(t)


def Eeta(eta,t0):
    Eetatemp=1
    for i in eta:
        Eetatemp=integrate(u(t)[i]*Eetatemp,(t,t0,t))
    return Eetatemp

#print(Eeta((1,),0))

def Eetavec(etalist,t0):
    Eetavectemp=[]
    for i in etalist:
        Eetavectemp.append(Eeta(i,t0))
    return Eetavectemp

#Eetavec([[0,0],[1,0,0,1]],0)

def getalletas(m,J):
    alletas=[]
    vocabulary=list(range(m+1))
    for i in list(range(1,J+1)):
        alletas.append(itertools.product(vocabulary, repeat = i))
    return alletas


#for i in getalletas(2,3):
#    for j in i:
#        print(j)
        
def Eetafliess(J,t0):
    m=len(u(t))-1
    Eetafliesstmp=[]
    for i in getalletas(m,J):
        Eetafliesstmp.append(Eetavec(i,t0))
    return Eetafliesstmp
   
    
Eetafliess(2,0)
