/*
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

for (int idx = 0; idx < MAX; idx++){
printf("Type a number : ");
scanf("%d\n",&num);
arr[idx].push_back(num);
}
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
}*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>

#define MAX 8

using namespace std;
typedef vector<int> vt;
vt v;

void input_value();
void swap(vt*, vt*);
void pLeft_quick_sort(int, int);
void pRight_quick_sort(int, int);
void pMid_quick_sort(int, int);
void print();

int main()
{
	input_value();
	//print();
	//cout <<" " << endl;
	//pLeft_quick_sort(0, v.size() - 1);
	//pRight_quick_sort(0, v.size() - 1);
	pMid_quick_sort(0, v.size() - 1);
	print();

	return 0;
}

void input_value()
{
	/*srand((unsigned int)time(NULL));
	for (int i = 0; i < MAX; i++){
	v.push_back(rand()%10);
	}*/
	v.push_back(6);
	v.push_back(7);
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	v.push_back(9);
	v.push_back(2);
	v.push_back(8);
}
void swap(vt v1, vt v2)
{
	vt temp;

	temp = v1;
	v1 = v2;
	v2 = temp;
}
void pLeft_quick_sort(int left, int right)
{
	int pivot = left;
	int i = left + 1;
	int j = right;

	while (i <= j){
		while (i < j && v[i] < v[pivot])
			i++;
		while (i <= j && v[j] > v[pivot])
			j--;
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	if (left < right){
		swap(v[j], v[pivot]);
		pivot = j;
		pLeft_quick_sort(left, pivot - 1);
		pLeft_quick_sort(pivot + 1, right);
	}
}
void pRight_quick_sort(int left, int right)
{
	int pivot = right;
	int i = left;
	int j = right - 1;

	while (i <= j) {
		while (i < j && v[i] <= v[pivot])
			i++;
		while (i < j && v[j] >= v[pivot])
			j--;
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	if (left < right){
		swap(v[i], v[pivot]);
		pivot = i;
		pRight_quick_sort(left, pivot - 1);
		pRight_quick_sort(pivot + 1, right);
	}
}
void pMid_quick_sort(int left, int right)
{
	int pivot = (left + right) / 2 +1 ;
	int i = left;
	int j = right;

	while (i < j){
		while (i < j && v[i] < v[pivot])
			i++;
		while (i < j && v[j] >= v[pivot])
			j--;

		if (i < j)
			swap(v[i], v[j]);
		else
			break;

	}
	
	
		
	if (left < right){
		swap(v[i], v[pivot]);
		pivot = i;

				
		pMid_quick_sort(left, pivot - 1);
		pMid_quick_sort(pivot + 1, right);
	}

}
void print()
{
	vector<int> ::iterator vi;

	for (vi = v.begin(); vi != v.end(); vi++)
		cout << *vi << endl;

}