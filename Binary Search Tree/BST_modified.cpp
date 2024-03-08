#include<iostream>
using namespace std;
                    
class node{
    public:
    int data;
    node* right;
    node* left;

    node(int val){
        this->data=val;
        this->right=NULL;
        this->left=NULL;
    }
};

class BST{
    node* root;
    public:
    BST(){
        root=NULL;
    }

    node* insert(node*,int num);// To insert a node into the BST.
    void preorder(node*); // To display preorder sequence of the BST.(VLR)
    void inorder(node*); // To display inorder sequence of the BST.(LVR)
    void postorder(node*); // To display postorder sequence of the BST.(LRV)
    node* minVal(node*); // To display minimum value in the BST.
    node* maxVal(node*); // To display maximum value in the BST.
    node* deletenode(node*,int k); // To delete a node from a BST.
    bool search(node*,int x); // To search a node in the BST. 
    int maxDepth(node*); //To get maximum depth of a BST.
    int getLeafCount(node*); // Will give count of leaf nodes in a BST.
};

node* BST::insert(node* root,int num)
{
    if (root==NULL){
        return new node(num);
    }
    else{
        if(num<root->data){
            root->left=insert(root->left,num);
        }
        else{
            root->right=insert(root->right,num);
        }
    }
    return root;
}

void BST::preorder(node* root)
{
    if (root!=NULL){
        cout<<root->data<<" "; // V
        preorder(root->left);// L
        preorder(root->right);// R
    }
}

void BST::inorder(node* root){
    if (root!=NULL){
        inorder(root->left);// L
        cout<<root->data<<" ";// V
        inorder(root->right);// R
    }
}

void BST::postorder(node* root){
    if (root!=NULL){
        postorder(root->left);// L
        postorder(root->right);// R
        cout<<root->data<<" ";//V
    }
}

node* BST::minVal(node* root){
    node* temp=root;
    while (temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}


node* BST::maxVal(node* root){
    node* temp=root;
    while (temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

bool BST::search(node* root,int x)
{
    if (root==NULL){
        return false;
    }

    if (root->data==x){
        return true;
    }

    if (x<root->data){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}

node* BST::deletenode(node* root,int k)
{   
    //Base Case
    if (root==NULL){
        return root;
    }

    if (root->data==k){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        //left child
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if (root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deletenode(root->right,mini);
            return root;
        }
    }
    else if(root->data>k){
        //Go to left part.
        root->left=deletenode(root->left,k);
        return root;
    }
    else{
        //Go to right part.
        root->right=deletenode(root->right,k);
        return root;
    }
}

int BST::getLeafCount(node* root){
    if (root==NULL){
        return 0;
    }

    if (root->left==NULL && root->right==NULL){
        return 1;
    }
    else{
        return (getLeafCount(root->left)+getLeafCount(root->right));
    } 
}

int BST::maxDepth(node* root)
{
    if (root == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main(){
    node* root=NULL;
    BST tree;
    root=tree.insert(root,12);
    tree.insert(root,15);
    tree.insert(root,20);
    tree.insert(root,10);
    tree.insert(root,9);

    cout<<"Inorder sequence of the BST is :"<<endl;
    tree.inorder(root);
    cout<<endl;

    
    cout<<"Preorder sequence of the BST is :"<<endl;
    tree.preorder(root);
    cout<<endl;

    
    cout<<"Postorder sequence of the BST is :"<<endl;
    tree.postorder(root);
    cout<<endl;

    bool s;
    s=tree.search(root,1);
    cout<<s; //1->True 0->False


    
    return 0;
}