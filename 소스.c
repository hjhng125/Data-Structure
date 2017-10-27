#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
	struct node *prev;
	int key;
	struct node *next;
}Node;

Node *head = NULL;
Node *last = NULL;

bool isEmpty();
Node* find(Node*);
void reverse();
void sortByKey(int);
void sortByPointer();
void disp();
void insertPrev(int);
void insertNext(int);
void insertKey(Node*, Node*);
void deletePrev();
void deleteNext();
Node* deleteKey(int);
int length();

void main()
{
	insertNext(2);
	insertNext(4);
	insertNext(1);
	insertNext(8);
	insertNext(7);
	insertNext(9);
	insertNext(5);
	insertNext(6);
	insertNext(3);
	//reverse();
	//sortByKey(length());
	sortByPointer();
	disp();

	//printf("%d", deleteKey(9)->key);
}
//��ũ�� ����ִ��� �ƴ��� Ȯ��
bool isEmpty()//is list empty
{
	return head == NULL;
}
Node* find(Node* current)
{
	Node* p = head;

	while (p != NULL){
		if (current->key < head->key)
			return head;
		else if (current->key > p->key && current->key < p->next->key){
			return p;
		}
		p = p->next;
	}
}
//����Ʈ�� reverse
void reverse()
{
	Node* temp;
	Node* current = head;

	while (current != NULL){
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL){
		last = head;
		head = temp->prev;
	}
}
//key���� �̿��� sort
void sortByKey(int length)
{
	Node* current;
	int idx1;
	int temp;

	for (idx1 = 0; idx1 < length - 1; idx1++){
		for (current = head; current->next != NULL; current = current->next){
			if (current->key > current->next->key){
				temp = current->key;
				current->key = current->next->key;
				current->next->key = temp;
			}
		}
	}
}
//pointer������ sort
void sortByPointer()
{
	Node* current = head;
	Node* findPos;
	Node* deletekey;

	while (current != last){
		/*
		if (current->key > last->key){ //���� ��尡 last���� ũ�� �ǵڷ�
			temp = deleteKey(current->key);
			insertNext(temp->key);
		}
		else if (current->key < head->key){ // �����尡 head���� ������ �Ǿ�����
			temp = deleteKey(current->key);
			insertPrev(temp->key);
		}
		else if (current->key >= head->key && current->key > current->next->key){ // �����尡 ����ΰ�� ���������� ũ�� ����
			temp = deleteKey(current->key);
			insertKey(temp, head);
		}
		current = head;
		idx++;*/
		if (current->key > current->next->key){
			findPos = find(current->next);
			deletekey = deleteKey(current->next->key);
			insertKey(findPos,deletekey);
		}
		else
			current = current->next;
	}
}
//��ũ ����Ʈ
void disp()
{
	Node* ptr = head;

	while (ptr != NULL){
		printf("%d\n", ptr->key);
		ptr = ptr->next;
	}
}
//�Ǿ����� insert
void insertPrev(int key)//is insert list
{
	Node *link = (Node*)malloc(sizeof(Node));
	link->key = key;

	if (isEmpty(head)){
		last = link;
	}
	else{
		head->prev = link;
	}
	link->next = head;
	head = link;
	head->prev = NULL;

}
//�ǵڷ� insert
void insertNext(int key)
{
	Node *link = (Node*)malloc(sizeof(Node));
	link->key = key;

	if (isEmpty(head)){
		head = link;
	}
	else{
		last->next = link;
	}
	link->prev = last;
	last = link;
	last->next = NULL;
}
// �μ�Ʈ�� ��ġ ã�� �־��ֱ�
void insertKey(Node* findPosKey, Node* insertkey)
{

	/*
	while (node != NULL){
		if (node->prev != NULL){
			if (temp->key > node->prev->key && temp->key < node->key){
				node->prev->next = temp;
				temp->prev = node->prev;
				temp->next = node;
				node->prev = temp;
			}
		}
		node = node->next;
	}
	*/
	if (findPosKey->key == head->key) //node = ����� temp = �־������ġ
		insertPrev(insertkey->key);
	else{
		insertkey->next = findPosKey->next;
		findPosKey->next->prev = insertkey;
		findPosKey->next = insertkey;
		insertkey->prev = findPosKey;
	}
}
//�Ǿ� delete
void deletePrev()
{
	if (head->next == NULL){
		head = NULL;
	}
	else
		head->next->prev = NULL;
	head = head->next;
}
//�ǵ� delete
void deleteNext()
{

	if (head->next == NULL){
		last = NULL;
	}
	else
		last->prev->next = NULL;

	last = last->prev;
}
//key���� ��ġ�ϴ� ��� delete
Node* deleteKey(int key)
{
	Node* ptr = head;
	Node* deletePoint;

	if (isEmpty(ptr))
		return NULL;

	while (ptr != NULL){
		if (ptr->key == key){
			if (ptr == head){
				head = head->next;
				deletePoint = ptr;
				head->prev = NULL;
			}
			else if (ptr == last){
				last = ptr->prev;
				deletePoint = ptr;
				last->next = NULL;
			}
			else{
				deletePoint = ptr;
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
		return deletePoint;
		}
		ptr = ptr->next;
	}
}
//��ũ�� ���� ����
int length()
{
	Node* p = head;
	int length = 0;
	while (p != NULL){
		p = p->next;
		length++;
	}
	return length;
}