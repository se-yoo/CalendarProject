#include<stdio.h>
#include<windows.h>

void printMonth(int month, int day, int dayOfTheWeek){
	printf("%d��\n\n", month);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("��\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("��\tȭ\t��\t��\t��\t");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf("��\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");

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
	int dayCnt[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //���� �ϼ�
	int year = 0; //�Է¹޴� �⵵
	int pastDaysCnt = 1; //1�� 1�� 1�Ϻ��� n-1�� 12�� 31�ϱ����� ��, 1��1���� �������̹Ƿ� ���ϰ��� +1 �ʿ�
	int dayOfTheWeek = 0; //���� ����

	printf("��µ� �޷��� �⵵�� �Է��ϼ��� >> ");
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