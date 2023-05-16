#include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;

// ����Ʈ �ʱ�ȭ
void init(ArrayListType* Lptr)
{
	Lptr->size = 0;
}

// ���� �˻�
int is_empty(ArrayListType* Lptr)
{
	return Lptr->size == 0;
}

// ��ȭ �˻�
int is_full(ArrayListType* Lptr)
{
	return Lptr->size == MAX_LIST_SIZE;
}

// ����Ʈ ���
void print_list(ArrayListType* Lptr)
{
	int i;
	for (i = 0; i < Lptr->size; i++) {
		printf("%d -> ", Lptr->array[i]);
	}
	printf("\n");
}

// ����Ʈ ����
void insert(ArrayListType* Lptr, int pos, element item)
{
	if (pos > Lptr->size)
	{
		printf("List Size : %d, [ %d %d ] ���� �Է����ּ���\n", Lptr->size, item, Lptr->size);
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

// ����Ʈ ����
element delete(ArrayListType* Lptr, int pos)
{
	element item;

	if (pos < 0 || pos >= Lptr->size)
	{
		printf("List size : %d , pos�� ���Է����ּ���(������ pos�� 0 ~ %d)\n", Lptr->size, Lptr->size - 1);
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

	// �ʱ�ȭ
	init(&L);

	do {
		// �Է°� �ޱ�
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

		// 1 �� ������ insert �ϱ�
		if (enter == 1)
		{
			printf("Enter the number and position(ex. 5 0 / 10 1 / 15 2) : ");
			scanf_s("%d %d", &insert_val, &pos);

			insert(&L, pos, insert_val);
			printf("\n");

		}
		// 2 �� ������ delete �ϱ�
		if (enter == 2)
		{
			if (L.size == 0)
			{
				printf("List�� �����Դϴ�.\n");
			}

			else
			{
				printf("Enter the position : ");
				scanf_s("%d", &pos);

				delete(&L, pos);
			}
		}
		// 3 �� ������ ����Ʈ ����ϱ�
		if (enter == 3)
		{
			print_list(&L);
			printf("\n");
		}
		// 3 �̻� �� ������ �ٽ� �Է��϶�� �ϱ�
		if (enter > 3)
		{
			printf("Invalid Memu. Please select again\n");
			printf("\n");
		}
		// 0 �� ������ ���α׷� ����
		if (enter == 0)
		{
			break;
		}

		getchar();
	} while (1);

	return 0;
}