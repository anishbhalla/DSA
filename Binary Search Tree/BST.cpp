#include<iostream>
using namespace std;
/*Binary Search Tree Code*/
/*(Using recursion)*/

class node{
    friend class BST;
    int data;
    node *left;
    node *right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

class BST{
    public:
    node *root;
    BST(){root=NULL;}

    node *insert(node *,int num); //To insert a node into a BST.
    void preorder(node *); //Will display preorder sequence of a BST.(VLR)
    void inorder(node *); //Will display inorder sequence of a BST(note that it is always sorted).(LVR)
    void postorder(node *); //Will display postorder sequence of a BST.(LRV)
    node *create(int d); //Creates a new node.
    node *minVal(node *); //Will give minimum value in BST.
    node *maxVal(node *); //Will give maximum value in BST.
    node *deletenode(node *,int k); //Deletes a node from the BST.
    int Search(node *,int); //Searches for a value in BST.
    int totalNodes(node *); //Gives total nodes in a BST.
};

node *BST:: insert(node *root,int num){
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

void BST:: preorder(node *root){
    if (root!=NULL){
        //First read the data of root node.
        cout<<root->data<<","; //V
        //Then recur on the left subtree.
        preorder(root->left); //L
        //Then recur on the right subtree.
        preorder(root->right); //R
    }
}

void BST:: inorder(node *root){
    if (root!=NULL){
        inorder(root->left); //L
        cout<<root->data<<","; //V
        inorder(root->right); //R
    }
}

void BST::postorder(node *root)
{
    if (root!= NULL)
    {
        postorder(root->left); //L
        postorder(root->right); //R 
        cout << root->data <<","; //V
    }
}

node *BST::create(int d)
{
    node *newnode = new node(d);
    newnode->data = d;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

node* BST::minVal(node *root){
    node *temp=root;

    while (temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* BST::maxVal(node *root){
    node *temp=root;

    while (temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node *BST::deletenode(node *root,int k){
    //BASE CASE
    if (root==NULL){
        return root;
    }
    if (root->data==k){
        /*CASE-I :0 children exists.*/
        if (root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        /*CASE-II :1 child exists.*/
        //right child:
        if(root->left==NULL && root->right!=NULL){
            node *temp=root->right;
            delete root;
            return temp;
        }
        //left child:
        if (root->left!=NULL && root->right==NULL){
            node *temp=root->left;
            delete root;
            return temp;
        }

        /*CASE-III :Both children exist*/
        //to delete a node with two children in a BST:      ->either replace the todelete node with max value from left subree       ->or replace the todelete node with min value from right subree              further delete the replaced value
        if (root->left!=NULL && root->right!=NULL){
            int max=maxVal(root->left)->data; //Finding maxmimum element from left subtree of root.
            root->data=max; //Copying maximum element into root value.
            root->left=deletenode(root->left,max); //Deleting the orignal max element on left subtree of root.
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

int BST::Search(node *root, int x)
{
    int depth = 0;
    node *temp = root;
    // Run the loop until temp points to a NULL pointer.
    while (temp != NULL)
    {
        depth++;
        if (temp->data == x){
            cout << "\nData found at depth: " << depth;
            // return true;
            break;
        }
        else if (temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    cout << "\n Data not found";
    // return false; 
}

int BST::totalNodes(node *root)
{
    if (root == NULL)
        return 0;

    int l = totalNodes(root->left);
    int r = totalNodes(root->right);

    return 1 + l + r;
}

int main(){
    node *root=NULL;
    BST tree;

    root=tree.insert(root,15);
    tree.insert(root,12);
    tree.insert(root,11);
    tree.insert(root,20);
    tree.insert(root,21);
    tree.insert(root,1);

    cout<<"The Inorder sequence of BST is :"<<endl;
    tree.inorder(root);
    cout<<endl;

    cout<<"The Preorder sequence of BST is :"<<endl;
    tree.preorder(root);
    cout<<endl;

    cout<<"The Postorder sequence of BST is :"<<endl;
    tree.postorder(root);
    cout<<endl;

    return 0;
}