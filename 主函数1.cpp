#include"顺序表(9.7(1)).h"
using namespace std;

int main(){
    int n;
    cin>>n;
    SeqList database;
    database.n = n;
    for(int i=0; i<database.n; i++)
        database.data[i] = new DataType;//姐，database是一个指针数组，所以对每一个指针都要指向一个地方，避免指针悬挂！！！
    for(int i=0; i<n; i++)
        cin>>database.data[i]->item>>database.data[i]->name;

    /*(1)
    cout<<"删除的项:"<<endl;
    DataType* disgard = dele_min(database);
    cout<<disgard->item<<' '<<disgard->name<<endl;
    cout<<"删除后的顺序表:"<<endl;
    for(int i=0; i<database.n; i++)
        cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    delete disgard;
    */

    /*(2)
    cout<<"输入要删除数的位置:"<<endl;
    int location;
    cin>>location;
    DataType* op = dele_index(database, location);
    cout<<"删除的项:"<<endl;
    cout<<op->item<<' '<<op->name<<endl;
    delete op;
    cout<<"删除后的顺序表:"<<endl;
    for(int i=0; i<database.n; i++)
        cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    */

    /*(3)
    cout<<"输入要增加的数据元素:"<<endl;
    DataType* op = new DataType;
    cin>>op->item>>op->name;
    cout<<"输入增加的位置:"<<endl;
    int location;
    cin>>location;
    if(add_index(database, location, op)){
        cout<<"增加后的顺序表:"<<endl;
        for(int i=0; i<database.n; i++)
            cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    }
    */

    /*(4)
    cout<<"输入要删除的数:"<<endl;
    int num;
    cin>>num;
    if(dele_item(database, num)){
        cout<<"删除后的顺序表:"<<endl;
        for(int i=0; i<database.n; i++)
            cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    }
    */

    /*(5)
    cout<<"输入删除区间:"<<endl;
    int s,t;
    cin>>s>>t;
    if(dele_seq(database, s, t)){
        cout<<"删除后的顺序表:"<<endl;
        for(int i=0; i<database.n; i++)
            cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    }
    */

    /*(6)
    cout<<"输入删除区间:"<<endl;
    int s,t;
    cin>>s>>t;
    if(dele_orderseq(database, s, t)){
        cout<<"删除后的顺序表:"<<endl;
        for(int i=0; i<database.n; i++)
            cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    }
    */
    
    /*(7)
    int n2;
    cin>>n2;
    SeqList database2;
    database2.n = n2;
    for(int i=0; i<database2.n; i++)
        database2.data[i] = new DataType;//姐，database是一个指针数组，所以对每一个指针都要指向一个地方，避免指针悬挂！！！
    for(int i=0; i<n; i++)
        cin>>database2.data[i]->item>>database2.data[i]->name;
    SeqList all = merge(database, database2);
    cout<<"合并后的顺序表:"<<endl;
        for(int i=0; i<all.n; i++)
            cout<<all.data[i]->item<<' '<<all.data[i]->name<<endl;
    dele(all);
    */

    /*(8)
    if(dele_same(database)){
        cout<<"删除后的顺序表:"<<endl;
        for(int i=0; i<database.n; i++)
            cout<<database.data[i]->item<<' '<<database.data[i]->name<<endl;
    }
    */

    dele(database);
}