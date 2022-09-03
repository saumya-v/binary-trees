#include <iostream>
#include <queue>
#include <vector>
using namespace std;
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
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
void print(Node<int> *head){
    Node<int> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
vector<Node<int>*> constructLL(BinaryTreeNode<int> *root){
    vector<Node<int>*> output;
    if(root==NULL){
        return output;
    }
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    int currentlevelremaining=1;
    int nextlevelcount=0;
    Node<int> *currentlevelhead=NULL;
    Node<int> *currentleveltail=NULL;
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *frontnode=pendingNodes.front();
        pendingNodes.pop();
        Node<int> *newnode=new Node<int>(frontnode->data);
        if(currentlevelhead==NULL){
            currentlevelhead=newnode;
            currentleveltail=newnode;
        }
        else{
            currentleveltail->next=newnode;
            currentleveltail=newnode;
        }
        if(frontnode->left!=NULL){
            pendingNodes.push(frontnode->left);
            nextlevelcount++;
        }
        if(frontnode->right!=NULL){
            pendingNodes.push(frontnode->right);
            nextlevelcount++;
        }
        currentlevelremaining--;
        if(currentlevelremaining==0){
            output.push_back(currentlevelhead);
            currentlevelhead=NULL;
            currentleveltail=NULL;
            currentlevelremaining=nextlevelcount;
            nextlevelcount=0;
        }
    }
    return output;
}
int main(){
    BinaryTreeNode<int> *root=takeinput();
    vector<Node<int>*> ans=constructLL(root);
    for(int i=0;i<ans.size();i++){
        print(ans[i]);
    }
}
