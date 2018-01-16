#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

void quick_sort(int, int);
vector<int> vt;

int main(void)
{
	int num;
	int num2;
	scanf("%d", &num);

	for (int i = 0; i < num; i++){
		scanf("%d", &num2);
		vt.push_back(num2);
	}
	quick_sort(0, vt.size() - 1);

	for (int i = 0; i < vt.size(); i++)
		printf("%d ", vt[i]);

	return 0;
}
void quick_sort(int left, int right)
{
	int pivot = left;
	int i = left;
	int j = right;

	while (i < j){
		while (i < j && vt[i] <= vt[pivot])
			i++;
		while (i <= j && vt[j] > vt[pivot])
			j--;
		if (i < j)
			swap(vt[i], vt[j]);
	}

	swap(vt[j], vt[pivot]);
	pivot = j;

	if (left < j)
		quick_sort(left, pivot - 1);
	if (i < right)
		quick_sort(pivot + 1, right);

}