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
theta =30* np.pi/180
theta1 = 90* np.pi/180

k=11

e1=np.array([[1],[0],[0]])
X=np.array([[0],[0]])
q1=np.array([[1,1,1],[np.cos(theta1),np.cos(theta),-1],[np.sin(theta1),-np.sin(theta),0]])

q2=k*e1
z=np.linalg.solve(q1,q2)

print(z)

print(z[0][0]+z[1][0]+z[2][0])
Y=np.array([[z[0][0]],[z[2][0]]])

Z=np.array([[z[0][0]],[0]])

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


plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

plt.savefig('fig.pdf')


#plt.show()
