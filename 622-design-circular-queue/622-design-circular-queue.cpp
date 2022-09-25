class MyCircularQueue {
    int front, back;
    int *arr;
    int size;
    
public:
    
    MyCircularQueue(int k) {
        front = back = -1;
        size = k;
        arr = new int[size];
    }
    
    bool enQueue(int value) {
        if((front==0 && back==size-1) or (front == back+1)) {
            return false;
        }
        
        if(front == -1) {
            front = back = 0;
            arr[back] = value;
            return true;
        }
        
        if(back==size-1 && front!=0) {
            back = 0;
            arr[back] = value;
            return true;
        }
        back++;
        arr[back] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1) return false;
        
        int val = arr[front];
        arr[front] = -1;
        
        if(front == back) {
            front = back = -1;
        }
        else if(front == size-1) {
            front = 0;
        }
        else {
            front++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(back == -1) return -1;
        return arr[back];
    }
    
    bool isEmpty() {
        return (front == -1);
    }
    
    bool isFull() {
        return ((front==0 && back==size-1) or (back == (front-1)%(size-1)));
    }
};