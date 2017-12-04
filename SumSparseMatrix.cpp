#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    int column;
    int row;
    Node *next;
    Node(int data,int row,int column)
    {
        this->data=data;
        this->column=column;
        this->row=row;
        next=NULL;
    }
};

Node *root;
Node *root2;
Node *newRoot;
int arr[10][10];
int arr2[10][10];
int newArray[10][10];

void Insert(Node *node)
{
    if(root==NULL){
        root=node;
        return;
    }
    else {
        Node *ptr=root;
        while(ptr!=NULL)
        {
            if(ptr->next==NULL) {
                ptr->next=node;
                return;
            }
            ptr=ptr->next;
        }
    }
}

void Insert2(Node *node)
{
    if(root2==NULL){
        root2=node;
        return;
    }
    else {
        Node *ptr=root2;
        while(ptr!=NULL)
        {
            if(ptr->next==NULL) {
                ptr->next=node;
                return;
            }
            ptr=ptr->next;
        }
    }
}

void spareArray(Node *node,int num)
{
    if(num==1){
        arr[10][10] = {0};
        Node *ptr=node;
        while(ptr!=NULL){
            arr[ptr->row][ptr->column]=ptr->data;
            ptr=ptr->next;
        }
        return ;
    }
    else{
        arr2[10][10] = {0};
        Node *ptr=node;
        while(ptr!=NULL){
            arr2[ptr->row][ptr->column]=ptr->data;
            ptr=ptr->next;
        }
        return ;
    }
}

void add(int a1[10][10],int a2[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            newArray[i][j]=a1[i][j]+a2[i][j];
        }
    }
}

void spareArrayNewRoot(int a[10][10])
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]!=0){
                Node *node=new Node(a[i][j],i,j);
                if(newRoot==NULL){
                    newRoot=node;
                }
                else {
                    Node *ptr=newRoot;
                    while(ptr!=NULL){
                        if(ptr->next==NULL) {
                            ptr->next=node;
                            break;
                            }
                        ptr=ptr->next;
                    }
                }
            }
        }
    }
}

void Delete(int num, int row, int column)
{
    Node *ptr, *ptr2;
    if(num==1){
        ptr = root;
        if(root->row==row && root->column==column){
                root=root->next;
                delete ptr;
        }
        while(ptr->next!=NULL){
            if(ptr->next->row==row && ptr->next->column==column){
                ptr2=ptr->next;
                ptr->next=ptr->next->next;
                delete ptr2;
                break;
            }
            ptr=ptr->next;
        }
        arr[row][column]=0;
    }
    if(num==2){
        ptr = root2;
        if(root2->row==row && root2->column==column){
                root2=root2->next;
                delete ptr;
            }
        while(ptr->next!=NULL){
            if(ptr->next->row==row && ptr->next->column==column){
                ptr2=ptr->next;
                ptr->next=ptr->next->next;
                delete ptr2;
                break;
            }
            ptr=ptr->next;
        }
        arr2[row][column]=0;
    }
}

void Search(int num, int row, int column)
{
    bool n = true;
    Node *ptr;
    if(num==1) ptr=root;
    if(num==2) ptr=root2;
    while(ptr!=NULL)
    {
        if(ptr->row==row && ptr->column==column){
            cout<<endl;
            cout<<"Row : "<<row<<" Column : "<<column<<" Data : "<<ptr->data<<endl;
            cout<<endl;
            n=false;
            break;
        }
        ptr=ptr->next;
    }
    if(n==true){
        cout<<endl;
        cout<<"Row : "<<row<<" Column : "<<column<<" Data : "<<0<<endl;
        cout<<endl;
    }
}

void Show(int a[10][10])
{
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }cout<<endl;
}

int main()
{
    int choice,r,c,v,a,Next;
    while(1){
        Next = 0;
        cout<<" 1.Insert value"<<endl;
        cout<<" 2.Delete value"<<endl;
        cout<<" 3.Find"<<endl;
        cout<<" 4.Show"<<endl;
        cout<<" 5.Sum Matrix"<<endl;
        spareArray(root,1);
        spareArray(root2,2);
        spareArrayNewRoot(newArray);
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"choose array : ";
            cin>>a;
            if(a==1){
                while(Next!=-1){
                    cout<<"Insert row : ";
                    cin>>r;
                    cout<<"Insert column : ";
                    cin>>c;
                    cout<<"Insert value : ";
                    cin>>v;
                    cout<<"Next ";
                    cin>>Next;
                    Insert(new Node(v,r,c));
                }
            }
            else if(a==2){
                while(Next!=-1){
                    cout<<"Insert row : ";
                    cin>>r;
                    cout<<"Insert column : ";
                    cin>>c;
                    cout<<"Insert value : ";
                    cin>>v;
                    cout<<"Next ";
                    cin>>Next;
                    Insert2(new Node(v,r,c));
                }
            }
            break;
        case 2:
            cout<<"choose array : ";
            cin>>a;
            if(a==1){
                while(Next!=-1){
                    cout<<"Insert row : ";
                    cin>>r;
                    cout<<"Insert column : ";
                    cin>>c;
                    cout<<"Next ";
                    cin>>Next;
                    Delete(a, r, c);
                }
            }
            else if(a==2){
                while(Next!=1){
                    cout<<"Insert row : ";
                    cin>>r;
                    cout<<"Insert column : ";
                    cin>>c;
                    cout<<"Next ";
                    cin>>Next;
                    Delete(a, r, c);
                }
            }
            break;
        case 3:
            cout<<"choose array : ";
            cin>>a;
            if(a==1){
                cout<<"Insert row : ";
                cin>>r;
                cout<<"Insert column : ";
                cin>>c;
                Search(a, r, c);
            }
            else if(a==2){
                cout<<"Insert row : ";
                cin>>r;
                cout<<"Insert column : ";
                cin>>c;
                Search(a, r, c);
            }
            break;
        case 4:
            cout<<"Choose array : ";
            cin>>a;
            if(a==1){
                Show(arr);
            }
            else if(a==2){
                Show(arr2);
            }
            else if(a==3){
                add(arr,arr2);
                Show(newArray);
            }
            break;
        case 5:
            add(arr,arr2);
            Show(newArray);
            spareArrayNewRoot(newArray);
            Node *ptr=newRoot;
            while(ptr!=NULL)
            {
                cout<<"row : "<<ptr->row<<" column : "<<ptr->column<<" data : "<<ptr->data<<endl;
                ptr=ptr->next;
            }cout<<endl;
            break;
        }
    }

    return 0;
}
