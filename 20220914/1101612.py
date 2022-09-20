import numpy as np

data = []

with open('Numbers.txt', 'r', encoding = 'utf-8') as f:
	lines = f.readlines()
	for line in lines:
		data.append(line.split())

data = np.array(data, dtype = np.int32)
data = np.transpose(data)
print(data)
