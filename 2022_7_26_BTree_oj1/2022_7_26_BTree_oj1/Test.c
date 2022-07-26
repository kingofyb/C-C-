#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//https://leetcode.cn/problems/univalued-binary-tree/
//��ֵ������
//bool flag = true;
//void PreOrderCompare(struct TreeNode* root, int val)
//{
//    if (root == NULL || flag == false)
//        return;
//
//    if (root->val != val)
//    {
//        flag = false;
//        return;
//    }
//
//    PreOrderCompare(root->right, val);
//    PreOrderCompare(root->left, val);
//}
//bool isUnivalTree(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//    flag = true;
//    PreOrderCompare(root, root->val);
//    return flag;
//}


//����һ�ַ���


// bool isUnivalTree(struct TreeNode* root){
//     if(root == NULL)
//     {
//         return true;
//     }

//     if(root->left && root->left->val != root->val)//���������Ϊ�գ����Ҳ����ڸ�
//     {
//         return false;
//     }
//     if(root->right && root->right->val != root->val)//���������Ϊ�գ����Ҳ����ڸ�
//     {
//         return false;
//     }
//     return isUnivalTree(root->left) && isUnivalTree(root->right);
// }


// https://leetcode-cn.com/problems/same-tree/
// ��ͬ����

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    if (p == NULL || q == NULL)
//    {
//        return false;
//    }
//    if (p->val != q->val)
//    {
//        return false;
//    }
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}

// https://leetcode-cn.com/problems/symmetric-tree/
// �Գƶ�����
//bool isSymmetricSubTree(struct TreeNode* root1, struct TreeNode* root2)
//{
//    if (root1 == NULL && root2 == NULL)
//    {
//        return true;
//    }
//    if (root1 == NULL || root2 == NULL)
//    {
//        return false;
//    }
//    if (root1->val != root2->val)
//    {
//        return false;
//    }
//
//    return isSymmetricSubTree(root1->left, root2->right) &&
//        isSymmetricSubTree(root1->right, root2->left);
//}
//bool isSymmetric(struct TreeNode* root) {
//    if (root == NULL)
//    {
//        return true;
//    }
//    return isSymmetricSubTree(root->left, root->right);
//}

// https://leetcode.cn/problems/binary-tree-preorder-traversal/
// ǰ�����

//int treeSize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : treeSize(root->left) + treeSize(root->right) + 1;
//}
//void preorder(struct TreeNode* root, int* a, int* pi)
//{
//    if (root == NULL)
//    {
//        return;
//    }
//
//    a[(*pi)++] = root->val;
//    preorder(root->left, a, pi);
//    preorder(root->right, a, pi);
//
//}
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = treeSize(root);
//    int* a = (int*)malloc(*returnSize * sizeof(int));
//    int i = 0;
//    preorder(root, a, &i);
//
//    return a;
//}

// https://leetcode.cn/problems/subtree-of-another-tree/
// ��һ����������

//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//    {
//        return true;
//    }
//    if (p == NULL || q == NULL)
//    {
//        return false;
//    }
//    if (p->val != q->val)
//    {
//        return false;
//    }
//    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//    {
//        return false;
//    }
//
//    //��������root�������������Ƚ�һ��
//    if (isSameTree(root, subRoot))
//    {
//        return true;
//    }
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}


// https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
// ����������
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//typedef char BTDataType;
//typedef struct BinaryTreeNode
//{
//    struct BinaryTreeNode* left;
//    struct BinaryTreeNode* right;
//    BTDataType data;
//}BTNode;
//
//BTNode* BuyNode(BTDataType x)
//{
//    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
//    assert(node);
//
//    node->data = x;
//    node->left = NULL;
//    node->right = NULL;
//
//    return node;
//}
//
//BTNode* CreateTree(char* str, int* pi)
//{
//    if (str[*pi] == '#')
//    {
//        (*pi)++;
//        return NULL;
//    }
//
//    BTNode* root = BuyNode(str[(*pi)++]);
//    root->left = CreateTree(str, pi);
//    root->right = CreateTree(str, pi);
//    return root;
//}
//void InOrder(BTNode* root)//�������
//{
//    if (root == NULL)
//        return;
//    InOrder(root->left);
//    printf("%c ", root->data);
//    InOrder(root->right);
//}
//int main()
//{
//    char str[100];
//    scanf("%s", str);
//    int i = 0;
//    BTNode* root = CreateTree(str, &i);
//    InOrder(root);
//    return 0;
//}




