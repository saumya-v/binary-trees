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
BinaryTreeNode<int> *buildTreeHelper(int *postorder,int poststart,int postend,int *inorder,int instart,int inend){
    if(poststart>postend || instart>inend){
        return NULL;
    }
    int rootval=postorder[postend];
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootval);
    int k=0;
    for(int i=instart;i<=inend;i++){
        if(rootval==inorder[i]){
            k=i;
            break;
        }
    }
    root->left=buildTreeHelper(postorder,poststart,poststart+k-instart-1,inorder,instart,k-1);
    root->right=buildTreeHelper(postorder,poststart+k-instart,postend-1,inorder,k+1,inend);
    return root;
}
BinaryTreeNode<int> *buildTree(int *postorder,int postsize,int *inorder,int insize){
    int poststart=0;
    int postend=postsize-1;
    int instart=0;
    int inend=insize-1;
    return buildTreeHelper(postorder,poststart,postend,inorder,instart,inend);
}
int main(){
    int size;
    cout<<"enter size "<<endl;
    cin>>size;
    int *in=new int[size];
    int *post=new int[size];
    for (int i = 0; i < size; i++) cin >> in[i];
    for (int i = 0; i < size; i++) cin >> post[i];
    BinaryTreeNode<int> *root=buildTree(post,size,in,size);
    printTree(root);
}
