#include<stdio.h>
#include<stdlib.h>

void push(int);
void pop();
void print();

int top = -1;
int n=0; //어레이의 사이즈
int arr[100] = {0, };


void main()
{
	int key, idx; //넣을 값과 루프 인덱스
	int flag;

	printf("Type a size of array : ");
	scanf("%d",&n);

	while (1){
		printf("1: push\n2: pop\n3: print\nelse: exit \n");
		scanf("%d", &flag);
		
		switch (flag)
		{
		case 1: 
			printf("Type a key:");
			scanf("%d", &key);
			push(key);
			break;

		case 2:
			pop();
			break;

		case 3: 
			print();
			break;

		default:
			exit(0);
		}
	}

}
void push(int key)
{
	if (top < n - 1){
		arr[++top] = key;
	}
	else {
		printf("\nStack overflow.\n");
	}
}
void pop()
{
	if (top >= 0){
		arr[top--] = 0;
	}
	else{
		printf("\nStack underflow.\n");
	}
}
void print()
{
	int idx;

	for (idx = top; idx >= 0; idx--)
		printf("%d ", arr[idx]);
	printf("\n");
}