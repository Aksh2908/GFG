class myQueue {

  public:
    vector<int> q;
    int front,rear,size;
    int maxCapacity;
    myQueue(int n) {
        maxCapacity=n;
        q.resize(n);
        front=0;
        rear=-1;
        size=0;
    }

    bool isEmpty() {
        return (size==0);
    }

    bool isFull() {
        return (size==maxCapacity);
    }

    void enqueue(int x) {
        if(isFull()) return;
        rear=(rear+1)%maxCapacity;
        q[rear]=x;
        size++;
    }

    void dequeue() {
        if(isEmpty()) return;
        front=(front+1)%maxCapacity;
        size--;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return q[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
};