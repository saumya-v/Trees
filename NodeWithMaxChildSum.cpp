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
        TreeNode<T> *node;
        int sum;
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
MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        MaxNodePair<int> *pair=new MaxNodePair<int>();
        pair->node=NULL;
        pair->sum=INT_MIN;
        return pair;
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        sum+=root->children[i]->data;
    }
    MaxNodePair<int> *ans=new MaxNodePair<int>();
    ans->node=root;
    ans->sum=sum;
    for(int i=0;i<root->children.size();i++){
        MaxNodePair<int> *childAns=maxSumNodeHelper(root->children[i]);
        if(childAns->sum>ans->sum){
            ans=childAns;
        }
    }
    return ans;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root){
    return maxSumNodeHelper(root)->node;
}

int main(){
    TreeNode<int> *root=takeinput();
    TreeNode<int> *ans=maxSumNode(root);
    cout<<ans->data;
}
