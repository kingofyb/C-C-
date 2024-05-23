#include<iostream>
using namespace std;

/*
1658. �� x ���� 0 ����С������

https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/

����һ���������� nums ��һ������ x ��ÿһ�β���ʱ����Ӧ���Ƴ����� nums ����߻����ұߵ�Ԫ�أ�Ȼ��� x �м�ȥ��Ԫ�ص�ֵ��
��ע�⣬��Ҫ�޸������Թ��������Ĳ���ʹ�á�

������Խ� x ǡ�� ���� 0 ������ ��С������ �����򣬷��� -1 ��

ʾ�� 1��

���룺nums = [1,1,4,2,3], x = 5
�����2
���ͣ���ѽ���������Ƴ�������Ԫ�أ��� x ���� 0

ʾ�� 2��

���룺nums = [5,6,7,8,9], x = 4
�����-1

ʾ�� 3��

���룺nums = [3,2,20,1,1,3], x = 10
�����5
���ͣ���ѽ���������Ƴ�������Ԫ�غ�ǰ����Ԫ�أ��ܹ� 5 �β��������� x ���� 0 ��

������
�ҵ���������a����ߣ�b���ұ��ǵ�a + b = x��
[[    ]        [     ]]
    a             b
����һ��sum��sum����������ĺ�
��ʱ���Կ����м���������ʹ��sum - x��ʹ�м���������������

ת�����ҳ����������ĳ��ȣ�����Ԫ�صĺ����õ���sum - x
                        len                        target
n - len

�ⷨһ������ö��

target = sum - x
  [ < target   ] R(>=target)
[              ] ]             ]
  L

sum1 �����L��R��ָ������ĺ�
��R��������ƶ����Ǹ���ѵ�λ��

���R�ҵ�һ��Ԫ��ʹ��ǰ��ĺ� >= target����ô�Ǹ�Ԫ��֮ǰ��Ԫ��֮�Ϳ϶� < target

�����ⷨ�Ļ�������L����һ����Ȼ��R�ص�L����
����R���б�Ҫ�����ƶ���
��ʵû�б�Ҫ������ǰ��������С��target�ˣ���ʱɾ���˵�һ��Ԫ�ؿ϶�����С��target
����Rû�б�Ҫ��ȥ��������RҪôԭ�ز�����Ҫô����ƶ�

�ⷨ������������
1.left = 0��right = 0

2.������ -> sum1 += nums[right]

3.�ж� -> ���������ĺ� > target �ͳ�����
������ -> sum1 -= nums[left]

���½�� -> ����������ĺ� = target �ٸ��½��

�������n��һ�£��ó������

ʱ�临�Ӷȣ�O(N)
�ռ临�Ӷȣ�O(1)
*/

//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x) {
//        int sum = 0; // ��������ĺ�
//
//        for (int a : nums) sum += a; // ������ÿ�������ó���Ȼ��+=
//        int target = sum - x;
//
//        // ϸ������
//        if (target < 0) return -1;
//
//        int ret = -1; // ���û���ҵ����������-1������ֱ�Ӹ�ֵ-1
//        for (int left = 0, right = 0, tmp = 0; right < nums.size(); right++)
//        {
//            // ������
//            tmp += nums[right];
//
//            while (tmp > target) // �ж�
//            {
//                tmp -= nums[left++]; // ������
//            }
//            if (tmp == target) // ���½��
//            {
//                ret = max(ret, right - left + 1);
//            }
//        }
//        if (ret == -1) return ret;
//        else return nums.size() - ret;
//    }
//};


/*
904. ˮ������

https://leetcode.cn/problems/fruit-into-baskets/description/

������̽��һ��ũ����ũ����������ֲ��һ�Ź�������Щ����һ���������� fruits ��ʾ������ fruits[i] �ǵ� i �����ϵ�ˮ�� ���� ��

����Ҫ�����ܶ���ռ�ˮ����Ȼ����ũ���������趨��һЩ�ϸ�Ĺ�أ�����밴��Ҫ���ժˮ����

��ֻ�� ���� ���ӣ�����ÿ������ֻ��װ ��һ���� ��ˮ����ÿ�������ܹ�װ��ˮ������û�����ơ�
�����ѡ������һ������ʼ��ժ�������� ÿ�� ����������ʼ��ժ�������� ǡ��ժһ��ˮ�� ����ժ��ˮ��Ӧ�����������е�ˮ�����͡�ÿ��ժһ�Σ��㽫�������ƶ�����һ��������������ժ��
һ�����ߵ�ĳ����ǰ����ˮ�����������ӵ�ˮ�����ͣ���ô�ͱ���ֹͣ��ժ��
����һ���������� fruits ������������ռ���ˮ���� ��� ��Ŀ��



ʾ�� 1��

���룺fruits = [1,2,1]
�����3
���ͣ����Բ�ժȫ�� 3 ������
ʾ�� 2��

���룺fruits = [0,1,2,2]
�����3
���ͣ����Բ�ժ [1,2,2] ����������
����ӵ�һ������ʼ��ժ����ֻ�ܲ�ժ [0,1] ����������

����������ժ

ת�����ҳ�һ����������鳤�ȣ��������в������������͵�ˮ��

fruits = [1,2,3,2,2]

�ⷨһ������ö�� + ��ϣ��
[1,2,3,2,2]

����̶�1���Ǿ�ֻ���ҵ�1,2
����̶�2�����Բ�ժ��2,3,2,2
...
�ҳ����п����ԣ�Ȼ��ѡ�����

���Խ�����ϣ����ˮ�����ͣ�ͳ��ˮ��һ�����ֶ�����

�ⷨ������������
���磺
     R
f = [1, 2, 1, 2, 3, 2, 3, 3]
     L
hash<int,int> ����Ҫ����ˮ�������࣬��Ҫ����ˮ��������


1. left = 0��right = 9

2. ������ -> hash[f[Right]]++

3. �ж� -> hash.size > 2
������ -> hash[f[Left]]--��Ҫ�ж�һ�£������Ӧ��λ�õ�Ԫ�ر��0��Ҫ�ӹ�ϣ����ɾ��

���½��


*/

//class Solution {
//public:
//    int totalFruit(vector<int>& fruits) {
//        unordered_map<int, int> hash; // ͳ�ƴ����ڳ����˶�����ˮ��
//
//        int ret = 0;
//        for (int left = 0, right = 0; right < fruits.size(); right++)
//        {
//            hash[fruits[right]]++; // ������
//
//            while (hash.size() > 2) // �ж�
//            {
//                hash[fruits[left]]--; // ������
//                if (hash[fruits[left]] == 0)
//                {
//                    hash.erase(fruits[left]); // ���0�ʹӹ�ϣ����ɾ��
//                }
//                left++;
//            }
//            ret = max(ret, right - left + 1); // ���Ӧ����left��right��ָ����ĳ���
//        }
//        return ret;
//    }
//};
// ʱ�临�ӶȱȽϺ�ʱ�����Կ��ԶԹ�ϣ����һ���Ż�
//
//
// �Ż���
// ��Ϊ
//1 <= fruits.length <= 10^5
//0 <= fruits[i] < fruits.length
//���Կ���ʹ��һ�������������ϣ��

// int hash[100001] = {0};
//
// for (int left = 0, right = 0, kinds = 0; right < fruits.size(); right++)
// if(hash[fruits[right]] == 0) kinds++; // ά��ˮ��������
// while (kinds > 2)
// hash.erase(fruits[left]); -> if(hash[fruits[left]] == 0) kinds--;

// ������ݷ�Χ�����޵ģ�����ʹ�������������ϣ����ֱ��ʹ������Ч�ʵ������ܴ�


/*
438. �ҵ��ַ�����������ĸ��λ��

https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/

���������ַ��� s �� p���ҵ� s ������ p �� ��λ�� ���Ӵ���������Щ�Ӵ�����ʼ�����������Ǵ������˳��

��λ�� ָ����ͬ��ĸ�������γɵ��ַ�����������ͬ���ַ�������

ʾ�� 1:

����: s = "cbaebabacd", p = "abc"
���: [0,6]
����:
��ʼ�������� 0 ���Ӵ��� "cba", ���� "abc" ����λ�ʡ�
��ʼ�������� 6 ���Ӵ��� "bac", ���� "abc" ����λ�ʡ�
 ʾ�� 2:

����: s = "abab", p = "ab"
���: [0,1,2]
����:
��ʼ�������� 0 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�
��ʼ�������� 1 ���Ӵ��� "ba", ���� "ab" ����λ�ʡ�
��ʼ�������� 2 ���Ӵ��� "ab", ���� "ab" ����λ�ʡ�


1. �����ⷨ

1. ��ο����ж������ַ����Ƿ��ǡ���λ�ʡ�
s1 = "aabca"
s2 = "abaca"

������Ȼ����һһ�Ƚϵķ���̫��ʱ��

���Կ������ù�ϣ��
����s1���ַ������ַ����ζ���hash1
����s2���ַ������ַ����ζ���hash2
Ȼ��Ƚ�������ϣ���ж�Ӧλ���ַ����ֵĸ����Ƿ���ȣ���Ⱦ�����λ��

2.�������
���磺
s = "cbaebabacd" 
��cΪ��㣬��һ������Ϊm���Ӵ���
���Ӵ�����ÿ���ַ����ֵĸ���������һ����ϣ��hash2����
Ȼ�����������Ӵ�֮�󣬱Ƚ�һ����������ϣ���Ƿ���ȾͿ���
Ȼ����bΪ���...

p = "abc"������Ϊm��hash1

hash1ͳ��p����ĸ���
hash2ͳ�ƻ�����������ÿ���ַ����ֵĸ���

����Ż���

ÿ��ö�ٵ�ʱ��ֻ��Ҫ�ѵ�һ���ַ�ɾ����Ȼ�������һ���ַ��Ϳ�����
����û�б�Ҫ���´�ͷ��ʼͳ����Ϣ

s = "c b a e b a b a c d"
     L   R
s = "c b a e b a b a c d"
       L   R

����ʹ�û�������
�ⷨ���������� + ��ϣ��
1. left = 0, right = 0

2. ������ -> hash2[in]++

3. �ж� -> right - left + 1 > m�����ƶ�
������ -> hash2[out]--

���½�� -> check(hash2, hash1)

�Ż������ԶԸ��½�����ж�����(check)�����Ż�
���ñ���count��ͳ�ƴ����С���Ч�ַ����ĸ���

s = "ccbaebabacd"��hash2

p = "abc"��hash1: a -> 1, b -> 1, c -> 1

�����ڣ������ -> �жϴ�ʱhash2[in]�Ƿ�С�ڵ���hash1[in]
���С�ڵ��ڣ�������ӵ���Ч�ַ���count++
��������������������Ч�ַ���count����

�����ڣ���ȥǰ -> hash2[out] <= hash1[out] -> count--
�������count����

���½����count == m
*/

//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int> ret;
//        int hash1[26] = { 0 }; // ͳ���ַ���p��ÿ���ַ����ֵĸ���
//
//        for (auto ch : p) hash1[ch - 'a']++; // ch - 'a'��Ӧλ�õ��±�
//
//        int hash2[26] = { 0 }; // ͳ�ƴ�������ÿһ���ַ����ֵĸ���
//        int m = p.size();
//        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
//        {
//            char in = s[right];
//            //hash2[in - 'a']++; // ������
//            // ά��һ��count��������hash2ǰ�����++
//            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++; // ������+ά��
//
//            if (right - left + 1 > m) // �ж�
//            {
//                char out = s[left++]; // Ԫ�ظ��ȥ֮��left�����ƶ�һ��
//                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--; // ������ + ��ȥǰά��count
//                //hash2[out - 'a']--; // ������
//            }
//            // ���½��
//            if (count == m) ret.push_back(left);
//        }
//        return ret;
//    }
//};


/*
30. �������е��ʵ��Ӵ�

https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/

����һ���ַ��� s ��һ���ַ������� words�� words �������ַ��� ������ͬ��

 s �е� �����Ӵ� ��ָһ������  words �������ַ���������˳�����������������Ӵ���

���磬��� words = ["ab","cd","ef"]�� ��ô "abcdef"�� "abefcd"��"cdabef"�� "cdefab"��"efabcd"�� �� "efcdab" ���Ǵ����Ӵ��� 
"acdbef" ���Ǵ����Ӵ�����Ϊ�������κ� words ���е����ӡ�
�������д����Ӵ��� s �еĿ�ʼ������������� ����˳�� ���ش𰸡�

ʾ�� 1��

���룺s = "barfoothefoobarman", words = ["foo","bar"]
�����[0,9]
���ͣ���Ϊ words.length == 2 ͬʱ words[i].length == 3�����ӵ����ַ����ĳ��ȱ���Ϊ 6��
�Ӵ� "barfoo" ��ʼλ���� 0������ words ���� ["bar","foo"] ˳�����е����ӡ�
�Ӵ� "foobar" ��ʼλ���� 9������ words ���� ["foo","bar"] ˳�����е����ӡ�
���˳���޹ؽ�Ҫ������ [9,0] Ҳ�ǿ��Եġ�

ʾ�� 2��

���룺s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
�����[]
���ͣ���Ϊ words.length == 4 ���� words[i].length == 4�����Դ����Ӵ��ĳ��ȱ���Ϊ 16��
s ��û���Ӵ�����Ϊ 16 ���ҵ��� words ���κ�˳�����е����ӡ�
�������Ƿ���һ�������顣

s = "barfoothefoobarman", words = ["foo","bar"] words������ַ������ȶ�Ϊ3

s = "[bar][foo][the][foo][bar][man]"
       b    a    c    a    b    d

��438. �ҳ�������ĸ����λ�� ����

�������� + ��ϣ��

��֮ͬ����
1. ��ϣ��
hash<string, int> -> string��Ӧ�ַ���int��Ӧ�ַ������ֵĴ���

2. left��rightָ����ƶ�
�ƶ��Ĳ������Ǹ����ַ�������ÿ�����ʵĳ���(len)

3. ��������ִ�еĴ���
len

*/

//class Solution {
//public:
//    vector<int> findSubstring(string s, vector<string>& words) {
//        unordered_map<string, int> hash1; // ����words �������е��ʵ�Ƶ��
//
//        for (auto& s : words) hash1[s]++; // �����ַ�������
//
//        vector<int> ret;
//        int len = words[0].size(), m = words.size();
//        for (int i = 0; i < len; i++) // ִ��len��
//        {
//            // �����ϣ��ά�������������浥�ʵ�Ƶ��
//            unordered_map<string, int> hash2;
//            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len) // ��Ϊ��Ҫ�Ѻ�����ַ����ŵ������������棬���right̫���󣬺��������û�г���Ϊlen���ַ���
//            {
//                // ������ + ά��count
//                string in = s.substr(right, len);
//                hash2[in]++;
//                // ��һ����ϣ��һ����������ʣ������Ļ��ͻ����´���һ��in��������ϣ��
//                // ���Ի���ʱ������
//                // ���in�����ڵ�һ����ϣ�������ʱ��Ž��������ж�
//                // ��Ϊ��ʱ�жϵ�ʱ�����inһ�����������ˣ����ԾͲ��������ٴ���һ��in�ڹ�ϣ��������
//                if (hash1.count(in) && hash2[in] <= hash1[in]) count++; // ������ǰ�ж�һ�£���ʡʱ��
//                // �ж�
//                if (right - left + 1 > len * m) // len * m �������������ַ����ĳ���
//                {
//                    // ������ + ά��count
//                    string out = s.substr(left, len);
//                    if (hash1.count(out) && hash2[out] <= hash1[out]) count--; // ��Ч����
//                    hash2[out]--;
//                    // �����ں�left����ƶ�len��
//                    left += len;
//                }
//
//                // ���½��������Ч�ַ��ĸ������õ����ֵ����浥�ʵĸ���ʱ
//                if (count == m) ret.push_back(left);
//            }
//        }
//        return ret;
//    }
//};