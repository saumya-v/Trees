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
    cout<<"Enter root"<<endl;
    cin>>rootdata;
    TreeNode<int> *root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter no. of nodes of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childData;
            cout<<"enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int> *nextlarger(TreeNode<int> *root,int x){
    if(root==NULL){
        return root;
    }
    TreeNode<int> *ans=NULL;
    if(root->data>x){
        ans=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *temp=nextlarger(root->children[i],x);
        if(ans==NULL){
            ans=temp;
        }
        else if(temp!=NULL && temp->data<ans->data){
            ans=temp;
        }
    }
    return ans;
}
int main(){
    TreeNode<int> *root=takeinput();
    int x;
    cout<<"enter x"<<endl;
    cin>>x;
    TreeNode<int> *ans=nextlarger(root,x);
    cout<<ans->data;
}
