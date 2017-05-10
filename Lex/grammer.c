 #include <stdio.h>
 #include <stdlib.h>


struct Stack{
	int capability;
	int sp;
	int *data;
};
typedef struct Stack *slink;

struct Flag{
    int a;
    int b;
};
typedef struct Flag *flag;

slink create_stack(int capability){
	slink stack=malloc(sizeof(struct Stack));
	if(!stack)
		return stack;
	stack->capability=capability;
	stack->sp=-1;
	stack->data=malloc(sizeof(int)*capability);
	return stack;
}

int empty(slink stack){
	return stack->sp==-1;
}

int full(slink stack){
	return stack->sp==stack->capability-1;
}

void push_stack(slink stack,int item){
	stack->data[++stack->sp]=item;
}

int pop_stack(slink stack){
	if(empty(stack))
		return -1;
	return stack->data[stack->sp--];
} 

static flag fflag[100]={0};
int DFA(char *ch,char (*id)[100],int (*num)[100]){
    //puts(ch);
    int i=0; 
    int j=0;
    int k=0;
    int p=0;
    int q=0;
    while(ch[i]!='\0'){
        if((ch[i]>64&&ch[i]<91)||(ch[i]>96&&ch[i]<123)){
            p=0;
            id[j][p]=ch[i];//printf("%c",ch[i]);
            while((ch[i+1]>64&&ch[i+1]<91)||(ch[i+1]>96&&ch[i+1]<123)||(ch[i+1]>47&&ch[i+1]<58)){
                id[j][p+1]=ch[i+1];
                p++;
                //printf("%c",id[j][i]);
                i++;
            }
            i++;
            printf("<id,%d>\n",j+1);
            fflag[q]->a=1;
            fflag[q]->b=j+1;
            q++;
            //puts(id[j]);
            //printf("%c",id[0][2]);
            j++;
        }
        else if(ch[i]>47&&ch[i]<58){
            p=0;
            num[k][p]=ch[i]-48;
            while(ch[i+1]>47&&ch[i+1]<58){
                num[k][p+1]=ch[i+1]-48;
                p++;
                i++;
            }
            printf("<num,%d>\n",k+1);
            fflag[q]->a=2;
            fflag[q]->b=k+1;
            q++;
            i++;
            k++;
        }
        else if(ch[i]==92){
            if(ch[i+1]=='s'){
                printf("<sum>\n");
                i=i+4;
                fflag[q]->a=3;
                q++;
            }
            else if(ch[i+1]=='i'){
                printf("<int>\n");
                i=i+4;
                fflag[q]->a=3;
                q++;
            }
            else{
                printf("xie error");
                exit(1);
            }
            //printf("<xie>\n");
            //i++;
        }
        else if(ch[i]=='('){
            printf("<(>\n");
            i++;
            fflag[q]->a=4;
            q++;
        }
        else if(ch[i]==')'){
            printf("<)>\n");
            i++;
            fflag[q]->a=5;
            q++;
        }
        else if(ch[i]=='{'){
            printf("<{>\n");
            i++;
            fflag[q]->a=6;
            q++;
        }
        else if(ch[i]=='}'){
            printf("<}>\n");
            i++;
            fflag[q]->a=7;
            q++;
        }
        else if(ch[i]=='_'){
            printf("<_>\n");
            i++;
            fflag[q]->a=8;
            q++;
        }
        else if(ch[i]=='^'){
            printf("<^>\n");
            i++;
            fflag[q]->a=9;
            q++;
        }
        else if(ch[i]==' '){
            printf("<blank>\n");
            i++;
            fflag[q]->a=10;
            q++;
        }
        /*else{
            printf("none error");
            exit(1);
        }*/

    }
    return(j);
}

int grammer(){
    slink stack=create_stack(20);
    //push_stack(stack,0);
    int i=0;
    int j=0;
    int k=0;
    int ggoto=0;
    while(1){
        switch(i){
            case 0:{
                       if(fflag[j]->a==1){
                           i=1;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                       }
                       if(fflag[j]->a==2){
                           i=1;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                       }
                       if(fflag[j]->a==3){
                           i=2;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                       }
                       if(fflag[j]->a==4){
                           i=3;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                       }
                       if(fflag[j]->a==5){
                           return -1;
                       }
                       if(fflag[j]->a==6){
                           return -1;
                       }
                       if(fflag[j]->a==7){
                           return -1;
                       }
                       if(fflag[j]->a==8){
                           return -1;
                       }
                       if(fflag[j]->a==9){
                           return -1;
                       }
                       if(fflag[j]->a==10){
                           return -1;
                       }
                       ggoto=4;  
                   }
            case 1:{
                       if(fflag[j]->a==1){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                           
                       }
                       if(fflag[j]->a==2){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                           
                       }
                       if(fflag[j]->a==3){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                          
                       }
                       if(fflag[j]->a==4){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                           
                       }
                       if(fflag[j]->a==5){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                       }
                       if(fflag[j]->a==6){
                           return -1;
                       }
                       if(fflag[j]->a==7){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                       }
                       if(fflag[j]->a==8){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                       }
                       if(fflag[j]->a==9){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                       }
                       if(fflag[j]->a==10){
                           while(!empty(stack)){
		               pop_stack(stack);
                               printf("%d\n",pop_stack(stack) );
                           }
                           printf("-->B");
                       }
                   }

        }
    }

}

 
 
 int main(){
     char id[100][100]={0};
     int num[100][100]={0};
     FILE *fp;
     //int flag[100];
     int i=0;
     int x=0;
     char ch[100];
     if((fp=fopen("test.txt","r"))==NULL){
         printf("don't exist");
         exit(1);
     }
     while(1){
         fscanf(fp,"%c",&ch[i]);
         if(ch[i]=='$'){
             //ch[i]=fgetc(fp);
             break;
         }
         if(ch[i]==EOF){
             ch[i]='\0';
         }
     }
     i=0;
     while(ch[i]!=EOF){
         fscanf(fp,"%c",&ch[i]);
         if(ch[i]=='$'){
             ch[i]='\0';//ch[i]=fgetc(fp);
             break;
         }
         i++;
     }
     
     
     x=DFA(ch,id,num);
     for(i=0;i<x;i++){
         puts(id[i]);
     }
     i=0;
     x=0;
     while(num[i][0]!=0){
         while(num[i][x]!=0){

         printf("%d",num[i][x]);
         x++;
         }
         printf("\n");
         x=0;
         i++;
     }
     //printf("%d",num[1][0]);
     //grammer();
     //i=0;
     /*while(flag[i]!=0){
         printf("%d ",flag[i]);
         i++;
     }*/
     return(1);
 
 
 }

