#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

// 리스트 초기화
void init(ArrayListType* Lptr)
{
	Lptr->size = 0;
}

// 공백 검사
int is_empty(ArrayListType* Lptr)
{
	return Lptr->size == 0;
}

// 포화 검사
int is_full(ArrayListType* Lptr)
{
	return Lptr->size == MAX_LIST_SIZE;
}

// 리스트 출력
void print_list(ArrayListType* Lptr)
{
	int i;
	for (i = 0; i < Lptr->size; i++) {
		printf("%d -> ", Lptr->array[i]);
	}
	printf("\n");
}

// 리스트 삽입
void insert(ArrayListType* Lptr, int pos, element item)
{
	if (pos > Lptr->size)
	{
		printf("List Size : %d, [ %d %d ] 으로 입력해주세요\n", Lptr->size, item, Lptr->size);
	}

	else if (!is_full(Lptr) && (pos >= 0) && (pos <= Lptr->size))
	{
		int movecount = 0;

		for (int i = (Lptr->size - 1); i >= pos; i--)
		{
			Lptr->array[i + 1] = Lptr->array[i];
				movecount++;
		}

		Lptr->array[pos] = item;
		Lptr->size++;

		printf("Move : %d\n", movecount);
	}
}

// 리스트 삭제
element delete(ArrayListType* Lptr, int pos)
{
	element item;

	if (pos < 0 || pos >= Lptr->size)
	{
		printf("List size : %d , pos를 재입력해주세요(가능한 pos값 0 ~ %d)\n", Lptr->size, Lptr->size - 1);
		return;
	}

	else
	{

		int movecount = 0;

		item = Lptr->array[pos];

		for (int i = pos; i < (Lptr->size - 1); i++)
		{
			Lptr->array[i] = Lptr->array[i + 1];
			movecount++;
		}

		Lptr->size--;

		printf("Move : %d\n", movecount);
		printf("Delete : %d\n", item);
		printf("\n");

		return 0;
	}
}

int main()
{
	ArrayListType L;

	// 초기화
	init(&L);

	do {
		// 입력값 받기
		int enter = 0;

		printf("Menu\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");

		printf("Enter the memu : ");
		scanf_s("%d", &enter);

		element insert_val = 0;
		int pos = 0;
		int movecount = 0;

		// 1 이 들어오면 insert 하기
		if (enter == 1)
		{
			printf("Enter the number and position(ex. 5 0 / 10 1 / 15 2) : ");
			scanf_s("%d %d", &insert_val, &pos);

			insert(&L, pos, insert_val);
			printf("\n");

		}
		// 2 가 들어오면 delete 하기
		if (enter == 2)
		{
			if (L.size == 0)
			{
				printf("List는 공백입니다.\n");
			}

			else
			{
				printf("Enter the position : ");
				scanf_s("%d", &pos);

				delete(&L, pos);
			}
		}
		// 3 이 들어오면 리스트 출력하기
		if (enter == 3)
		{
			print_list(&L);
			printf("\n");
		}
		// 3 이상 값 들어오면 다시 입력하라고 하기
		if (enter > 3)
		{
			printf("Invalid Memu. Please select again\n");
			printf("\n");
		}
		// 0 이 들어오면 프로그램 종료
		if (enter == 0)
		{
			break;
		}

		getchar();
	} while (1);

	return 0;
}