/*
	Function to find minimum value the Data
*/
float minimum(float *data, int records) {

float swap;
int i,j;
	for( i = 0 ; i < ( records - 1 ); i++) {
		for ( j = 0 ; j < records - i - 1; j++) {
			if (*(data + j) > *(data + j + 1)){
			swap = *(data + j);
        	*(data + j)   = *(data + j + 1);
        	*(data + j + 1) = swap;
     		}
    	}
	}
	return *(data + 0);
//	printf("\nMinimum Value of the Data: %0.2f", *(data + 0)); // Minimum Value 
//	printf("Maximum Value of the Data: %0.2f\n ", *(data + records -1)); // Maximum Value
//	printf("\nRange of the Data: %0.2f\n", (*(data + records - 1) - *(data + 0))); // Range(Max. - Min.)
}

//function to find maximum value
float maximum(float *data, int records) {

float swap;
int i,j;
	for ( i = 0 ; i < ( records - 1 ); i++) {
		for ( j = 0 ; j < records - i - 1; j++) {
			if (*(data + j) > *(data + j + 1)){
			swap = *(data + j);
        	*(data + j)   = *(data + j + 1);
        	*(data + j + 1) = swap;
     		}
    	}
	}
	return *(data + records-1);
//	printf("\nMinimum Value of the Data: %0.2f", *(data + 0)); // Minimum Value 
//	printf("Maximum Value of the Data: %0.2f\n ", *(data + records -1)); // Maximum Value
//	printf("\nRange of the Data: %0.2f\n", (*(data + records - 1) - *(data + 0))); // Range(Max. - Min.)
}

/* 
	Function to Calculate Median of the Data
*/

float median(float *data, int records) {
	float oddcase = *(data + records/2);
	float evencase = ((*(data + records/2) + *(data + records/2 - 1))/2.0);
	
	if(records%2 != 0){  //if number of records is odd
		return oddcase; //printf("Median of the Data is %.2f\n", oddcase);
	}
	else {	// if number of records is even
		return evencase; //printf("Median of the Data is %.2f\n", evencase);
	}
}

/* 
	Function to Calculate Mean of the Data
*/

float mean(float *data, int records) {
	float sum, mean;
	int i;
	for( i = 0; i < records; i++){
		sum = sum + *(data+i);
	}
	mean = sum/(float)records;
	return mean;
	
} 

/* 
	Function to Calculate Variance of the Data
*/

float variance(float *data, int records) {
	float sum=0.0, sum1=0.0, mean;
	int i;
	for( i = 0; i < records; i++){
		sum = sum + *(data+i);	  	// Calculating Mean
	}
	mean = sum/(float)records;
	for( i = 0; i < records; i++){
		sum1 = sum1 + pow((*(data + i) - mean), 2);
	} 
	//float var1 = sum1/(float)records; // variance for the entire population
	float var2 = sum1/((float)records - 1.0); //variance for the sample of the population
	//float std1 = sqrt(var1); //standard deviation for the entire population
	float std2 = sqrt(var2); //standard deviation for the sample of the population
	
	//printf("\nActual Variance of the Data: %.3f",var1);
	//printf("\nVariance of the Data: %.3f",var2);
	//printf("\nActual Standard Deviation of the Data: %.3f", std1);
	//printf("\nStandard Deviation of the Data: %.3f", std2);
	return var2;
}
/*
	Function to Calculate Standard Deviation of the Data
*/
float std(float *data, int records) {
	float sum=0.0, sum1=0.0, mean;
	int i;
	for( i = 0; i < records; i++){
		sum = sum + *(data+i);	  	// Calculating Mean
	}
	mean = sum/(float)records;
	for( i = 0; i < records; i++){
		sum1 = sum1 + pow((*(data + i) - mean), 2);
	} 
	//float var1 = sum1/(float)records; // variance for the entire population
	float var2 = sum1/((float)records - 1.0); //variance for the sample of the population
	//float std1 = sqrt(var1); //standard deviation for the entire population
	float std2 = sqrt(var2); //standard deviation for the sample of the population
	
	//printf("\nActual Variance of the Data: %.3f",var1);
	//printf("\nVariance of the Data: %.3f",var2);
	//printf("\nActual Standard Deviation of the Data: %.3f", std1);
	//printf("\nStandard Deviation of the Data: %.3f", std2);
	return std2;
}

/*
	Function to Calculate Kurtosis of the Data
*/

float kurt(float *data, int records) {
	float p11 = (records*(records+1)); //Numerator part1   
	float p12 = ((records-1)*(records-2)*(records-3)); //Denominator part1
	float part1 = p11/p12;  //part1
	float p31 = (3*pow(records-1,2));  //Numerator part3
	float p32 = ((records-2)*(records-3)); //Denominator part3
	float part3 = p31/p32;  //part3
	float sum=0.0, sum1=0.0, p21=0.0, mean;
	int i;
	for( i = 0; i < records; i++){
		sum = sum + *(data+i);	  	
	}
	mean = sum/(float)records;		//  Mean
	
	for( i = 0; i < records; i++){
		sum1 = sum1 + pow((*(data + i) - mean), 2);
	} 
	float var1 = sum1/((float)records - 1.0); // variance 
	float std = sqrt(var1); //standard deviation 
	float p22 = pow(std,4);  // Denominator part2
	
	for( i = 0; i < records; i++) {
		p21= p21 + pow((*(data + i) - mean), 4); //Numerator part2
	} 
	
	float part2 = p21/p22; //part2
	float kurt = ((part1*part2) - part3); //Kurtosis
	return kurt;
}

/* 
	Function to Calculate Skewness of the Data 
*/

float skew(float *data, int records){
	float p11 = records; //numerator of part1
	float p12 = ((records-1)*(records-2)); //denominator of part1
	float part1 = p11/p12; //part1
	float sum=0.0, sum1=0.0, p21=0.0, mean;
	int i;
	for( i = 0; i < records; i++){
		sum = sum + *(data+i);	  	
	}
	mean = sum/(float)records;		//  Mean
	
	for( i = 0; i < records; i++){
		sum1 = sum1 + pow((*(data + i) - mean), 2);
	} 
	float var1 = sum1/((float)records - 1.0); // variance 
	float std = sqrt(var1); //standard deviation 
	float p22 = pow(std,3);  // Denominator part2
	
	for( i = 0; i < records; i++) {
		p21= p21 + pow((*(data + i) - mean), 3); //Numerator part2
	}
	
	float part2 = p21/p22; //part2
	float skew = part1*part2;
	
	return skew;
}

/* 
	Function to Calculate Mode of the Data 


void mode(float *data, int record) {
	int i,j,mode=0,k,max=0,c;
	float b[100] = {0};    
	for (i = 0; i < record - 1; i++){
		mode = 0;
		for (j = i + 1; j < record; j++){
		 	if (*(data+i) == *(data+j)) {
				mode++;
            }
	    }

        if ((mode > max) && (mode != 0)) {
            k = 0;
            max = mode;
			b[k] = *(data+i);
			k++;
        }
		else if (mode == max) {
			b[k] = *(data+i);
		    k++;
        }
	}

    for (i = 0; i < record; i++){
		if (*(data+i) == b[i]) 
	        c++;
	    }
	    if (c == record)
		    printf("\nThere is no mode");
        else {
        	printf("\nMode\t= ");
			for (i = 0; i < k; i++)
	            printf("%f ",b[i]);
		}
        printf("\n");
}
*/

void mode(float *data, int N) {

    int maxValue = 0, maxCount = 0, i, j;

 

    for (i = 0; i < N; ++i) {

        int count = 0;

        for (j = 0; j < N; ++j) {

            if (*(data+j) == *(data+i))
                ++count;

        }

        if (count > maxCount) {

            maxCount = count;

            maxValue = *(data+i);

        }

    }

 

    printf("%f",maxValue);

}	


	
