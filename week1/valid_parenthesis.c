typedef struct{
    char* arr;
    int top;
}Stack;

void create(Stack *stack,int size){
    stack->arr=(char *)malloc(size *sizeof(char));
    stack->top=-1;
}

bool isEmpty(Stack *stack){
    return stack->top==-1;
}

void push(Stack *stack,char val){
    stack->top++;
    stack->arr[stack->top]=val;

}

char pop(Stack *stack){
    char val = stack->arr[stack->top];
    stack->top--;
    return val; 
}

bool isValid(char* s) {
    int size=0;
    while(s[size] != '\0'){
        size++;
    }
    Stack st;
    create(&st,size);

    for(int i=0;i<size;i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            push(&st,s[i]);
        }else{
            if(isEmpty(&st)){
                free(st.arr);
                return false;
            }
            char topElement = pop(&st);

            if ((s[i] == ')' && topElement != '(') ||
                (s[i] == '}' && topElement != '{') ||
                (s[i] == ']' && topElement != '[')) {
                free(st.arr);
                return false; 
            }
        }
    }
    bool res = isEmpty(&st);
    free(st.arr);
    return res;
}
