/*
AUTHOR:Haldhar Dwivedi
Roll No:CED18I022
college:IIITDM
*/
#include <bits/stdc++.h>

using namespace std;

int MAX = 3;

// node of b+ tree is given below
class node {
  bool leaf;
  int *key, size;
  node **ptr;
   public:
  node();
  friend class bptree;//friend class allow using of private member fuction of class node by b+tree
};

node::node() 
{
  key = new int[MAX];
  ptr = new node *[MAX + 1];
}
// here class bptree will represent our b+tree
class bptree {
  node *root;
  void insertinternal(int, node *, node *);
  node *findparent(node *, node *);

   public:
  bptree();
  void insert(int);
  void removeinternal(int x,node *cursor,node *child);
  void display(node*);
  void remove(int x);
  node *getroot();
};

bptree::bptree()
{
  root = NULL;
}

//-----------------------main insert function hai ye------------------------------
void bptree::insert(int x)
 {
  if (root == NULL) 
  {
    root = new node;
    root->key[0] = x;
    root->leaf = true;
    root->size = 1;
  } 
  else 
  {
    node *cursor = root;
    node *parent;
    while (cursor->leaf == false) 
    {
      parent = cursor;
      for (int i = 0; i < cursor->size; i++) 
      {
        if (x < cursor->key[i]) 
        {
          cursor = cursor->ptr[i];
          break;
        }
        if (i == cursor->size - 1) 
        {
          cursor = cursor->ptr[i + 1];
          break;
        }
      }
    }
    if (cursor->size < MAX) 
    {
      int i = 0;
      while (x > cursor->key[i] && i < cursor->size)
        i++;
      for (int j = cursor->size; j > i; j--) 
      {
        cursor->key[j] = cursor->key[j - 1];
      }
      cursor->key[i] = x;
      cursor->size++;
      cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
      cursor->ptr[cursor->size - 1] = NULL;
    } 
    else 
    {
      node *newLeaf = new node;
      int virtualnode[MAX + 1];
      for (int i = 0; i < MAX; i++) 
      {
        virtualnode[i] = cursor->key[i];
      }
      int i = 0, j;
      while (x > virtualnode[i] && i < MAX)
        i++;
      for (int j = MAX + 1; j > i; j--) 
      {
        virtualnode[j] = virtualnode[j - 1];
      }
      virtualnode[i] = x;
      newLeaf->leaf = true;
      cursor->size = (MAX + 1) / 2;
      newLeaf->size = MAX + 1 - (MAX + 1) / 2;
      cursor->ptr[cursor->size] = newLeaf;
      newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];
      cursor->ptr[MAX] = NULL;
      for (i = 0; i < cursor->size; i++)
       {
        cursor->key[i] = virtualnode[i];
      }
      for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++)
      {
        newLeaf->key[i] = virtualnode[j];
      }
      if (cursor == root) {
        node *newroot = new node;
        newroot->key[0] = newLeaf->key[0];
        newroot->ptr[0] = cursor;
        newroot->ptr[1] = newLeaf;
        newroot->leaf = false;
        newroot->size = 1;
        root = newroot;
      } else 
      {
        insertinternal(newLeaf->key[0], parent, newLeaf);
      }
    }
  }
}

// -----------------Insert internal leaves function hai-----------------
void bptree::insertinternal(int x, node *cursor, node *child) 
{
  if (cursor->size < MAX) 
  {
    int i = 0;
    while (x > cursor->key[i] && i < cursor->size)
      i++;
    for (int j = cursor->size; j > i; j--) 
    {
      cursor->key[j] = cursor->key[j - 1];
    }
    for (int j = cursor->size + 1; j > i + 1; j--) 
    {
      cursor->ptr[j] = cursor->ptr[j - 1];
    }
    cursor->key[i] = x;
    cursor->size++;
    cursor->ptr[i + 1] = child;
  } 
  else 
  {
    node *newinternal = new node;
    int virtualKey[MAX + 1];

    node *virtualPtr[MAX + 2];

    for (int i = 0; i < MAX; i++) 
    {
      virtualKey[i] = cursor->key[i];
    }

    for (int i = 0; i < MAX + 1; i++) 
    {
      virtualPtr[i] = cursor->ptr[i];
    }
    int i = 0, j;

    while (x > virtualKey[i] && i < MAX)
      i++;

    for (int j = MAX + 1; j > i; j--) 
    {
      virtualKey[j] = virtualKey[j - 1];
    }
    virtualKey[i] = x;

    for (int j = MAX + 2; j > i + 1; j--) 
    {
      virtualPtr[j] = virtualPtr[j - 1];
    }
    virtualPtr[i + 1] = child;
    newinternal->leaf = false;
    cursor->size = (MAX + 1) / 2;
    newinternal->size = MAX - (MAX + 1) / 2;
    for (i = 0, j = cursor->size + 1; i < newinternal->size; i++, j++) 
    {
      newinternal->key[i] = virtualKey[j];
    }
    for (i = 0, j = cursor->size + 1; i < newinternal->size + 1; i++, j++) 
    {
      newinternal->ptr[i] = virtualPtr[j];
    }
    if (cursor == root)
    {
      node *newroot = new node;
      newroot->key[0] = cursor->key[cursor->size];
      newroot->ptr[0] = cursor;
      newroot->ptr[1] = newinternal;
      newroot->leaf = false;
      newroot->size = 1;
      root = newroot;
    } 
    else
    {
      insertinternal(cursor->key[cursor->size], findparent(root, cursor), newinternal);
    }
  }
}

// finding parent
node* bptree::findparent(node* cursor, node* child)
{
  
  node* parent;
  if(cursor->leaf || (cursor->ptr[0])->leaf)
  {
    return NULL;
  }
  for(int i = 0; i < cursor->size+1; i++)
  {
    if(cursor->ptr[i] == child)
    {
      parent = cursor;
      return parent;
    }
    else
    {
      parent = findparent(cursor->ptr[i],child);
      if(parent!=NULL)return parent;
    }
  }
  return parent;
}

// Print the tree
void bptree::display(node *cursor) 
{
  if (cursor != NULL) 
  {
    for (int i = 0; i < cursor->size; i++) 
    {
      cout << cursor->key[i] << " ";
    }
    cout << "\n";
    if (cursor->leaf != true) 
    {
      for (int i = 0; i < cursor->size + 1; i++) 
      {
        display(cursor->ptr[i]);
      }
    }
  }
}

/***********************deletion here*********************/
void bptree::remove(int x)
{
  //delete if null 
  if(root==NULL)
  {
    cout<<"Tree empty\n";
  }
  else
  {
    node* cursor = root;
    node* parent;
    int leftSibling, rightSibling;
    //in the following while loop, cursor will will travel to the leaf node possibly consisting the key
    while(cursor->leaf == false)
    {
      for(int i = 0; i < cursor->size; i++)
      {
        parent = cursor;
        leftSibling = i-1; //leftSibling is the index of left sibling in the parent node
        rightSibling =  i+1; //rightSibling is the index of right sibling in the parent node
        if(x < cursor->key[i])
        { 
          cursor = cursor->ptr[i];
          break;
        }
        if(i == cursor->size - 1)
        {
          leftSibling = i;
          rightSibling = i+2;
          cursor = cursor->ptr[i+1];
          break;
        }
      }
    }
    //in the following for loop, we search for the key if it exists
    bool found = false;
    int pos;
    for(pos = 0; pos < cursor->size; pos++)
    {
      if(cursor->key[pos] == x)
      {
        found = true;
        break;
      }
    }
    if(!found)//if key does not exist in that leaf node
    {
      cout<<"Not found\n";
      return;
    }
    //deleting the key
    for(int i = pos; i < cursor->size; i++)
    {
      cursor->key[i] = cursor->key[i+1];
    }
    cursor->size--;
    if(cursor == root)//if it is root node, then make all pointers NULL
    {
     // cout<<"Deleted "<<x<<" from leaf node successfully\n";
      for(int i = 0; i < MAX+1; i++)
      {
        cursor->ptr[i] = NULL;
      }
      if(cursor->size == 0)//if all keys are deleted
      {
       // cout<<"Tree died\n";
        delete[] cursor->key;
        delete[] cursor->ptr;
        delete cursor;
        root = NULL;
      }
      return;
    }
    cursor->ptr[cursor->size] = cursor->ptr[cursor->size+1];
    cursor->ptr[cursor->size+1] = NULL;
   // cout<<"Deleted "<<x<<" from leaf node successfully\n";
    if(cursor->size >= (MAX+1)/2)//no underflow
    {
      return;
    }
    //cout<<"Underflow in leaf node!\n";
    //underflow condition
    //first we try to transfer a key from sibling node
    //check if left sibling exists
    if(leftSibling >= 0)
    {
      node *leftnode = parent->ptr[leftSibling];
      //check if it is possible to transfer
      if(leftnode->size >= (MAX+1)/2+1)
      {
        //make space for transfer
        for(int i = cursor->size; i > 0; i--)
        {
          cursor->key[i] = cursor->key[i-1];
        }
        //shift pointer to next leaf
        cursor->size++;
        cursor->ptr[cursor->size] = cursor->ptr[cursor->size-1];
        cursor->ptr[cursor->size-1] = NULL;
        //transfer
        cursor->key[0] = leftnode->key[leftnode->size-1];
        //shift pointer of leftsibling
        leftnode->size--;
        leftnode->ptr[leftnode->size] = cursor;
        leftnode->ptr[leftnode->size+1] = NULL;
        //update parent
        parent->key[leftSibling] = cursor->key[0];
      //  cout<<"Transferred "<<cursor->key[0]<<" from left sibling of leaf node\n";
        return;
      }
    }
    if(rightSibling <= parent->size)//check if right sibling exist
    {
      node *rightnode = parent->ptr[rightSibling];
      //check if it is possible to transfer
      if(rightnode->size >= (MAX+1)/2+1)
      {
        //shift pointer to next leaf
        cursor->size++;
        cursor->ptr[cursor->size] = cursor->ptr[cursor->size-1];
        cursor->ptr[cursor->size-1] = NULL;
        //transfer
        cursor->key[cursor->size-1] = rightnode->key[0];
        //shift pointer of rightsibling
        rightnode->size--;
        rightnode->ptr[rightnode->size] = rightnode->ptr[rightnode->size+1];
        rightnode->ptr[rightnode->size+1] = NULL;
        //shift conent of right sibling
        for(int i = 0; i < rightnode->size; i++)
        {
          rightnode->key[i] = rightnode->key[i+1];
        }
        //update parent
        parent->key[rightSibling-1] = rightnode->key[0];
      // cout<<"Transferred "<<cursor->key[cursor->size-1]<<" from right sibling of leaf node\n";
        return;
      }
    }
    //must merge and delete a node
    if(leftSibling >= 0)//if left sibling exist
    {
      node* leftnode = parent->ptr[leftSibling];
      // transfer all keys to leftsibling and then transfer pointer to next leaf node
      for(int i = leftnode->size, j = 0; j < cursor->size; i++, j++)
      {
        leftnode->key[i] = cursor->key[j];
      }
      leftnode->ptr[leftnode->size] = NULL;
      leftnode->size += cursor->size;
      leftnode->ptr[leftnode->size] = cursor->ptr[cursor->size];
     // cout<<"Merging two leaf nodes\n";
      removeinternal(parent->key[leftSibling],parent,cursor);// delete parent node key
      delete[] cursor->key;
      delete[] cursor->ptr;
      delete cursor;
    }
    else if(rightSibling <= parent->size)//if right sibling exist
    {
      node* rightnode = parent->ptr[rightSibling];
      // transfer all keys to cursor and then transfer pointer to next leaf node
      for(int i = cursor->size, j = 0; j < rightnode->size; i++, j++)
      {
        cursor->key[i] = rightnode->key[j];
      }
      cursor->ptr[cursor->size] = NULL;
      cursor->size += rightnode->size;
      cursor->ptr[cursor->size] = rightnode->ptr[rightnode->size];
     // cout<<"Merging two leaf nodes\n";
      removeinternal(parent->key[rightSibling-1],parent,rightnode);// delete parent node key
      delete[] rightnode->key;
      delete[] rightnode->ptr;
      delete rightnode;
    }
  }
}
void bptree::removeinternal(int x, node* cursor, node* child)
{
  //deleting the key x first
  //checking if key from root is to be deleted
  if(cursor == root)
  {
    if(cursor->size == 1)//if only one key is left, change root
    {
      if(cursor->ptr[1] == child)
      {
        delete[] child->key;
        delete[] child->ptr;
        delete child;
        root = cursor->ptr[0];
        delete[] cursor->key;
        delete[] cursor->ptr;
        delete cursor;
        //cout<<"Changed root node\n";
        return;
      }
      else if(cursor->ptr[0] == child)
      {
        delete[] child->key;
        delete[] child->ptr;
        delete child;
        root = cursor->ptr[1];
        delete[] cursor->key;
        delete[] cursor->ptr;
        delete cursor;
        //cout<<"Changed root node\n";
        return;
      }
    }
  }
  int pos;
  for(pos = 0; pos < cursor->size; pos++)
  {
    if(cursor->key[pos] == x)
    {
      break;
    }
  }
  for(int i = pos; i < cursor->size; i++)
  {
    cursor->key[i] = cursor->key[i+1];
  }
  //now deleting the pointer child
  for(pos = 0; pos < cursor->size+1; pos++)
  {
    if(cursor->ptr[pos] == child)
    {
      break;
    }
  }
  for(int i = pos; i < cursor->size+1; i++)
  {
    cursor->ptr[i] = cursor->ptr[i+1];
  }
  cursor->size--;
  if(cursor->size >= (MAX+1)/2-1)//no underflow
  {
   // cout<<"Deleted "<<x<<" from internal node successfully\n";
    return;
  }
  //cout<<"Underflow in internal node!\n";
  //underflow, try to transfer first
  if(cursor==root)return;
  node* parent = findparent(root, cursor);
  int leftSibling, rightSibling;
  //finding left n right sibling of cursor
  for(pos = 0; pos < parent->size+1; pos++)
  {
    if(parent->ptr[pos] == cursor)
    {
      leftSibling = pos - 1;
      rightSibling = pos + 1;
      break;
    }
  }
  //try to transfer
  if(leftSibling >= 0)//if left sibling exists
  {
    node *leftnode = parent->ptr[leftSibling];
    //check if it is possible to transfer
    if(leftnode->size >= (MAX+1)/2)
    {
      //make space for transfer of key
      for(int i = cursor->size; i > 0; i--)
      {
        cursor->key[i] = cursor->key[i-1];
      }
      //transfer key from left sibling through parent
      cursor->key[0] = parent->key[leftSibling];
      parent->key[leftSibling] = leftnode->key[leftnode->size-1];
      //transfer last pointer from leftnode to cursor
      //make space for transfer of ptr
      for (int i = cursor->size+1; i > 0; i--)
      {
        cursor->ptr[i] = cursor->ptr[i-1];
      }
      //transfer ptr
      cursor->ptr[0] = leftnode->ptr[leftnode->size];
      cursor->size++;
      leftnode->size--;
    //  cout<<"Transferred "<<cursor->key[0]<<" from left sibling of internal node\n";
      return;
    }
  }
  if(rightSibling <= parent->size)//check if right sibling exist
  {
    node *rightnode = parent->ptr[rightSibling];
    //check if it is possible to transfer
    if(rightnode->size >= (MAX+1)/2)
    {
      //transfer key from right sibling through parent
      cursor->key[cursor->size] = parent->key[pos];
      parent->key[pos] = rightnode->key[0];
      for (int i = 0; i < rightnode->size -1; i++)
      {
        rightnode->key[i] = rightnode->key[i+1];
      }
      //transfer first pointer from rightnode to cursor
      //transfer ptr
      cursor->ptr[cursor->size+1] = rightnode->ptr[0];
      for (int i = 0; i < rightnode->size; ++i)
      {
        rightnode->ptr[i] = rightnode->ptr[i+1];
      }
      cursor->size++;
      rightnode->size--;
    //  cout<<"Transferred "<<cursor->key[0]<<" from right sibling of internal node\n";
      return;
    }
  }
  //transfer wasnt posssible hence do merging
  if(leftSibling >= 0)
  {
    //leftnode + parent key + cursor
    node *leftnode = parent->ptr[leftSibling];
    leftnode->key[leftnode->size] = parent->key[leftSibling];
    for(int i = leftnode->size+1, j = 0; j < cursor->size; j++)
    {
      leftnode->key[i] = cursor->key[j];
    }
    for(int i = leftnode->size+1, j = 0; j < cursor->size+1; j++)
    {
      leftnode->ptr[i] = cursor->ptr[j];
      cursor->ptr[j] = NULL;
    }
    leftnode->size += cursor->size+1;
    cursor->size = 0;
    //delete cursor
    removeinternal(parent->key[leftSibling], parent, cursor);
   // cout<<"Merged with left sibling\n";

  }
  else if(rightSibling <= parent->size)
  {
    //cursor + parent key + rightnode
    node *rightnode = parent->ptr[rightSibling];
    cursor->key[cursor->size] = parent->key[rightSibling-1];
    for(int i = cursor->size+1, j = 0; j < rightnode->size; j++)
    {
      cursor->key[i] = rightnode->key[j];
    }
    for(int i = cursor->size+1, j = 0; j < rightnode->size+1; j++)
    {
      cursor->ptr[i] = rightnode->ptr[j];
      rightnode->ptr[j] = NULL;
    }
    cursor->size += rightnode->size+1;
    rightnode->size = 0;
    //delete cursor
    removeinternal(parent->key[rightSibling-1], parent, rightnode);
    //cout<<"Merged with right sibling\n";
  }
}




// Get the root
node *bptree::getroot()
{
  return root;
}

int main() 
{
  cout<<"enter the order of the b+tree"<<endl;
  cin>>MAX;
  bptree pt;
  int i=1;
  int num;
  while(i)
  {
    cout<<"enter a key to insert it to tree"<<endl;
    cin>>num;
    pt.insert(num);
    cout<<"wanna add another key 1 for  yes and 0 for no"<<endl;
    cin>>i;
  }
  system("clear");
  cout<<"after insertion tree "<<endl;
  pt.display(pt.getroot());
  i=1;
  while(i)
  {
    cout<<"enter a key to delete it from tree"<<endl;
    cin>>num;
    pt.remove(num);
    cout<<"wanna delete another key 1 for  yes and 0 for no"<<endl;
    cin>>i;
  }
  cout<<"after deletion tree :"<<endl;
  pt.display(pt.getroot());
}
