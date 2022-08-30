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
void printTree(TreeNode<int> *root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
            TreeNode<int> *front=pendingNodes.front();
            pendingNodes.pop();
            cout<<front->data<<":";
            for(int i=0;i<front->children.size();i++){
                if(i<front->children.size()-1){
                    cout<<front->children[i]->data<<",";
                }
                else{
                    cout<<front->children[i]->data;
                }
                pendingNodes.push(front->children[i]);
            }
            cout<<endl;
    }

}
void replacewithdepth(TreeNode<int> *root,int depth){
    if(root==NULL){
        return;
    }
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        replacewithdepth(root->children[i],depth+1);
    }
}
void replacedepth(TreeNode<int> *root){
    replacewithdepth(root,0);
}
int main(){
    TreeNode<int> *root=takeinput();
    replacedepth(root);
    printTree(root);
}
