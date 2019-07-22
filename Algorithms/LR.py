import numpy as np 
import time

# Func1: calculate the sigmoid function
def sigmoid(inX):
	return 1.0/(1 + np.exp(-inX))

# train a logistic regression model using some optional optimize algorithm
# input: train_x is a mat datatype, each row stands for one example
#        train_y is a mat datatype, each row is corresponding label
#		 opts is optimize option include step and maximum number of iterations
def trainLogRegress(train_x, train_y, opts):
	# calculate trainint time 
	startTime = time.time()

	numSamples, numFeatures = train_x.shape
	alpha = opts['alpha']
	maxIter = opts['maxIter']
	weights = np.ones((numFeatures,1))

	# optimize through gradient descent algorithm
	for k in range(maxIter):
		if opts['optimizeType'] == 'gradDescent':
			output = sigmoid(train_x*weights)
			error = train_y - output
			weights = weights + alpha*train_x.transpose()*error
		elif opts['optimizeType'] == 'stocGradDescent':
			for i in range(numSamples):
				output = sigmoid(train_x[i,:]*weights)
				error = train_y[i,0] - output
				


