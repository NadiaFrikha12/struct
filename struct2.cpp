//remplir un tableau de structure

#include<stdio.h>
#include<stdlib.h>

//declaration de la structure
struct etudiant {
	char* nom;
	char* prenom;
	int age;
	int CIN;
};

typedef struct etudiant student;

int main(){
	student* p; //pointeur de structure 
	int n;
	printf("donner le nombre d'etudiant");
	scanf("%d",&n);
	
	//allouer la memoire pour n etudtiant 
	p=(student*)malloc(n*sizeof(student));
	if(p==NULL){
		printf("erreur");
		return 0;
	}
	else{
		
		for(int i=0; i<n; i++){ //remplir la structure par les donnees des n etudiants
			
			p[i].nom=(char*)malloc(10*sizeof(char)); //allouer la memoire pour le nom de l'ième etudiant
			if(p[i].nom==NULL){ //liberer la memoire pour prévenir la fuite de memoire
				for(int j=0; j<i; j++){ //liberer le contenu de la structure
					if (p[j].nom != NULL){
						free(p[j].nom);
					}
					if (p[j].prenom != NULL){
						free(p[j].prenom);
					}
				}
				if (p!=NULL){ //liberer la memoire de la structure
					free(p);
				}
			}
			else{
				printf("donner le nom: ");
				scanf("%s",p[i].nom);
					
			}
			
			p[i].prenom=(char*)malloc(10*sizeof(char)); //allouer la memoire pour le prenom de l'ième etudiant
			if(p[i].prenom==NULL){ //liberer la memoire 
				for(int j=0; j<i; j++){
					if (p[j].nom != NULL){
						free(p[j].nom);
					}
					if (p[j].prenom != NULL){
						free(p[j].prenom);
					}
				}
				if (p!=NULL){
					free(p);
				}
			}
			else{
				printf("\ndonner le prenom: ");
				scanf("%s",p[i].prenom);	
			}
			
			printf("\ndonner l'age: "); 
			scanf("%d",p[i].age); //remplir la case i de structure par l'age de l'ième etudiant 
			printf("\ndonner la CIN: ");
			scanf("%d",p[i].CIN); //remplir la case i de structure par le numéro de la CIN de l'ième etudiant 
		}		
	}
	
	//liberer la mémoire pour prévenir la fuite de memoire	
	if (p!=NULL){
		for(int i=0; i<n; i++){
			if (p[i].nom != NULL){
				free(p[i].nom);
			}
			if (p[i].prenom != NULL){
				free(p[i].prenom);
			}
		}
	free(p);
	}
	
		
	return 0;
}
