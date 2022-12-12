// FUNCTIONS

//ADMIN MAIN MENU FUNCTIONS

// FUNCTIONS

#include <stdio.h>
#include <stdlib.h>
#include "..\dataTypes.h"
#include <string.h>
#include "..\macros.h"

//Global Variables
extern u8 patientCounter;
extern u8 pwordFlag;
extern patient *patientsNodeHead;
//Functions Prototypes
int login();
void getMode();
void adminMode();
void userMode();
void terminate(u8 opText[50]);
void addNewPatient();
patient *getLastNodeAddress();
void displayAll();
void editPatientNode();
patient *getEnteredIDAddress(u32 userInput);



void addNewPatient(){
	
	system("cls");
	// Variable declaration
		u8 age=0;
	u8 name[50];
	u8 gender[10];
	patient *newPatient=NULL;
	
	// Creating New Node
	newPatient=(patient*)malloc(sizeof(patient));
	
	//SECTION1
	printf("\n=====================================  ENTER PATIENT DATA =====================================\n\n");

	        patientCounter++;
			
			printf("\t\t\t NAME:");
			scanf("%s",&name);
			
			printf("\t\t\t AGE: ");
			scanf("%d",&age);
			
			printf("\t\t\t GENDER: ");
			scanf("%s",&gender);
		
		
		newPatient->id=patientCounter+1000;
		newPatient->name[0]=name;
		newPatient->next=NULL;
		newPatient->age=age;
		newPatient->gender[0]=gender;
	
	printf("\nFirst Patient Address=%d",newPatient);
	
	
	if(!patientsNodeHead){
		
		printf("\nif(!patientsNodeHead) ENTERED");
		patientsNodeHead=newPatient;
		printf("\npatientsNodeHead=%d",patientsNodeHead);
	}
	else{
		printf("\nELSE ENTERD");
		patient *lastNodeAddress=getLastNodeAddress();
		
		lastNodeAddress->next=newPatient;
		printf("\nlaseNodeAddress=%d\nlastNodeAddress->next=%d",lastNodeAddress,lastNodeAddress->next);
	}
  
	adminMode();
}



patient *getLastNodeAddress(){
	
	patient *lastNodeAddress=patientsNodeHead;
	
	while(lastNodeAddress->next!=NULL){
		
		lastNodeAddress=lastNodeAddress->next;
	}
	
	//printf("lastNodeAddress Returned from the Function: ID:%d NAME:%s  GENDER: %s  age:%d  NEXT:%d",lastNodeAddress->id,lastNodeAddress->name[0],lastNodeAddress->gender[0],lastNodeAddress->age,lastNodeAddress->next);
	return lastNodeAddress;
}

void displayAll(){
	
	//Variables Declaration and init
	patient *lastNodeAddress=patientsNodeHead;
	u8 c=1;
	
	
		while(lastNodeAddress->next!=NULL){	
	printf("\n\n\n\n==================================== PATIENT %d ==================================\n\n",c);
	printf("\nADDRESS:%d\nID: %d\nNAME:%s\nGENDER:%s\nAGE:%d\nNEXT:%d",lastNodeAddress,lastNodeAddress->id,lastNodeAddress->name[0],lastNodeAddress->gender[0],lastNodeAddress->age,lastNodeAddress->next);
		
	printf("\n\n\n\n==================================== PATIENT %d ==================================",c);
    lastNodeAddress=lastNodeAddress->next;
	c++;
	}
	
	
	
	printf("\n\n\n\n==================================== PATIENT %d ==================================\n\n",c);
	printf("\nADDRESS:%d\nID: %d\nNAME:%s\nGENDER:%s\nAGE:%d\nNEXT:%d",lastNodeAddress,lastNodeAddress->id,lastNodeAddress->name[0],lastNodeAddress->gender[0],lastNodeAddress->age,lastNodeAddress->next);
		
	printf("\n\n\n\n==================================== PATIENT %d ==================================",c);

u8 i;



printf("\n\t\t\t 1 To Proceed");
printf("\nInput Box:");
scanf("%d",&i);
if(i==1)adminMode();
}


void editPatientNode(){
    u32 userInput=0;	
    u8 name[50];
	u8 gender[10];
	u8 age=0;
	printf("=================================== ENTER PID ===================================\n\n\n");
    printf("\t\t\t\t\tID: \n");
	scanf("%d",&userInput);
	
	patient *enteredIDAddress=getEnteredIDAddress(userInput);
	
	//printf("ADDRESS:%d\nID:%d\nNAME:%d\n",EnteredIDAddress,EnteredIDAddress->id,EnteredIDAddress->name[0]);
	
	printf("\n=====================================  ENTER PATIENT DATA =====================================\n\n");
	printf("================================ PID: %d ===============================\n\n\n",enteredIDAddress->id);

	      
			
			printf("\t\t\t NAME:");
			scanf("%s",&name);
			
			printf("\t\t\t AGE: ");
			scanf("%d",&age);
			
			printf("\t\t\t GENDER: ");
			scanf("%s",&gender);
		
		
	
		enteredIDAddress->name[0]=name;
	
		enteredIDAddress->age=age;
		enteredIDAddress->gender[0]=gender;
	
	printf("\n NEW ENTERIES\nID:%d\nNAME: %d\nGENDER:%d",enteredIDAddress->id,enteredIDAddress->name[0],enteredIDAddress->gender[0]);
	
	u8 i;
	printf("\nPRESS 1 TO PROCCEED: ");
	scanf("%d",&i);
	
	adminMode();
}

patient *getEnteredIDAddress(u32 userInput){
	u8 flag=False;
	patient *currentNode=patientsNodeHead;
	
	while(flag==False){
	if(currentNode->id==userInput){flag=True;break;}

	currentNode=currentNode->next;
	
	if(currentNode->next==NULL)break;
	}
	return currentNode;
}