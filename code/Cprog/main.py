import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
#local imports
#from line.funcs import *
#from triangle.funcs import *
#from conics.funcs import circ_gen

def line_gen(X,Z):
   len =10
   dim = X.shape[0]
   x_XZ = np.zeros((dim,len))
   lam_1 = np.linspace(0,1,len)
   for i in range(len):
     temp1 = X + lam_1[i]*(Z-X)
     x_XZ[:,i]= temp1.T
   return x_XZ

def dir_vec(X,Z):
   return Z-X
def norm_vec(X,Z):
   return (omat@dir_vec(X,Z))

#Input parameters
x=np.loadtxt('X.dat',dtype='float')
q=np.loadtxt('q.dat',dtype='float')
Q=q.reshape(3,1)
X=x.reshape(2,1)
print(Q)

Y=np.array([[Q[1][0]],[Q[0][0]]])

Z=np.array([[Q[1][0]],[0]])

l=(np.linalg.norm(Z-X))
m=(np.linalg.norm(X-Y))
#print(round(l-m,1))

##Generating all lines
x_ZY = line_gen(Z,Y)
x_XZ = line_gen(X,Z)
x_YX = line_gen(Y,X)
#Plotting all lines
plt.plot(x_YX[0,:],x_YX[1,:],label='$c$')
plt.plot(x_XZ[0,:],x_XZ[1,:],label='$b$')
plt.plot(x_ZY[0,:],x_ZY[1,:],label='$a$')
#Labeling the coordinates
M = np.block([Y,Z,X]).T

vert_labels = ['Y','Z','X']

plt.scatter(M[:, 0], M[:, 1])
# Label the points if the plot is a triangle
if M.shape[0] == 3:
    for i, txt in enumerate(vert_labels):   
        plt.annotate(txt, (M[i, 0], M[i, 1]), textcoords="offset points", xytext=(0, 10), ha='center')

#plotting the points of X,Y,Z
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

plt.savefig('/data/data/com.termux/files/home/code/figs/fig.pdf')


#plt.show()
