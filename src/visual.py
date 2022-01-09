import matplotlib.pyplot as plt
import numpy as np

with open("out.txt") as file:
    line = file.read().split()
    heat = np.array(line)

X = np.linspace(0,1,10)
plt.plot(X,heat)
plt.show()