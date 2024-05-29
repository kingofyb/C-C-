#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
69. x ��ƽ����

https://leetcode.cn/problems/sqrtx/description/

����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��

���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��

ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5 ��


ʾ�� 1��

���룺x = 4
�����2

ʾ�� 2��

���룺x = 8
�����2
���ͣ�8 ������ƽ������ 2.82842..., ���ڷ���������������С�����ֽ�����ȥ��

������17��ƽ����

�ⷨһ�������ⷨ

��1��ʼ���γ���
����1��ƽ����1��2��ƽ����4...ֱ��5��ƽ����25>17������һ����4�㼸��ƽ�������Ե���4

1  2  3  4  5  6  7
1  4  9  16 25 36 49

Ѱ�Ҷ�����

���԰���Щ�������һ�κ���

           ret
------------*--------------

ret��ߵ������ƽ����ȫ��С�ڵ���x�������λ�ÿ�ʼ�ұߵ�����ƽ����ȫ����x

�ⷨ�������ֲ���

�ȶ���һ��L(��1��ʼ)��һ��R(x)
��������Ӧ���Ǵ�1��x

1. mid*mid <= x -> ����������䣬����leftָ�룬left = mid

2. mid*mid > x -> �����ұ����䣬����rightָ�룬right = mid - 1 

*/

//class Solution {
//public:
//    int mySqrt(int x)
//    {
//        // x �п���С��1
//        if (x < 1) return 0; // ����߽����
//        int left = 1, right = x;
//        while (left < right)
//        {
//            long long mid = left + (right - left + 1) / 2; // long long�����
//            if (mid * mid <= x) left = mid;
//            else right = mid - 1; // ����ģ�棬������ּ������Ͱ���mid�����1����
//        }
//        return left;
//    }
//};

/*
35. ��������λ��

https://leetcode.cn/problems/search-insert-position/description/

����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��

ʾ�� 1:

����: nums = [1,3,5,6], target = 5
���: 2

ʾ�� 2:

����: nums = [1,3,5,6], target = 2
���: 1

ʾ�� 3:

����: nums = [1,3,5,6], target = 7
���: 4

Ѱ�Ҷ�����

��һ�������ֱ���ҵ�target

�ڶ���������Ҳ���target��Ҫ�Ҳ���λ��
�����λ��Ӧ���ǵ�һ�α�����������ǰ�棬�������
�����ҵ�λ�õ����ֵӦ���Ǵ��ڵ���target��
��ߵ�����ȫ��С��target

[С��t][���ڵ���t             ]
-------------------------------
         ret

1. x < t -> left = mid + 1

2. x >= t -> right = mid
*/

//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target) {
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] < target) left = mid + 1;
//            else right = mid;
//        }
//        // ���target����λ�����������
//        if (nums[left] < target) return left + 1; // right + 1Ҳ�ǶԵģ���Ϊleft��right�Ѿ�������
//        return left;
//    }
//};

/*
852. ɽ������ķ嶥����

https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/

�����������Ե����� arr ��Ϊ ɽ������ ��
arr.length >= 3

���� i��0 < i < arr.length - 1��ʹ�ã�
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]

������������ɵ�ɽ������ arr ���������� arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] ���±� i ��

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log(n)) �Ľ��������

ʾ�� 1��

���룺arr = [0,1,0]
�����1

ʾ�� 2��

���룺arr = [0,2,1,0]
�����1

ʾ�� 3��

���룺arr = [0,10,5,2]
�����1

����������ɽ����Ȼ�����½�

�ⷨһ������ö��
����һ��ָ��ӿ�ʼ���ǰһ������һ�����Ͳ����Ƿ�ֵ��ֱ�ӵ���һ��λ��
��ɨ�赽��һ�����Ǵ��ں��������ʱ����Ƿ嶥

ʱ�临�Ӷȣ�O(N)

�Ż���
ɽ������������������Ǵ���ǰһ�������ұ���������������С��ǰһ����

�ⷨ�������ֲ���
������ - �ܰ�����ֳ�������
�м�ֵ���±�Ϊmid

1. �������������䣬mid�����������ս�����棬������ȥ�ұ�������
arr[mid] > arr[mid - 1] -> left = mid

2. �����ұ����䣬Ҫ�����������
arr[mid] < arr[mid - 1] -> right = mid - 1
*/

//class Solution {
//public:
//    int peakIndexInMountainArray(vector<int>& arr) {
//        int left = 1, right = arr.size() - 2; // �׿���һ�������һ��λ��
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2;
//            if (arr[mid] > arr[mid - 1]) left = mid;
//            else right = mid - 1;
//        }
//        return left;
//    }
//};