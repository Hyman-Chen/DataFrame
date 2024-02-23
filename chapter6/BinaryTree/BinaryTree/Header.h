//
//  Header.h
//  BinaryTree
//
//  Created by Hyman on 2024/2/24.
//

#ifndef Header_h
#define Header_h
#define ElementType int

// 定义二叉树
typedef struct TreeNode *BinTree;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

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

int IsEmpty(BinTree BT){
    if (BT->Left==NULL && BT->Right==NULL) return 1;
    else return 0;
}

// 非递归中序遍历
//void InOrderTraversal(BinTree BT){
//    BinTree T = BT;
//    if (!IsEmpty(BT)) {
//        if (BT->Left){
//    }
//}
#endif /* Header_h */
