//source: https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
//source: https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
//source: https://www.programiz.com/cpp-programming/library-function/cstdlib/srand

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <unistd.h>
using namespace std;

class bst
{
private:
	int m1 = pow(2,20);
	int m2 = pow(2,19) + pow(2,20);
	int m3 = pow(2,18) + pow(2,17);
	int count = 0;//node count
	int count_insert = 0;
	int count_del = 0;
	
	struct node{
		int val;
		int* m;
		int height;
		node* left;
		node* right;
	};
	
	node* root;
	
	node* insert(int x, node* t){
		int remaindr = x % 3;
		if(t == NULL){
			count_insert++;
			t = new node;
			t->val = x;
			count++;
			t->height=0;
			t->left = t->right = NULL;
			if(remaindr == 0){
				t->m = new int[m1];
			}
			else if(remaindr == 1){
				t->m = new int[m2];
			}
			else{
				t->m = new int[m3];
			}
		}
		else if(x < t->val){
			t->left = insert(x, t->left);
			if(height(t->left) - height(t->right) == 2){
				if(x < t->left->val)
					t = rightRotate1(t);
				else
					t = rightRotate2(t);
			}
		}
		else if(x > t->val){
			t->right = insert(x, t->right);
			if(height(t->right) - height(t->left) == 2){
				if(x < t->right->val)
					t = leftRotate1(t);
				else
					t = leftRotate2(t);
			}
		}
		t->height = max(height(t->left),height(t->right))+1;
	}
	node* rightRotate1(node* &t){
		if(t==NULL || t->left == NULL){
			return t;
		}
		else{
			node* u = t->left;
			t->left = u->right;
			u->right = t;
			t->height = max(height(t->left),height(t->right))+1;
			u->height = max(height(u->left),t->height)+1;
			return u;
		}
		return t;
	}
	node* leftRotate1(node* &t){
		if(t==NULL || t->right == NULL){
			return t;
		}
		else{
			node* u = t->right;
			t->right = u->left;
			u->left = t;
			t->height = max(height(t->left),height(t->right))+1;
			u->height = max(height(t->right),t->height)+1;
			return u;
		}
		return t;
	}
	node* leftRotate2(node* &t){
		t->right = rightRotate1(t->right);
		return leftRotate1(t);
	}
	node* rightRotate2(node* &t){
		t->left = leftRotate1(t->left);
		return rightRotate1(t);
	}
	node* findMin(node* t){
		if(t==NULL)
			return NULL;
		else if(t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}
	node* findMax(node* t){
		if(t==NULL) 
			return NULL;
		else if(t->right == NULL) 
			return t;
		else
			return findMax(t->right);
	}
	node* del(int x, node* t){
		node* tmp;
		if(t==NULL) //element not found
			return NULL;
		else if(x < t->val) //element search
			t->left = del(x,t->left);
		else if(x>t->val)
			t->right = del(x,t->right);
		else if(t->left && t->right){ //element with two children found
			tmp = findMin(t->right);
			t->val = tmp->val;
			t->right = del(t->val,t->right);
		}
		else{//element with zero or one child
			tmp = t;
			if(t->left == NULL)
				t=t->right;
			else if(t->right == NULL)
				t=t->left;
			delete[] tmp->m;
			delete tmp;
			count_del++;
			count--;
		}
		if(t==NULL)
			return t;
		t->height = max(height(t->left),height(t->right))+1;
		
		//if unbalanced node: if left node is deleted
		if(height(t->left) - height(t->right) == 2){
			if(height(t->left->left) - height(t->left->right) == 1)
				return leftRotate1(t);
			else
				return leftRotate2(t);
		}
		//if unbalanced node: if right node is deleted
		else if(height(t->right) - height(t->left) == 2){
			if(height(t->right->left) - height(t->right->left) == 1)
				return rightRotate1(t);
			else
				return rightRotate2(t);
		}
		return t;
	}
	int height(node* t){
		return (t==NULL ? -1: t->height);
	}
	int getBalance(node* t)  
	{  
	    if (t == NULL)  
	        return 0;  
		else
	    	return height(t->left) - height(t->right);  
	}  
	void order(node* t){
		if(t==NULL)
			return;
		order(t->left);
		cout << t->val<<endl;
		order(t->right);
	}
public:
	bst(){
		root = NULL;
	}
	void inser(int x){
		root = insert(x,root);
	}
	void del(int x){
		root = del(x,root);
	}
	void display(){
		order(root);
	}
	int getCount(){
		return count;
	}
	int getInsertCount(){
		return count_insert;
	}
	void setCount(){
		count_insert = 0;
	}
	int getDeleteCount(){
		return count_del;
	}
};

int main(int agrc, char* argv[]){
	
	srand((unsigned int)time(0));
	bst node;
	
	double insert_start_count =0;
	double insert_total_count =0;
	double del_total_count = 0;
	double start,end,timer;
	int *arr = new int[150000];
	int tmp_count = 0;
	for(int i=0;i<150000;i++){
		arr[i] = rand()%299+1;
	}
	
	
	int x=0;
	start = clock();
	while(node.getCount() < 50){
		x++;
		node.insert(arr[x]);
	}
	end=clock();
	timer = end - start;
	insert_start_count +=timer;
	
	node.setCount(); //resetting count to 0
	for(int i=0;i<100000;i++){
		while(node.getCount() < 50){
			x++;
			start = clock();
			node.insert(arr[x]);
			end=clock();
		}
		
		timer = end - start;
		insert_start_count +=timer;
		
		while(node.getCount() >= 50){
			
			start = clock();
			node.del(arr[x]);
			end=clock();
		}
		
		timer = end - start;
		del_total_count +=timer;
	}
	
	cout << "Average time for initial insertions: " << insert_start_count/50.00 << " ms." << endl;
	cout << "Average time for insertions: " << insert_total_count/node.getInsertCount() << " ms." << endl;
	cout << "Average time for deletions: " << del_total_count/node.getDeleteCount() << " ms." << endl;
	
	sleep(1);
	
}