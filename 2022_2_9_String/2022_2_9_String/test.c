#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//  //char* *pa;
//	return 0;
//}

//int main()
//{
//	char* c[] = { "ENTER","NEW","POINT","FIRST" };
//	char** cp[] = { c + 3,c + 2,c + 1,c };
//	char*** cpp = cp;
//
//	printf("%s\n", **++cpp);//POINT
//	printf("%s\n", *-- * ++cpp + 3);//ER
//  //cpp�����Ѿ�ָ��c+2��
//  //����++cpp ���������� c+1
//  //--����c .ENTER +3 -> ENT.ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//  //**(cpp-2)+3 cpp-2֮��ָ��c+3,����������c+3
//  //�ٽ�������FIRST��F�ĵ�ַ +3 .FIRST +3 -> FIR.ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//  //*(*(cpp-1)-1)+1 cpp����ָ��c+1, cpp-1�����������c+2
//  //c+2-1=(c����)c+1 c+1��c������ָ��NEW .NEW +1 -> N.EW
//	return 0;
//}


//strlen
//1.�������ķ���
//2.�ݹ�ķ���
//3.ָ��-ָ��
//4.
//int my_strlen(const char* str)
//{
//	assert(str);
//	int cnt = 0;
//	while (*str != '\0')
//	{
//		cnt++;
//		str++;
//	}
//	return cnt;
//}
////strlen�ķ���ֵ��unsigned int
//int main()
//{
//	int len = my_strlen("abcdef");
//	printf("%d\n", len);
//	printf("%d\n", sizeof("abcdef"));
//	return 0;
//}

//int main()
//{
//	char str[] = "Geneius";
//	print(str);
//	return 0;
//} 
//print(char* s)
//{
//	if (*s)
//	{
//		print(++s);
//		printf("%c", *s);
//	}
//}

//ASCII����������
//int cmp(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//
//int main()
//{
//    char str[1001];
//    while (scanf("%s", str) != -1) {
//        int len = strlen(str);
//        qsort(str, len, sizeof(char), cmp);
//        printf("%s\n", str);
//    }
//    return 0;
//}

