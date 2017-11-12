#include<iostream>
#include<vector>
using namespace std;

template<class t>
class heap
{ vector<t> tree;

void heapify_insert();
void heapify_del();
int p(int );


public:
heap(t data)  { tree.push_back(data); }
~heap()   {tree.clear();}
void insert(t data);
void show();
t sort();
};

template <class t>
 void heap<t>::insert(t data)
{ tree.push_back(data);  
   heapify_insert();                            
}

template<class t>
void heap<t>::heapify_insert()
{ int c=tree.size();
   t temp; 
   c--;
  int p=c/2;
 
 while(p!=0 && tree[c] > tree[p])
     {    temp = tree[p];
          tree[p] = tree[c];
          tree[c] = temp;
          c=p;
         p/=2;
     }
}

template <class t>
void heap<t>::show()
{  for(int i = 1, s=tree.size(); i <s; i++)
         cout << tree[i] << " \n";
        cout << "\n" << endl;
}

template <class t>
t heap<t>::sort()
{ t temp=tree[1];
  tree[1]=tree[tree.size()-1];
  tree.pop_back();
  heapify_del();
  cout<<temp<<endl;
  return temp;
}

template <class t>
void heap<t>::heapify_del()
{ int  sc,bc,s=tree.size(),p=1;
  int rc=2*p+1,lc=2*p;
  t temp;

while(lc<s)
{   if(rc>=s) 
     { if(tree[lc]>tree[p])
          { temp=tree[p];
             tree[p]=tree[lc];
             tree[lc]=temp;
             }
        return;
     }
    else
    { bc=tree[rc]>tree[lc]?rc:lc;
      sc=(bc==rc)?lc:rc;
          if(tree[bc]<tree[p])
              return;
          else 
             { temp=tree[p];
               tree[p]=tree[bc];
               tree[bc]=temp;
                p=bc;
                lc=2*p;
                rc=2*p+1;
             }
      }
}
}




int main(){
heap<int> a(0);
a.insert(67);
a.insert(72);
a.insert(74);
a.insert(83);
a.insert(87);
a.insert(90);
a.insert(80);
a.insert(81);
a.insert(78);
a.insert(79);
a.insert(70);
a.insert(71);

a.show();
cout<<endl;

for(int i=0;i<12;i++)
a.sort();

a.show();

cout<<"\n\tend\t";
}