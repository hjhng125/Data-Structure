#include<cstdio>

using namespace std;

#define MAX 6

void merge_sort(int, int);
void merge(int, int, int);
void print();

int arr[MAX] = {3,8,0,2,1,4};
int main()
{
	merge_sort(0, MAX - 1);
	print();
	return 0;
}

void merge_sort(int left, int right)
{
	if (left == right)
		return;

	int m = (left + right) / 2;

	merge_sort(left, m);
	merge_sort(m + 1, right);
	merge(left, m, right);
}
void merge(int left, int mid, int right)
{
	int l = left, r = mid + 1;
	int idx = 0;
	int temp[MAX];

	while (l <= mid && r <= right){
		if (arr[l] <= arr[r])
			temp[idx++] = arr[l++];
		else
			temp[idx++] = arr[r++];
	}
	while (l <= mid)
		temp[idx++] = arr[l++];
	while (r <= right)
		temp[idx++] = arr[r++];
	
	idx = 0;
	
	for (int i = left; i <= right; i++)
		arr[i] = temp[idx++];
}
void print()
{
	for (int i = 0; i < MAX; i++)
		printf("%d ",arr[i]);
}