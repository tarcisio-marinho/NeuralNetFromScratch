import matplotlib.pyplot as plt 
from matplotlib import style
import random
style.use("ggplot")


n = []
for i in range(100):
	x = (random.randint(0, 400))
	y = (random.randint(0, 400))
	if(x > y):
		plt.scatter(x,y,c='r')
	else:
		plt.scatter(x, y, c='b')

x1, y1 = [400, 0], [400, 0]
plt.plot(x1,y1, marker='o')
plt.show()

