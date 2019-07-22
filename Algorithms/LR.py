import numpy as np 

def sigmoid(x):
	return 1.0 / (1+np.exp(-x))

def trainLogRegress(train_x, train_y, opts):
	numSamples, numFeatures = train_x.shape

	alpha = opts['alpha']
	maxIter = opts['Iters']

	weights = np.mat(np.random.randn(numFeatures, 1))
	train_x = np.hstack((train_x, np.ones((numSamples, 1))))

	for k in range(maxIter):
		if opts['method'] == 'gradDescent':
			output = sigmoid(train_x*weights)
			error = train_y - output
			weights += alpha*train_x.T*error
		else
			for i in range(numSamples):
				output = sigmoid(train_x[i, :]*weights)
				error = train_y[i, :] - output
				weights += alpha*np.ravel(error)[0]*train_x[i, :]

	return weights

def testLogRegress(weights, test_x, test_y):
	numSamples, _ = test_x.shape
	test_x = np.hstack((test_x, np.ones((numSamples, 1))))
	prediction = (test_x*weights > 0.5).astype(np.int16)
	return np.sum(prediction==test_y) / float(numSamples)

