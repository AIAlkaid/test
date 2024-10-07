#include"SetList.h"

using namespace std;

int main(){
    int n1, n2;
    cout<<"输入A,B集合的个数"<<endl;
    cin>>n1>>n2;
    cout<<"输入集合A"<<endl;
    struct node* A = create(n1);
    first(A);
    cout<<"输入集合B"<<endl;
    struct node* B = create(n2);
    first(B);
    cout<<"集合A"<<endl;
    print_list(A);
    cout<<endl;
    cout<<"集合B"<<endl;
    print_list(B);
    cout<<endl;
    cout<<endl;
    cout<<"并集"<<endl;
    struct node* C = unionseq(A, B);
    print_list(C);
    delete_node(C);
    cout<<endl;
    cout<<"交集"<<endl;
    C = intersection(A, B);
    print_list(C);
    delete_node(C);
    cout<<endl;
    cout<<"A-B差集"<<endl;
    C = differ(A, B);
    print_list(C);
    delete_node(C);
    cout<<endl;
    cout<<"输入要在A集合中查找的数"<<endl;
    int m;
    cin>>m;
    find(A, m);
    cout<<endl;
    cout<<"输入要在A集合中删除的数"<<endl;
    int a;
    cin>>a;
    cout<<"删除后的A集合"<<endl;
    del(A, a);
    print_list(A);
    delete_node(A);
    delete_node(B);
}