#include<stdio.h>
#include<windows.h>

void printMonth(int month, int day, int dayOfTheWeek){
	printf("%d월\n\n", month);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("일\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("월\t화\t수\t목\t금\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("토\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");

	for (int i = 0; i < dayOfTheWeek; i++){
		printf("\t");
	}

	for (int i = 1; i <= day; i++){
		if ((dayOfTheWeek + i) % 7 < 2) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11+((dayOfTheWeek + i) % 7));
		printf("%d\t", i);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		if ((dayOfTheWeek + i) % 7 == 0) printf("\n");
	}
}

void main(){
	int dayCnt[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //월의 일수
	int year = 0; //입력받는 년도
	int pastDaysCnt = 1; //1년 1월 1일부터 n-1년 12월 31일까지의 수, 1월1일이 월요일이므로 요일계산시 +1 필요
	int dayOfTheWeek = 0; //시작 요일

	printf("출력될 달력의 년도를 입력하세요 >> ");
	scanf_s("%d", &year);

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) dayCnt[1] = 29;

	for (int i = 1; i < year; i++){
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) pastDaysCnt += 366;
		else pastDaysCnt += 365;
	}

	dayOfTheWeek = pastDaysCnt % 7;

	printf("\n");
	for (int i = 1; i <= 12; i++){
		printMonth(i,dayCnt[i-1],dayOfTheWeek);
		pastDaysCnt += dayCnt[i - 1];
		dayOfTheWeek = pastDaysCnt % 7;
		printf("\n\n");
	}
}