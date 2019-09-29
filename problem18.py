import numpy as np
import matplotlib.pyplot as plt 
from mpl_toolkits.mplot3d import Axes3D

def line_dir_pt(m,A):
  len = 10
  x_AB = np.zeros((3,len))
  lam_1 = np.linspace(-2,10,len)
  for i in range(len):
    temp1 = A + lam_1[i]*m
    x_AB[:,i]= temp1.T
  return x_AB

#defining A,B,C,n,k
A = np.loadtxt("A.dat").reshape(3,1)
B = np.loadtxt("B.dat").reshape(3,1)
C = np.loadtxt("C.dat").reshape(3,1)
n = np.loadtxt("n.dat").reshape(3,1)
k = np.loadtxt("k.dat")

#creating x,y for 3D plotting

xx, yy = np.meshgrid([-1,2], [-1,2])
#setting up plot
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d',aspect='equal')
#corresponding z for plane
z1 = ((k-n[0]*xx-n[1]*yy)*1.0)/(n[2])

#defining lines : x(k) = A + k*l
A1 = A
l1 = A-B
A2 = B
l2 = B-C
A3 = C
l3 = A-C


#generating points in line 
l1_p = line_dir_pt(l1,A1)
l2_p = line_dir_pt(l2,A2)
l3_p = line_dir_pt(l3,A3)

#plotting line
plt.plot(l1_p[0,:],l1_p[1,:],l1_p[2,:],label="Line L1")
plt.plot(l2_p[0,:],l2_p[1,:],l2_p[2,:],label="Line L2")
plt.plot(l3_p[0,:],l3_p[1,:],l3_p[2,:],label="AB")

#plotting point
ax.scatter(A[0],A[1],A[2],'o',label="Point A")
ax.scatter(B[0],B[1],B[2],'o',label="Point B")
ax.scatter(C[0],C[1],C[2],'o',label="Point C")
ax.text(1.1,0.1,0.1,'A')
ax.text(0.6,0.6,0.1,'B')
ax.text(0.34,0.34,0.34,'C')


ax.plot_surface(xx, yy, z1, color='r',alpha=0.1,label="plane p")
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.xlim((-0.6,0.6))
plt.ylim((-0.6,0.6))
plt.grid()
plt.show() 
