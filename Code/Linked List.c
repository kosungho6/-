#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct STATION
{
	char name[20];
	struct STATION *next;
	struct STATION *prev;
}station;

station *first; // 출발역 선언 
station *last; // 종착역 선언 
station *add; // 추가역 선언


void init()
{
	// 출발역 메모리 할당 
	first = (station*)malloc(sizeof(station));  
	// 종착역 메모리 할당 
	last = (station*)malloc(sizeof(station));
	strcpy(first->name,"출발역");
	strcpy(last->name,"종착역");
	
		// 출발역이 가리키는 다음역을  종착역으로 할당 
	first->next = last; 
	// 종착역이 가리키는 이전역을 출발역으로 할당  
	last->prev = first;
		
	first->prev = NULL;
	last->next = NULL;	
}

void add_station(station *add) // 역 추가 함수 
{
	// 새로운 역 메모리 할당
	add = (station*)malloc(sizeof(station));
	// 새로 추가될 역 이름 입력 
	printf("새로 추가될 역을 입력하세요 : ");
	scanf("%s", add->name);
	// 종착역 이전의 다음역은 새로 추가될 역을 가리킨다. 
	last->prev->next = add;
	// 새로 추가될 역의 이전역은 종착역의 이전역이 된다. 
	add->prev = last->prev;
	// 새로 추가될 역의 다음역은 종착역이 된다. 
	add->next = last;
	// 종착역의 이전역은 새로 추가될 역이 된다. 
	last->prev = add; 
	
}
 
void del_station(char *name) // 역 삭제 함수 
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
			printf("삭제완료\n");
		}
			del = del->next;	
	}
}

void search_station(char *name) // 역 검색 함수 
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

void print() // 전체 노선 출력함수 
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
	printf("\n1. 추가 2.삭제  3. 검색 4. 전체노선 5. 종료\n");
	printf("메뉴 선택 : ");
	scanf("%d",&select);
	switch(select)
	{
		case 1:
			add_station(add);
			break;
		case 2:
			printf("삭제할 역을 입력하세요 : ");
			scanf("%s", &name);
			del_station(name);
			break;
		case 3:
			printf("검색할 역을 입력하세요 : ");
			scanf("%s", &name);
			search_station(name);
			break;
		case 4:
			print();
			break;
	}
	}
	printf("프로그램 종료\n");
	
	return 0;
}
