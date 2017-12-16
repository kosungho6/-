#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct STATION
{
	char name[20];
	struct STATION *next;
	struct STATION *prev;
}station;

station *first; // ��߿� ���� 
station *last; // ������ ���� 
station *add; // �߰��� ����


void init()
{
	// ��߿� �޸� �Ҵ� 
	first = (station*)malloc(sizeof(station));  
	// ������ �޸� �Ҵ� 
	last = (station*)malloc(sizeof(station));
	strcpy(first->name,"��߿�");
	strcpy(last->name,"������");
	
		// ��߿��� ����Ű�� ��������  ���������� �Ҵ� 
	first->next = last; 
	// �������� ����Ű�� �������� ��߿����� �Ҵ�  
	last->prev = first;
		
	first->prev = NULL;
	last->next = NULL;	
}

void add_station(station *add) // �� �߰� �Լ� 
{
	// ���ο� �� �޸� �Ҵ�
	add = (station*)malloc(sizeof(station));
	// ���� �߰��� �� �̸� �Է� 
	printf("���� �߰��� ���� �Է��ϼ��� : ");
	scanf("%s", add->name);
	// ������ ������ �������� ���� �߰��� ���� ����Ų��. 
	last->prev->next = add;
	// ���� �߰��� ���� �������� �������� �������� �ȴ�. 
	add->prev = last->prev;
	// ���� �߰��� ���� �������� �������� �ȴ�. 
	add->next = last;
	// �������� �������� ���� �߰��� ���� �ȴ�. 
	last->prev = add; 
	
}
 
void del_station(char *name) // �� ���� �Լ� 
{
	station *del;
	del = first;
	while(del != NULL)
	{
		if(strcmp(name,del->name)==0)
		{
			del->prev->next = del->next;
			del->next->prev = del->prev; 
			free(del);
			printf("�����Ϸ�\n");
		}
			del = del->next;	
	}
}

void search_station(char *name) // �� �˻� �Լ� 
{
	station *search;
	search = first;
	while(search != NULL)
	{
		if(strcmp(name,search->name)==0)
		{
			printf("%s\n", search->name);
		}
		search = search->next;
			}		
}

void print() // ��ü �뼱 ����Լ� 
{
	station *all_prt;
	all_prt = first;
	while(all_prt != NULL)
	{
		printf("%s ->", all_prt->name);
		all_prt = all_prt->next;
	}
}


int main()
{
	init();
	int select;
	char name[20];
	while(select != 5)
	{
	printf("\n1. �߰� 2.����  3. �˻� 4. ��ü�뼱 5. ����\n");
	printf("�޴� ���� : ");
	scanf("%d",&select);
	switch(select)
	{
		case 1:
			add_station(add);
			break;
		case 2:
			printf("������ ���� �Է��ϼ��� : ");
			scanf("%s", &name);
			del_station(name);
			break;
		case 3:
			printf("�˻��� ���� �Է��ϼ��� : ");
			scanf("%s", &name);
			search_station(name);
			break;
		case 4:
			print();
			break;
	}
	}
	printf("���α׷� ����\n");
	
	return 0;
}
