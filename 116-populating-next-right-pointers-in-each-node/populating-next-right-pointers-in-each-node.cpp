/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Node* connect(Node* root) {

    //     if(root==NULL){
    //         return root;
    //     }

    //     queue<Node*> q;
    //     q.push(root);
    //     Node* noNode = new Node;
    //     q.push(noNode);
    //     while(q.size()>1){
    //         Node *temp=q.front();
    //         q.pop();
    //         if(q.front()==noNode){
    //             temp->next=NULL;
    //             if(temp->right && temp->left){
    //                 q.push(temp->left);
    //                 q.push(temp->right);
    //             }
    //             q.pop();
    //             q.push(noNode);
    //         }
    //         else{
    //             temp->next=q.front();
    //             if(temp->right && temp->left){
    //                 q.push(temp->left);
    //                 q.push(temp->right);
    //             }
    //         }
    //     }
    //     return root;
    // }

    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        Node* parent=root;
        while(parent->left){
            Node* curr=parent;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next){
                    curr->right->next=curr->next->left;
                }
                curr=curr->next;
            }
            parent=parent->left;
        }
        return root;
    }
};