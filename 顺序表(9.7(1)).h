#include<iostream>
#include<string>
#include <utility>
using namespace std;

#define maxSize 100
typedef struct{
    int item;
    string name;
}DataType;//假设顺序表里面的元素是一个结构，用来比较大小的数据为item


typedef struct{
    DataType *data[maxSize];
    int n;   
}SeqList;


//(1)
DataType* dele_min(SeqList&L){
    if(L.n == 0){
        cout<<"顺序表为空！";
        return NULL;
    }
    else{
        int min = L.data[0]->item;
        int location = 0;
        for(int i=1; i<L.n; i++){
            if(min > L.data[i]->item){
                min = L.data[i]->item;
                location = i;
            }
        }
        DataType* ope = new DataType;
        ope->item = L.data[location]->item;
        ope->name = L.data[location]->name;

        DataType* t = L.data[location];
        L.data[location] = L.data[L.n-1];
        L.data[L.n-1] = t;
        delete t;
        L.data[L.n-1] = NULL;
        L.n -= 1;
        return ope;//这里要注意的点是return标志着一段代码的结束，所以return后面的代码不执行

    }
}


//(2)
DataType* dele_index(SeqList&L, int i){
    if(L.n == 0){   
        cout<<"顺序表为空！";
        return NULL;
    }

    else if(i <= 0 || i >= L.n){
        cout<<"i设置不合理！";
        return NULL;
    }

    else{
        DataType* p = new DataType;
        p->item = L.data[i-1]->item;
        p->name = L.data[i-1]->name;
        delete L.data[i-1];
        for(int j=i-1; j<L.n-1; j++){
            L.data[j] = L.data[j+1];
        }
        L.n -= 1;
        return p;
    }
}


//(3)
bool add_index(SeqList&L, int i, DataType*type){
    if(L.n == 0){   
        cout<<"顺序表为空！";
        return false;
    }

    else if(L.n == maxSize){
        cout<<"顺序表已满，无法进行插入操作！";
        return false;
    }

    else if(i < 0 || i > L.n ){
        cout<<"i设置不合理！";
        return false;
    }

    else{
        L.n += 1;
        for(int j=L.n; j>=i; j--){
            L.data[j] = L.data[j-1];
        }
        L.data[i-1] = type;
        return true;
    }
}

//(4)
bool dele_item(SeqList&L, double x){
    if(L.n == 0){   
        cout<<"顺序表为空！";
        return false;
    }

    else{//这里的逻辑还要理一下
        int i = 0;
        while(i < L.n){
            if(L.data[i]->item == x){
                delete L.data[i];
                for(int j=i; j<L.n-1; j++){
                    L.data[j] = L.data[j+1];
                }
                L.data[L.n-1] = NULL;
                L.n -= 1;
            }
            else i++;
        }
    return true;
    }
}

//(5)
bool dele_seq(SeqList&L, int s, int t){
    if(L.n == 0){   
        cout<<"顺序表为空！";
        return false;
    }

    else if(s > t){
        cout<<"s、t设置不合理！";
        return false;
    }

    else{
        int i = 0;
        while(i < L.n){
            if(L.data[i]->item >= s && L.data[i]->item <= t){
                delete L.data[i];
                for(int j=i; j<L.n-1; j++){
                    L.data[j] = L.data[j+1];
                }
                L.data[L.n-1] = NULL;
                L.n -= 1;
            }
            else i++;
        }
    return true;
    }

}

//(6)

bool dele_orderseq(SeqList&L, double s, double t){
    if(L.n == 0){   
        cout<<"顺序表为空！";
        return false;
    }

    else if(s > t){
        cout<<"s、t设置不合理！";
        return false;
    }

    else{
        int i = 0;
        while(L.data[i]->item < s) i++;
        int begin = i;
        while(L.data[i]->item < t) i++;
        int end = i + 1;
        for(int j=begin; j<L.n-end+begin; j++){
            delete L.data[j];
            L.data[j] = L.data[j+end-begin];
        }
        L.n -= end - begin;
    }
    return true;   
}

//(7)

SeqList merge(SeqList&L1, SeqList&L2){
    SeqList L;
    L.n = L1.n + L2.n;
    int i=0, j=0, p=0;
    while(i<L1.n && j<L2.n){
        if(L1.data[i]->item <= L2.data[j]->item){
            L.data[p] = L1.data[i];
            i++;
        }
        else{
            L.data[p] = L2.data[j];
            j++;
        }
        p++;
    }

    if(i == L1.n){
        for(int k=p, q=j; k<L.n; k++){
            L.data[k] = L2.data[q];
            q++;
        }
    }

    else if(j == L2.n){
         for(int k=p, q=i; k<L.n; k++){
            L.data[k] = L1.data[q];
            q++;
        }
    }

    return L;
}

//(8)

bool dele_same(SeqList&L){
    if(L.n == 0){   
        cout<<"顺序表为空！";
        return false;
    }

    else{
        int i=0;
        while(i < L.n-1){
            for(int j = i+1; j < L.n; j++) {
                if(L.data[i]->item == L.data[j]->item){
                    delete L.data[j];
                    for(int k=j; k<L.n-1; k++)
                        L.data[k] = L.data[k+1];                
                    L.data[L.n-1] = NULL;
                    L.n -= 1;
                }
            }
            i++;
        }
        return true;
}


void dele(SeqList&L){
    for(int i=0; i<L.n; i++)
        delete L.data[i];
}


