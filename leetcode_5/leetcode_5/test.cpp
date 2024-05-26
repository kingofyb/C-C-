#include<iostream>
using namespace std;

/*
76. ��С�����Ӵ�

https://leetcode.cn/problems/minimum-window-substring/description/

����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��

ע�⣺

���� t ���ظ��ַ�������Ѱ�ҵ����ַ����и��ַ��������벻���� t �и��ַ�������
��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�


ʾ�� 1��

���룺s = "ADOBECODEBANC", t = "ABC"
�����"BANC"
���ͣ���С�����Ӵ� "BANC" ���������ַ��� t �� 'A'��'B' �� 'C'��


ʾ�� 2��

���룺s = "a", t = "a"
�����"a"
���ͣ������ַ��� s ����С�����Ӵ�

�ⷨһ�� ����ö�� + ��ϣ��

�ȶ���left��right�����������λ��
ö��һ��λ������ң��ҵ�һ��λ��֮�󣬷������������һ����С������֮����left�ƶ�һ��
Ȼ��right������left��ʼ�����

���룺s = "ADOBECODEBANC", t = "ABC"
hash1:
��t��A����1�Σ�B����1�Σ�C����1��

hash2��
��s�У���¼ABC���ּ���
ֻҪ��hash2�У��ַ�ͳ�Ƴ��ֵĴ������ڵ���hash1����ô����һ����Ч��ö��

�Ż���
          ����Ҫ��
s = "-----------------------------"
        [L       R]

��left�����ƶ�һ��ʱ�������������
1�����ɷ���Ҫ��
right����

2��������Ҫ��
right�����ƶ����ҷ���Ҫ���λ��

����ָ����ͬ���˶��ģ����Ե����ԣ����Կ���ʹ�û�������

�ⷨ������������ + ��ϣ��
s = "A D O B E C O D E B A N C", t = "ABC"
     L
       R




1. left = 0, right = 0

2. ������ -> hash2[in]++

3. �жϣ������ڸպúϷ�ʱ������ -> check(hash1, hash2)

���½�� -> ��ʼλ�á����յ���̳���

������ -> hash2(out)--

�жϳ����ȸ��½�����ٳ�����Ȼ������ж�

�Ż����ж�����
ʹ�ñ���count�����Ч�ַ��ġ����ࡱ

1. ������ -> ��֮�󣬵�hash2(in) == hash1(in), count++
ֻҪhash2����A�ĸ�����hash1����A�ĸ������ʱͳ��

2. ������ -> ��֮ǰ����hash2(out) == hash1(out), count--
��������ں�hash2����A�ĸ�����0�����1��Ȼ��hash1����AΪ1����Ϊ����Ч�ַ�����ôcount--

3. �ж����� -> count == hash1.szie()
*/

//class Solution {
//public:
//    string minWindow(string s, string t)
//    {
//        // ����ģ���ϣ����Ϊȫ��Ӣ���ַ�
//        int hash1[128] = { 0 }; // ͳ���ַ���t��ÿ���ַ���Ƶ��
//        int hash2[128] = { 0 }; // ͳ�ƴ�����ÿ���ַ���Ƶ��
//        int kinds = 0; // ͳ����Ч�ַ��ж�����
//        for (auto ch : t)
//        {
//            // if(hash[ch] == 0) kinds++;
//            // hash[ch]++;
//            // ͬ��
//            if (hash1[ch]++ == 0) kinds++; // ��֮ǰ�������0��˵���ҵ�һ����Ч�ַ�������kinds++
//        }
//
//
//
//        int minlen = INT_MAX, begin = -1; // minlen����С�����Ӵ����ȣ�begin�������ʼλ��
//        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
//        {
//            char in = s[right];
//            //     hash2[in]++;
//            //     if(hash2[in] == hash1[in])
//            //     {
//            //         count++;
//            //     }
//            // ͬ��
//            if (++hash2[in] == hash1[in]) count++; // ������+ά��count����
//
//            while (count == kinds) // �ж�����
//            {
//                // ֻҪ���ڳ���С��minlen
//                if (right - left + 1 < minlen) // ���½��
//                {
//                    minlen = right - left + 1;
//                    begin = left;
//                }
//                // ������
//                char out = s[left++];
//
//                // if(hash2[out] == hash1[out]) count--;
//                // hash2[out]--;
//
//                // ͬ��
//                if (hash2[out]-- == hash1[out]) count--; // ˵����ʱ��Ч�ַ�������Ҫ����
//            }
//        }
//        if (begin == -1) return ""; // �������-1˵��û���ҵ�һ���Ӵ������ؿմ�
//        else return s.substr(begin, minlen); // �ҵ��˾Ͱ����ó���
//    }
//};

/*
���ֲ����㷨������ģ��

1. �ص�
��������ѭ�����㷨

704. ���ֲ���

https://leetcode.cn/problems/binary-search/description/

����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��


ʾ�� 1:

����: nums = [-1,0,3,5,9,12], target = 9
���: 4
����: 9 ������ nums �в����±�Ϊ 4


ʾ�� 2:

����: nums = [-1,0,3,5,9,12], target = 2
���: -1
����: 2 ������ nums ����˷��� -1

ԭ��
[1, 2, 3, 4, 5, 6, 7, 8], t = 5

�ⷨһ�������ⷨ -> O(N)
��������������t�������Ԫ�ضԱ�

����ѡ��4����ô�����������У�4��4��������Ԫ�ؿ϶���5С

�ⷨ�������ֲ����㷨�������ԡ�
�������ж����Ե�ʱ��Ϳ����ö��ֲ����㷨

�����ԣ�
�����Ƿ���һ�����ɣ�Ȼ������������ѡȡĳһ������ܰ��������ֳ�������
Ȼ����ݹ��ɿ�����ѡ���Ե���ȥһ���֣�Ȼ����������������һ����������������ҵ�ʱ��Ϳ����ö��ֲ���

ѡ���м�㣬ʱ�临�Ӷ�����

                 M
[                x                 ], t
 L                                R

L = left, R = right, M = mid

���ذ汾���ֲ����㷨�ĺ��ģ�

��һ�������x < t��ɾ�������� -> left = mid + 1 -> Ȼ�����ڸ���֮���[left, right]����Ѱ�ҽ��

�ڶ��������x > t��ɾ�������� -> right = mid - 1 -> Ȼ�����ڸ���֮���[left, right]����Ѱ�ҽ��

�����������x = t��ֱ�ӷ��ؽ��

ϸ�����⣺
1. ѭ������������ -> left > right

2. Ϊʲô����ȷ��

3. ʱ�临�Ӷ�
ѭ��1�Σ�n/2
2�Σ�n/4
3�Σ�n/8
...
x�Σ�1 -> 2^x/n -> 2^x = n -> x = logN
*/

//class Solution {
//public:
//    int search(vector<int>& nums, int target)
//    {
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            // int mid = (left + right) / 2; // ���������
//            int mid = left + (right - left) / 2; // ��ֹ���
//            if (nums[mid] < target) left = mid + 1;
//            else if (nums[mid] > target) right = mid - 1;
//            else return mid;
//        }
//        return -1;
//    }
//};

// ���ض���ģ��
// 
// 
// 
//        int left = 0, right = nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2; 
//            if (......) 
//                  left = mid + 1;
//            else if (......) 
//                  right = mid - 1;
//            else 
//                  return ......;
//        }