import numpy as np 

# compute the eucludian distance
def euliDistance(vector1, vector2):
	return np.sqrt(np.sum(np.power(vector2 - vector1, 2)))

# initialize the ccentroids
def initCentroids(dataset, k):
	numSamples, numFeatures = dataset.shape
	centroids = dataset[np.random.randint(0,numSamples,size=k),:]
	return centroids

# kmeans clustering
def kmeans(dataset, k):
	numSamples, numFeatures = dataset.shape

	# initialize centroids
	centroids = initCentroids(dataset, k)

	# initialize results 
	clusterResult = np.zeros((numSamples, 2))
	clusterChanged = True

	while clusterChanged:
		clusterChanged = False

		for i in range(numSamples):
			# update for every sample
			minIndex = 0
			minDistance = 10000.0

			for j in range(k):
				distance = euliDistance(numSamples[i, :], centroids[j, :])
				if distance<minDistance:
					minDistance = distance
					minIndex = j				

			# update for every sample
			if minIndex != clusterResult[i, 0]:
				clusterResult[i, :] = minIndex, minDistance
				clusterChanged = True

		# Update the centroids every iteration
		for j in range(k):
			centroids[j, :] = np.mean(dataset[clusterResult[:, 0]==j], axis=0)

	return centroids, clusterResult
