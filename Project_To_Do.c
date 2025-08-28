#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* data;
    struct node*left;
    struct node*right;
}node;

node* createTask(const char *str){
    node *newTask = (node*)malloc(sizeof(node));
    newTask->data = (char*)malloc(strlen(str) + 1);
    // We did + 1 in uppar code because In C, strings are null-terminated, meaning they end with a
    //  \0 character to mark the end. This null terminator isn’t included in the length returned by strlen
    strcpy(newTask->data, str);
    newTask->left = NULL;
    newTask->right = NULL;

    return newTask;
}

node* insertTask(node* root,const char* str){
    if (root == NULL)
    {
        return createTask(str);
    }

    int cmp = strcmp(str,root->data);
    // strcmp is used for comparing strings
    if(cmp < 0){
        root->left = insertTask(root->left,str);
    }
    else if(cmp > 0){
        root->right = insertTask(root->right,str);
    }
    return root;
}

// Funtion to display tasks in order
void displayTasks(node* root){
    if(root!= NULL){
        displayTasks(root->left);
        printf("- %s\n",root->data);
        displayTasks(root->right);
    }
}

node* searchTask(node* root ,const char *str){
    if(root == NULL || strcmp(root->data, str) == 0){
        return root;
    }
    if(strcmp(str,root->data)<0){
        return searchTask(root->left,str);
    }
    return searchTask(root->right, str);
}
void freeTask(node* root){
    if (root != NULL)
    {
        freeTask(root->left);
        freeTask(root->right);
        free(root->data);
        free(root);
    }
    
}

int main(){
    node *root = NULL;
    int choice;
    char task[100];
    
    while(1){
        printf("\nTo-Do list Menu: \n");
        printf("1. Add Task\n");
        printf("2. View Task\n");
        printf("3. Search Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();
        
        // Clear the newline character from input buffer

        switch (choice)
        {
        case 1:
            printf("Enter the task description: ");
            fgets(task, sizeof(task), stdin);
            task[strcspn(task,"\n")] = 0;
            root = insertTask(root, task);
            printf("Task '%s' Added.\n",task );
            break;
        
        case 2:
            printf("\nYou To-Do List: \n");
            if(root == NULL){
                printf("No tasks yet!!! ☹︎ \n");
            }else{
                displayTasks(root);
            }
            break;
        
        case 3:
            printf("Enter task to Search: ");
            fgets(task,sizeof(task),stdin);
            task[strcspn(task,"\n")] = 0;

            node * found = searchTask(root,task);
            
            if(found != NULL){
                printf("Task '%s' found in the list.\n",found->data);
            }
            else{
                printf("Task '%s' not found. \n",root->data);
            }
            break;

            case 4:
            printf("Exiting and freeing memory...\n");
            freeTask(root);
            return 0;

        default:
            printf("Invalid choice! Try again. \n");
    }
    
}
}