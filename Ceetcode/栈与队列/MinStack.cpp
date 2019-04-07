/* 最小栈：使用两个栈实现一个最小栈，即使用 getMin() 方法访问栈的最小值，一道经典的常考题。
	1.设置两个栈，s1 正常存储，s2 只存比当前最小值（小于等于）的值；
	  理解这里的意思，返回当前的最小值，那么我们就用一个栈来存储当前的最小值。
	2.入栈时，s1 直接入栈，s2 先检查x和 当前栈最小值的关系。
	3.出栈时，s1 肯定直接出，如果s2 栈顶元素和 s1 相同，那么也需要出栈。 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
    	s1.push(x);
        if(s2.empty() || x<=s2.top()) s2.push(x); // 入栈
    }
    
    void pop() {
        if(s1.top()==s2.top()) s2.pop(); // 出栈
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};