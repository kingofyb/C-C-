#include<iostream>
using namespace std;

int main()
{

	return 0;
}

/*
34. �����������в���Ԫ�صĵ�һ�������һ��λ��

https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/

����һ�����շǵݼ�˳�����е��������� nums����һ��Ŀ��ֵ target�������ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

��������в�����Ŀ��ֵ target������ [-1, -1]��

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

ʾ�� 1��

���룺nums = [5,7,7,8,8,10], target = 8
�����[3,4]

ʾ�� 2��

���룺nums = [5,7,7,8,8,10], target = 6
�����[-1,-1]

ʾ�� 3��

���룺nums = [], target = 0
�����[-1,-1]


�ⷨһ����������
[1, 2, 3, 3, 3, 4, 5] t = 3
��ǰ����ɨ�豩�����ң�������O(N)

�Ż�
�����������������

�ⷨ�������ض���
[1, 2, 3, 3, 3, 4, 5] t = 3
 L        M        R
�ڼ��������ʱ�临�ӶȻή�ͣ�������������ڵ�Ԫ�ض�һ��

�Ż�
[1, 2, 3, 3, 3, 4, 5] t = 3
[    ] [            ]
�������С��t���ұ�������ڵ���t

�������������ж����ߵĹ���ʱ�Ϳ����ö��ֲ���

 L             M             R
[-----------------------------] t
               x
-------------------------------------------------------- ����������˵�

1. x < t -> left = mid + 1 -> [left,right]

2. x >= t -> right = mid -> [left, right] 

��Ϊ mid�п��������ս�������Բ��ܸ��µ� mid + 1

ϸ�ڴ���

1. ѭ������
left < right

a. �� left = right��ʱ��������ս���������ж�
b. ����жϣ��ͻ���ѭ��

��һ�������[left, right]���н��
 L                           R
[-----------------------------] t
[       ][                    ]         
           t
��Ϊ left = mid + 1������ left�������������������
��left��right������λ�þ������ս��

�ڶ��������ȫ����t
 L                           R
[-----------------------------] t
ֻ�����еڶ���������rightֻ�������ƶ�
ֱ���ж���˵��ֵ�Ƿ���t

�����������ȫС��t
ֻ�����е�һ��������leftֻ�������ƶ�
ֱ���ж��Ҷ˵��ֵ�Ƿ���t

2. ���е�Ĳ���
a. left + (right - left) / 2
b. left + (right - left + 1) / 2
������ĸ�����ż��ʱ����a���е��ǿ�����b�ǿ���

��b��������ѭ������Ϊ���Ҷ˵�

��a���������˵㣬�����е�һ������ʱleft�����ƣ���ʱ��ȵĻ�����ֹѭ��
�����еڶ�������ʱ��right����µ�mid����ʱ�����������ˣ�����ֹѭ����
�������е�Ĳ���ֻ����a������ֹѭ��

-------------------------------------------------------- ���������Ҷ˵�
[1, 2, 3, 3, 3, 4, 5] t = 3
[             ][    ]

�������ȫ��С�ڵ���t���ұ�ȫ������t

 L             M             R
[-----------------------------] t
               x
1. x <= t��mid��ʱ������������Ը���left -> left = mid -> [left, right] left��right�м���Ѱ�ҽ��

2. x > t��mid��ʱ���ұ����򣬸���right -> right = mid - 1 -> [left, right]

����ϸ�ڣ�
1. ѭ������
left < right

2. ���е�ķ�ʽ
a. left + (right - left) / 2
b. left + (right - left + 1) / 2

b������Ҷ˵�
�����Ԫ��ʣ2��ʱ
[* *]
 L R

���ʹ��a����ômid��������L����ô���ڵ�һ��������left�������ﲻ����Ȼ��mid���������λ�ã��ͻ�������ѭ��
ʹ��b��mid����R�������е�һ������ʱ��left���ƶ���right����ֹѭ��
���еڶ���������right�ƶ���left��Ҳ����ֹѭ��


*/

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        // ����߽����
//        if (nums.size() == 0) return { -1, -1 };
//        int begin = 0;
//        // 1. ������˵�
//        int left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left) / 2; // �е��±�
//            if (nums[mid] < target) left = mid + 1;
//            else right = mid;
//
//        }
//        // ����ѭ����left��right����
//        // �ж��Ƿ��н��
//        if (nums[left] != target) return { -1, -1 };
//        else begin = left; // ����left��right��һ���������˵�
//
//        // 2. �����Ҷ˵�
//        // ��ʵleft����Ҫ���ã�����Ϊ�˱��ִ���Ķ�����
//        left = 0, right = nums.size() - 1;
//        while (left < right)
//        {
//            int mid = left + (right - left + 1) / 2; // �е��±�
//            if (nums[mid] <= target) left = mid;
//            else right = mid - 1;
//        }
//        return { begin, right }; // ��ʱleft����right������Ҷ˵�
//    }
//};


// ��������� -1 ��ʱ������� +1
// �������۵Ĵ��룬�������⼴��
// ����������˵��ģ��
//while (left < right)
//{
//    int mid = left + (right - left) / 2;
//    if (...) left = mid + 1;
//    else right = mid;
//}

// ���������Ҷ˵��ģ��
//while (left < right)
//{
//    int mid = left + (right - left + 1) / 2;
//    if (...) left = mid;
//    else right = mid - 1;
//}