[TOC]

#### 1.random

##### 1.numpy.random.rand(d0,d1,..,dn)

>按照给定的维度 d，生成 [0,1) 之间的数据。

##### 2.numpy.random.randn()

>标准正态分布

##### 3.numpy.random.randint(low, high=None, size, dtype)

>范围为[low, high)，若只有一个数字，则范围默认为 [0,low)，没有size 则默认生成一个数字。

##### 4.numpy.random.choice(a,size=None,replace=True,p=None)

>从给定的数组 a 中生成一组随机数，size 为生成随机数的维度，p 为数组中数据出现的概率，和必须为1.

##### 5.numpy.random.uniform(low,high,size)