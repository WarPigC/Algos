#include <iostream>
#include <queue>

struct node{
    int data;
    node* left;
    node* right;

    node(int d)
        :data{d},
        left{nullptr},
        right{nullptr}
    {}
};


class Btree{
    node* root = nullptr;

    void RecursiveHelper(node* node,int val){
        if(node == nullptr){
            std::cout << "No value found\n";
            return;
        }
        else if (node->data == val){
            std::cout << "Value found\n";
            return;
        }
        else if(node->data < val){
            RecursiveHelper(node->left, val);
        }
        else{
            RecursiveHelper(node->right, val);
        }
    }

    node* InsertHelper(node* node, int val){
        if(!node){
            return new struct node(val);
        }
        else if(val < node->data){
            node->left = InsertHelper(node->left, val);
        }
        else{
            node->right = InsertHelper(node->right, val);
        }
        return node;
    }    
    
    node* getMin(node* node){ 
        
        auto temp = node;
        while(node->left != nullptr){
            temp = temp->left;
        }
        return temp;
    }

    void SearchHelper(int val){
        node* temp = root;
        while(temp != nullptr){
            if (root == nullptr){
                std::cout << "Tree empty\n";
                return;
            }

            if (temp->data == val){
                std::cout << "Value found\n";
                return;
            }
            else if (temp->data < val){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        std::cout << "No value found\n";
    }

    node* RemoveHelper(node* node, int val){                                    
        if (!node) {
            return nullptr;
        }

        if (val > node->data) { 
            node->right = RemoveHelper(node->right, val);
        }
        else if (val < node->data) {
            node->left = RemoveHelper(node->left, val);
        }
        else {
            if (!node->left) {
                return node->right;
            }
            else if (!node->right) {
                return node->left;
            }
            else {
                struct node* minNode = getMin(node->right);
                node->data = minNode->data;
                node->right = RemoveHelper(node->right, minNode->data);
            }
        }
        return node;
    }


    void InorderSearch(node* node){
        if(node){
            InorderSearch(node->left);
            std::cout << node->data << " ";
            InorderSearch(node->right);
        }
        else{
            return;
        }
    }


    int maxDepthDFS(node* n){          // DFS approach
        if (!n) return 0; 
        else return 1 + std::max(maxDepthDFS(n->left), maxDepthDFS(n->right));
    }

    int maxDepthBFS(node* n){		// BFS approach

        std::queue<node*> q;
        q.push(n);
        int depth {};
		int level = 1;

        while (!q.empty()){
            ++depth;
            int queueSize = q.size();

			std::cout << "level " << level++ << " ";

            for(int i = 0; i < queueSize; ++i){
                node* temp = q.front();
                q.pop();
				std::cout << temp->data << " " ;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
			std::cout << std::endl;
        }
        return depth;
    }

    public:

    void displayDepth(){
        //std::cout << maxDepthDFS(root) << std::endl;
		std::cout << maxDepthBFS(root) << std::endl;
    }
    
    void display(){         // Inorder output
        InorderSearch(root);
        std::cout << '\n';
    }


    void Rsearch(int val){
        RecursiveHelper(root, val);
    }

    void search(int val){
        SearchHelper(val);
    }

    void insertNode(int val){        
        root = InsertHelper(root,val);              
    }

    void deleteNode(int val){
        root = RemoveHelper(root, val);
    }
};




int main(){
    Btree obj;
    

    obj.insertNode(2);
    obj.insertNode(3);
    obj.insertNode(10);
    obj.insertNode(1);

    //obj.deleteNode(2);
    //obj.search(2);
    //obj.display();

    //obj.insertNode(2);
    //obj.search(2);
    //obj.display();
	obj.displayDepth();

	return 0;
}
