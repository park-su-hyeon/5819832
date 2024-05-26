#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[100];
} element;

typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* h, element value) {

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	p->data = value;
	p->link = h;
	h = p;
	return h;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));

	if (pre == (ListNode*)NULL) {
		fprintf(stderr, "Insert parameter error in pre == NULL");
		return;
	}
	p->data = value;
	p->link = pre->link;    //<1>
	pre->link = p; // <2>
	return head;
}


ListNode* delete_first(ListNode* head) {

	if (head == NULL) return NULL;
	ListNode* remove = head;

	head = remove->link;
	free(remove);
	return head;
}

ListNode* delete(ListNode* h, ListNode* pre) {
	ListNode* remove = pre->link;

	pre->link = remove->link;
	free(remove);

	return h;
}

void print_list(ListNode* h) {
	while (h != (ListNode*)NULL) {
		printf("[%d] ", h->data);
		h = h->link;
	}
	printf("\n");
}


ListNode* search_list(ListNode* h, element x) {
	ListNode* p = h;

	while (p != NULL) {
		if (p->data == x) break;
		p = p->link;
	}
	return p;
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	return q;
}

int main() {
	ListNode* head = (ListNode*)NULL;
	element data;
	int choice;
	char* names[] = { "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach" };

	while (1) {
		printf("\n메뉴:\n");
		printf("1. 리스트에 추가\n");
		printf("2. 리스트에서 삭제\n");
		printf("3. 리스트 출력\n");
		printf("4. 프로그램 종료\n");
		printf("\n선택: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			scanf("&c", &data.name);
			if (serch_list(head, data.name) != NULL) {
				printf("이미 존재하는 리스트입니다.\n");
			}
			else {
				head = insert_first(head, data);
			}
			break;

		case 2:
			scanf("&c", &data.name);
			if (serch_list(head, data.name) == NULL) {
				printf("해당하는 리스트가 없습니다.\n");
			}
			else {
				delete(head, data.name);

			}

		case 3:
			printf("삭제 된 리스트: ");


		case 4:
			exit(1);

		default:
			printf("잘못된 선택입니다. 다시 시도하세요.\n");
			break;

		}
	}

	return 0;
}
