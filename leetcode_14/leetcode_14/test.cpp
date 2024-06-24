#include<iostream>
using namespace std;

int main()
{
	return 0;
}

/*
136. ֻ����һ�ε�����

https://leetcode.cn/problems/single-number/description/

����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣



ʾ�� 1 ��
���룺nums = [2,2,1]
�����1

ʾ�� 2 ��
���룺nums = [4,1,2,1,2]
�����4

ʾ�� 3 ��
���룺nums = [1]
�����1

����˼��
���ð�λ�����������������������⣺

�����������ʣ�
a ^ a = 0����ͬ���������Ϊ0��
a ^ 0 = a����������0�����Ϊ��������
�����ɺͽ���ɣ�a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b��
���������г���һ����ֻ����һ�Σ����������������Σ����������������ʣ���Щ�ɶԳ��ֵ����ụ��������0��
���ʣ�µľ����Ǹ�ֻ����һ�ε�����

ʾ������
���� nums = [2, 2, 1]����������������������У�

��ʼ value = 0��
�������飺
value ^= 2��value = 0 ^ 2 = 2
value ^= 2��value = 2 ^ 2 = 0
value ^= 1��value = 0 ^ 1 = 1
���� value ��ֵΪ1������1��
����������Ԥ�ڣ�֤����������ȷ�ġ�

ͨ��������㣬����������ʱ���ڣ�O(n)���ҵ�Ψһֻ����һ�ε����֣�
����ֻʹ�ó�������Ķ���ռ䣨O(1)������������ȸ�Ч�ּ�ࡣ
*/

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int value = 0;
//        for (auto e : nums) { value ^= e; }
//        return value;
//    }
//};

/*
118. �������

https://leetcode.cn/problems/pascals-triangle/description/

������ǵ��ص���ÿ���������Ϸ�������֮�͡�

���ַ���ʱ�临�Ӷ�Ϊ O(N^2)���ռ临�Ӷ�Ҳ�� O(N^2)
*/

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            vv[i].resize(i + 1, 0); // ��0�п�һ��0����1�п�2��0...
//            // ��һ�������һ����1
//            vv[i].front() = 1;
//            vv[i].back() = 1;
//        }
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            for (size_t j = 0; j < vv[i].size(); ++j)
//            {
//                if (vv[i][j] == 0)
//                {
//                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//                }
//            }
//        }
//        return vv;
//    }
//};

//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int>> vv;  // ����һ����ά����vv���洢������ǵ�ÿһ��
//        vv.resize(numRows);  // ����vv�Ĵ�СΪnumRows��
//        for (size_t i = 0; i < vv.size(); ++i) {  // ����ÿһ��
//            vv[i].resize(i + 1, 0);  // ÿһ����i+1��Ԫ�أ���ʼ��Ϊ0
//            vv[i].front() = 1;  // ÿһ�еĵ�һ��Ԫ��Ϊ1
//            vv[i].back() = 1;  // ÿһ�е����һ��Ԫ��Ϊ1
//        }
//        for (size_t i = 0; i < vv.size(); ++i) {  // �ٴα���ÿһ��
//            for (size_t j = 0; j < vv[i].size(); ++j) {  // ����ÿһ�е�ÿ��Ԫ��
//                if (vv[i][j] == 0) {  // �����ǰԪ����0����ʾ����Ҫ����
//                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];  // ��ǰԪ���������Ϻ����ϵ�Ԫ��֮��
//                }
//            }
//        }
//        return vv;  // �������ɵ��������
//    }
//};



/*
26. ɾ�����������е��ظ���

https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/

ʾ�� 1��
���룺nums = [1,1,2]
�����2, nums = [1,2,_]
���ͣ�����Ӧ�÷����µĳ��� 2 ������ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2 ��
����Ҫ���������г����³��Ⱥ����Ԫ�ء�



ʾ�� 2��
���룺nums = [0,0,1,1,1,2,2,3,3,4]
�����5, nums = [0,1,2,3,4]
���ͣ�����Ӧ�÷����µĳ��� 5 �� ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4 ��
����Ҫ���������г����³��Ⱥ����Ԫ�ء�

*/

//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        int src = 0;
//        int dst = 0;
//        while (src < nums.size())
//        {
//            if (nums[src] == nums[dst])
//            {
//                ++src;
//            }
//            else
//            {
//                nums[++dst] = nums[src++];
//            }
//        }
//
//        nums.resize(dst + 1);
//        return dst + 1;
//    }
//};


/*
17. �绰�������ĸ���

https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

����һ������������ 2-9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�

ʾ�� 1��
���룺digits = "23"
�����["ad","ae","af","bd","be","bf","cd","ce","cf"]

ʾ�� 2��
���룺digits = ""
�����[]

ʾ�� 3��
���룺digits = "2"
�����["a","b","c"]

*/


//class Solution {
//    char* numToStr[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//    // string numToStr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
//public:
//    void Combine(string digits, int di, vector<string>& retV, string combineStr)
//    {
//        if (di == digits.size())
//        {
//            retV.push_back(combineStr);
//            return;
//        }
//        // �ݹ�
//        // ȡ�����ַ�ӳ����ַ���
//        int num = digits[di] - '0';
//        string str = numToStr[num];
//        for (auto ch : str)
//        {
//            // di+1�ͻ�����һ����
//            Combine(digits, di + 1, retV, combineStr + ch);
//        }
//    }
//    vector<string> letterCombinations(string digits) {
//        vector<string> v;
//        if (digits.empty())
//        {
//            return v;
//        }
//        string str;
//        Combine(digits, 0, v, str);
//
//        return v;
//    }
//};