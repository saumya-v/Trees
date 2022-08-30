#include<iostream>
#include<vector>
#include<queue>
#include<climits>
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
template<typename T>
class MaxNodePair{
    public:
        TreeNode<int> *fmax;
        TreeNode<int> *smax;
        MaxNodePair(TreeNode<int> *first,TreeNode<int> *second){
            this->fmax=first;
            this->smax=second;
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
MaxNodePair<int> *secondLargestHelper(TreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return new MaxNodePair<int>(NULL,NULL);
    }
    MaxNodePair<int> *ans=new MaxNodePair<int>(root,NULL);
    for(int i=0;i<root->children.size();i++){
        MaxNodePair<int> *childans= secondLargestHelper(root->children[i]);
        if(childans->fmax->data>ans->fmax->data){
            if(childans->smax==NULL){
                ans->smax=ans->fmax;
                ans->fmax=childans->fmax;
            }
            else if(childans->smax->data>ans->fmax->data){
                ans->fmax=childans->fmax;
                ans->smax=childans->smax;
            }
            else{
                ans->smax=ans->fmax;
                ans->fmax=childans->fmax;
            }
        }
        else{
            if(ans->fmax->data!=childans->fmax->data &&(ans->smax==NULL || childans->fmax->data>ans->smax->data)){
                ans->smax=childans->fmax;
            }
        }
    }
    return ans;
}
TreeNode<int> *secondLargest(TreeNode<int> *root){
    return secondLargestHelper(root)->smax;
}

int main(){
    TreeNode<int> *root=takeinput();
    TreeNode<int> *ans=secondLargest(root);
    cout<<ans->data;
}
