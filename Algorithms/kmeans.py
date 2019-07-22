import numpy as np
import time
import matplotlib.pyplot as plt

# Func1: calculate Eulidean distance
def eulDistance(vector1, vector2):
	return np.sqrt(np.sum(np.power(vector2-vector1, 2)));

# Func2: initialize centroids with random samples
def initCentroids(dataset, k):
	numSamples, dim = dataset.shape
	centroids = np.zeros((k, dim))
	for i in range(k):
		index = int(np.random.uniform(0,numSamples))
		centroids[i, :] = dataset[index, :]
	return centroids

# Func3: k-means cluster
def kmeans(dataset, k):
	numSamples = dataset.shape[0]
	# first column stores which cluster this sample belong to,
	# second column stores the error between this sample and its centroid
	clusterAssment = np.mat(np.zeros((numSamples, k)))
	clusterChanged = True

	# Step 1: init centroids
	centroids = initCentroids(dataset, k)

	while clusterChanged:
		clusterChanged = False
		## for each example
		for i in range(numSamples): # python3 中 range 就是 xrange
			minDist = 10000.0
			minIndex = 0
			# for each centroid
			# Step 2: find the centroid who is closest
			for j in range(k):
				distance = eulDistance(centroid[j,:], numSamples[i,:])
				if distance<minDist:
					minDist = distance
					minIndex = j

			# Step 3: update its cluster
			if clusterAssment[i,0] != minIndex:
				clusterChanged = True
				clusterAssment[i,:] = minIndex, minDist**2 # 连续赋值，厉害

		# Step 4: update centroids
		for j in range(k):
			pointsInCluster = dataset[np.nonzero(clusterAssment[:,0].A==j)]
			centroids[j,:] = np.mean(pointsInCluster, axis=0)

	return centroids, clusterAssment


