////Francisco Rocha Juárez. A01730560.
//Iker Guerrero González. A00830026.
//Aldo Mauricio Cruz Lozada. A01732372.

#include<iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

//Function to visit nodes in Preorder
void Preorder(struct Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	printf("%d ",root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder
void Inorder(Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%d ",root->data); // Print data
}

/* Print nodes at a given level */
void printGivenLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        // printf("%d ", root->data);
        std::cout << root->data << ' ';
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

//Function to find bst height
int height(Node *root)
 {
 	int coun=0,count1;
 	if(root->left<=root->right)
 	{

 	while(root->left!=NULL)
 	{
 		coun+=1;
 		root=root->left;
	 }
}
else
{
	while(root->right!=NULL)
 	{
 		coun+=1;
 		root=root->right;
	 }
}
return coun+1;
 }

/* Function to line by line print level order traversal a tree*/
void levelByLevel(Node *root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
    }
}


void traversal (Node *root ,int n) {
  if (n == 1) {
    Preorder(root);
  } else if ( n == 2) {
    Inorder(root);
  } else if (n == 3) {
    Postorder(root);
  } else if (n == 4) {
    levelByLevel(root);
  }
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
}


// utility function to return level of given node
int whatlevelamI(Node *root, int data)
{
	 queue<Node*> q;
	 int level = 0;
	 q.push(root);

	 // extra NULL is pushed to keep track
	 // of all the nodes to be pushed before
	 // level is incremented by 1
	 q.push(NULL);
	 while (!q.empty()) {
			 Node* temp = q.front();
			 q.pop();
			 if (temp == NULL) {
					 if (q.front() != NULL) {
							 q.push(NULL);
					 }
					 level += 1;
			 } else {
					 if (temp->data == data) {
							 return level;
					 }
					 if (temp->left) {
							 q.push(temp->left);
					 }
					 if (temp->right) {
							 q.push(temp->right);
					 }
			 }
	 }
	 return -1;
}


 bool ancestors(Node *root, int target)
 {
   int counter = 0;
   /* base cases */
   if (root == NULL)
      return false;

   if (root->data == target)
      return true;

   /* If target is present in either left or right subtree of this node,
      then print this node */
   if ( ancestors(root->left, target) ||
        ancestors(root->right, target) )
   {
     cout << root->data << " ";
     return true;
   }

   /* Else return false */
   return false;
 }

 /* Given a non-empty binary search tree, return the node
 with minimum key value found in that tree. Note that the
 entire tree does not need to be searched. */
 struct Node *minValueNode(Node *node)
 {
     struct Node *current = node;

     /* loop down to find the leftmost leaf */
     while (current && current->left != NULL)
         current = current->left;

     return current;
 }


 /* Given a binary search tree and a data, this function
 deletes the data and returns the new root */
 struct Node *deleteNode(Node *root, int data)
 {
     // base case
     if (root == NULL)
         return root;

     // If the data to be deleted is
     // smaller than the root's
     // data, then it lies in left subtree
     if (data < root->data)
         root->left = deleteNode(root->left, data);

     // If the data to be deleted is
     // greater than the root's
     // data, then it lies in right subtree
     else if (data > root->data)
         root->right = deleteNode(root->right, data);

     // if data is same as root's data, then This is the node
     // to be deleted
     else {
         // node has no child
         if (root->left==NULL and root->right==NULL)
             return NULL;

         // node with only one child or no child
         else if (root->left == NULL) {
             struct Node *temp = root->right;
             free(root);
             return temp;
         }
         else if (root->right == NULL) {
             struct Node *temp = root->left;
             free(root);
             return temp;
         }

         // node with two children: Get the inorder successor
         // (smallest in the right subtree)
         struct Node *temp = minValueNode(root->right);

         // Copy the inorder successor's content to this node
         root->data = temp->data;

         // Delete the inorder successor
         root->right = deleteNode(root->right, temp->data);
     }
     return root;
 }

int main() {
  //Binary tree created
	Node* root = NULL;
	int value;
	vector<int> valor_repetidos;

	int n; //numero de nodos a insertar
	vector<int> num_add_vector;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> value;
		num_add_vector.push_back(value);
	}

	int m; //numero de nodos a eliminar
	vector<int> num_eliminar_vector;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> value;
		num_eliminar_vector.push_back(value);
	}

	int q; //numero de valores a desplegar sus ancestros
	vector<int> num_ances_vector;
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		std::cin >> value;
		num_ances_vector.push_back(value);
	}

	int r; //numero de valores a desplegar en que nivel se encuentran
	vector<int> num_nivel_vector;
	std::cin >> r;
	for (int i = 0; i < r; i++) {
		std::cin >> value;
		num_nivel_vector.push_back(value);
	}

	//Insertar valores en el arbol
	for (int i = 0; i < num_add_vector.size(); i++) {
		root = Insert(root,num_add_vector[i]);
	}

	//Encontrar valores valores repetidos en el vector y almacenarlos en otro
	for (int i = 0; i < num_add_vector.size()-1; i++) {
		for (int j = i+1; j < num_add_vector.size(); j++) {
			if (num_add_vector[i] == num_add_vector[j]) {
				valor_repetidos.push_back(num_add_vector[i]);
			}
		}
	}

	//Eliminar valores del arbol binario
	for (int i = 0; i < num_eliminar_vector.size(); i++) {
		root = deleteNode(root,num_eliminar_vector[i]);
	}


	//Eliminar valores repetidos del arbol binario
	for (int i = 0; i < valor_repetidos.size(); i++) {
		root = deleteNode(root,valor_repetidos[i]);
	}

	traversal(root,1);
	cout<<endl;
	traversal(root,2);
	cout<<endl;
	traversal(root,3);
	cout<<endl;
	traversal(root,4);
	cout<<endl;

	std::cout << height(root);
	cout<<endl;

	//We show the ancestors with a loop cycle
	for (int i = 0; i < num_ances_vector.size(); i++) {
		ancestors(root,num_ances_vector[i]);
		cout<<endl;
	}

	//We show the level we are with a loop cycle
	for (int i = 0; i < num_nivel_vector.size(); i++) {
		cout<<whatlevelamI(root,num_nivel_vector[i])<<endl;
	}

}
