class MyCircularDeque {
public:
    int* q;
    int f, b, s, cnt =0;
    MyCircularDeque(int k) {
        s = k;
        f = s/2, b = f + 1;
        q = new int[s];
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        f = ++f % s;
        q[f]=value;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        b = b == 0 ? s-1 : --b;
        q[b] = value;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        f = f == 0 ? s-1 : --f;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        b = ++b % s;
        cnt--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return q[f];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return q[b];
    }
    
    bool isEmpty() {
        return cnt == 0;
    }
    
    bool isFull() {
        return cnt == s;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */