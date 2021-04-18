#include<bits/stdc++.h>

using namespace std;

class bnode
{
	int *key;//array to store key element
	int t;//minimum degree
	bnode **c;
	int n;
	bool leaf;
public:
	bnode(int d,bool _leaf);
	void insnotfull(int k);
	void splitchild(int i,bnode *y);
	void insertnotfull(int k); 
	friend class btree;
};
// Constructor for bnode class 
bnode::bnode(int t1, bool leaf1) 
{ 
	t = t1; 
	leaf = leaf1;  
	key = new int[2*t-1]; 
	c = new bnode *[2*t]; 
	n = 0; 
} 

class btree
{
	bnode *root;
	int t;
public:
	btree(int d)
	{
		root=NULL;
		t=d;
	}
	void insert(int k);
};

void btree::insert(int k)
{
	if(root==NULL)
	{
		root= new bnode(t,true);
		root->key[0]=k;
		root->n=1;//intially one key
	}
	else
	{
		if(root->n ==2*t-1)
		{
			bnode *s= new bnode(t,false);
			s->c[0]=root;
			s->splitchild(0,root);
			int i;
			if(s->key[0]<k)
				i++;
			s->c[i]->insertnotfull(k);
			root=s;
		}
		else
			root->insertnotfull(k);
	}
}
void bnode::insertnotfull(int k) 
{  
    int i = n-1; 
    if (leaf == true) 
    { 
        while (i >= 0 && key[i] > k) 
        { 
            key[i+1] = key[i]; 
            i--; 
        } 
        key[i+1] = k; 
        n = n+1; 
    } 
    else 
    { 
        while (i >= 0 && key[i] > k) 
            i--; 
        if (c[i+1]->n == 2*t-1) 
        { 
            c[i+1]->splitchild(i+1, c[i+1]); 
            if (key[i+1] < k) 
                i++; 
        } 
        c[i+1]->insertnotfull(k); 
    } 
} 

  
void bnode::splitchild(int i, bnode *y) 
{ 
    // Create a new node which is going to store (t-1) keys 
    // of y 
    bnode *z = new bnode(y->t, y->leaf); 
    z->n = t - 1; 
  
    for (int j = 0; j < t-1; j++) 
        z->key[j] = y->key[j+t]; 

    if (y->leaf == false) 
    { 
        for (int j = 0; j < t; j++) 
            z->c[j] = y->c[j+t]; 
    } 
  
    y->n = t - 1; 
 
    for (int j = n; j >= i+1; j--) 
        c[j+1] = c[j]; 
  
    c[i+1] = z; 
  

    for (int j = n-1; j >= i; j--) 
        key[j+1] = key[j]; 
 
    key[i] = y->key[t-1]; 
  
    n = n + 1; 
} 

int main()
{
	
    btree t(3); // A B-Tree with minium degree 3
    t.insert(10); 
    t.insert(20); 
    t.insert(5); 
    t.insert(6); 
    t.insert(12);
    t.insert(22);  
}