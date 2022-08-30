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
TreeNode<int> *maxNode(TreeNode<int> *root){
    if(root==NULL){
        return root;
    }
    TreeNode<int> *max=root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *maxchild=maxNode(root->children[i]);
        if(maxchild->data>max->data){
            max=maxchild;
        }
    }
    return max;
}
int main(){
    TreeNode<int> *root=takeinput();
    TreeNode<int> *ans=maxNode(root);
    cout<<ans->data;
}
