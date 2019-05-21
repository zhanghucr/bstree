/**
 * ����������(C����): C����ʵ�ֵĶ�����������
 */

#include "bstree.h"

/* ��ȡ�ڵ����� */
int bstree_node_number(bs_tree_t tree)
{
    int    num_l = 0;
    int    num_r = 0;
    
    if (tree == NULL)  //�ݹ����
    {
        return 0;
    }

    num_l = bstree_node_number(tree->left);
    num_r = bstree_node_number(tree->right);
    return (num_l + num_r + 1);
}

/* ��ȡҶ�ӽڵ����� */
int bstree_leaf_number(bs_tree_t tree)
{
    int    num_l = 0;
    int    num_r = 0;
    
    if (tree == NULL)
    {
        return 0;
    }
    
    if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }
    
    num_l = bstree_leaf_number(tree->left);   //��������Ҷ�ڵ�ĸ���
    num_r = bstree_leaf_number(tree->right);  //��������Ҷ�ڵ�ĸ���
    return (num_l + num_r);
}

/* ��ȡ������� */
int bstree_depth(bs_tree_t tree)
{
    int    depth_l = 0;
    int    depth_r = 0;
    
    if (tree == NULL)  //�ݹ����
    {
        return 0;
    }
    
    depth_l = bstree_depth(tree->left);
    depth_r = bstree_depth(tree->right);
    return depth_l > depth_r ? (depth_l + 1) : (depth_r + 1);
}

/* ǰ�����"������" */
void bstree_traverse_preorder(bs_tree_t tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->key);
        bstree_traverse_preorder(tree->left);
        bstree_traverse_preorder(tree->right);
    }
}

/* �������"������" */
void bstree_traverse_inorder(bs_tree_t tree)
{
    if (tree != NULL)
    {
        bstree_traverse_inorder(tree->left);
        printf("%d ", tree->key);
        bstree_traverse_inorder(tree->right);
    }
}

/* �������"������" */
void bstree_traverse_postorder(bs_tree_t tree)
{
    if (tree != NULL)
    {
        bstree_traverse_postorder(tree->left);
        bstree_traverse_postorder(tree->right);
        printf("%d ", tree->key);
    }
}

/* ����α���"������" */
void bstree_traverse_breadth(bs_tree_t tree)
{
    if (tree == NULL)
    {
        return;
    }
    
    queue<bs_node_t *> que;
    que.push(tree);
    while (!que.empty())
    {
        bs_node_t *x = que.front();
        que.pop();

        printf("%d ", x->key);
        
        if (x->left != NULL)
        {
            que.push(x->left);
        }
        
        if (x->right != NULL)
        {
            que.push(x->right);
        }
    }
    
    return;
}

/* �ж��Ƿ�Ϊ��ȫ������ */
bool bstree_is_complete(bs_tree_t tree)
{
    bool    leaf_flag = false;
    bool    result = true;
    
    if (tree == NULL)
    {
        return false;
    }
    
    queue<bs_node_t *> que;
    que.push(tree);
    while (!que.empty())
    {
        bs_node_t *x = que.front();
        que.pop();
        if (leaf_flag) //�Ѿ��������п������Ľڵ��ˣ�������ֵı���ΪҶ�ڵ㣨����������Ϊ�գ�
        {
            if (x->left != NULL || x->right != NULL)
            {
                result = false;
                break;
            }
        }
        else
        {
            if (x->left != NULL && x->right != NULL)
            {
                que.push(x->left);
                que.push(x->right);
            }
            else if (x->left != NULL && x->right == NULL)
            {
                leaf_flag = true;
                que.push(x->left);
            }
            else if (x->left == NULL && x->right != NULL)
            {
                result = false;
                break;
            }
            else
            {
                leaf_flag = true;
            }
        }
    }
    
    return result;
}

/* �ж��Ƿ�Ϊ�������� */
bool bstree_is_full(bs_tree_t tree)
{
    bool    leaf_flag = false;
    bool    result = true;
    
    if (tree == NULL)
    {
        return false;
    }
    
    queue<bs_node_t *> que;
    que.push(tree);
    while (!que.empty())
    {
        bs_node_t *x = que.front();
        que.pop();
        if (leaf_flag) //�Ѿ��������п������Ľڵ��ˣ�������ֵı���ΪҶ�ڵ㣨����������Ϊ�գ�
        {
            if (x->left != NULL || x->right != NULL)
            {
                result = false;
                break;
            }
        }
        else
        {
            if (x->left != NULL && x->right != NULL)
            {
                que.push(x->left);
                que.push(x->right);
            }
            else if (x->left == NULL && x->right == NULL)
            {
                leaf_flag = true;
            }
            else
            {
                result = false;
                break;
            }
        }
    }
    
    return result;
}

/* ����"������x"�м�ֵΪkey�Ľڵ� */
#ifdef RECURSIVE_ALGO
bs_node_t* bstree_search(bs_tree_t tree, bs_type_t key)
{
    if (tree == NULL || tree->key == key)
    {
        return tree;
    }

    if (key < tree->key)
    {
        return bstree_search(tree->left, key);
    }
    else
    {
        return bstree_search(tree->right, key);
    }
}
#else
bs_node_t* bstree_search(bs_tree_t tree, bs_type_t key)
{
    while ((tree != NULL) && (tree->key != key))
    {
        if (key < tree->key)
        {
            tree = tree->left;
        }
        else if (key > tree->key)
        {
            tree = tree->right;
        }
    }

    return tree;
}
#endif

/* ������С��㣺����treeΪ�����Ķ���������С��� */
bs_node_t* bstree_minimum(bs_tree_t tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    
    return tree;
}
 
/* ��������㣺����treeΪ�����Ķ������������ */
bs_node_t* bstree_maximum(bs_tree_t tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    while (tree->right != NULL)
    {
        tree = tree->right;
    }
    
    return tree;
}

/* �ҽ��(x)�ĺ�̽�㡣��������"������������ֵ���ڸý��"��"��С���" */
bs_node_t* bstree_successor(bs_node_t *x)
{
    // ���x�����Һ��ӣ���"x�ĺ�̽��"Ϊ "�����Һ���Ϊ������������С���"��
    if (x->right != NULL)
    {
        return bstree_minimum(x->right);
    }

    // ���xû���Һ��ӡ������"x����͵ĸ���㣬����x�ڵ����ڸø�����������"���ҵ������"��͵ĸ����"����"x�ĺ�̽��"��
    while (x->parent != NULL)
    {
        if (x == x->parent->left)
        {
            return x->parent;
        }
        
        x = x->parent;
    }

    return NULL;
}
 
/* �ҽ��(x)��ǰ����㡣��������"������������ֵС�ڸý��"��"�����" */
bs_node_t* bstree_predecessor(bs_node_t *x)
{
    // ���x�������ӣ���"x��ǰ�����"Ϊ "��������Ϊ���������������"��
    if (x->left != NULL)
    {
        return bstree_maximum(x->left);
    }

    // ���xû�����ӡ������"x����͵ĸ���㣬����x������ڸø�����������"���ҵ������"��͵ĸ����"����"x��ǰ�����"��
    while (x->parent != NULL)
    {
        if (x == x->parent->right)
        {
            return x->parent;
        }
        
        x = x->parent;
    }

    return NULL;
}

/*
 * ���������ض�������㡣
 *
 * ����˵����
 *     key �Ǽ�ֵ��
 *     parent �Ǹ���㡣
 *     left �����ӡ�
 *     right ���Һ��ӡ�
 */
static bs_node_t* bstree_create_node(bs_type_t key, bs_node_t *parent, bs_node_t *left, bs_node_t *right)
{
    bs_node_t *p;

    if ((p = (bs_node_t *)malloc(sizeof(bs_node_t))) == NULL)
    {
        return NULL;
    }
    
    p->key = key;
    p->left = left;
    p->right = right;
    p->parent = parent;
    return p;
}

/* 
 * �������뵽��������
 *
 * ����˵����
 *     tree �������ĸ����
 *     z ����Ľ��
 * ����ֵ��
 *     ���ڵ�
 */
#ifdef RECURSIVE_ALGO
static bs_node_t* bstree_insert_node(bs_tree_t tree, bs_node_t *z)
{
    if (tree == NULL)
    {
        return z;
    }
    
    if (z->key < tree->key)
    {
        if (tree->left == NULL)
        {
            z->parent = tree;
        }
        
        tree->left = bstree_insert_node(tree->left, z);
    }
    else
    {
        if (tree->right == NULL)
        {
            z->parent = tree;
        }
        
        tree->right = bstree_insert_node(tree->right, z);
    }
    
    return tree;
}
#else
static bs_node_t* bstree_insert_node(bs_tree_t tree, bs_node_t *z)
{
    bs_node_t *x = tree;
    
    if (tree == NULL)
    {
        return z;
    }

    // ����z�Ĳ���λ��
    while (x != NULL)
    {
        if (z->key < x->key)
        {
            if (x->left == NULL)
            {
                z->parent = x;
                x->left = z;
                break;
            }

            x = x->left;
        }
        else
        {
            if (x->right == NULL)
            {
                z->parent = x;
                x->right = z;
                break;
            }

            x = x->right;
        }
    }

    return tree;
}
#endif

/* 
 * �½����(key)����������뵽��������
 *
 * ����˵����
 *     tree �������ĸ����
 *     key ������ļ�ֵ
 * ����ֵ��
 *     ���ڵ�
 */
bs_node_t* bstree_insert(bs_tree_t tree, bs_type_t key)
{
    bs_node_t *z;    // �½����

    // ����½����ʧ�ܣ��򷵻ء�
    if ((z = bstree_create_node(key, NULL, NULL, NULL)) == NULL)
    {
        return tree;
    }

    return bstree_insert_node(tree, z);
}

/* 
 * ɾ�����(z)�������ظ��ڵ�
 *
 * ����˵����
 *     tree �������ĸ����
 *     z ɾ���Ľ��
 * ����ֵ��
 *     ���ڵ�
 */
#ifdef RECURSIVE_ALGO
static bs_node_t* bstree_delete_node(bs_tree_t tree, bs_node_t *z)
{
    if (tree->key > z->key) /* delete from left subtree */
    {
        tree->left = bstree_delete_node(tree->left, z);
    }
    else if (tree->key < z->key) /* delete from right subtree */
    {
        tree->right = bstree_delete_node(tree->right, z);
    }
    else  /* if (tree->key == z->key) */
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            /* if t is a leaf node */
            free(tree);
            tree = NULL;
        }
        else if (tree->left)  /* if tree has left subtree */
        {
            /* replace t with the rightmost node in left subtree */
            bs_node_t *p = bstree_predecessor(tree);
            tree->key = p->key;
            tree->left = bstree_delete_node(tree->left, p); 
        }
        else  /* if tree has right subtree */
        {
            /* replace tree with the leftmost node in right subtree */
            bs_node_t *p = bstree_successor(tree);
            tree->key = p->key;
            tree->right = bstree_delete_node(tree->right, p);
        }
    }
    
    return tree;
}
#else
static bs_node_t* bstree_delete_node(bs_tree_t tree, bs_node_t *z)
{
    bs_node_t *x = NULL;  /* ������ɾ���Ľڵ����/������ */
    bs_node_t *y = NULL;  /* ������ɾ���Ľڵ� */

    if ((z->left == NULL) && (z->right == NULL))  /* ��ɾ���Ľڵ�ΪҶ�ӽڵ� */
    {
        y = z;
    }
    else if (z->left != NULL)
    {
        y = bstree_predecessor(z);  /* ��ɾ���Ľڵ���������� */
    }
    else
    {
        y = bstree_successor(z);  /* ��ɾ���Ľڵ���������� */
    }

    if (y->left != NULL)
    {
        x = y->left;
    }
    else
    {
        x = y->right;
    }

    if (x != NULL)
    {
        x->parent = y->parent;
    }

    if (y->parent == NULL)
    {
        tree = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }

    if (y != z)
    {
        z->key = y->key;
    }

    if (y != NULL)
    {
        free(y);
    }

    return tree;
}
#endif

/* 
 * ɾ�����(keyΪ�ڵ�ļ�ֵ)�������ظ��ڵ�
 *
 * ����˵����
 *     tree �������ĸ����
 *     z ɾ���Ľ��
 * ����ֵ��
 *     ���ڵ�
 */
bs_node_t* bstree_delete(bs_tree_t tree, bs_type_t key)
{
    bs_node_t *z;

    if ((z = bstree_search(tree, key)) != NULL)
    {
        tree = bstree_delete_node(tree, z);
    }

    return tree;
}

/*
 * ���ٶ�����
 */
void bstree_destroy(bs_tree_t tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->left != NULL)
    {
        bstree_destroy(tree->left);
    }
    
    if (tree->right != NULL)
    {
        bstree_destroy(tree->right);
    }

    free(tree);
}

/*
 * ��ӡ"������"
 *
 * tree       -- �������Ľڵ�
 * key        -- �ڵ�ļ�ֵ 
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
void bstree_show(bs_tree_t tree)
{
    if (tree != NULL)
    {
        if (tree->parent == NULL)  // tree�Ǹ��ڵ�
        {
            printf("----------------------------------\n");
            printf("tree depth: %d\n", bstree_depth(tree));
            printf("tree nodes: %d\n", bstree_node_number(tree));
            printf("leaf nodes: %d\n", bstree_leaf_number(tree));
            printf("complete  : %d\n", bstree_is_complete(tree));
            printf("full      : %d\n", bstree_is_full(tree));
            printf("----------------------------------\n");
            
            printf("(%2d) root\n", tree->key);
        }
        else if (tree->parent->left == tree)
        {
            printf("(%2d) <--- (%2d)\n", tree->key, tree->parent->key);
        }
        else
        {
            printf("(%2d) ---> (%2d)\n", tree->parent->key, tree->key);
        }

        bstree_show(tree->left);
        bstree_show(tree->right);
    }
}

