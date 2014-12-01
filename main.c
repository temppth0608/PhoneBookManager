//
//  main.c
//  PhoneBookManager
//
//  Created by 박태현 on 2014. 12. 1..
//  Copyright (c) 2014년 박태현. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100

typedef struct PhoneInfo {
    char name[10];
    char number[20];
    int year;
} PhoneInfo;

enum {INPUT=1, CHANGE, PRINT, SEARCH, EXIT};

void showWrongChoise(int ); //잘못된 선택 처리
void showMenu();            //메뉴 출력
void showPhoneInfo();		//출력
void insertData();			//추가
void searchData();			//검색
int searchKey();			//검색 키
void sortingData();			//정렬(이름순)
void changeData();			//변경

PhoneInfo info[MAX_NUM]; 	//PhoneInfo를 담기위한 배열
static int infoNum;  				//저장돤 PhoneInfo수

int main(void) {
    int choise;
    printf("2014-12-01 Park Tae Hyun\n\n\n");
    
    while(1) {
        showMenu();
        printf("선택 : ");
        scanf("%d", &choise);
        printf("\n");
        
        if(choise<INPUT || choise>EXIT) {
            showWrongChoise(choise);
            continue;
        }
        
        switch(choise) {
            case INPUT:
                insertData(); break;
            case CHANGE:
                changeData(); break;
            case PRINT:
                sortingData();
                showPhoneInfo(); break;
            case SEARCH:
                searchData(); break;
            case EXIT:
                printf("프로그램을 종료합니다.\n");
                return 0;
        }
    }
}

void showMenu() {
    printf("----------전화번호부 관리 프로그램---------\n");
    printf("1.데이터 추가\n");
    printf("2.데이터 수정\n");
    printf("3.데이터 전체 출력(이름순 나열)\n");
    printf("4.데이터 검색\n");
    printf("5.프로그램 종료\n");
    printf("\n");
}

void showWrongChoise(int wrongChoise) {
    printf("!!!!!%d에 해당하는 선택사항이 없습니다.!!!!!\n", wrongChoise);
}

void insertData() {
    char name[20];
    char number[20];
    int year;
    
    printf("이름 입력 : ");
    scanf("%s", name);
    printf("전화번호 입력 : ");
    scanf("%s", number);
    printf("나이 입력 : ");
    scanf("%d", &year);
    
    strcpy(info[infoNum].name, name);
    strcpy(info[infoNum].number, number);
    info[infoNum].year = year;
    infoNum++;
    printf("데이터 추가가 완료되었습니다.\n\n");
}

void changeData() {
    char inputName[10];
    int dataIndex;
    char name[10];
    char number[20];
    int year;
    
    printf("데이터 수정을 시작합니다.\n");
    printf("이름 : ");
    scanf("%s", inputName);
    
    dataIndex = searchKey(inputName);
    if(dataIndex < 0) {
        printf("찾으려는 데이터가 없습니다.\n\n");
    }else {
        printf("수정된 이름 : ");
        scanf("%s", name);
        printf("수정된 전화번호 : ");
        scanf("%s", number);
        printf("수정된 나이 : ");
        scanf("%d", &year);
        
        strcpy(info[dataIndex].name, name);
        strcpy(info[dataIndex].number, number);
        info[dataIndex].year = year;
        
        printf("데이터 수정이 완료되었습니다.\n\n");
    }
}

void sortingData() {
    int i, j;
    PhoneInfo temp;
    for(i = 0; i < infoNum-1; i++) {
        for(j = 0; j < infoNum-1; j++) {
            if(strcmp(info[j].name, info[j+1].name) > 0) {
                temp = info[j];
                info[j] = info[j+1];
                info[j+1] = temp;
            }
        }
    }
}

void searchData() {
    char inputName[10];
    int dataIndex;
    
    printf("데이터 검색을 시작합니다.\n");
    printf("이름 : ");
    scanf("%s", inputName);
    
    dataIndex = searchKey(inputName);
    if(dataIndex < 0) {
        printf("찾으려는 데이터가 없습니다.\n\n");
    }else {
        printf("이름 : %s\n", info[dataIndex].name);
        printf("전화번호 : %s\n", info[dataIndex].number);
        printf("나이 : %d\n", info[dataIndex].year);
        printf("\n");
    }
    printf("데이터 검색이 완료되었습니다.\n\n");
}

int searchKey(char* name) {
    int index;
    for(index = 0; index < infoNum; index++) {
        if(strcmp(name, info[index].name) == 0) {
            return index;
        }
    }
    return -1;
}

void showPhoneInfo() {
    int i;
    printf("데이터 전체를 출력합니다(이름순 나열).\n");
    for(i=0; i<infoNum; i++) {
        printf("이름 : %s\n", info[i].name);
        printf("전화번호 : %s\n", info[i].number);
        printf("나이 : %d\n", info[i].year);
        printf("\n");
    }
    printf("데이터 출력이 완료되었습니다.\n\n");
}

















