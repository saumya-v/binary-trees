#include<iostream>
#include<queue>
using namespace std;
template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode<int> *takeinput(){
    int rootdata;
    cout<<"enter root data "<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int leftchild;
        cout<<"enter left child of "<<front->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchild);
            front->left=child;
            pendingNodes.push(child);
        }
        int rightchild;
        cout<<"enter right child of "<<front->data<<endl;
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightchild);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;
}
BinaryTreeNode<int> *removeleafNodes(BinaryTreeNode<int> *root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    removeleafNodes(root->left);
    removeleafNodes(root->right);
    return root;
}
void printTree(BinaryTreeNode<int> *root){
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        if(front==NULL){
            cout<<endl;
            if(pendingNodes.size()!=NULL){
                pendingNodes.push(NULL);
            }
        }
        else{
            cout<<front->data<<":"<<endl;
            cout<<"L: ";
            if(front->left!=NULL){
                pendingNodes.push(front->left);
                cout<<front->left->data<<",";
            }
            else{
                cout<<-1<<",";
            }
            cout<<"R: ";
            if(front->right!=NULL){
                pendingNodes.push(front->right);
                cout<<front->right->data<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
}
int main(){
    BinaryTreeNode<int> *root=takeinput();
    root=removeleafNodes(root);
    printTree(root);
}

