#include<iostream>
using namespace std;

class Node
{
public:
    Node() {}
    Node(int n): n(n) { Node* next = NULL; }
    int n;
    Node* next;
};
void show(Node* head, int n)       //打印链表
{
    Node* p = head->next;
    while(p->next != head->next)
    {
        cout << p->n << " ";
        p = p->next;
    }
    cout << p->n;
    cout << endl;
}
Node* CreateList(int n)
{
    Node* head = new Node(0);
    Node* pr = head;
    for(int i=1;i<=n;i++)
    {
        Node* p = new Node(i);
        pr->next = p;
        pr = p;
        
    }
    pr->next = head->next;
    return head;
}
void yue_se_fu(Node* head, int m, int n)
{
    Node* p1 = head, p2;
    int k=0;
    int del = 0;
    int len=n;
    char ch;
    while (del<n-1)
    {
        //getchar();
        //cout << p1->next->n << "  ";
        k++;
        if(k == m)
        {
            Node* temp = p1->next;
            if(temp == head->next)
                head->next = p1;
            p1->next = temp->next;
            cout << temp->n << " "; //show(head, len--);
            free(temp);
            del++;
            k=0;
        }
        //k++;
        if(k!=0)
        p1 = p1->next;
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    Node* head = CreateList(n);
    yue_se_fu(head, m, n);
    show(head, n);
    return 0;
}