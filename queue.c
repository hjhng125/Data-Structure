#include<stdio.h>
#include<stdbool.h>
#define MAX 6

void init();
void Insert(int);
int Delete();
void arrayPrint();
void queuePrint();

bool isEmpty();
bool isFull();

int front = 0;
int rear = -1;
int arr[MAX];
int count = 0;

void main()
{
	int flag, key;
	int data;

	//printf("Type number of array : \n");
	//scanf("%d",&n);

	init();

	while (1){
		printf("1: insert\n2: delete\n3: arrayPrint\nelse: queuePrint and exit  \n");

		scanf("%d", &flag);


		switch (flag){

		case 1:
			printf("Type insert key : \n");
			scanf("%d", &key);
			Insert(key);
			break;

		case 2:
			printf("%d",Delete());
			break;

		case 3:
			arrayPrint();
			break;
		default:
			queuePrint();
			exit(0);
		}
	}

}
void init()
{
	int i;

	for (i = 0; i < MAX; i++){
		arr[i] = 0;
	}
}
void Insert(int key)
{
	if (isFull()){
		printf("Queue overflow.\n");
		return;
	}
	if (rear == MAX - 1){
		rear = -1;
	}
	
	arr[++rear] = key;
	count++;

}

int Delete()
{
	int extract;

	if (isEmpty()){
		printf("Queue underflow.\n");
		return;
	}
	if (front == MAX)
		front = 0;

	extract = arr[front];
	arr[front] = 0;
	front++;
	count--;

	return extract;
}
void arrayPrint()
{
	int i;

	for (i = 0; i < MAX; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void queuePrint()
{
	int i;

	while (!isEmpty()){
		printf("%d ", Delete());
	}
	printf("\n");
}
bool isEmpty()
{
	return count == 0;
}
bool isFull()
{
	return count == MAX;
}