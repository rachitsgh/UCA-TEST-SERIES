typedef struct{
    char *arr;
    int top;
}Stack;

void create(Stack *st,int size){
    st->arr = (char *)malloc(size * sizeof(char));
    st->top=-1;
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

char peek(Stack *stack){
    if(isEmpty(stack)){
        return -1;
    }
    return stack->arr[stack->top];
}

char* removeDuplicateLetters(char* s) {
    for(int i=0;s[i]!='\0';i++){
        freq[s[i]-'a']++;
    }
    int visited[26]={0};
    Stack st;
    create(&st,100);
    for(int i=0;i<strlen(s);i++){
        char ch=s[i];
        freq[ch-'a']--;
        if(visited[ch-'a']==1){
            continue;
        }

        while(!isEmpty(&st) && peek(&st)>ch && freq[peek(&st)-'a']>0){
            char re = peek(&st);
            pop(&st);
            visited[re-'a']=0;
        }

        push(&st,ch);
        visited[ch-'a']=true;

    }
    char* ans = (char*)malloc((st.top + 2) * sizeof(char));  
    for (int i = 0; i < st.top + 1; i++) {
        ans[i] = st.arr[i];
    }
    ans[st.top + 1] = '\0';
    free(st.arr);
    return ans;
}
