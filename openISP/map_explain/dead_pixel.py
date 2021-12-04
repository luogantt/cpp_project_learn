from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

fig = plt.figure()
ax = Axes3D(fig)
X = np.arange(-4, 4, 0.02)
Y = np.arange(-4, 4, 0.02)
X, Y = np.meshgrid(X, Y)
R = 1/((X**2 + Y**2)+0.1)
Z = R
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='rainbow')
plt.savefig('t.png')#保存图片
plt.show()