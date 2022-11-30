#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

	struct student{
		char name[40];
		int midTerm;
		int final;
		struct student *next;
	};
	typedef struct student node;
	node *root,*iter;
	
	node* createList(int x){
		
		for(int i=0;i<x;i++){
			if(i==0){
				root=(node *)malloc(sizeof(node));
				iter=root;
			}
			else{
				iter->next=(node *)malloc(sizeof(node));
				iter=iter->next;
			}
			printf("\nEnter name of %d. student: ",i+1);
			scanf("%s",iter->name);
			printf("\nEnter midterm note of %d. student: ",i+1);
			scanf("%d",&iter->midTerm);
			printf("\nEnter final note of %d. student: ",i+1);
			scanf("%d",&iter->final);
			
		}
		iter->next=NULL;
		return root;
	}
	yazOgrList(){
		FILE *myptr=fopen("Ogrenci.txt","w");
		iter=root;
		
		if(myptr==NULL)
		printf("Dosya Olusturulamadi!");
		
		else{
		fclose(myptr);
		
	    	while(iter != NULL){
	    		 fopen("Öðrenci Listesi.txt","a");
	    		 fprintf(myptr,"Ögrenci adý: %s Vize notu: %d, Final notu: %d, Ortalamasi: %.2f\n\n",iter->name,iter->midTerm,iter->final,iter->final*0.6+iter->midTerm*0.4);
	    		 iter=iter->next;
			     
			}
		system("CLS");
		printf("Veriler Dosyaya aktarildi!");
     	}
    }
	int main(){
		int x;
		
		printf("\nHow many student will you enter the list? ");
		scanf("%d",&x);
		createList(x);
		yazOgrList();
		getchar();
	
	}
