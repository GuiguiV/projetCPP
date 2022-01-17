import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

with open("out.txt") as file:
    lines = file.readlines()
    N_etapes = len(lines)
    taille_portion = len(lines[0])
    array = [line.split(" ")[:-1] for line in lines]
    heat = np.array(array).astype(np.float).flatten()
    print(heat)
"""
X, T = np.indices((taille_portion,N_etapes))
X = X.flatten()
T = T.flatten()"""
fig = plt.figure()

X = np.arange(0, taille_portion,1)
Y = np.arange(0, N_etapes,1)
X, Y = np.meshgrid(X, Y)

ax = fig.add_subplot(111, projection='3d')

Axes3D.plot_surface(X,Y,heat)

"""plt.plot(X,heat)
plt.show()"""