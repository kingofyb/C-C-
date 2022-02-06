#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//数组名是数组首元素的地址
//这里有2个例外
//1. sizeof(数组名),这里的数组名是表示整个数组的，计算的是整个数组的大小，单位是字节。
//2. &数组名，这里的数组名也表示整个数组，取出的是数组的地址

//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a));//数组名a单独放在sizof内部，计算的是整个数组的大小，单位是字节，4*4=16
//	printf("%d\n", sizeof(a + 0));//a表示首元素地址，a+0还是数组首元素地址，是地址4/8字节
//	printf("%d\n", sizeof(*a));//a表示首元素地址，*a就是对首元素地址的解引用，就是首元素，4个字节
//	printf("%d\n", sizeof(a + 1));//a表示首元素地址，a+1就是第二个元素的地址，是地址，大小是4/8个字节
//	printf("%d\n", sizeof(a[1]));//a[1]是数组的第二个元素，大小是4个字节
//	printf("%d\n", sizeof(&a));//&a表示是数组的地址，数组的地址也是地址，大小是4/8个字节
//	printf("%d\n", sizeof(*&a));//可以理解为*和&抵消效果，*&a相当于a，sizeof(a)是16
//	//&a -> int(*)[4]
//	//&a是数组的地址，它的类型是int(*)[4]数组指针，如果解引用，访问的就是4个int的数组，大小是16个字节
//	printf("%d\n", sizeof(&a + 1));//&a是数组的地址，&a+1跳过整个数组后的地址，还是个地址，4/8个字节
//	printf("%d\n", sizeof(&a[0]));//&a[0]取出数组第一个元素的地址，是地址就是4/8
//	printf("%d\n", sizeof(&a[0] + 1));//&a[0]+1就是第二个元素的地址，是地址就是4/8个字节
//	return 0;
//}

//int main()
//{
//	//字符数组
//	char arr[] = { 'a','b','c','d','e','f' };
//
//	printf("%d\n", strlen(arr));//arr是首元素的地址，但是arr数组中没有\0，计算的时候就不知道什么时候停止，结果是：随机值
//	printf("%d\n", strlen(arr + 0));//arr是首元素的地址，arr+0还是首元素的地址，结果是：随机值
//	//printf("%d\n", strlen(*arr)); //err,strlen需要的是一个地址，从这个地址开始向后找字符,直到\0，统计字符的个数。
//	//但是*arr是数组的首元素，也就是'a',这是传给strlen的就是'a'的ascii码值97，strlen函数会把97作为起始地址，统计字符串，会形成内存访问冲突
//	
//	//printf("%d\n", strlen(arr[1]));//err 和上一个一样，内存访问冲突
//
//	printf("%d\n", strlen(&arr));//&arr是arr数组的地址，虽然类型和strlen的参数类型有所差异，但是传参过去后，还是从第一个字符的
//	//位置向后数字符，结果还是随机值。
//
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//随机值
//
//	//printf("%d\n", sizeof(arr));//arr作为数组名单独放在sizeof内部，计算的整个数组的大小，单位是字节，6
//	//printf("%d\n", sizeof(arr + 0));//arr就是首元素的地址，arr+0还是首元素的地址，地址大小就是4/8
//	//printf("%d\n", sizeof(*arr));//arr就是首元素的地址，*arr就是首元素，是一个字符，大小是一个字节，1
//	//printf("%d\n", sizeof(arr[1]));//arr[1]就是数组的第二个元素，是一个字符，大小是1个字节
//	//printf("%d\n", sizeof(&arr));//&arr取出的是数组的地址，数组的地址也是地址，地址就是4/8个字节
//	//printf("%d\n", sizeof(&arr + 1));//&arr取出的是数组的地址，&arr+1，跳过了整个数组，&arr+1还是地址，地址就是4/8个字节
//	//printf("%d\n", sizeof(&arr[0] + 1));//&arr[0]是第一个元素的地址，&arr[0]+1就是第二个元素的地址，地址就是4/8个字节
//
//	return 0;
//}

//int main()
//{
//	char* p = "abcdef";
//
//	printf("%d\n", strlen(p));//p中存放的是'a'的地址，strlen(p)就是从'a'的位置向后求字符串的长度，长度是6
//	printf("%d\n", strlen(p + 1));//p+1是'b'的地址，从b的位置开始求字符串长度是5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	printf("%d\n", strlen(&p));//随机值
//	printf("%d\n", strlen(&p + 1));//随机值
//	printf("%d\n", strlen(&p[0] + 1));//p[0] -> *(p+0) -> *p ->'a' ,&p[0]就是首字符的地址，&p[0]+1就是第二个字符的地址
//	//从第2 字符的位置向后数字符串，长度是5
//
//
//	//printf("%d\n", sizeof(p)); //p是一个指针变量，sizeof(p)计算的就是指针变量的大小，4 / 8个字节
//	//printf("%d\n", sizeof(p + 1));//p是指针变量，是存放地址的，p+1也是地址，地址大小就是4/8字节
//	//printf("%d\n", sizeof(*p));//*p访问的是1个字节
//	//printf("%d\n", sizeof(p[0]));//p[0]--> *(p+0) -> *p   1个字节
//
//	//printf("%d\n", sizeof(&p));//&p也是地址，是地址就是4/8字节，&p是二级指针
//
//	//printf("%d\n", sizeof(&p + 1)); //&p是地址， + 1后还是地址，是地址就是4 / 8字节
//	////&p + 1,是p的地址+1，在内存中跳过p变量后的地址
//
//	//printf("%d\n", sizeof(&p[0] + 1));//p[0]就是a，&p[0]就是a的地址，&p[0]+1就是b的地址，是地址就是4/8字节
//
//	return 0;
//}

//int i;
//void prt()
//{
//	for (i = 5; i < 8; i++)
//		printf("%c", '*');
//	printf("\t");
//}
//int main()
//{
//	for (i = 5; i <= 8; i++)
//		prt();
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//	return 0;
//}


//首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，
//和所有正整数的平均值，结果保留一位小数。
//0即不是正整数，也不是负数，不计入计算
//输入：
//5
//1 2 3 4 5
//10
//1 2 3 4 5 6 7 8 9 0
//输出：
//0 3.0
//0 5.0
//int main()
//{
//    int n = 0;
//    int arr[1000];
//    int i = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        float sum = 0;
//        int m = 0;
//        int j = 0;
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d ", &arr[i]);
//            if (arr[i] < 0)
//            {
//                m++;
//            }
//            if (arr[i] > 0)
//            {
//                j++;
//                sum += arr[i];
//            }
//        }
//        printf("%d %.1f\n", m, sum / j);
//    }
//    return 0;
//}


//有一个长度为 n 的非降序数组，比如[1, 2, 3, 4, 5]，
//将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，
//比如变成了[3, 4, 5, 1, 2]，或者[4, 5, 1, 2, 3]这样的。
//请问，给定这样一个旋转数组，求数组中的最小值。
//二分查找
//int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
//    // write code here
//    int left = 0;
//    int right = rotateArrayLen - 1;
//    while (left < right)
//    {
//        int mid = (left + right) / 2;
//        if (rotateArray[mid] < rotateArray[right])
//        {
//            right = mid;
//        }
//        else if (rotateArray[mid] > rotateArray[right])
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            right--;
//        }
//    }
//    return rotateArray[left];
//}