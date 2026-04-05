typedef struct {
    int* a;
    int Front;
    int Rear;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* pst = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (pst == NULL)
    {
        perror("malloc error");
        return NULL;
    }
    pst->a = (int*)malloc(sizeof(int) * (k + 1));
    pst->Front = pst->Rear = 0;
    pst->k = k + 1;
    return pst;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->Front == obj->Rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->Rear + 1) % (obj->k) == obj->Front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->a[obj->Rear++] = value;
    obj->Rear = (obj->Rear) % obj->k;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->Front = (obj->Front + 1) % obj->k;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->a[(obj->Front) % obj->k];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
    {
        if (obj->Rear % obj->k == 0)
            return obj->a[obj->k - 1];
        else
            return obj->a[obj->Rear - 1];
    }
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    obj->Front = obj->Rear = obj->k = 0;
}
