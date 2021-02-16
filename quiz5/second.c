#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>

//int foo(int* a);

struct Stack{
    int top;
    int* array;
    int size;
};

struct Stack* createStack()
{
    struct Stack *s = (struct Stack *) malloc(sizeof(struct Stack));
    //struct Stack s = {-1,(int *)malloc(sizeof(int))};
    s->top = -1;
    s->size = 1;
    s->array = (int *)malloc(sizeof(int));
    if (s->array == NULL) {
        printf("Out of memory!\n");
    }
    return s;
}

int isEmpty(struct Stack* stack){
    if (stack->top==-1)
        return 0;
    else
        return 1;
}

int isFull(struct Stack* stack){
    if (stack->size==(stack->top+1))
        return 0;
    else
        return 1;
}

void push(struct Stack* stack, int item){
    stack->top++;
    stack->size = stack->size+1;
    stack->array = (int *)realloc(stack->array, stack->size*sizeof(int));
    
    
    stack->array[stack->top] = item;
}

int pop(struct Stack* stack){
    if (isEmpty(stack)==0)
        exit(1);
    int index = stack->array[stack->top];

    stack->top--;
    if(stack->top==0){    
        stack->array = (int *)realloc(stack->array, 1*sizeof(int));
        return index;}

    stack->size = stack->size-1;
    stack->array = (int *)realloc(stack->array, stack->size*sizeof(int));
    
    return index;
}

//int foo(int* a){
//    return sizeof(a)/sizeof(int);
//}

struct StackFast{
    int top;
    int* array;
    int size;
};

struct StackFast* createStackFast()
{
    struct StackFast *s = (struct StackFast *) malloc(sizeof(struct StackFast));
    //struct Stack s = {-1,(int *)malloc(sizeof(int))};
    s->top = -1;
    s->size = 1;
    s->array = (int *)malloc(sizeof(int));
    if (s->array == NULL) {
        printf("Out of memory!\n");
    }
    return s;
}

int isEmptyFast(struct StackFast* stack){
    if (stack->top==-1)
        return 0;
    else
        return 1;
}

int isFullFast(struct StackFast* stack){
    if (stack->size==(stack->top+1))
        return 0;
    else
        return 1;
}

void pushFast(struct StackFast* stack, int item){
    if(isEmptyFull(stack)==0){     //isFull
        stack->array = (int *)realloc(stack->array, 2*stack->size*sizeof(int));
        stack->size = stack->size*2;
    }
    stack->top++;
    stack->array[stack->top] = item;
}

int popFast(struct StackFast* stack){
    if (isEmptyFast(stack)==0)
        exit(1);
    int index = stack->array[stack->top];

    stack->top--;
    if(stack->top==0){    
        stack->array = (int *)realloc(stack->array, 1*sizeof(int));
        return index;}

    if(stack->size/(stack->top)==2){
        stack->size = stack->size/2;
        stack->array = (int *)realloc(stack->array, stack->size*sizeof(int));
    }
    return index;
}


int main()
{
    struct Stack *s;
    s = createStack();
    //printf("0");
    //printf("%d", s->top);
    for(int i=0;  i<10; i++)
    {
        push(s,i);
        //printf( " size = %d \n", s->size);
        //printf( " top = %d \n", s->top);
        for(int j=0;  j<i; j++){
            printf("%d ",s->array[j]);
        }
        printf("\n");
        //printf("%d \n", i);
        //printf("%d \n", s->array[i]);
    }
    int a =0;
    for(int i=9;  i>0; i--)
    {
        a = pop(s);
        printf( " size = %d \n", s->size);
        printf( " top = %d \n", s->top);
        for(int j=0;  j<i-1; j++){
            printf("%d ",s->array[j]);
            //printf("%d \n", s->size);
        }
        printf("\n");
}}