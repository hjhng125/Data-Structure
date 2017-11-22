#include<cstdio>
#include<vector>

using namespace std;

typedef vector<int> vt;
vt v;

void input_number();
void Selection_sort();
void swap(vt*, vt*);
void print();

int main()
{
	input_number();
	Selection_sort();
	print();
}

void input_number()
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
void Selection_sort()
{
	int min;
	
	for (int i = 0; i < v.size(); i++){
		for (int j = i; j < v.size(); j++){
			if (j == i)
				min = j;
			else if (v[min] > v[j])
				min = j;
		}
		swap(v[min], v[i]);
	}
}
void swap(vt v1, vt v2)
{
	vt temp;
	
	temp = v1;
	v1 = v2;
	v2 = temp;
}
void print()
{
	for (int i = 0; i < v.size(); i++)
		printf("%d",v.at(i));
}