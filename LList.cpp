#include<iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
int main(){
    int z[6]={1,2,3,4,5,6};
    ListNode* list[6]; 
    /*ポインタ(配列)を宣言しただけではメモリは割り当てられない
    この時点でlistのポインタは適当なアドレス値を指す*/
    for(int i=0;i<5;i++){
        list[i] = new ListNode(z[i]);
        //newで初めて割り当てられlistのアドレス値が意味を持つ
        cout<<list[0]<<endl;
        (*list[i]).next=list[i+1];
        cout << list[i]->val<<endl;
        //ポインタからのメンバへのアクセスはアロー演算子か*.
    }
    return 0;
    }