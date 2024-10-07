#include<iostream>
#include <locale>
#include<string>
using namespace std;

struct node{
    int number;
    struct node*next;
};
node *create_node(){
    node*new_node = new node;
    if(!new_node)
        return NULL;
    new_node->next = NULL;
    return new_node; 
}

node *create(int n){
    
    node*head = new node;
    node*tail = head;
    node*p;
    for(int i=0;i<n;i++){
        p = create_node();
        if(!p) return head;
        if(head==NULL)
            head = p;
        else
            tail->next = p;
        tail = p;   
    }
    return head;
}

void first(node* head){
    node* p = head->next;
    while(p != NULL){
        int num;
        cin>>num;
        p->number = num;
        p = p->next;
    }
}

void print_list(node *head){
    node *pt = head->next;
    while(pt != NULL){
        cout<<pt->number<<' ';
        pt = pt->next;
    }
    cout<<endl;
}

void delete_node(node*head){
        node*p = head;
        while(p != NULL){
            node*pt = head->next;
            delete p;
            head = pt;
            p = head;
        }
}

void add(node* head, int num, int location){
    if(location <= 0) cout<<"插入位置不正确!"<<endl;
    else{
        node* q = create_node();
        q->number = num;
        node* p = head;
        int n = 0;
        int flag = 1;
        for(int i=0; i<location-1; i++){
            if(p->next == NULL){
                if(n == location-1)
                    p->next = q;
                else
                    cout<<"插入位置不正确!"<<endl;
                flag = 0;
            }
            else 
                p = p->next;
            n++;
        }
        if(flag){
            q->next = p->next;
            p->next = q;          
        }
    }
}

void del(node* head, int num){
    node* p = head->next;
    node* pt = head;
    int flag = 0;
    while(p->next != NULL){
        if(p->number == num){
            pt->next = p->next;
            delete p;
            p = pt->next;
            flag = 1;
        }
        p = p->next;
        pt = pt->next;
    }
    if(p->number == num) {
        pt->next = NULL;
        delete p;
        flag = 1;
    }
    if(flag == 0) cout<<"链表中没有这个元素!"<<endl;
}


void find(node* head, int num){
    node* p = head->next;
    int flag = 0;
    while(p->next != NULL){
        if(p->number == num){
            flag = 1;
            break;
        }
        p = p->next;
    }
    if(p->number == num){
        flag = 1;
    }
    if(flag == 0) cout<<"链表中没有这个元素!"<<endl;
    else{
        cout<<"链表中有这个元素"<<endl;
    }
}

node* unionseq(node* head1, node* head2){
    node* C = create_node();
    node* p = head1->next;
    while(p != NULL){
        node* k = create_node();
        k->number = p->number;
        k->next = C->next;
        C->next = k;
        p = p->next;
    }
    node* p2 = head2->next;
    while(p2 != NULL){
        node* p1 = head1->next;
        int flag = 1;
        while(p1 != NULL){
            if(p2->number == p1->number){
                flag = 0;
                break;
            }
            p1 = p1->next;
        }
        if(flag){
            node* q = create_node();
            q->number = p2->number;
            q->next = C->next;
            C->next = q;
        }
        p2 = p2->next;
    }
    return C;
}

node* intersection(node* head1, node* head2){
    node* head = create_node();
    node* p2 = head2->next;
    while(p2 != NULL){
        node* p1 = head1->next;
        int flag = 0;
        while(p1 != NULL){
            if(p2->number == p1->number){
                flag = 1;
                break;
            }
            p1 = p1->next;
        }
        if(flag){
            node* q = create_node();
            q->number = p2->number;
            q->next = head->next;
            head->next = q;
        }
        p2 = p2->next;
    }
    return head;
}

node* differ(node* head1, node*head2){
    node* C = create_node();
    node* p = head1->next;
    while(p != NULL){
        node* k = create_node();
        k->number = p->number;
        k->next = C->next;
        C->next = k;
        p = p->next;
    }
    node* inter = intersection(head1, head2);
    node* p0 = C;
    node* p1 = C->next;
    while(p1 != NULL){
        int flag = 1;
        node* p2 = inter->next;
        while(p2 != NULL){
            if(p1->number == p2->number){
                flag = 0;
                break;
            }
        p2 = p2->next;

        }
        if(flag == 0){
            p0->next = p1->next;
            delete p1;
            p1 = p0->next;
        }
        else{
            p0 = p0->next;
            p1= p1->next;
        }
    }
    delete_node(inter);
    return C;
}