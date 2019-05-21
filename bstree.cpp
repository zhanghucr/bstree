/**
 * 二叉搜索树(C语言): C语言实现的二叉搜索树。
 */

#include "bstree.h"

/* 获取节点数量 */
int bstree_node_number(bs_tree_t tree)
{
    int    num_l = 0;
    int    num_r = 0;
    
    if (tree == NULL)  //递归出口
    {
        return 0;
    }

    num_l = bstree_node_number(tree->left);
    num_r = bstree_node_number(tree->right);
    return (num_l + num_r + 1);
}

/* 获取叶子节点数量 */
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
    
    num_l = bstree_leaf_number(tree->left);   //左子树中叶节点的个数
    num_r = bstree_leaf_number(tree->right);  //右子树中叶节点的个数
    return (num_l + num_r);
}

/* 获取树的深度 */
int bstree_depth(bs_tree_t tree)
{
    int    depth_l = 0;
    int    depth_r = 0;
    
    if (tree == NULL)  //递归出口
    {
        return 0;
    }
    
    depth_l = bstree_depth(tree->left);
    depth_r = bstree_depth(tree->right);
    return depth_l > depth_r ? (depth_l + 1) : (depth_r + 1);
}

/* 前序遍历"二叉树" */
void bstree_traverse_preorder(bs_tree_t tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->key);
        bstree_traverse_preorder(tree->left);
        bstree_traverse_preorder(tree->right);
    }
}

/* 中序遍历"二叉树" */
void bstree_traverse_inorder(bs_tree_t tree)
{
    if (tree != NULL)
    {
        bstree_traverse_inorder(tree->left);
        printf("%d ", tree->key);
        bstree_traverse_inorder(tree->right);
    }
}

/* 后序遍历"二叉树" */
void bstree_traverse_postorder(bs_tree_t tree)
{
    if (tree != NULL)
    {
        bstree_traverse_postorder(tree->left);
        bstree_traverse_postorder(tree->right);
        printf("%d ", tree->key);
    }
}

/* 按层次遍历"二叉树" */
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

/* 判断是否为完全二叉树 */
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
        if (leaf_flag) //已经出现了有空子树的节点了，后面出现的必须为叶节点（左右子树都为空）
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

/* 判断是否为满二叉树 */
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
        if (leaf_flag) //已经出现了有空子树的节点了，后面出现的必须为叶节点（左右子树都为空）
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

/* 查找"二叉树x"中键值为key的节点 */
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

/* 查找最小结点：返回tree为根结点的二叉树的最小结点 */
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
 
/* 查找最大结点：返回tree为根结点的二叉树的最大结点 */
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

/* 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点" */
bs_node_t* bstree_successor(bs_node_t *x)
{
    // 如果x存在右孩子，则"x的后继结点"为 "以其右孩子为根的子树的最小结点"。
    if (x->right != NULL)
    {
        return bstree_minimum(x->right);
    }

    // 如果x没有右孩子。则查找"x的最低的父结点，并且x节点属于该父结点的左子树"，找到的这个"最低的父结点"就是"x的后继结点"。
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
 
/* 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点" */
bs_node_t* bstree_predecessor(bs_node_t *x)
{
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (x->left != NULL)
    {
        return bstree_maximum(x->left);
    }

    // 如果x没有左孩子。则查找"x的最低的父结点，并且x结点属于该父结点的右子树"，找到的这个"最低的父结点"就是"x的前驱结点"。
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
 * 创建并返回二叉树结点。
 *
 * 参数说明：
 *     key 是键值。
 *     parent 是父结点。
 *     left 是左孩子。
 *     right 是右孩子。
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
 * 将结点插入到二叉树中
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 插入的结点
 * 返回值：
 *     根节点
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

    // 查找z的插入位置
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
 * 新建结点(key)，并将其插入到二叉树中
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     key 插入结点的键值
 * 返回值：
 *     根节点
 */
bs_node_t* bstree_insert(bs_tree_t tree, bs_type_t key)
{
    bs_node_t *z;    // 新建结点

    // 如果新建结点失败，则返回。
    if ((z = bstree_create_node(key, NULL, NULL, NULL)) == NULL)
    {
        return tree;
    }

    return bstree_insert_node(tree, z);
}

/* 
 * 删除结点(z)，并返回根节点
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 删除的结点
 * 返回值：
 *     根节点
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
    bs_node_t *x = NULL;  /* 真正待删除的节点的左/右子树 */
    bs_node_t *y = NULL;  /* 真正待删除的节点 */

    if ((z->left == NULL) && (z->right == NULL))  /* 待删除的节点为叶子节点 */
    {
        y = z;
    }
    else if (z->left != NULL)
    {
        y = bstree_predecessor(z);  /* 待删除的节点存在左子树 */
    }
    else
    {
        y = bstree_successor(z);  /* 待删除的节点存在右子树 */
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
 * 删除结点(key为节点的键值)，并返回根节点
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 删除的结点
 * 返回值：
 *     根节点
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
 * 销毁二叉树
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
 * 打印"二叉树"
 *
 * tree       -- 二叉树的节点
 * key        -- 节点的键值 
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void bstree_show(bs_tree_t tree)
{
    if (tree != NULL)
    {
        if (tree->parent == NULL)  // tree是根节点
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

