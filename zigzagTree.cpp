#include<iostream>
#include<queue>
#include<stack>
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
        cout<<"enter left child of "<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(leftchild);
            front->left=child;
            pendingNodes.push(child);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            BinaryTreeNode<int> *child=new BinaryTreeNode<int>(rightchild);
            front->right=child;
            pendingNodes.push(child);
        }
    }
    return root;

}
void zigzag(BinaryTreeNode<int> *root){
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    int currentlevelremaining=1;
    bool flag=true;
    int nextLevelCount=0;
    while(!s1.empty() || !s2.empty()){
        if(flag){
            BinaryTreeNode<int> *top=s1.top();
            s1.pop();
            cout<<top->data<<" ";
            currentlevelremaining--;
            if(top->left){
                s2.push(top->left);
                nextLevelCount++;
            }
            if(top->right){
                s2.push(top->right);
                nextLevelCount++;
            }
            if(currentlevelremaining==0){
                cout<<endl;
                currentlevelremaining=nextLevelCount;
                nextLevelCount=0;
                flag=false;
            }
        }
        else{
            BinaryTreeNode<int> *top=s2.top();
            s2.pop();
            cout<<top->data<<" ";
            currentlevelremaining--;
            if(top->right){
                s1.push(top->right);
                nextLevelCount++;
            }
            if(top->left){
                s1.push(top->left);
                nextLevelCount++;
            }
            if(currentlevelremaining==0){
                cout<<endl;
                currentlevelremaining=nextLevelCount;
                nextLevelCount=0;
                flag=true;
            }
        }
    }
}
int main(){
    BinaryTreeNode<int> *root=takeinput();
    zigzag(root);
}
