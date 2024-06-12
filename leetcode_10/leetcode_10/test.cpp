#include<iostream>
#include <unordered_map>
using namespace std;

/*
14. �����ǰ׺

https://leetcode.cn/problems/longest-common-prefix/

��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��



ʾ�� 1��

���룺strs = ["flower","flow","flight"]
�����"fl"

ʾ�� 2��

���룺strs = ["dog","racecar","car"]
�����""
���ͣ����벻���ڹ���ǰ׺��


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // ��������ַ�������Ϊ�գ��򷵻ؿ��ַ���
        if(strs.empty()) return "";

        // ʹ�� minmax_element ���ҵ��ַ�����������С�������ַ���
        // p ��һ�� pair��p.first ָ����С�ַ�����p.second ָ������ַ�����
        const auto p = minmax_element(strs.begin(), strs.end());

        // ������С�ַ�����ÿһ���ַ����ӵ�һ���ַ������һ���ַ�����
        for(int i=0; i<p.first->size(); i++)
        {
            // �����ĳ��λ�ã���С�ַ���������ַ������ַ�����ͬ���򷵻���С�ַ����Ĵӿ�ʼ����ǰλ�õ��Ӵ�
            if(p.first->at(i) != p.second->at(i))
            {
                //  ������С�ַ����ӿ�ʼ���� i ��λ�õ��Ӵ�
                return p.first->substr(0,i);
            }
        }

        // ���ѭ��������˵����С�ַ���������������ǰ׺
        return *p.first;
    }
};

const -> ����һ�����η�����ʾ���� p �ǳ��������ܱ��޸ġ���ȷ���� p ��ֵ������֮�����ٱ��ı�

auto -> ����һ������˵���������߱����������Ҳ�ĳ�ʼ�����ʽ�Զ��ƶϱ��� p �����͡�
�����p �������� std::pair<iterator, iterator>������ iterator �� strs �����ĵ���������

p -> ���Ǳ��������ƣ�����һ�� std::pair�������������������ֱ�ָ�� strs ��������С�������ַ�����

minmax_element -> ����һ����׼�⺯����λ�� <algorithm> ͷ�ļ��С�����������������������һ�� std::pair��
���е�һ��Ԫ���Ƿ�Χ�ڵ���СԪ�أ��ڶ���Ԫ���Ƿ�Χ�ڵ����Ԫ�ء�

strs.begin() -> ����һ����������ָ�� strs �����ĵ�һ��Ԫ�ء�

strs.end() -> ����һ����������ָ�� strs ���������һ��Ԫ��֮���λ�á�

p.first -> ���� p ��� std::pair �ĵ�һ��Ԫ�أ�p.first ��ָ�� strs ����С�ַ����ĵ�������

"->" -> ���ǳ�Ա���������������ָ�����ĳ�Ա���������ڷ��ʵ�����ָ����ַ����ĳ�Ա���� at()

at(i) -> �����ַ�����ĳ�Ա�����������ַ���������Ϊ i ���ַ���������� i ������Χ�����׳� out_of_range �쳣

p.second -> ���� p ��� std::pair �ĵڶ���Ԫ�أ�p.second ��ָ�� strs ������ַ����ĵ�����

substr(0, i) -> �ַ�����ĳ�Ա����������һ�����ַ�������ʼλ��Ϊ 0������Ϊ i

*p.first -> ����������������ڻ�ȡָ��������ָ��Ķ��������*p.first ��ȡ������ p.first ָ����ַ���

--------------------------------------------------------------------------
std::string substr (size_t pos = 0, size_t len = npos) const;
pos �����ַ�����ʼ��λ�á�
len �����ַ����ĳ��ȡ�

������ p.first->substr(0, 0) ʱ��

p.first ��һ��ָ���ַ�����ָ�룬������ָ������ַ��� "dog"��
substr(0, 0) ��ʾ��λ�� 0 ��ʼ������Ϊ 0��

����ζ�Ŵ��ַ����ĵ�һ���ַ���ʼ����ȡ����Ϊ 0 �����ַ�������Ȼ�����������ַ�����һ�����ַ�����
*/



/*
20. ��Ч������

https://leetcode.cn/problems/valid-parentheses/description/

����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�


ʾ�� 1��

���룺s = "()"
�����true

ʾ�� 2��

���룺s = "()[]{}"
�����true

ʾ�� 3��

���룺s = "(]"
�����false

ջ��һ�ֺ���ȳ������ݽṹ������ζ�����һ��ѹ��ջ��Ԫ�����ȵ�����
���������ر��ʺϴ���ɶԳ��֡�Ƕ�׽ṹ�����⣬��������ƥ�䡢��������ջ�ȡ�

����������

push����Ԫ��ѹ��ջ����
pop����ջ��Ԫ�ص�����
top������ջ��Ԫ�ض���������
empty�����ջ�Ƿ�Ϊ�ա�


ջ�ĺ���ȳ� (LIFO) ���ԣ�

ջ��һ�ֺ���ȳ� (LIFO, Last In First Out) �����ݽṹ���ʺϴ�������ƥ�����⡣
ÿ������һ��������ʱ������ѹ��ջ�У�ÿ������һ��������ʱ�����ջ���Ƿ��Ƕ�Ӧ�������ţ�����ǣ��򵯳�ջ��Ԫ�ء�



ƥ�����Ŷԣ�

ÿ�������Ŷ�������һ����Ӧ�������ţ����ұ��밴��ȷ��˳��Ƕ�ס�ͨ��ջ�����ݽṹ����������ʵ������ƥ�䡣

�ַ���������

ͨ�������ַ�����������ÿһ���ַ��Ƿ������ţ���������Ӧ�Ĵ���������̱�֤���ַ����е�ÿһ�����Ŷ�������ƥ�䡣


class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s)
        {
            // ���c�� ([{ ����ջ
            if(c == '(' || c == '{' || c == '[')
            {
                stk.push(c);
            }
            // ���c�� )]} ����ջ��Ϊ�� ���ж�ջ���Ƿ�Ϊ��֮��Ӧ�������� �����ջ�������򷵻�false
            else if(c == ')' && !stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else if(c == '}' && !stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else if(c == ']' && !stk.empty() && stk.top() == '[')
            {
                stk.pop();
            }
            else
            {
                // ���c�� )}] ջΪ�� ��ô����false
                // ���c�� )}] ջ��Ϊ�գ� ���� ջ��������c��Ӧ�������� ��ô����false
                return false;
            }
        }
        // ����"(){}[" �� ������ջ��Ϊ�գ���ô�����ж������������
        return stk.empty();
    }
};

�Ż���
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk; // ����һ���ַ�ջ

        for (char c : s) { // ʹ�÷�Χ for ѭ�������ַ��� s �е�ÿһ���ַ� c
            // ����ַ� c �������� (��{ �� [������ѹ��ջ stk
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            }
            // ����ַ���������֮һ�������ƥ����
            else {
                // ���ջ�Ƿ�Ϊ�գ����Ϊ���򷵻� false����Ϊû�ж�Ӧ�������š�
                // ʹ�ø������� isMatchingPair ���ջ��Ԫ���Ƿ��뵱ǰ������ƥ�䣬�����ƥ���򷵻� false
                if (stk.empty() || !isMatchingPair(stk.top(), c)) {
                    return false;
                }
                // ƥ��ɹ�������ջ��Ԫ��
                stk.pop();
            }
        }

        // �����ջ�Ƿ�Ϊ�գ����Ϊ����������ȫƥ�䣬������δƥ���������
        return stk.empty();
    }

private:
    // �������������ڼ�����������Ƿ�ƥ��
    bool isMatchingPair(char left, char right) {
        return (left == '(' && right == ')') ||
               (left == '{' && right == '}') ||
               (left == '[' && right == ']');
    }
};

�������� isMatchingPair ���ڼ�����������Ƿ�ƥ�䡣
���������ַ� left �� right�����������һ��ƥ������ţ��򷵻� true�����򷵻� false

*/

/*
ʲôʱ��ʹ��for (auto c : s)��ʲôʱ��ʹ��for (int i = 0; i < s.size(); i++)

ֻ�������Ҳ���Ҫ������ʹ�� for (auto c : s)�������ʹ�������ࡣ
��Ҫ������ʹ�� for (int i = 0; i < s.size(); i++)��
��Ҫ�޸�Ԫ�أ�ʹ�� for (int i = 0; i < s.size(); i++) �� for (auto& c : s)���������Ҫ����������Ҫ�޸�Ԫ�أ���


ֻ��������
std::string s = "example";
for (auto c : s) {
    std::cout << c << " ";
}

��Ҫ������
std::string s = "example";
for (int i = 0; i < s.size(); i++) {
    if (i % 2 == 0) { // ��ӡż���������ַ�
        std::cout << s[i] << " ";
    }
}

�޸�Ԫ�أ�
std::string s = "example";
for (auto& c : s) {
    c = toupper(c); // ��ÿ���ַ�ת��Ϊ��д
}
std::cout << s; // ��� "EXAMPLE"

��Ҫ�������޸�Ԫ�أ�
std::vector<int> nums = {1, 2, 3, 4, 5};
for (int i = 0; i < nums.size(); i++) {
    nums[i] *= 2; // ��ÿ��Ԫ�س���2
}
for (auto num : nums) {
    std::cout << num << " "; // ��� "2 4 6 8 10"
}

*/

/*
HJ73 �������ڵ�����ת��

https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&&tqId=21296&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

������������ڣ���������һ��ĵڼ��졣
��֤���Ϊ4λ�������ںϷ���
���ף�ʱ�临�Ӷȣ�O(n) ���ռ临�Ӷȣ�O(1)

����������
����һ�У�ÿ�пո�ָ�ֱ����꣬�£���

���������
�������һ��ĵڼ���

2012 12 31
366

#include <iostream>
using namespace std;

int main()
{
    // ��������5�£���ǰ���ĸ��¿϶��ǹ���ģ�ֱ�Ӽ��ϾͿ���
    int year, month, day;
    cin >> year >> month >> day;

    int monthDays1_N[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
    // [1,month-1]
    int n = monthDays1_N[month-1] + day;

    // ����һ�󣬰��겻���İ�����һ��
    if(month > 2 && ((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)))
    {
        n += 1;
    }

    cout<<n<<endl;

    return 0;

}
*/

/*


*/




int main() {
    std::unordered_map<std::string, int> umap;

    // ����Ԫ��
    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["orange"] = 3;

    // ����Ԫ��
    std::cout << "apple: " << umap["apple"] << std::endl;

    // ����Ԫ��
    if (umap.find("banana") != umap.end()) {
        std::cout << "banana found" << std::endl;
    }

    // ����Ԫ��
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}