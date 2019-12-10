import numpy as np
import matplotlib.pyplot as plt

# Import data
omp_file = open("../logs/times_omp.txt", "r")
omp_lines = omp_file.readlines()
omp = []
x = []
for i in omp_lines:
	x.append(float(i.split(' ')[0]))
	omp.append(float(i.split(' ')[1]))

no_omp_file = open("../logs/times_no_omp.txt", "r")
no_omp_lines = no_omp_file.readlines()
no_omp = []
for i in no_omp_lines:
	no_omp.append(float(i.split(' ')[1]))

plt.plot(x, omp, label='With parallelization')
plt.xticks(np.arange(min(x)-10, max(x)+200, 100))
plt.yticks(np.arange(min(omp), max(no_omp), 5.))

plt.xlabel("Resolution")
plt.ylabel("Raycasting Time (s)")

plt.plot(x, no_omp, label='Without parallelization')
plt.legend(loc='upper left')

plt.show()
