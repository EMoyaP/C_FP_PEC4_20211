/*
* File: main.c
* Author: Eugenio Moya
* Course: 20211
* Descripción: PEC4 2021 1
*/

/* System header files */
#include <stdio.h>
#include <stdbool.h>


/* Global constants */
#define MIN_COWORKCENTERS 1   		//Min. Number of cowork centers
#define MAX_COWORKCENTERS 5   		//Max. Number of cowork centers
#define MAX_COWORKERS 2			    //Max. number of coworkers
#define MAX_DISTANCE 5.0			//Max. acceptable distance
#define MAX_PRICE 100.0             //Max. acceptable price


/* User defined types */
typedef enum {STARTUPS, FREELANCERS, RURAL, SPECIALIZED, GENERALIST} tCoworkingType;


/* Main function */
int main(int argc, char **argv) {
	
	/* Declaracition of variables */
	int coworkCenterIdVector[MAX_COWORKCENTERS];
	tCoworkingType coworkTypeVector[MAX_COWORKCENTERS];
	float priceVector[MAX_COWORKCENTERS];
	float distanceFromCityCenterVector[MAX_COWORKCENTERS];
	bool hasKitchenVector[MAX_COWORKCENTERS];
	int i;                         //índice
	int l; 							//índice
	int numCoworkCenters;
	tCoworkingType coworkType;
	int acceptableCoworkCentersList[MAX_COWORKCENTERS]; 
	int numAcceptableCoworkCenters = 0;  
	int intToBool;

	/* Data input */
    /* Exercise 2.1 */
	printf("INPUT DATA\n");
    printf("NUMBER OF COWORK CENTERS ? (1-5) >> \n");
    scanf("%d",&numCoworkCenters);    //num. of cowork centers in the city
    
	/*Data validation*/
    while ((numCoworkCenters < MIN_COWORKCENTERS) || (numCoworkCenters > MAX_COWORKCENTERS))  {
        printf("INVALID DATA, TRY AGAIN!\n");
		printf("NUMBER OF COWORK CENTERS ? (1-5) >> \n");
        scanf("%d",&numCoworkCenters);
    }
	
	/*Exercise 2.2*/    
    for (i=0; i<numCoworkCenters; i++) {
        printf("CENTER #%d\n",i+1);
		printf("ID? (AN INTEGER) >>\n");
        scanf("%d",&coworkCenterIdVector[i]);
        printf("TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
        scanf("%u",&coworkTypeVector[i]);
        printf("PRICE [EUR]? (A REAL) >>\n");
        scanf("%f",&priceVector[i]);
        printf("DISTANCE FROM CITY CENTER [KM]? (A REAL) >> \n");
        scanf("%f",&distanceFromCityCenterVector[i]);
        printf("HAS KITCHEN? (0-FALSE, 1-TRUE) >>\n");
        scanf("%d",&intToBool);
		hasKitchenVector[i] = (bool)intToBool;
    }
	
	/*Exercise 2.3*/
	printf("LOOKING FOR CENTERS\n");
    printf("TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
    scanf("%u",&coworkType);
    
	/*Data processing*/
    /*Exercise 2.4*/
	l=0;
   	for (i=0; i<numCoworkCenters; i++) {
		if ((coworkTypeVector[i]==coworkType) && (distanceFromCityCenterVector[i] < MAX_DISTANCE) &&(priceVector[i] <= MAX_PRICE) &&(hasKitchenVector[i] == 1)){
			acceptableCoworkCentersList[l]=coworkCenterIdVector[i];
			numAcceptableCoworkCenters++;
			l++;		
        }        
	}

	/* Data output */
    /* Exercise 2.5 */
	printf("RESULTS\n");
		
		if (numAcceptableCoworkCenters >= 1) {
			printf("NUMBER OF ACCEPTABLE CENTERS: %d\n", numAcceptableCoworkCenters);
			for (i=0; i<numAcceptableCoworkCenters; i++) {
			printf("CENTER ID: %d\n",acceptableCoworkCentersList[i]);
			}
		}else{
			printf("THERE ARE NO ACCEPTABLE CENTERS.\n");
		}
	
	return 0;
}

