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
	int i, j, k=0, kk=25, first=1,tors=0;
	
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
	
		
	while(fgets(l, 500, f )){ 
		k++;
		for(i=0;i<strlen(l) && first;i++){//first title to set the base
			if(first && l[i] == 't'){
				if(l[i+1] == 'i' && l[i+2]=='t'){
					first=0;
					break;
				}
			}	
		}
		if(!first && kk == k){
			if(!tors){//get title
				kk+=12;//go to status
				for(j=27;j<strlen(l);j++){
					if(l[j]!=']'){
						mgname[j-27]=l[j];
					}
					else break;
				}
				printf("%s \n",mgname);
				tors=1;
			}
			else if(tors) {//get status
				printf("%c%c%c%c%c ",l[16],l[17],l[18],l[19],l[20],l[21]);
				kk+=14;//go to title
				tors=0;
				//save status file
				if(l[16]=='R'){
					fprintf(r,"%s",mgname);
					fprintf(r,"\n");
				}
				else if(l[16]=='C'){
					fprintf(c,"%s",mgname);
					fprintf(c,"\n");
				}
				else if(l[16]=='P'){
					fprintf(w,"%s",mgname);
					fprintf(w,"\n");
				}
				else if(l[16]=='H'){
					fprintf(h,"%s",mgname);
					fprintf(h,"\n");
				}
				else if(l[16]=='D'){
					fprintf(d,"%s",mgname);
					fprintf(d,"\n");
				}
				
				for(j=0;j<100;j++) mgname[j] = 0;
			}
		}
		//printf("\n");
	}
	
	
	
	fclose(r);
	fclose(f);
	fclose(w);
	fclose(h);
	fclose(d);
	fclose(c);
	return 0;
}
