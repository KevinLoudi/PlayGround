/*project test in code block*/
/*
 Author: Kevin
 Propose:
 Environment: GCC 4.9 for C++11
*/
#include <iostream>
#include <vector>
/*#include <string>
#include "../../algorithm/algorithm.h"
#include "../../algorithm/basic_data_structure.h"
#include "../../algorithm/ddlinklist.h"
#include "../../algorithm/sstack.h" */
#include "../../algorithm/c_string_operations.h"
#include "../../algorithm/mmatrix.h"
//#include "../../algorithm/bbinary_tree.h"
#include "../../algorithm/hash_map.h"
#include "../../algorithm/equal.h"
#include "../../algorithm/hash_code.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
//    using namespace DataStructure;
//    double data[] = {2,9,4,6,7,3,1,5,12,14,8,11,9.7,8.3,4.5,2.5,7.6};
//    const UINT M=3;
//    const UINT N=4;
    /*vector<double> datalst(data, data+M*N);


    Mmatrix<double> equ(3,4,datalst);
    cout<<equ.print(datalst,cout);

    //solve the 3*4 equation
    vector<double> x =equ.gauss_elimination_solver();
    cout<<equ.print(x,cout)<<"\n";

    //calculate determinate
    Mmatrix<double> mat(M,M,datalst);
    cout<<equ.det(mat)<<"\n"; */

    //generate a binary tree
//    BTree<double> tree;
//    for(UINT i=0; i<M*N; ++i)
//    {
//        tree.insert_helper(data[i]);
//    }
//
//    cout<<tree.print_helper(cout);
//
//    return 0;
     //test hash map
     const int S=10;
     char* strs[S]=
    {
    "abc",
    "qq",
    "hello",
    "abc",
    "lmy",
    "ab",
    "qq",
    "lqw",
    "sww",
    "lqw"
    };
    int*  data = malloc(sizeof(int)* S);
    for (int i=0; i<S; i++)
    {
        data[i]=i;
    }

    //创建映射需要指定两个函数，hashCode函数和equal函数。
    MyHashMap * map = createMyHashMap(myHashCodeString, myEqualString);

    //插入数据
    for (int i=0; i<S; i++)
    {
        myHashMapPutData(map, strs[i], &data[i]);
    }

    //输出大小
    printf("size=%d\n",myHashMapGetSize(map));

    //测试删除
    myHashMapRemoveDataByKey(map,"qq");
    myHashMapRemoveDataByKey(map,"ab");
    myHashMapRemoveDataByKey(map,"qwert");

    //输出大小
    printf("after remove size=%d\n",myHashMapGetSize(map));

    //遍历
    MyHashMapEntryIterator * it = createMyHashMapEntryIterator(map);
    while(myHashMapEntryIteratorHasNext(it))
    {
        Entry * pp= myHashMapEntryIteratorNext(it);
        char * key = pp-> key;
        int * value = pp->value;
        printf("%s(%d)\n", key, *value);
    }
    //释放遍历器
    freeMyHashMapEntryIterator(it);

    //释放映射
    freeMyHashMap(map);

    //释放数据
    free(data);
     return 0;
}




//int main()
//{
//    /*using namespace Algorithm;
//    Sort<int> s;
//    int a[]={12,15,78,96,53,47,19,44};
//    s.print(cout,a,8);
//    //s.selectsort(a,8,);
//    //s.bubblesort(a,8);
//    //s.insertsort(a,8,1);
//    s.quicksort(a,0,7);
//    s.print(cout,a,8); */
//
//    using namespace DataStructure;
//    /*LinkList<string> l;
//    l.addLast("a");
//    l.addLast("b");
//    l.addLast("c");*/
//    /*l.addFirst("0");
//    l.addFirst("-1");
//    l.addFirst("-2");*/
//    /*cout<<l.print(cout);
//    cout<<endl<<l.getFirst()<<" "<<l.getLast()<<endl;
//    //make run-time error happen
//    //cout<<l.removeLast()<<l.removeLast()<<l.removeLast()<<l.removeLast()<<l.removeLast();
//    //cout<<l.removeLast()<<" "<<l.removeFirst()<<endl;
//    l.addix("cc",2);
//    cout<<"access "<<l.getix(2)<<endl;
//    cout<<"find "<<"cc at"<<l.searchix("cc")<<endl;
//    cout<<l.removeix(2)<<endl;
//    cout<<"newest list"<<endl;
//    cout<<l.print(cout);
//    cout<<"clear list"<<endl;
//    cout<<l.clearlist();
//    cout<<l.print(cout);*/
//
//    //int ix=l.searchix("0");
//    //cout<<l.print_reverse_helper(cout,ix);
//
//    /*cout<<"Initial list: "<<endl;
//    cout<<l.print(cout)<<endl;
//    Node<string>* StrHead=l.getHead();
//    Node<string>* StrTail=l.getTail();
//    cout<<StrHead->element<<" "<<StrTail->element<<endl;
//    l.reverselist();
//    cout<<"Reversed list: "<<endl;
//    cout<<l.print(cout)<<endl; */
//
////    DoubleLinkList<string> dlst;
////    /*dlst.addFirst("a");
////    dlst.addFirst("b");
////    dlst.addFirst("c");
////    dlst.addFirst("d");
////    dlst.addLast("e");
////    dlst.addLast("f");
////    dlst.addAt("c2",2);
////    dlst.addAt("a1",1);*/
////    dlst.addLast("a");
////    dlst.addLast("b");
////    dlst.addLast("c");
////    dlst.addLast("d");
////    //cout<<dlst.removeHead()<<endl;
////    //cout<<dlst.removeTail()<<endl;
////    dlst.addAt("e",4);
////    dlst.addAt("f",dlst.size_());
////    cout<<dlst.print(cout);
////    /*dlst.removeAt(dlst.size_());
////    dlst.removeAt(0);
////    dlst.removeAt(1);*/
////    //cout<<dlst.print_reverse(cout);
////    cout<<"c at "<<dlst.findAt("c")<<endl;
////    cout<<"c is found and remove at "<<dlst.removeIf("c")<<endl;
////    cout<<"x is found and remove at "<<dlst.removeIf("x");//dlst.removeIf("c")<<endl;
////    cout<<dlst.print(cout);
////    dlst.clear_();
////    cout<<dlst.print(cout);
//
////    const int LEN=5;
////    string str1[LEN]={"a","b","c","d","e"};
////    string str2[LEN]={"0","1","2","3","4"};
////    DoubleLinkList<string> dlst1(str1,LEN,"null");
////    DoubleLinkList<string> dlst2(str2,LEN,"null");
////    dlst1.setAt("a1",0);
////    cout<<dlst1.getNext("e");
////
////    //random access
////    /*int len=dlst1.size_();
////    for(int ix=0; ix<len; ++ix)
////        cout<<dlst1.getAt(ix)<<endl; */
////
////    cout<<dlst1.print(cout);
////    cout<<dlst2.print(cout);
////    /*dlst2=dlst1;
////    cout<<dlst2.print(cout);*/
//
//    Sstack<string>ss1(10,"null");
//    ss1.push("a");
//    ss1.push("b");
//    ss1.push("c");
//    cout<<ss1.print(cout)<<endl;
//    cout<<ss1.pop()<<endl;
//    cout<<"new stack"<<endl;
//    ss1.push("0");
//    //cout<<ss1.printInfo(cout)<<endl;
//    Sstack<string>ss2=ss1;
//    cout<<ss2.print(cout)<<endl;
//    Sstack<string>ss3(ss1);
//    cout<<ss3.print(cout)<<endl;
//    return 0;
//}
