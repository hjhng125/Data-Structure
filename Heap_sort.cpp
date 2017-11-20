#include<cstdio>
#include<cstdlib>
#include<ctime>

#define MAX 8
#define PARENT(x) ((x-1)/2)
#define LEFT(x) ((2*x)+1)
#define RIGHT(x) ((2*x)+2)
#define SWAP(x,y) {int t; t = x; x = y; y = t;}

void heap_sort();
void init_heap(int, int);
void cons_heap(int, int);
void make_heap(int, int);
int find_max_index(int, int);
void view_heap();
int arr[MAX];
int parent;

void main()
{
	heap_sort();
}
void heap_sort()
{
	int n = MAX - 1;

	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX; i++){
		int num = rand() % 9;
		if (num == 0){
			i--;
			continue;
		}
		init_heap(i, num);
	}
	printf("초기 배열: \n");
	view_heap();

	while (n > 0){
		SWAP(arr[0], arr[n]);
		make_heap(0, n);
		n--;
	}

	printf("정렬된 배열 : \n");
	view_heap();
}
void init_heap(int index, int input_num)
{
	int parent;

	arr[index] = input_num;

	if (index == 0)
		return;
	else{
		do {
			parent = PARENT(index);
			if (arr[index] > arr[parent]){
				SWAP(arr[index], arr[parent]);
				index = parent;
			}
			else return;
		} while (parent != 0);
	}
}
void make_heap(int now, int array_num)
{
	while (LEFT(now) < array_num){
		int max = find_max_index(array_num, now);
		if (max == now)
			break;
		SWAP(arr[now], arr[max]);
		now = max;
	}
}
int find_max_index(int n, int now)
{
	if (RIGHT(now) >= n){
		if (arr[LEFT(now)] > arr[now])
			return LEFT(now);
		return now;
	}
	else if (arr[LEFT(now)] < arr[RIGHT(now)])
		return RIGHT(now);
	return LEFT(now);
}
void view_heap()
{
	for (int i = 0; i < MAX; i++)
		printf("%d ", arr[i]);
	printf("\n");
}