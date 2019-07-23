import numpy as np 

def calculate_AUC(labels, preds, n_bins=100):
	# calculate the cases
	pos_num = sum(labels)
	neg_num = len(labels) - pos_num
	total_case = pos_num * neg_num

	# create hist
	bin_width = 1.0/ n_bins
	pos_hist = [0] * n_bins
	neg_hist = [0] * n_bins
	for i in range(len(labels)):
		ind = int(preds[i]/ bin_width)
		if labels[i] == 1:
			pos_hist[i] += 1
		else:
			neg_hist[i] += 1

	accumulated_neg = 0
	satisfied_pairs = 0
	for i in range(n_bins):
		satisfied_pairs += (pos_hist[i]*accumulated_neg + 
									0.5*pos_hist[i]*neg_hist[i])
		accumulated_neg += neg_hist[i]

	return satisfied_pairs / float(total_case)


