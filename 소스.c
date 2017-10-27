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
//링크가 비어있는지 아닌지 확인
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
//리스트를 reverse
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
//key값을 이용한 sort
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
//pointer변경의 sort
void sortByPointer()
{
	Node* current = head;
	Node* findPos;
	Node* deletekey;

	while (current != last){
		/*
		if (current->key > last->key){ //현재 노드가 last보다 크면 맨뒤로
			temp = deleteKey(current->key);
			insertNext(temp->key);
		}
		else if (current->key < head->key){ // 현재노드가 head보다 작으면 맨앞으로
			temp = deleteKey(current->key);
			insertPrev(temp->key);
		}
		else if (current->key >= head->key && current->key > current->next->key){ // 현재노드가 헤드인경우 다음값보다 크면 실핼
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
//링크 프린트
void disp()
{
	Node* ptr = head;

	while (ptr != NULL){
		printf("%d\n", ptr->key);
		ptr = ptr->next;
	}
}
//맨앞으로 insert
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
//맨뒤로 insert
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
// 인서트할 위치 찾아 넣어주기
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
	if (findPosKey->key == head->key) //node = 새노드 temp = 넣어야할위치
		insertPrev(insertkey->key);
	else{
		insertkey->next = findPosKey->next;
		findPosKey->next->prev = insertkey;
		findPosKey->next = insertkey;
		insertkey->prev = findPosKey;
	}
}
//맨앞 delete
void deletePrev()
{
	if (head->next == NULL){
		head = NULL;
	}
	else
		head->next->prev = NULL;
	head = head->next;
}
//맨뒤 delete
void deleteNext()
{

	if (head->next == NULL){
		last = NULL;
	}
	else
		last->prev->next = NULL;

	last = last->prev;
}
//key값이 일치하는 경우 delete
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
//링크의 길이 구함
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