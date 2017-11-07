#include<stdio.h>
#include<vector>

#define MAX 8 

using namespace std;
typedef vector<int> vt;

void input_value();
void quick_sort(int, int);
void swap(int*, int*);
void display();
int arr[MAX];

int main()
{
	input_value();
	quick_sort(0,MAX);
	display();

	return 0;
}
void input_value()
{
	int num;

	/*for (int idx = 0; idx < MAX; idx++){
		printf("Type a number : ");
		scanf("%d\n",&num);
		arr[idx].push_back(num);
	}*/
	arr[0] = 6;
	arr[1] = 1;
	arr[2] = 7;
	arr[3] = 3;
	arr[4] = 2;
	arr[5] = 5;
	arr[6] = 8;
	arr[7] = 4;
	
}
void quick_sort(int left, int right)
{
	int pivot = left;
	int j = pivot;

	if (left < right){
		for (int i = left + 1; i < right; i++){
			if (arr[pivot] > arr[i]){				
				j++;
				swap(&arr[i], &arr[j]);
			}
		}
		swap(&arr[pivot], &arr[j]);
		pivot = j;
		quick_sort(left, pivot);
		quick_sort(pivot+1, right);
	}
}
void swap(int* num1, int* num2)
{
	int temp;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
void display()
{
	for (int i = 0; i < MAX; i++)
		printf("%d", arr[i]);
}