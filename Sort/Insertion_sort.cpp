#include<cstdio>
#include<vector>

using namespace std;
typedef vector<int> vt;
vt v;

void input_value();
void insertion_sort();
void print();
int main()
{
	input_value();
	insertion_sort();
	print();
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
void insertion_sort()
{
	int temp;
	int j;

	for (int i = 1; i < v.size(); i++){
		temp = v[i];
		for (j = i - 1; j >= 0; j--){
			if (temp < v[j])
				v[j + 1] = v[j];
			else
				break;
		}
		v[j + 1] = temp;
	}

}
void print()
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ",v.at(i));
}