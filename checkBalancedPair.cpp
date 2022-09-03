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
int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}
class checkBalanced{
public:
    int height;
    bool balanced;
};
checkBalanced *isBalanced(BinaryTreeNode<int> *root){
    if(root==NULL){
        checkBalanced *ans=new checkBalanced();
        ans->height=0;
        ans->balanced=true;
        return ans;
    }
    checkBalanced *ans1=isBalanced(root->left);
    checkBalanced *ans2=isBalanced(root->right);
    bool flag;
    if((!ans1->balanced)||(!ans2->balanced)||(abs(ans1->height)-(ans2->height))>1){
        flag= false;
    }
    else{
        flag=true;
    }
    checkBalanced *output=new checkBalanced();
    output->balanced=flag;
    output->height=1+max(ans1->height,ans2->height);
    return output;
}
bool isBalanced1(BinaryTreeNode<int> *root){
    if(root==NULL){
        return true;
    }
    return isBalanced(root)->balanced;
}
int main(){
    BinaryTreeNode<int> *root=takeinput();
    if(isBalanced1(root)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
