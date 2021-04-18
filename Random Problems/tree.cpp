#include<bits/stdc++.h>

using namespace std;
long int degree;
strcut node
{
	int *key;
	int t ; //minimum degree
	node **c;
	int n;
	bool leaf;
}*root;

void insert(int k)
{
	if(root==NULL)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->t=degree;
		root->key[0]=k;
		root->n=1;
		root->leaf=true;
	}
	else//if tree not empty
	{
		if(root->n==2*degree-1)
		{
			struct node *s=(struct node *)malloc(sizeof(struct node));
			s->c[0]=root;
			splitchild(0,root,s);
			int i=0;
			if(s->key[0]<k)
				i++;
			insertnotfull(k,s->c[i]);
			root=s;
		}
		else
			insertnotfull(k,root);
	}
}

void insertnotfull(int k,struct node *s)
{
	int i=n-1;
	if(s->leaf==true)
	{
		 while (i >= 0 && s->key[i] > k) 
        { 
            s->key[i+1] = s->key[i]; 
            i--; 
        }
        s->key[i+1]=k;
        s->n=s->n+1; 
	}
	else
	{
		while (i >= 0 && s->key[i] > k) 
            i--; 
        if (s->c[i+1]->n == 2*(s->t)-1) 
        { 
            splitchild(i+1, s->c[i+1]); 
            if (s->key[i+1] < k) 
                i++; 
        } 
       insertNonFull(k,s->c[i+1]); 
	}
}

void splitchild(int i,struct node *y)
{
	struct node *z=(struct node *)malloc(sizeof(struct node));
	z->n=
}