/*
 * @lc app=leetcode.cn id=641 lang=c
 * @lcpr version=30204
 *
 * [641] 设计循环双端队列
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

typedef struct {
    int *array;
    int front;
    int tail;
    int size;
} MyCircularDeque;

MyCircularDeque *MyCircularDequeCreate(int k)
{
    MyCircularDeque *queue = malloc(sizeof(MyCircularDeque));
    if (queue == NULL) {
        return NULL;
    }
    queue->size = k + 1;
    int *array_ = malloc(sizeof(int) * queue->size);
    if (array_ == NULL) {
        free(queue);
        return NULL;
    }
    queue->array = array_;
    queue->front = queue->tail = 0;
    return queue;
}

bool MyCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
    // queue is full
    if ((obj->tail + 1) % obj->size == obj->front) {
        return false;
    }
    // front - 1 then assign
    obj->front = (obj->front - 1 + obj->size) % obj->size;
    obj->array[obj->front] = value;
    return true;
}

bool MyCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
    // queue is full
    if ((obj->tail + 1) % obj->size == obj->front) {
        return false;
    }
    // assign first
    obj->array[obj->tail] = value;
    obj->tail = (obj->tail + 1 + obj->size) % obj->size;
    return true;
}

bool MyCircularDequeDeleteFront(MyCircularDeque *obj)
{
    // queue is empty
    if (obj->front == obj->tail) {
        return false;
    }
    obj->front = (obj->front + 1 + obj->size) % obj->size;
    return true;
}

bool MyCircularDequeDeleteLast(MyCircularDeque *obj)
{
    // queue is empty
    if (obj->front == obj->tail) {
        return false;
    }
    obj->tail = (obj->tail - 1 + obj->size) % obj->size;
    return true;
}

int MyCircularDequeGetFront(MyCircularDeque *obj)
{
    // queue is empty
    if (obj->front == obj->tail) {
        return -1;
    }
    int res = obj->array[obj->front];
    return res;
}

int MyCircularDequeGetRear(MyCircularDeque *obj)
{
    // queue is empty
    if (obj->front == obj->tail) {
        return -1;
    }
    int temp = (obj->tail - 1 + obj->size) % obj->size;
    return obj->array[temp];
}

bool MyCircularDequeIsEmpty(MyCircularDeque *obj)
{
    if (obj->front == obj->tail) {
        return true;
    }
    return false;
}

bool MyCircularDequeIsFull(MyCircularDeque *obj)
{
    if (obj->front == (obj->tail + 1) % obj->size) {
        return true;
    }
    return false;
}

void MyCircularDequeFree(MyCircularDeque *obj)
{
    if (obj != NULL) {
        free(obj->array);
    }
    free(obj);
    return;
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);

 * bool param_2 = myCircularDequeInsertLast(obj, value);

 * bool param_3 = myCircularDequeDeleteFront(obj);

 * bool param_4 = myCircularDequeDeleteLast(obj);

 * int param_5 = myCircularDequeGetFront(obj);

 * int param_6 = myCircularDequeGetRear(obj);

 * bool param_7 = myCircularDequeIsEmpty(obj);

 * bool param_8 = myCircularDequeIsFull(obj);

 * myCircularDequeFree(obj);
*/
// @lc code=end
