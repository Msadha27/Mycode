#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Jam
{
        char date[100];
        char event[100];
        char venue[100];
        char timings[100];
        char student_name[50];
        int st_count;
};
struct Jam Events[500];
int line=0;
void list_events();
void get_details();
int  register_stud();
void display();
void main()
{
        int ch; 
        printf("1.List all events\n");
        printf("2.Get the venue and timings of the events\n");
        printf("3.Student Registeration to the events\n");
        printf("4.Display the summary of the registerations\n");
        printf("5.Exit the program\n");
        for(;;)
        {
            printf("Enter your choice\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:list_events();
                        break;
                case 2:get_details();
                        break;
                case 3:register_stud();
                        break;
                case 4:display();
                     break;
                default:exit(0);
            }
        }

}
void list_events()
{
    FILE *fp;
    char list[500];
    fp=fopen("C:/Users/HP/Desktop/Events.txt","r");
    while (fgets(list,sizeof(list),fp)!=NULL)
    {
        printf("%s",list);
        line++;
    } 
}
void get_details()
{
    FILE *fp;
    fp=fopen("C:/Users/HP/Desktop/fullevents.txt","r");
    char E[10];
    printf("Enter the event\n");
    scanf("%s",E);
    int i=0;
    while (i <sizeof(Events) && fscanf(fp, "%49[^,],%49[^,],%49[^,],%29[^\n]\n", 
        Events[i].date,Events[i].event, Events[i].venue, Events[i].timings)== 4)
    {
        i++;  
    }

    fclose(fp);
    for (int i = 0; i <sizeof(Events); i++) 
    {
        if (strstr(Events[i].event, E) != NULL)
        {
            printf("Event found!\n");
            printf("Event date: %s\n", Events[i].date);
            printf("Event Name: %s\n", Events[i].event);
            printf("Venue: %s\n", Events[i].venue);
            printf("Timings: %s\n", Events[i].timings);
            return;
        }
    }
    printf("Event not found\n");
     
}
int register_stud()
{
    char even[20],name[10];
    printf("Enter the event \n");
    scanf("%s",even);
    printf("Enter your name\n");
    scanf("%s",name);
    for( int i=0;i<line-2;i++)
    {
        if(strstr(Events[i].event,even)!=NULL)
        {
           
            strcpy(Events[i].student_name,name);
            return Events[i].st_count++;
        }
    }
}
void display()
{ 
    printf("Details of the registration\n");
    for(int i=0;i<line-2;i++)
    {
        printf("Events name:%s \n",Events[i].event);
        printf("No of students registered for the event : %d\n",Events[i].st_count);
    }
}  