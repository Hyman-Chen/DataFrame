//
//  Header.h
//  BinaryTree
//
//  Created by Hyman on 2024/2/24.
//

#ifndef Header_h
#define Header_h
#define ElementType int
#define MaxSize 10

// 定义堆栈
typedef struct sNode *Stack;
struct sNode{
    ElementType data[MaxSize];
    int top;
};

//// 定义树和二叉树
//typedef struct TreeNode *Tree;
//struct TreeNode{
//    ElementType Data;
//    Tree Left;
//    Tree Right;
//};

// 定义二叉树
typedef struct TreeNode1 *BinTree;
typedef BinTree Position;
struct TreeNode1{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
// 二叉树查找操作
Position Find(ElementType X, BinTree BST){
    if (!BST) return NULL;
    if (X<BST->Data) return Find(X, BST->Left);
    else if (X>BST->Data) return Find(X, BST->Right);
    else return BST;
}
// 改为迭代查找
Position IterFind(ElementType X, BinTree BST){
    while (BST){
        if (X > BST->Data) BST = BST->Right;
        else if (X<BST->Data) BST = BST ->Left;
        else return BST;
    }
    return BST;
}
//递归FindMin
Position FindMin(BinTree BST){
    if (!BST) return NULL;
    else if (BST->Left == NULL) return BST;
    else return FindMin(BST->Left);
}
//迭代FindMin
Position IterFindMin(BinTree BST){
    while(BST){
        if (BST->Left == NULL) return BST;
        else BST = BST->Left;
    }
    return NULL;
}
Position IterFindMax(BinTree BST){
    if(BST){
        while (BST->Right) BST = BST->Right;
    }
    return BST;
    
}

//Insert
BinTree Insert(ElementType X, BinTree BST){
    if (!BST){
        BST = malloc(sizeof(struct TreeNode1));
        BST ->Data = X;
        BST->Left = BST->Right= NULL;
    }
    else {
        if (X < BST->Data)
            BST ->Left = Insert(X, BST);
        else if (X > BST -> Data)
            BST ->Right = Insert(X, BST);
    }
    return BST;
}
//Delete??????????
BinTree Delete(ElementType X, BinTree BST){
    Position Tmp;
    if (!BST) printf("要删除的元素未找到\n");
    else if (X<BST->Data)
        BST->Left = Delete(X, BST->Left);
    else if (X>BST->Data)
        BST->Right = Delete(X, BST->Right);
    else
        if (BST->Left && BST->Right){
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Data, BST->Right);
        }else{
            Tmp = BST;
            if (BST->Left) BST = BST->Left;
            else if (BST->Right) BST = BST->Right;
            free(Tmp);
        }
    return BST;
}

//// 构造空树
//void InitTree(Tree *T){
//    (*T) = NULL;
//}

//// 销毁树
//void DestroyTree(Tree *T){
//    if (*T)
//    {
//        DestroyTree( &( *T ) -> Left );
//        DestroyTree( &( *T ) -> Right );
//        (*T) = NULL;
//        free((*T));
//    }
//    return;
//}

//// 创建树
//void CreateTreee(Tree *T){
//    (*T) = (Tree)malloc(sizeof(struct TreeNode));
//}
// 二叉树的判空
int IsEmpty(BinTree BT){
    if (BT == NULL) return 1;
    else return 0;
}
// 先序遍历
void PreOrderTraversal(BinTree BT){
    if (BT){printf("%d",BT->Data);
        PreOrderTraversal(BT->Left);
        PreOrderTraversal(BT->Left);
    }
}
// 中序遍历
void InOrderTraversal0(BinTree BT){
    if (BT){
        InOrderTraversal0(BT->Left);
        printf("%d",BT->Data);
        InOrderTraversal0(BT->Left);
    }
}
// 后序遍历
void PostOrderTraversal(BinTree BT){
    if (BT){
        PostOrderTraversal(BT->Left);
        PostOrderTraversal(BT->Left);
        printf("%d",BT->Data);
    }
}

#endif /* Header_h */
