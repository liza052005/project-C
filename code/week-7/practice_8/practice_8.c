#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 10

// �������
typedef struct {
	char first_name[30];
	char last_name[30];
	int birth_year;
	char gender;
	double height;
} Person;

// ��������
typedef struct {
	char fields[4][20];
	int count;
} SortCriteria;

// ����� �����
void print_people(Person people[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%s %s, %d, %c, %.2lf\n",
			people[i].first_name, people[i].last_name,
			people[i].birth_year, people[i].gender,
			people[i].height);
	}
}

int compare(void* context, const void* a, const void* b) {
	// �������� � ���� Person
	Person* p1 = (Person*)a;
	Person* p2 = (Person*)b;
	// �������� � ���� SortCriteria
	SortCriteria* criteria = (SortCriteria*)context;

	// ���������� �������� ���������� � ������� ����������
	for (int i = 0; i < criteria->count; i++) {
		// �������� �������� ����������
		char* sort_field = criteria->fields[i];
		// ��������� ��������� ���������
		int comp_result = 0;

		if (strcmp(sort_field, "year") == 0) {
			// ���������� �� ���� �������� (�� �������� � ��������)
			comp_result = p1->birth_year - p2->birth_year;
		}
		else if (strcmp(sort_field, "name") == 0) {
			// ���������� �� �����
			char fullname1[31], fullname2[31];
			snprintf(fullname1, sizeof(fullname1), "%s %s", p1->first_name, p1->last_name);
			snprintf(fullname2, sizeof(fullname2), "%s %s", p2->first_name, p2->last_name);
			comp_result = strcmp(fullname1, fullname2);
		}
		else if (strcmp(sort_field, "gender") == 0) {
			// ���������� �� ���� (��������, 'M' < 'W')
			comp_result = p1->gender - p2->gender;
		}
		else if (strcmp(sort_field, "height") == 0) {
			// ���������� �� ����� (�� �������� � ��������)
			if (p1->height < p2->height)
				comp_result = -1;
			else if (p1->height > p2->height)
				comp_result = 1;
			else
				comp_result = 0;
		}

		// ���� �� �������� ���� ������ ����������, ���������� ��������� ���������
		if (comp_result != 0)
			return comp_result;
	}
	// ���� ��� �������� �� ������� ��������, ���������� 0
	return 0;
}

// ����������
void sort_people(Person people[], int count, SortCriteria* criteria) {


	qsort_s(people, count, sizeof(Person), compare, criteria);
}

int main() {
	// ������ ����
	FILE* file = fopen("people.txt", "r");
	if (!file) {
		printf("Unable to read file!\n");
		exit(1);
	}

	Person people[MAX_PEOPLE];
	int count = 0;
	while (fscanf(file, "%s %s %d %c %lf",
		people[count].first_name, people[count].last_name,
		&people[count].birth_year, &people[count].gender,
		&people[count].height) == 5) {
		count++;
	}
	fclose(file);

	// �������� � ������ ��������� �����
	SortCriteria criteria;
	criteria.count = 0;

	printf("Enter field for sort (year, name, gender, height), using [' '] SPACE: ");
	char input[30]; // ������ �����
	fgets(input, sizeof(input), stdin);

	//// �������� ������� ����� ������ � ���������� \0
	input[strcspn(input, "\n")] = '\0';

	// ���� �� ������ ��������� ����������, �� ������� ��������������� ������
	if (strcmp(input, "") == 0)
	{
		printf("[No sorting parameters provided. Printing default array]:\n");
		print_people(people, count);
		exit(1);
	}

	// ��������� ������ �� ����������� �������
	char* token = strtok(input, " ");
	// ���� ��������� ��������� max = 4
	while (token && criteria.count < 4) {
		if (criteria.count > 4)
		{
			printf("Too lot criteries! [%d]\n", criteria.count);
			exit(1);
		}
		else
		{
			// �������� ������� ����� ������ � ���������� \0
			token[strcspn(token, "\n")] = '\0';
			strcpy(criteria.fields[criteria.count++], token);
			// ���������� � default
			token = strtok(NULL, " ");
		}
	}

	// ���������� ������� �������� �� �������� ���������
	sort_people(people, count, &criteria);

	// ����� ��������������� ������
	printf("Sorted data:\n");
	print_people(people, count);

	return 0;
}