#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>


void cut();
void map();
double CheckForNumbers();


double GetIntegerNumber (void){
	double IntNumber;
	int ZeroOrOne, IntRestart;
 			for( ; ; ){
    			ZeroOrOne = scanf("%lf",&IntNumber);
				if (ZeroOrOne == 0)	CheckForNumbers(0);
				if (ZeroOrOne == 1){
					IntRestart = IntNumber;
					if (IntNumber - IntRestart > 0) printf("������\n");
  					else break;
				}
			}		
	return IntNumber;
}


double CheckForNumbers(int NUmberOrNot){
	double numberOrNot;
	if (NUmberOrNot == 0){
		while(getchar() != '\n');
			printf("������\n");
	}
	else while(!scanf("%lf", &numberOrNot)){
		while(getchar() != '\n');
			printf("������\n");
	}
	return numberOrNot;	
}


void map(int *array, int sizeOfArray, void (*funCut)(int*)){
	int count = 0;
	for (count = 0; count < sizeOfArray; count++){;
		funCut(&array[count]);
	}
}


void cut(int *ptr){
	if (*ptr > 0) *ptr = 0;
}


int main(void){
	int sizeOfArray = 0, count = 0, oneOrNot = 0;
	int *array = NULL;
	setlocale(LC_ALL, "RU");
	printf("����� ����������\n");
	printf("����� ������ ������� 403 ������, 6 �������, 3 �����������\n");
	do{
		printf("������� ������ �������\n");
		sizeOfArray = GetIntegerNumber();
		array = (int*)malloc(sizeOfArray* sizeof(int));
		printf("������� 1, ���� ������ ������� ����� ���� ");
		scanf("%d", &oneOrNot);
		if (oneOrNot == 1){
			printf("������� ������, ��������� �� %d �����\n", sizeOfArray);
			for (count = 0; count < sizeOfArray; count++){
				array[count] = GetIntegerNumber();
			}
		} else{
			for (count = 0; count < sizeOfArray; count++){
				array[count] = -10000 + rand ()% 20001;
			}
		}
		printf("����������� ������\n");
		for (count = 0; count < sizeOfArray; count++){
				printf("%d ", array[count]);
		}
		printf("\n");
		printf("��������� ������\n");
		map(array, sizeOfArray, cut);
		for (count = 0; count < sizeOfArray; count++){
			printf("%d ", array[count]);
		}
		printf("\n");
		free(array);
		printf("������� 0, ���� ������ ���������\n");
	} while (CheckForNumbers(1) != 0);
}
