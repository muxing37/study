#include <stdio.h>
#include <stdlib.h>

/*链表实现的栈*/
struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void stack_init(struct Stack *s)
{
    s->top=NULL;
}

int stack_push(struct Stack *s,int value)
{
    struct Node *node=malloc(sizeof(struct Node));
    if(node==NULL) return -1;

    node->data=value;
    node->next=s->top;
    s->top=node;
    return 0;
}

int stack_pop(struct Stack *s,int *out)
{
    if(s->top==NULL) return -1;

    struct Node *node=s->top;
    *out=node->data;
    s->top=node->next;
    free(node);
    return 0;
}

void stack_destroy(struct Stack *s)
{
    int dummy;
    while(stack_pop(s,&dummy)==0);
}

/*数组实现的循环队列*/

#define MAX 8

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void queue_init(struct Queue *q)
{
    q->front=0;
    q->rear=0;
}

int queue_empty(struct Queue *q)
{
    return q->front==q->rear;
}

int queue_full(struct Queue *q)
{
    return (q->rear + 1)%MAX==q->front;
}

int queue_enqueue(struct Queue *q,int value)
{
    if(queue_full(q)) return -1;

    q->data[q->rear]=value;
    q->rear=(q->rear+1)%MAX;
    return 0;
}

int queue_dequeue(struct Queue *q, int *out)
{
    if(queue_empty(q)) return -1;

    *out=q->data[q->front];
    q->front=(q->front+1)%MAX;
    return 0;
}

/*测试主函数*/

int main(void)
{
    struct Stack s;
    struct Queue q;
    int value;
    int i;
    /* 测试栈 */
    stack_init(&s);
    for(i=0;i<5;i++) {
        stack_push(&s,i);
    }
    while(stack_pop(&s,&value)==0) {
        printf("stack pop: %d\n",value);
    }
    stack_destroy(&s);

    /* 测试队列 */
    queue_init(&q);

    for(i=0;i<6;i++) {
        queue_enqueue(&q,i);
    }
    while(queue_dequeue(&q, &value)==0) {
        printf("queue dequeue: %d\n",value);
    }
    return 0;
}

/*
栈的特性：LIFO（后进先出）
使用链表实现，动态分配内存
插入删除都在栈顶进行

队列的特性：FIFO（先进先出）
使用数组实现循环队列，静态分配内存
插入在队尾，删除在队头
牺牲一个存储单元来区分空和满状态
*/