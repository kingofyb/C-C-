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
//  //cpp现在已经指向c+2了
//  //先算++cpp 解引用完是 c+1
//  //--完是c .ENTER +3 -> ENT.ER
//	printf("%s\n", *cpp[-2] + 3);//ST
//  //**(cpp-2)+3 cpp-2之后指向c+3,解引用完是c+3
//  //再解引用是FIRST里F的地址 +3 .FIRST +3 -> FIR.ST
//	printf("%s\n", cpp[-1][-1] + 1);//EW
//  //*(*(cpp-1)-1)+1 cpp现在指向c+1, cpp-1解引用完就是c+2
//  //c+2-1=(c数组)c+1 c+1在c数组里指向NEW .NEW +1 -> N.EW
//	return 0;
//}


//strlen
//1.计数器的方法
//2.递归的方法
//3.指针-指针
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
////strlen的返回值是unsigned int
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

//ASCII码排列数组
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

