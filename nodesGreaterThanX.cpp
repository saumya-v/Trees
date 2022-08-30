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
int greaterThanX(TreeNode<int> *root,int x){
    int sum=0;
    for(int i=0;i<root->children.size();i++){
        sum=sum+greaterThanX(root->children[i],x);
    }
     if(root->data>x){
        return sum+1;
    }
    return sum;
}
int main(){
    TreeNode<int> *root=takeinput();
    int x;
    cout<<"enter x"<<endl;
    cin>>x;
    cout<<greaterThanX(root,x);
}
