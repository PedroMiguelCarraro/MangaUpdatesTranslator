#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	
	FILE *f = NULL; //Input
	FILE *r = NULL; //Reading
	FILE *c = NULL; //Complete
	FILE *w = NULL; //Waiting aka Plan to Read
	FILE *h = NULL; //On Hold
	FILE *d = NULL; //Dropped
	
	char l[500], mgname[100];
	char t[] = "title", s[] = "status";
	int i,j,k,fg,pass,temp,ext;
	
	f = fopen("mangalist.xml", "r"); //Input
	r = fopen("list_read.txt", "w");  //Output Reading
	c = fopen("list_comp.txt", "w");  //Output Complete
	w = fopen("list_wait.txt", "w");  //Output Waiting aka PlantoRead
	h = fopen("list_hold.txt", "w");  //Output On Hold
	d = fopen("list_drop.txt", "w");  //Output Dropped
	 
	if(f == NULL){
		printf("ERRO trying to open Input\n");
		fclose(f);
	}
	
	if(r == NULL){ printf("ERRO trying to create ROutput\n");
		fclose(r);}
	if(c == NULL){ printf("ERRO trying to create COutput\n");
		fclose(c);}
	if(w == NULL){ printf("ERRO trying to create WOutput\n");
		fclose(w);}
	if(h == NULL){ printf("ERRO trying to create HOutput\n");
		fclose(h);}
	if(d == NULL){ printf("ERRO trying to create DOutput\n");
		fclose(d);}
	
	pass=0; temp=0;
	while(fgets(l, 500, f )){ 
		for(i=0;i<strlen(l);i++){
			if(l[i] == 't' && !pass){
				fg=1;
				for(j=i, k=0; j<i+5 && k<5; j++, k++){
					if(l[j] != t[k]){fg=0;}
				}
				if(fg && k==5 /*&& l[j-11] == '<' */){
					j+=10;
					printf("l[j] = %c\n",l[j]);
					while(l[j] != ']'){
						mgname[j] = l[j];
						//printf("%s %c\n", mgname);
						j++;	
					}
					ext=j;
					mgname[j]='\n';
					pass=1;
				}
				
			}/*
			if(l[i] == 's' && pass){
				fg=1;
				for(j=i, k=0; j<i+6 && k<6; j++, k++){
					if(l[j] != s[k]){fg=0;}
				}
				if(fg && k==6 && l[j-11] == '<' ){
					temp=l[j+2];
					//printf("AQUI2\n");
					//printf("%s %c\n",mgname, temp);
				}
				k=0;
				
				//printf("%s %c\n",mgname, temp);
				
				switch(temp){
					case 'R':
						while(k < ext){
						fprintf(r,"%c",mgname[k]);
						k++;	
					}fprintf(r,"\n");
					break;
					
					case 'C':
						while(k < ext){
						fprintf(r,"%c",mgname[k]);
						k++;	
					}fprintf(r,"\n");
					break;
					
					case 'P':
						while(k < ext){
						fprintf(r,"%c",mgname[k]);
						k++;	
					}fprintf(r,"\n");
					break;
					
					case 'O':
						while(k < ext){
						fprintf(r,"%c",mgname[k]);
						k++;	
					}fprintf(r,"\n");
					break;
					
					case 'D':
						while(k < ext){
						fprintf(r,"%c",mgname[k]);
						k++;	
					}fprintf(r,"\n");
					break;
						
				}
				pass=0;
			}*/
		}
	}
	
	
	fclose(r);
	fclose(f);
	return 0;
}
