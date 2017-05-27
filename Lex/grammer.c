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
    int i;
    int j;
    int k;
};

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

//flag fflag[100]={0};
int DFA(char *ch,char (*id)[100],int (*num)[100],struct Flag *fflag){
    //puts(ch);
    int i=0; 
    int j=0;
    int k=0;
    int p=0;
    int q=0;
    int r=0;
    int s=0;
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
            fflag[q].a=1;
            fflag[q].b=j+1;
            q++;
            //puts(id[j]);
            //printf("%c",id[0][2]);
            j++;
        }
        else if(ch[i]>47&&ch[i]<58){
            p=0;
            num[k][p]=ch[i]-48;
            //printf("%d",num[k][p]);
            while(ch[i+1]>47&&ch[i+1]<58){
                num[k][p+1]=ch[i+1]-48;
                //printf("%d",num[k][p+1]);
                p++;
                i++;
            }
            printf("<num,%d>\n",k+1);
            fflag[q].a=2;
            //printf("hello");
            fflag[q].b=k+1;
            q++;
            i++;
            k++;
        }
        else if(ch[i]==92){
            if(ch[i+1]=='s'){
                printf("<sum>\n");
                i=i+4;
                fflag[q].a=44;
                q++;
            }
            else if(ch[i+1]=='i'){
                printf("<int>\n");
                i=i+4;
                fflag[q].a=45;
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
            fflag[q].a=4;
            q++;
        }
        else if(ch[i]==')'){
            printf("<)>\n");
            i++;
            fflag[q].a=5;
            q++;
        }
        else if(ch[i]=='{'){
            printf("<{>\n");
            i++;
            fflag[q].a=6;
            //fflag[q].b=x+1;
            //x++;
            q++;
        }
        else if(ch[i]=='}'){
            printf("<}>\n");
            i++;
            fflag[q].a=7;
            //fflag[q].b=y+1;
            //y++;
            q++;
        }
        else if(ch[i]=='_'){
            printf("<_>\n");
            i++;
            fflag[q].a=8;
            fflag[q].b=r+1;
            r++;
            q++;
        }
        else if(ch[i]=='^'){
            printf("<^>\n");
            i++;
            fflag[q].a=9;
            fflag[q].b=s+1;
            s++;
            q++;
        }
        else if(ch[i]==' '){
            printf("<blank>\n");
            i++;
            fflag[q].a=10;
            q++;
        }
        /*else{
            printf("none error");
            exit(1);
        }*/

    }
    return(j);
}

/*int grammer(){
    slink stack=create_stack(100);
    //push_stack(stack,0);
    int i=0;
    int j=0;
    int k=0;
    int ggoto=0;
    while(1){
        if(ggoto==0)
        switch(i){
            case 0:{
                       if(fflag[j]->a==1){
                           i=1;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                           j++;
                       }
                       if(fflag[j]->a==2){
                           i=1;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                           j++;
                       }
                       if(fflag[j]->a==3){
                           i=2;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                           j++;
                       }
                       if(fflag[j]->a==4){
                           i=3;
                           push_stack(stack,fflag[k]->a);
                           push_stack(stack,i);
                           k++;
                           j++;
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
                           
		                       pop_stack(stack);
                               printf("%d",pop_stack(stack));                         
                               printf("-->B\n");
                           
                       }
                       if(fflag[j]->a==2){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                           
                       }
                       if(fflag[j]->a==3){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                          
                       }
                       if(fflag[j]->a==4){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                           
                       }
                       if(fflag[j]->a==5){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                       }
                       if(fflag[j]->a==6){
                           return -1;
                       }
                       if(fflag[j]->a==7){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                       }
                       if(fflag[j]->a==8){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                       }
                       if(fflag[j]->a==9){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                       }
                       if(fflag[j]->a==10){
                           pop_stack(stack);
                               printf("%d",pop_stack(stack) );                         
                               printf("-->B\n");
                       }
                   }
            case 2:{
                       
            }
            case 3:{
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
            }
            case 4:{
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
            }

        }
    }

}*/
void grammer(struct Flag *fflag,int r,int s){
    int i=0,j=0,k=0,z=0;
    int sum1;
    slink sstack=create_stack(100);
    push_stack(sstack,1);
    /*push_stack(sstack,8);
    push_stack(sstack,9);
    printf("stack:%d",sstack->data[sstack->sp]);*/
    while(1){
        //printf("%d",sstack->data[sstack->sp]);
        switch(sstack->data[sstack->sp]){
        case 1:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==44){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,44);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,45);
                i++;break;

            }
            else{
                printf("kaishi cuo wu");
                exit(1);
            }

        }
        case 2:{
            if(fflag[i].a==0){
                return;
            }
            else{
                printf("wer");
                exit(1);
            }
        }
        case 3:{
            //printf("hu:%d",sstack->data[sstack->sp]);
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                i++;break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==5){
                printf("B->T\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,41);break;
            }
            else if(fflag[i].a==0){
                printf("B->T\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,41);break;
            }
            else if(fflag[i].a==7){
                printf("B->T\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,41);break;
            }
            else if(fflag[i].a==44){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,44);
                i++;break;
            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,45);
                i++;break;
            }
            else{
                printf("cuo wujjj");
                exit(1);
            }
        }
        case 4:{
            
            if(fflag[i].a==1){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);            
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==2){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==0){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }           
            else if(fflag[i].a==10){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==4){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==5){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==7){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                //printf("ji:%d",sstack->data[sstack->sp]);
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==9){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,12);
                i++;break;
            }
            else if(fflag[i].a==8){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,11);
                i++;break;
            }
            else if(fflag[i].a==44){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }
            else if(fflag[i].a==45){
                printf("T->R\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);break;
            }
            else{
                printf("cuo wu\n");
                exit(1);break;
            }
        }
        case 5:{
            if(fflag[i].a>=0&&fflag[i].a<=10&&fflag[i].a!=6){
                printf("R->id\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,43);break;
            }
            else if(fflag[i].a==44 || fflag[i].a==45){
                printf("R->id\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,43);break;
            }
            else {
                printf("cuo\n");
                exit(1);
            }
            
        }
        case 6:{
            if(fflag[i].a>0&&fflag[i].a<=10&&fflag[i].a!=6){
                printf("R->num\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,43);
                break;
            }
            else {
                printf("cuoo");
                exit(1);
            }
        }
        case 7:{
            if(fflag[i].a>0&&fflag[i].a<=10&&fflag[i].a!=6){
                printf("R->blank\n");
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,43);break;
            }
            else {
                printf("cuooo");
                exit(1);
            }

        }
        case 8:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                i++;break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==3){

            }
            else{
                printf("kuo wu");
                exit(1);
            }
        }
        case 9:{

        }
        case 10:{
            if(fflag[i].a==5 || fflag[i].a==7){
                printf("B->TB\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                //printf("hyh:%d",sstack->data[sstack->sp]);
                push_stack(sstack,41);break;
            }
            else if(fflag[i].a==0){
                //printf("hyh:%d",sstack->data[(sstack->sp)-1]);
                printf("B->TB\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,41);break;
            }
            else{
                printf("uo");
                exit(1);
            }
        }
        case 11:{
            if(fflag[i].a==6){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,15);
                i++;break;
            }
            else if(fflag[i].a==9){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,14);
                i++;break;
            }
            else {
                printf("cuup");
                exit(1);
            }
        }
        case 12:{
            if(fflag[i].a==6){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,16);
                i++;break;
            }
            else {
                printf("cuuo");
                exit(1);
            }
        }
        case 13:{
            if(fflag[i].a==5){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,17);
                i++;break;
            }
            else {
                printf("cuuo");
                exit(1);
            }
        }
        case 14:{
            if(fflag[i].a==6){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,18);
                i++;break;
            }
            else {
                printf("cuuo");
                exit(1);
            }
        }
        case 15:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                i++;break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else{
                printf("huhuh");
                exit(1);
            }
        }
        case 16:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                i++;break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else{
                printf("huhuh");
                exit(1);
            }
        }
        case 17:{
            if(fflag[i].a>=0 && fflag[i].a<=10 && fflag[i].a!=6){
                printf("R->(B)\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                //printf("huh:%d",sstack->data[sstack->sp]);
                push_stack(sstack,43);break;
            }
            else {
                printf("cuooo");
                exit(1);
            }
        }
        case 18:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                i++;break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else{
                printf("h ");
                exit(1);
            }
        }
        case 19:{
            if(fflag[i].a==7){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,22);
                i++;break;
            }
            else{
                printf("hhh");
                exit(1);
            }
        }
        case 20:{
            if(fflag[i].a==7){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,23);
                i++;break;
            }
            else{
                printf("hhhh");
                exit(1);
            }
        }
        case 21:{
            if(fflag[i].a==7){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,24);
                i++;break;
            }
            else{
                printf("hhhh");
                exit(1);
            }
        }
        case 22:{
            if(fflag[i].a==0||fflag[i].a==1 || fflag[i].a==2 || fflag[i].a==10 || fflag[i].a==4 || fflag[i].a==5 ||fflag[i].a==7){
                printf("T->R_{B}");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                j=i;
                while(1){
                    if(fflag[j].a==8&&fflag[j].b==z+r){
                        printf("%d",z+r);
                        break;
                    }
                    if(fflag[j].a==1||fflag[j].a==2){
                        fflag[j].i+=35;
                        fflag[j].j+=25;
                        fflag[j].k=30;
                        j--;
                    }
                    j--;
                }
                z--;
                push_stack(sstack,42);break;
            }
            else{
                printf("cjcj");
                exit(1);
            }
        }
        case 23:{
            if(fflag[i].a==0||fflag[i].a==1 || fflag[i].a==2 || fflag[i].a==10 || fflag[i].a==4 || fflag[i].a==5 ||fflag[i].a==7){
                printf("T->R^{B}\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);
                j=i;
                //printf("%d",k+s);
                while(1){
                    if(fflag[j].a==9){//&&fflag[j].b==k+s){
                        //printf("%d",k+s);
                        break;
                    }
                    if(fflag[j].a==1||fflag[j].a==2){
                        fflag[j].i-=15;
                        fflag[j].j+=25;
                        fflag[j].k=30;
                        j--;
                    }
                    j--;
                }
                k--;
                //fflag[j-2].i-=15;
                //fflag[j-2].j+=25;
                //fflag[j-2].k=30;
                break;
            }
            else{
                printf("cjcj");
                exit(1);
            }
        }
        case 24:{
            if(fflag[i].a==6){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,25);
                i++;break;
            }
            else{
                printf("iii");
                exit(1);
            }
        }
        case 25:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                i++;break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else{
                printf("huhuhuh");
                exit(1);
            }
        }
        case 26:{
            if(fflag[i].a==7){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,27);
                i++;break;
            }
            else{
                printf("iiif");
                exit(1);
            }
        }
        case 27:{
            if(fflag[i].a==0||fflag[i].a==1 || fflag[i].a==2 || fflag[i].a==10 || fflag[i].a==4 || fflag[i].a==5 ||fflag[i].a==7){
                printf("T->R^_{B}{B}\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                push_stack(sstack,42);
                fflag[i-2].i-=15;
                fflag[i-2].j+=25;
                fflag[i-2].k=30;
                fflag[i-5].i+=35;
                fflag[i-5].j+=25;
                fflag[i-5].k=30;
                break;
            }
            else{
                printf("cjcj");
                exit(1);
            }
        }
        case 41:{
            if(sstack->data[(sstack->sp)-1]==1){
                push_stack(sstack,2);break;
            }
            else if(sstack->data[(sstack->sp)-1]==3){
                push_stack(sstack,10);break;
            }
            else if(sstack->data[(sstack->sp)-1]==8){
                push_stack(sstack,13);break;
            }
            else if(sstack->data[(sstack->sp)-1]==15){
                push_stack(sstack,19);break;
            }
            else if(sstack->data[(sstack->sp)-1]==16){
                push_stack(sstack,20);break;
            }
            else if(sstack->data[(sstack->sp)-1]==18){
                push_stack(sstack,21);break;
            }
            else if(sstack->data[(sstack->sp)-1]==25){
                push_stack(sstack,26);break;
            }
            else if(sstack->data[(sstack->sp)-1]==46){
                push_stack(sstack,47);break;
            }
            else if(sstack->data[(sstack->sp)-1]==49){
                push_stack(sstack,50);break;
            }
            else if(sstack->data[(sstack->sp)-1]==52){
                push_stack(sstack,53);break;
            }
            else if(sstack->data[(sstack->sp)-1]==55){
                push_stack(sstack,56);break;
            }
            else if(sstack->data[(sstack->sp)-1]==58){
                push_stack(sstack,59);break;
            }
            else if(sstack->data[(sstack->sp)-1]==61){
                push_stack(sstack,62);break;
            }
            else{
                printf("wrong");
                exit(1);
            }

        }
        case 42:{
            //printf("hh:%d",sstack->data[(sstack->sp)]);
            if(sstack->data[(sstack->sp)-1]==1){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==3){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==8){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==15){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==16){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==18){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==25){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==46){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==49){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==52){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==55){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==58){
                push_stack(sstack,3);break;
            }
            else if(sstack->data[(sstack->sp)-1]==61){
                push_stack(sstack,3);break;
            }
            else{
                printf("xihoo");
                exit(1);
            }
        }
        case 43:{
            if(sstack->data[(sstack->sp)-1]==1){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==3){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==8){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==15){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==16){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==18){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==25){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==46){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==49){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==52){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==55){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==58){
                push_stack(sstack,4);break;
            }
            else if(sstack->data[(sstack->sp)-1]==61){
                push_stack(sstack,4);break;
            }

        }
        case 44:{
            if(fflag[i].a==6){
                fflag[i].i=1;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,46);
                i++;
                break;
            }
            else {
                printf("sum kuo hao cuo wu");
                exit(1);
            }
        }
        case 45:{
            if(fflag[i].a==6){
                fflag[i].i=4;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,55);
                i++;
                break;
            }
            else {
                printf("int kuo hao cuo wu");
                exit(1);
            }

        }
        case 46:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else if(fflag[i].a==46){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else{
                printf("sum kuo hao nei cuo wu");
                exit(1);
            }
        }
        case 47:{
            if(fflag[i].a==7){
                //fflag[i].b=1;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,48);
                i++;
                break;
            }
            else {
                printf("sum you kuo hao cuo wu");
                exit(1);
            }
        }
        case 48:{
            if(fflag[i].a==6){
                fflag[i].i=2;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,49);
                i++;
                break;
            }
            else {
                printf("sum zuo kuo hao cuo wu");
                exit(1);
            }
        }
        case 49:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else if(fflag[i].a==46){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else{
                printf("sum kuo hao nei cuo wu");
                exit(1);
            }

        }
        case 50:{
            if(fflag[i].a==7){
                //fflag[i].b=2;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,51);
                i++;
                break;
            }
            else {
                printf("sum you2 kuo hao cuo wu");
                exit(1);
            }
        }
        case 51:{
            if(fflag[i].a==6){
                fflag[i].i=3;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,52);
                i++;
                break;
            }
            else {
                printf("sum zuo3 kuo hao cuo wu");
                exit(1);
            }
        }
        case 52:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else if(fflag[i].a==46){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else{
                printf("sum kuo hao nei cuo wu");
                exit(1);
            }
        }
        case 53:{
            if(fflag[i].a==7){
                //fflag[i].b=3;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,54);
                i++;
                break;
            }
            else {
                printf("sum you3 kuo hao cuo wu");
                exit(1);
            }
        }
        case 54:{
            if(fflag[i].a==0||fflag[i].a==1 || fflag[i].a==2 || fflag[i].a==10 || fflag[i].a==4 || fflag[i].a==5 ||fflag[i].a==7){
                printf("T->sum{B}{B}{B}\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                j=i;
                while(1){
                    if(fflag[j].a==44){
                        break;
                    }
                    
                    while(fflag[j].i!=3){
                        //printf("%d",fflag[j].i);
                        j--;
                        
                    }
                    j--;
                    while(fflag[j].i!=2){
                        if(fflag[j].a==1||fflag[j].a==2){
                            fflag[j].i-=30;
                            fflag[j].j+=25;
                            fflag[j].k=30;
                        }
                        j--;
                        
                    }
                    j--;
                    while(fflag[j].i!=1){
                        if(fflag[j].a==1||fflag[j].a==2){
                            fflag[j].i+=50;
                            fflag[j].j+=25;
                            fflag[j].k=30;
                        }
                        j--;
                    }
                    j--;
                }
                push_stack(sstack,42);
                break;
            }
            else{
                printf("cjcj");
                exit(1);
            }
        }
        case 55:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else if(fflag[i].a==46){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else{
                printf("int kuo hao nei cuo wu");
                exit(1);
            }
        }
        case 56:{
            if(fflag[i].a==7){
                //fflag[i].b=4;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,57);
                i++;
                break;
            }
            else {
                printf("int you kuo hao cuo wu");
                exit(1);
            }

        }
        case 57:{
            if(fflag[i].a==6){
                fflag[i].i=5;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,58);
                i++;
                break;
            }
            else {
                printf("int zuo kuo hao cuo wu");
                exit(1);
            }
        }
        case 58:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else if(fflag[i].a==46){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else{
                printf("int kuo hao nei cuo wu");
                exit(1);
            }
        }
        case 59:{
            if(fflag[i].a==7){
                //fflag[i].b=5;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,60);
                i++;
                break;
            }
            else {
                printf("int you2 kuo hao cuo wu");
                exit(1);
            }

        }
        case 60:{
            if(fflag[i].a==6){
                fflag[i].i=6;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,61);
                i++;
                break;
            }
            else {
                printf("int zuo3 kuo hao cuo wu");
                exit(1);
            }

        }
        case 61:{
            if(fflag[i].a==1){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,5);
                i++;
                break;
            }
            else if(fflag[i].a==2){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,6);
                //printf("%d",sstack->data[sstack->sp]);
                i++;
                break;
            }
            else if(fflag[i].a==10){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,7);
                i++;break;
            }
            else if(fflag[i].a==4){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;

            }
            else if(fflag[i].a==45){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else if(fflag[i].a==46){
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,8);
                i++;break;
            }
            else{
                printf("int kuo hao nei cuo wu");
                exit(1);
            }
        }
        case 62:{
            if(fflag[i].a==7){
                //fflag[i].b=6;
                push_stack(sstack,fflag[i].a+30);
                push_stack(sstack,63);
                i++;
                break;
            }
            else {
                printf("int you2 kuo hao cuo wu");
                exit(1);
            }
        }
        case 63:{
            if(fflag[i].a==0||fflag[i].a==1 || fflag[i].a==2 || fflag[i].a==10 || fflag[i].a==4 || fflag[i].a==5 ||fflag[i].a==7){
                printf("T->int{B}{B}{B}\n");
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                pop_stack(sstack);
                j=i;
                while(1){
                    if(fflag[j].a==45){
                        break;
                    }
                    while(fflag[j].i!=6){
                        j--;
                        
                    }
                    j--;
                    while(fflag[j].i!=5){
                        if(fflag[j].a==1||fflag[j].a==2){
                            fflag[j].i-=30;
                            fflag[j].j+=25;
                            fflag[j].k=30;
                        }
                        j--;
                        
                    }
                    j--;
                    while(fflag[j].i!=4){
                        if(fflag[j].a==1||fflag[j].a==2){
                            fflag[j].i+=50;
                            fflag[j].j+=25;
                            fflag[j].k=30;
                        }
                        j--;
                    }
                    j--;
                }
                push_stack(sstack,42);
                break;
            }
            else{
                printf("cjcj");
                exit(1);
            }
        }

    }
    }
}
 
 
 int main(){
     struct Flag fflag[100]={0};
     char id[100][100]={0};
     int num[100][100]={0};
     FILE *fp,*fk;
     //int flag[100];
     int i=0;
     int j=0;
     int k=0;
     int z=0;
     int x=0;
     int max8=0,max9=0;
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
     
     
     x=DFA(ch,id,num,fflag);
     for(i=0;i<x;i++){
         puts(id[i]);
     }
     i=0;
     x=0;
     /*while(num[i][0]!=0){
         while(num[i][x]!=0){

         printf("%d",num[i][x]);
         x++;
         }
         printf("\n");
         x=0;
         i++;
     }*/
     //printf("%d",num[1][0]);
     //grammer();
     //i=0;
     /*while(flag[i]!=0){
         printf("%d ",flag[i]);
         i++;
     }*/

     /*while(fflag[i].a!=0){
         printf("%d  ",fflag[i].a);
         printf("%d\n",fflag[i].b);
         i++;
     }*/
     i=0;
     while(fflag[i].a!=0){
         if(fflag[i].a==8){
             if(max8<fflag[i].b){
                 max8=fflag[i].b;
             }
             i++;
         }
         else if(fflag[i].a==9){
             if(max9<fflag[i].b){
                 max9=fflag[i].b;
             }
             i++;
         }
         else 
             i++;
     }
     i=0;
     //printf("rf:%d %d",max8,max9);
     /*while(fflag[i].a!=0){
         if(fflag[i].a==1){
             fflag[i].i=175;
             fflag[i].j=500;
             fflag[i].k=50;
             i++;
         }
         else if(fflag[i].a==2){
             fflag[i].i=175;
             fflag[i].j=500;
             fflag[i].k=50;
             i++;
         }
         else if(fflag[i].a==4){
             fflag[i].i=175;
             fflag[i].j=500;
             fflag[i].k=50;
             i++;
         }
         else if(fflag[i].a==5){
             fflag[i].i=175;
             fflag[i].j=500;
             fflag[i].k=50;
             i++;
         }
         else
             i++;
     }*/
     grammer(fflag,max8,max9);
     i=0;
     while(fflag[i].a!=0){
         printf("%d  ",fflag[i].a);
         printf("%d  ",fflag[i].b);
         printf("%d  ",fflag[i].i);
         printf("%d  ",fflag[i].j);
         printf("%d\n",fflag[i].k);
         i++;
     }
     i=0;j=0;k=1;z=1;
     if((fk=fopen("output.html","w"))==NULL){
         printf("don't exist html");
         exit(1);
     }
     //char *string="<html><head><META content='text/html; charset=gb2312'></head><body>";
     fputs("<html><head><META content='text/html; charset=gb2312'></head><body>",fk);
     while(fflag[i].a!=0){
     if(fflag[i].a==1){
         fputs("<div style='position: absolute; top:",fk);
         fprintf(fk,"%d",fflag[i].i+175);
         fputs("px; left:",fk);
         if(fflag[i].j==0){
             fprintf(fk,"%d",500+k*25);
             k++;
         }
         else{
         fprintf(fk,"%d",fflag[i].j+500+k*25);
         k++;}
         fputs("px;'><span style='font-size:",fk);
         if(fflag[i].k==0){
             fputs("50",fk);
         }
         else
         fprintf(fk,"%d",fflag[i].k);
         
         fputs("px; font-style:",fk);
         fputs("oblique",fk);
         fputs("; lineheight:100%;'>",fk);
         while(id[(fflag[i].b)-1][j]!=0){
             fprintf(fk,"%c",id[fflag[i].b-1][j]);
             j++;

         }
         j=0;
         //printf("hu");
         i++;
         fputs("</span></div>",fk);
         }
     //fputs("; lineheight:100%;'>",fk);
     else if(fflag[i].a==2){
         fputs("<div style='position: absolute; top:",fk);
         fprintf(fk,"%d",fflag[i].i+175);
         fputs("px; left:",fk);
         if(fflag[i].j==0){
             fprintf(fk,"%d",500+k*25);
             k++;
         }
         else{
         fprintf(fk,"%d",fflag[i].j+500+k*25);
         k++;}
         fputs("px;'><span style='font-size:",fk);
         if(fflag[i].k==0){
             fputs("50",fk);
         }
         else
         fprintf(fk,"%d",fflag[i].k);
         fputs("px; font-style:",fk);
         fputs("normal",fk);
         fputs("; lineheight:100%;'>",fk);
         while(num[(fflag[i].b)-1][j]!=0){
             fprintf(fk,"%d",num[fflag[i].b-1][j]);
             j++;}
        j=0;
        i++;
        fputs("</span></div>",fk);
        }
    else if(fflag[i].a==44){
        fputs("<div style='position: absolute; top:",fk);
            fputs("175px; left:",fk);
            fprintf(fk,"%d",500+k*25);
            fputs("px;'><span style='font-size:50px; font-style:normal; lineheight:100%;'>∑",fk);
            //fprintf(fk,"%c","∑");
            fputs("</span></div>",fk);
            k++;
            i++;
    }
    else if(fflag[i].a==45){
        fputs("<div style='position: absolute; top:",fk);
            fputs("175px; left:",fk);
            fprintf(fk,"%d",500+k*25);
            fputs("px;'><span style='font-size:50px; font-style:normal; lineheight:100%;'>∫",fk);
            k++;
            i++;
             fputs("</span></div>",fk);
    }
    else if(fflag[i].a==10){
        fputs("<p>  </p>",fk);
        i++;
    }
    else 
            //printf("huhu");
            i++;
     }
     fputs("</body></html>",fk);

     fclose(fk);










     return(1);
 
 }

