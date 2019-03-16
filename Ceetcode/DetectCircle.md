这里简要的介绍另一种解法：

设L1代表head到entry的距离；

设L2代表entry到meeting node的距离；

由于快指针速度是慢指针的二倍，则快慢指针相遇时必有：

2(L1+L2)=L1+L2+x+L2

这里的 x 代表meeting node到entry node的距离，可以得到 x=L1；

也就是说得到快慢指针相遇的地点时，这时再设一个指针entry从head开始走，那么当entry和slow相遇时，它们都走了L1的距离，刚好就是entry node。