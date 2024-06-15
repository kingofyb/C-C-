#include<iostream>
using namespace std;

int main()
{
	return 0;
}

// ģ�� - ��άǰ׺��
/*
DP35 ��ģ�塿��άǰ׺��

https://www.nowcoder.com/practice/99eb8040d116414ea3296467ce81cbbc?tpId=230&tqId=38962&ru=/exam/oj

����һ�� n �� m �еľ��� A ���±��1��ʼ��

�������� q �β�ѯ��ÿ�β�ѯ���� 4 ������ x1 , y1 , x2 , y2

������� (x1, y1) Ϊ���Ͻ� , (x2,y2) Ϊ���½ǵ��Ӿ���ĺͣ�
����������
��һ�а�����������n,m,q.

������n�У�ÿ��m����������������Ԫ��

������q�У�ÿ��4������x1, y1, x2, y2���ֱ������β�ѯ�Ĳ���

���룺
3 4 3
1 2 3 4
3 2 1 0
1 5 7 8
1 1 2 2
1 1 3 3
1 2 3 4

�����
8
25
32

�ⷨһ�������ⷨ -> ģ��
ֱ������������ĺ�

ÿ��ѯ�ʶ�Ҫ��������һ��

ʱ�临�Ӷȣ�O(n*m*q)

�ⷨ����ǰ׺��

1. Ԥ�������һ��ǰ׺�;���
dp[i][j]��ʾ����[1,1]λ�õ�[i,j]λ�ã����������������Ԫ�صĺ�
dp[i][j] = A + B + C + D = (A + B) + (A + C) + D - A

A + B = dp[i-1][j]
A + C = dp[i][j-1]
D = arr[i][j]
A = dp[i-1][j-1]


ֱ�ӱ���dpһ�����ȫ���ó���

2. ʹ��ǰ׺�;���

�����[x1,y1] ~ [x2,y2]

��������������������ټ�ȥ
D = A + B + C + D - (A+B) - (A+C) + A 

A + B + C + D = dp[x2][y2]

A + B = dp[x1-1][y2]

A + C = dp[x2][y1-1]

A = dp[x1-1][y1-1]


ʱ�临�Ӷȣ�O(m*n) + O(q)
*/

//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    // 1. ��������
//    int n = 0, m = 0, q = 0;
//    cin >> n >> m >> q;
//
//    // ��Ϊ�±��Ǵ�1��ʼ�����ģ�����m��nҪ+1���ܷ��ʵ�[m][n]���λ��
//    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cin >> arr[i][j];
//        }
//    }
//
//    // 2. Ԥ����ǰ׺�;���longlong��ֹ���
//    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
//
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
//        }
//    }
//
//    // 3. ʹ��ǰ׺�;���һ��q�Σ�����q--
//    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
//    while (q--)
//    {
//        cin >> x1 >> y1 >> x2 >> y2;
//        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
//
//    }
//
//    return 0;
//}

/*
13. ��������ת����

https://leetcode.cn/problems/roman-to-integer/description/

ʾ�� 1:
����: s = "III"
���: 3

ʾ�� 2:
����: s = "IV"
���: 4

ʾ�� 3:
����: s = "IX"
���: 9


*/


//class Solution {
//public:
//    int romanToInt(string s)
//    {
//        // �����������ֵ�������ӳ��
//        unordered_map<char, int> roman_map = {
//            {'I', 1},
//            {'V', 5},
//            {'X', 10},
//            {'L', 50},
//            {'C', 100},
//            {'D', 500},
//            {'M', 1000}
//        };
//
//        int result = 0;
//        int n = s.size();
//
//        for (int i = 0; i < n; i++)
//        {
//            // �����ǰ�ַ��������һ���ַ������ҵ�ǰ�ַ���ʾ����ֵС����һ���ַ���ʾ����ֵ
//            if (i < n - 1 && roman_map[s[i]] < roman_map[s[i + 1]])
//            {
//                // ��ȥ��ǰ�ַ���ʾ����ֵ
//                result -= roman_map[s[i]];
//            }
//            else
//            {
//                result += roman_map[s[i]];
//            }
//        }
//        return result;
//    }
//};

/*
28. �ҳ��ַ����е�һ��ƥ������±�

https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

ʾ�� 1��
���룺haystack = "sadbutsad", needle = "sad"
�����0
���ͣ�"sad" ���±� 0 �� 6 ��ƥ�䡣
��һ��ƥ������±��� 0 �����Է��� 0 ��

ʾ�� 2��
���룺haystack = "leetcode", needle = "leeto"
�����-1
���ͣ�"leeto" û���� "leetcode" �г��֣����Է��� -1 ��


ʱ�临�Ӷȣ�O(n * m)������ n �� haystack �ĳ��ȣ�m �� needle �ĳ��ȡ������£�ÿ���ַ�����Ҫ���бȽϡ�
�ռ临�Ӷȣ�O(1)����Ϊֻʹ���˳����ռ䡣
*/

//class Solution {
//public:
//    int strStr(string haystack, string needle)
//    {
//        int n = haystack.size(), m = needle.size();
//        // ��ѭ������ haystack ��ÿһ�����ܵ���ʼλ�� i����ΧΪ 0 �� n - m����
//        for (int i = 0; i + m <= n; i++)
//        {
//            bool flag = true;
//            // ��ѭ������ needle ��ÿһ���ַ������ haystack �� i λ�ÿ�ʼ���Ӵ��Ƿ��� needle ƥ�䡣
//            for (int j = 0; j < m; j++)
//            {
//                if (haystack[i + j] != needle[j])
//                {
//                    flag = false;
//                    break;
//                }
//            }
//            // �������ƥ���Ӵ�����������ʼλ�� i
//            if (flag)
//            {
//                return i;
//            }
//        }
//        return -1;
//    }
//};

/*
66. ��һ

https://leetcode.cn/problems/plus-one/description/

ʾ�� 1��
���룺digits = [1,2,3]
�����[1,2,4]
���ͣ����������ʾ���� 123��

ʾ�� 2��
���룺digits = [4,3,2,1]
�����[4,3,2,2]
���ͣ����������ʾ���� 4321��
*/

//class Solution {
//public:
//    vector<int> plusOne(vector<int>& digits) {
//        int n = digits.size(); // ��ȡ����ĳ���
//
//        // ����������һ��Ԫ�ؿ�ʼ����
//        for (int i = n - 1; i >= 0; --i) {
//            if (digits[i] < 9) { // �����ǰԪ��С��9
//                digits[i] += 1; // ����ǰԪ�ؼ�һ
//                return digits; // ֱ�ӷ��ؽ��
//            }
//            digits[i] = 0; // �����ǰԪ�ص���9��������Ϊ0
//        }
//
//        // �������Ԫ�ض���9����������Ŀ�ͷ����1
//        digits.insert(digits.begin(), 1);
//        return digits; // ���ؽ��
//    }
//};