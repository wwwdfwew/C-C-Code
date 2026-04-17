typedef int QLDataType;

struct QListNode
{
	QLDataType data;
	struct QListNode* next;
};
//记录链表的头尾节点和队列的元素个数
typedef struct QNode
{
	struct QListNode* head;
	struct QListNode* tail;
	int size;
}Queue;
//初始化队列头尾节点
void QueueInit(Queue* ps)
{
	assert(ps);
	ps->head = ps->tail = NULL;
	ps->size = 0;
}
//入队列
void QueuePush(Queue* ps, QLDataType data)
{
	assert(ps);
	struct QListNode* newnode = (struct QListNode*)malloc(sizeof(struct QListNode));
	if (newnode == NULL)
	{
		perror("malloc error");
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	if (ps->head == NULL)
	{
		ps->head = ps->tail = newnode;
	}
	else
	{
		ps->tail->next = newnode;
		ps->tail = newnode;
	}
	ps->size++;
}
//出队列
void QueuePop(Queue* ps)
{
	assert(ps);
	struct QListNode* prve = ps->head;
	ps->head = ps->head->next;
	prve = NULL;
	ps->size--;
}
//返回出队列的元素
QLDataType QueueFront(Queue* ps)
{
	assert(ps);
	return ps->head->data;
}
//返回队列的尾端元素
QLDataType QueueBack(Queue* ps)
{
	assert(ps);
	/*while (ps->head->next != NULL)
		ps->head = ps->head->next;
	return ps->head->next;*/
	return ps->tail->data;
}
//返回队列元素个数
int QueueSize(Queue* ps)
{
	assert(ps);
	return ps->size;
}
//判断队列是否为空
bool QueueEmpty(Queue* ps)
{
	assert(ps);
	return ps->size == 0;
}
//销毁队列
void QueueDestroy(Queue* ps)
{
	assert(ps);
	while (ps->head)
	{
		struct QListNode* prve = ps->head;
		ps->head = ps->head->next;
		free(prve);
		prve = NULL;
		ps->size--;
	}
}


typedef struct {
	Queue que1;
	Queue que2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&pst->que1);
	QueueInit(&pst->que2);
	return pst;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->que1))
		QueuePush(&obj->que1, x);
	else
		QueuePush(&obj->que2, x);
}

int myStackPop(MyStack* obj) {
	Queue* cur1 = &obj->que1;
	Queue* cur2 = &obj->que2;
	if (!QueueEmpty(&obj->que1))
	{
		cur1 = &obj->que2;
		cur2 = &obj->que1;
	}
	while (cur2->head != cur2->tail)
	{
		QueuePush(cur1, QueueFront(cur2));
		QueuePop(cur2);
	}
	int top = QueueFront(cur2);
	QueuePop(cur2);
	return top;
}

int myStackTop(MyStack* obj) {
	Queue* cur1 = &obj->que1;
	Queue* cur2 = &obj->que2;
	if (!QueueEmpty(&obj->que1))
	{
		cur1 = &obj->que2;
		cur2 = &obj->que1;
	}
	while (cur2->head != cur2->tail)
	{
		QueuePush(cur1, QueueFront(cur2));
		QueuePop(cur2);
	}
	int top = QueueFront(cur2);
	QueuePush(cur1, QueueFront(cur2));
	QueuePop(cur2);
	return top;
}

bool myStackEmpty(MyStack* obj) {
	if (QueueEmpty(&obj->que1) && QueueEmpty(&obj->que2))
		return true;
	else
		return false;
}

void myStackFree(MyStack* obj) {
	if (!QueueEmpty(&obj->que1))
		QueueDestroy(&obj->que1);
	else
		QueueDestroy(&obj->que2);
}