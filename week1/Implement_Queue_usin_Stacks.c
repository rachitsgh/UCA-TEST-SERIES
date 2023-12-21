
typedef struct {
    int *arr;
    int top;
} Stack;

typedef struct {
    Stack *st1;
    Stack *st2;
} MyQueue;

void createstack(Stack *st, int size) {
    st->arr = (int *)malloc(size * sizeof(int));
    st->top = -1;
}

bool isEmpty(Stack *st) {
    return st->top == -1;
}

void push(Stack *st, int val) {
    st->top++;
    st->arr[st->top] = val;
}

int pop(Stack *st) {
    int val = st->arr[st->top];
    st->top--;
    return val;
}

MyQueue* myQueueCreate() {
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    obj->st1 = (Stack *)malloc(sizeof(Stack));
    obj->st2 = (Stack *)malloc(sizeof(Stack));

    createstack(obj->st1, 100);
    createstack(obj->st2, 100);

    return obj;
}

void myQueuePush(MyQueue *obj, int x) {
    while (!isEmpty(obj->st1)) {
        push(obj->st2, pop(obj->st1));
    }
    push(obj->st1, x);
    while (!isEmpty(obj->st2)) {
        push(obj->st1, pop(obj->st2));
    }
}

int myQueuePop(MyQueue *obj) {
    if (isEmpty(obj->st1)) {
        return -1; // Queue is empty
    }
    return pop(obj->st1);
}

int myQueuePeek(MyQueue *obj) {
    if (isEmpty(obj->st1)) {
        return -1; // Queue is empty
    }
    return obj->st1->arr[obj->st1->top];
}

bool myQueueEmpty(MyQueue *obj) {
    return isEmpty(obj->st1);
}

void myQueueFree(MyQueue *obj) {
    free(obj->st1->arr);
    free(obj->st1);
    free(obj->st2->arr);
    free(obj->st2);
    free(obj);
}



/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
