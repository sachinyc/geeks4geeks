#include<iostream>
#include<stack>


class tree{

    public:
        int data;
        tree * left;
        tree * right;

};

void insert(tree * root)
{
    tree *node1 = new tree();
    tree *node2 = new tree();
    node1->data = 2;
    node1->left = NULL;
    node1->right = NULL;
    node2->data = 3;
    node2->left = NULL;
    node2->right = NULL;
    root->left = node1;
    root->right = node2;


    tree *node11 = new tree();
    tree *node22 = new tree();
    node11->data = 4;
    node11->left = NULL;
    node11->right = NULL;
    node22->data = 5;
    node22->left = NULL;
    node22->right = NULL;
    node1->left = node11;
    node1->right = node22;


}

void inorder(tree *root)
{
    if(root == NULL) return;
        inorder(root->left);
        std::cout<< root->data << "\t";
        inorder(root->right);
}

void preorder(tree *root)
{
    if(root == NULL) return;
        std::cout<< root->data << "\t";
        preorder(root->left);
        preorder(root->right);
}

void postorder(tree *root)
{
    if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        std::cout<< root->data << "\t";
}


void inorder_iterative(tree *root)
{
    if(root == NULL) return;
    std::stack<tree *> st;
    
    while(1)
    {
        if(root != NULL)
        {
            st.push(root);
            root = root->left;
        
        }
        else
        {
            if(st.empty())
                break;
            root = st.top();
            std::cout<<root->data<<"\t";
            st.pop();
            root = root->right;        

        } 
    
    }   

}

void preorder_iterative(tree *root)
{
    if(root == NULL) return;
    std::stack<tree *> st;
    
    while(1)
    {
        if(root != NULL)
        {
            std::cout<<root->data<<"\t";
            st.push(root);
            root = root->left;
        
        }
        else
        {
            if(st.empty())
                break;
            root = st.top();
            st.pop();
            root = root->right;        

        } 
    
    }   

}


void postorder_iterative(tree *root)
{
    if(root == NULL) return;
    std::stack<tree *> st1, st2;
    
    st1.push(root);

    while(!st1.empty())
    {
        tree *temp = st1.top();
        st2.push(temp);
        st1.pop();

        if(temp->left != NULL || temp->right != NULL)
        {
            st1.push(temp->left);
            st1.push(temp->right);
        }
    }

        while(!st2.empty())
        {
              tree *temp = st2.top();
              std::cout<<temp->data<<"\t";
              st2.pop();
        }
}

void postorder_iterative_with_1_stack(tree *root)
{
    if(root == NULL) return;
    std::stack<tree *> st;
    tree * curr = root;

    while( curr != NULL || !st.empty())
    {
        st.push(curr);
        curr = curr->left;

        if(curr == NULL)
        {
            while(!st.empty() && st.top()->right == NULL)
            {
                std::cout<<st.top()->data<<"\t";
                tree *temp = st.top();
                if(!st.empty())
                    st.pop();
                if(temp == st.top()->right)
                {
                    std::cout<<st.top()->data<<"\t";
                    if(!st.empty())
                        st.pop();
                }
            }
                
            if(!st.empty())
                curr = st.top()->right;
        
        }
    }
}

int main()
{
    tree *root = new tree();
    root->data = 1;
    root->left = NULL;
    root->right = NULL;
    
    // Function to insert elements into the tree
    insert(root);
    std::cout<<"Inorder traversal = ";
    inorder(root);
    std::cout<<std::endl;


    std::cout<<"Preorder traversal = ";
    preorder(root);
    std::cout<<std::endl;
    
    std::cout<<"Postorder traversal = ";
    postorder(root);
    std::cout<<std::endl;


    std::cout<<" Inorder Travesral without recursion"<<std::endl;
    inorder_iterative(root);
    std::cout<<std::endl;
    
    std::cout<<" Preorder Travesral without recursion"<<std::endl;
    preorder_iterative(root);
    std::cout<<std::endl;
    
    std::cout<<" postorder Travesral without recursion"<<std::endl;
    postorder_iterative(root);
    std::cout<<std::endl;
    
    std::cout<<" postorder Travesral without recursion with one stack"<<std::endl;
    postorder_iterative_with_1_stack(root);
    std::cout<<std::endl;
    
    return 0;
}
