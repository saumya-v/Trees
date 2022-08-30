#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    TreeNode(T data){
        this->data=data;
    }
};
TreeNode<int> *takeinput(){
    int rootdata;
    cout<<"enter root data "<<endl;
    cin>>rootdata;
    TreeNode<int> *root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        int numchild;
        cout<<"enter no. of children of "<<front->data<<endl;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childdata;
            cout<<"enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childdata;
            TreeNode<int> *child=new TreeNode<int>(childdata);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
int identical(TreeNode<int> *root1,TreeNode<int> *root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL &&root2!=NULL){
        return false;
    }
    if(root1!=NULL &&root2==NULL){
        return false;
    }
    if(root1->children.size()!=root2->children.size()){
        return false;
    }
    if(root1->data!=root2->data){
        return false;
    }
    for(int i=0;i<root1->children.size();i++){
        if (!identical(root1->children[i],root2->children[i])){
            return false;
        }
    }
    return true;
}
int main(){
    TreeNode<int> *root1=takeinput();
    TreeNode<int> *root2=takeinput();
    if(identical(root1,root2)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
