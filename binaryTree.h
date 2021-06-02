#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

using namespace std;

template <typename E>
struct TreeNode
{
    E value;
    TreeNode<E>* left;
    TreeNode<E>* right;
    TreeNode<E>()
    {
        value = E();
        left = NULL;
        right = NULL;
    }
};

template <typename E, typename C>
class BinaryTree
{
public:
    BinaryTree() {root = NULL;}

    BinaryTree(const BinaryTree& rhs);
    ~BinaryTree() {destroySubtree(root);}
    void operator =(const BinaryTree& rhs);

    void insertNode(E);
    bool searchNode(E);
    E getValue(E);
    E getRootValue();
    void remove(E);
    void displayInOrder() const {displayInOrder(root);}
    int getSize() const {return getSize(root);}
    void inOrderList(vector<E>& itemList);

private:
    TreeNode<E>* root;
    C highestPriority;

    void insert(TreeNode<E> *&nodePtr, TreeNode<E> *&newNode);
    void destroySubtree(TreeNode<E> *nodeptr);
    void deleteNode(E, TreeNode<E>*&nodeptr);
    void makeDeletion(TreeNode<E> *&nodeptr);
    void displayInOrder(TreeNode<E> *nodeptr) const;
    void displayPreOrder(TreeNode<E> *nodeptr) const;
    void displayPostOrder(TreeNode<E> *nodeptr) const;
    int getSize(TreeNode<E> *nodeptr) const;
    void copy(TreeNode<E> *&current, const TreeNode<E> *other);
    void inOrderList(vector<E>& itemList, TreeNode<E> *nodeptr);
};
template <typename E, typename C>
BinaryTree<E, C>::BinaryTree(const BinaryTree<E, C>& rhs)
{
    copy(root, rhs.root);
}

template <typename E, typename C>
void BinaryTree<E, C>::operator=(const BinaryTree<E, C>& rhs)
{
    destroySubtree(root);
    copy(root, rhs.root);
}

template <typename E, typename C>
void BinaryTree<E, C>::insertNode(E value)
{
    TreeNode<E>* new_node = new TreeNode<E>;

    new_node->value = value;
    new_node->left = new_node->right = NULL;

    insert(root, new_node);
}

template <typename E, typename C>
void BinaryTree<E, C>::insert(TreeNode<E> *&nodePtr, TreeNode<E> *&newNode)
{
    if (nodePtr == NULL)
        nodePtr = newNode;
    else if (highestPriority(newNode->value, nodePtr->value))
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

template <typename E, typename C>
void BinaryTree<E, C>::displayInOrder(TreeNode<E> *nodeptr) const
{
    if (nodeptr)
    {
        displayInOrder(nodeptr->left);
        cout << nodeptr->value << "\n\n";
        displayInOrder(nodeptr->right);
    }
}

template <typename E, typename C>
void BinaryTree<E, C>::destroySubtree(TreeNode<E>* nodeptr)
{
    while (nodeptr)
    {
        makeDeletion(nodeptr);
    }
}

template <typename E, typename C>
bool BinaryTree<E, C>::searchNode(E value)
{
    TreeNode<E>* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == value)
            return true;
        else if (highestPriority(value, nodePtr->value))
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return false;
}

template <typename E, typename C>
E BinaryTree<E, C>::getValue(E value)
{
    TreeNode<E>* nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == value)
            return nodePtr->value;
        else if (highestPriority(value, nodePtr->value))
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
}

template <typename E, typename C>
E BinaryTree<E, C>::getRootValue()
{
    if (root)
        return root->value;
    else
        return E();
}

template <typename E, typename C>
void BinaryTree<E, C>::remove(E value)
{
    deleteNode(value, root);
}

template <typename E, typename C>
void BinaryTree<E, C>::deleteNode(E value, TreeNode<E>*& nodePtr)
{
    if (highestPriority(value, nodePtr->value))
        deleteNode(value, nodePtr->left);
    else if (highestPriority(nodePtr->value, value))
        deleteNode(value, nodePtr->right);
    else
        makeDeletion(nodePtr);
}

template <typename E, typename C>
void BinaryTree<E, C>::makeDeletion(TreeNode<E>*& nodePtr)
{
    TreeNode<E> *tempNodePtr;

    if (nodePtr == NULL)
        printf("cannot delete empty node.\n");

    else if (nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }

    else if (nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }

    //If nodeptr has two Children
    else
    {
        tempNodePtr = nodePtr->right;

        while (tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;

        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;

        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

template <typename E, typename C>
int BinaryTree<E, C>::getSize(TreeNode<E>* nodePtr) const
{
    if (!nodePtr)
        return 0;
    else if ((!(nodePtr->left)) && (!(nodePtr->right)))
        return 1;
    else
        return (1 + getSize(nodePtr->left) + getSize(nodePtr->right));
}

template <typename E, typename C>
void BinaryTree<E, C>::copy(TreeNode<E>*& current, const TreeNode<E>* other)
{
    if (other == NULL)
    {
        current = NULL;
    }
    else
    {
        TreeNode<E>* temp = new TreeNode<E>;
        temp->value = other->value;
        current = temp;
        copy(current->left, other->left);
        copy(current->right, other->right);
    }

}

template <typename E, typename C>
void BinaryTree<E, C>::inOrderList(vector<E>& itemList, TreeNode<E>* nodePtr)
{
    if (nodePtr)
    {
        inOrderItemList(itemList, nodePtr->left);
        itemList.push_back(nodePtr->value);
        inOrderItemList(itemList, nodePtr->right);
    }

}

template <typename E, typename C>
void BinaryTree<E, C>::inOrderList(vector<E>& itemList)
{
    inOrderItemList(itemList, root);
}

#endif // BINARYTREE_H
