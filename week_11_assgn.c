#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{

    struct userword
    {
        char inputword[32];
        struct userword *next;

    };

    typedef struct userword USER_INPUT;
    typedef struct userword* USER_INPUT_PTR;

    USER_INPUT_PTR head = NULL;
    char inputholder[33];

   

    //code logic for user entering
    while (1)
    {
        
        USER_INPUT *newnode = (USER_INPUT *)malloc(sizeof(USER_INPUT));
        newnode->next = NULL;
        

        //clear inputholder
        for(int i = 0; i < sizeof(inputholder) ; i++)
            inputholder[i] = '\000';

        printf("Please enter a word:\n");
        scanf("%s",inputholder);

        //check to break for ***
        if(inputholder[0] == '*' && inputholder[1] == '*' && inputholder[2] == '*')
        {//free malloc once breaking out of the loop
            free(newnode);
            printf("All the entered words in order:\n");
            break;
        }
        //input checks for letter, apos , hyphen and null char
        for(int i = 0; i < sizeof(inputholder) ; i++)
        {
            if(inputholder[i] == '\000')
                {
                    newnode->inputword[i] = '\000';
                    break;
                }    
            if( isalpha(inputholder[i]) == 0 && (inputholder[i] != '\''  || inputholder[i] != '-' || inputholder[i] != '\000' ) )
                {
                    printf("Invalid input detected! Please only enter letters, apostrophes and hyphens!\n");
                    break;
                }
            else
                {
                    inputholder[i] = tolower(inputholder[i]);
                    newnode->inputword[i] = inputholder[i];
                }
        }

        //if head is null means first time adding a node to the linked list
        if(head == NULL)
        {
            head = newnode;
        }

        //else put it at the end of the list
        else
        {
            USER_INPUT* temp = head;

            
            //current pointer word higher ascii value than the next
            while (1)
            {                    
                //(temp!= NULL && strcmp(newnode->inputword, temp->inputword) > 0 )
                if(strcmp(newnode->inputword, temp->inputword) > 0)
                {
                    if(temp->next != NULL)
                    {
                        if(strcmp(newnode->inputword, temp->next->inputword) > 0)
                        {
                            temp = temp->next;
                        }
                        else
                        {
                            newnode->next = temp->next;
                            temp->next = newnode;
                            break;
                        }     
                    }
                    if(temp->next == NULL)
                    {
                        temp->next = newnode;
                        break;
                    }
                    
                }

                else
                {
                    if(temp == head)
                    {head=newnode;}

                    newnode->next = temp;
                    break;
                }
                            
            }   
            
        }
        
        
    };


    //printing whatever values i have
    USER_INPUT* temp2 = head;
    while (temp2 != NULL)
    {   
        for (int i = 0; sizeof(temp2->inputword); i++)
            if(temp2->inputword[i] == '\000')
                break;
            else
                printf("%c",temp2->inputword[i]);
        printf("\n");
        temp2 = temp2->next;
    }
    
    

    return 0;
}