#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else // a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int prev = left - 1;
	int cur = left;
	int keyindex = right;

	while (cur < right)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}
	Swap(&a[++prev], &a[keyindex]);

	int div = prev;

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

}

void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}

	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}

	// 分割成一段一段数据，内存排序后写到，小文件，
	int n = 10;
	int a[10];
	int i = 0;
	int num = 0;
	char subfile[20];
	int filei = 1;

	memset(a, 0, sizeof(int) * n);
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);
			sprintf(subfile, "%d", filei++);
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				printf("打开文件失败\n");
				exit(-1);
			}
			for (int j = 0; j < n; j++)
			{
				fprintf(fin, "%d\n", a[j]);
			}
			fclose(fin);

			i = 0;
			memset(a, 0, sizeof(int) * n);
		}
	}

	// 利用互相归并到文件，实现整体有序
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";
	for (int i = 2; i <= n; ++i)
	{
		// 读取file1和file2,进行归并出mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(file2, "%d", i + 1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	printf("%s文件排序成功\n", file);
	fclose(fout);
}

int main()
{
	MergeSortFile("SortData.txt");

	return 0;
}