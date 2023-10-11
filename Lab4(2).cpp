#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* CreateTree(struct Node* root, int data)
{
	if (root == NULL)
	{
		root = (struct Node*)malloc(sizeof(struct Node));
		if (root == NULL)
		{
			printf("������ ��������� ������");
			exit(0);
		}

		root->left = NULL;
		root->right = NULL;
		root->data = data;
		return root;
	}

	if (data > root->data)
	{
		root->right = CreateTree(root->right, data);
	}
	else
	{
		root->left = CreateTree(root->left, data);
	}
	return root;
}

void print_tree(struct Node* root, int l)
{
	if (root == NULL)
	{
		return;
	}

	print_tree(root->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", root->data);
	print_tree(root->left, l + 1);
}

// ������� �������� ���������� ������ ������������� ����� � ������
int CountOccurrences(struct Node* root, int target)
{
	// ���� � ������ ��� ������� ��������
	if (root == NULL)
	{
		return 0; // ������� 0
	}

	if (root->data == target) // ���� ������ ������� ������
	{
		// ����������� ������� � ���������� �� ������� � ������ ���������
		return 1 + CountOccurrences(root->left, target) + CountOccurrences(root->right, target);
	}
	else if (target < root->data) // ���� ������� ������� ������ �������� 
	{
		return CountOccurrences(root->left, target); // �� ���� ��� � ����� ���������
	}
	else // ����� 
	{
		return CountOccurrences(root->right, target); // ���� ��� � ������ ���������
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int D, start = 1;

	struct Node* root = NULL;
	printf("\t\t\t\t������� -10, ����� ���������� ���������� ������: \n");
	while (start)
	{
		printf("������� �����: ");
		scanf("%d", &D);
		if (D == -10)
		{
			printf("���������� ������ ��������\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, D);
	}

	print_tree(root, 0);

	printf("\n������� �������� ��� �������� ���������: ");
	scanf("%d", &D); // ���� �������� ����� 

	int count = CountOccurrences(root, D); // �������

	printf("\n�������� %d ����������� %d ���(�) � ������\n", D, count);

	return 0;
}
