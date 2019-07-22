import numpy as np 

def kNNclassify(input, dataset, labels, k):
	numSamples, numFeatures = dataset.shape

	# calculate Euclidean distance
	distances = np.sqrt(np.sum(np.power(tile(input, (numSamples,1)) - dataset, 2), 
		axis = 1))

	sortDistIndices = np.argsort(distances)

	classCount = {}

	for i in range(k):
		# choose min k distance
		voteLabels = labels[sortDistIndices[i]]

		classCount[voteLabels] = classCount.get(voteLabels, 0) + 1

	# max voted class will return
	maxCount = 0
	for key,value in classCount.items():
		if value> maxCount:
			maxCount = value
			maxIndex = key

	return maxIndex

