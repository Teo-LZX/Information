#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct S
{
    char name[20];
    int num;
    int score;
    struct S* next;
}Student;

int res_num=0;
int res_score=-1;
char res_name[20];

Student* create()
{
    Student* head = (Student*)malloc(sizeof(Student));
    head->next = NULL;
    Student* p = head;
    printf("请输入姓名学号成绩:\n");
    Student *temp = (Student*)malloc(sizeof(Student));
    scanf("%s %d %d", temp->name, &temp->num, &temp->score);
    temp->next = NULL;
    p->next = temp;
    p = p->next;
    getchar();
    res_score = temp->score;
    res_num = temp->num;
    strcpy(res_name, temp->name);
    while(1)
    {
        printf("是否继续输入,按Y键继续输入，其他键就结束.\n");
        char ch;
        scanf("%c", &ch);
        getchar();
        if(ch != 'Y')
            break;

        printf("请输入学生姓名，学号，成绩： \n");
        Student *temp = (Student*)malloc(sizeof(Student));
        scanf("%s %d %d", temp->name, &temp->num, &temp->score);
        getchar();
        
        if(temp->score>res_score)
        {
            //printf("temp_score=%d, res_score=%d\n", temp->score, res_score);
            res_score=temp->score;
            res_num=temp->num;
            strcpy(res_name, temp->name);
            //printf("temp_score=%d, res_score=%d\n", temp->score, res_score);
        }

        temp->next = NULL;
        p->next = temp;
        p = p->next;
        
    }
    return head;
}

void show(Student* head)
{

    printf("result:\n");
    printf("%s %d %d", res_name, res_num, res_score);

}

int main()
{
    Student* head = create();
    show(head);
}