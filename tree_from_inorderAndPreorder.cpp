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
BinaryTreeNode<int> *buildTreeHelper(int *preorder,int prestart,int preend,int *inorder,int instart,int inend){
    if(prestart>preend || instart>inend){
        return NULL;
    }
    int rootval=preorder[prestart];
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootval);
    int k=0;
    for(int i=instart;i<=inend;i++){
        if(rootval==inorder[i]){
            k=i;
            break;
        }
    }
    root->left=buildTreeHelper(preorder,prestart+1,prestart+(k-instart),inorder,instart,k-1);
    root->right=buildTreeHelper(preorder,prestart+(k-instart)+1,preend,inorder,k+1,inend);
    return root;
}
BinaryTreeNode<int> *buildTree(int *preorder,int presize,int *inorder,int insize){
    int prestart=0;
    int preend=presize-1;
    int instart=0;
    int inend=insize-1;
    return buildTreeHelper(preorder,prestart,preend,inorder,instart,inend);
}
int main(){
    int size;
    cout<<"enter size "<<endl;
    cin>>size;
    int *pre=new int[size];
    int *in=new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root=buildTree(pre,size,in,size);
    printTree(root);
}

