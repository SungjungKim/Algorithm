/*
        21_maxproduct
        Sungjung Kim
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_SIZE 10000

double product[MAX_SIZE] = {0, };

/*
 * prev: 이전까지 곱해진 값을 저장
 * result: 곱셈을 한 결과값을 저장
 */
void process(int num_product)
{
	double prev, mul, result;
	prev = product[0];
	result = product[0];

	for(int i = 1; i < num_product; i++) {
		if(product[i] > prev * product[i]) prev = product[i];
		else prev *= product[i];

		// update
		if(prev > result) result = prev;
	}	

	printf("%.3f", result);
}


int main(void)
{
	int num_product;
	cin >> num_product;

	for(int i = 0; i < num_product; i++)
		cin >> product[i];
	
	process(num_product);

	return 0;
}
