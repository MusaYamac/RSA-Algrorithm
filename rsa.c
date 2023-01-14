/*
 * rsa.c
 *
 *  Created on: Jan 3, 2023
 *      Author: kadir.yamac
 */

#include <rsa.h>

extern int encd;
extern int solo;
extern int dycd;
extern int payint;
extern int decrypted[];


void encrypt(int input){
	int temp = input;
	int i = PublicKey;
	int res = 1;     // Initialize result

	input = input % N; // Update x if it is more than or
	// equal to p

	while (i > 0)
	{
		// If y is odd, multiply x with result
		if (i & 1)
			res = (res*input) % N;

		// y must be even now
		i = i>>1; // y = y/2
		input = (input*input) % N;
	}
	encd = res;

}

void decrypt(int input){
	int temp = input;
	int i = PrivateKey;
	int res = 1;     // Initialize result

	input = input % N; // Update x if it is more than or
	// equal to p

	while (i > 0)
	{
		// If y is odd, multiply x with result
		if (i & 1)
			res = (res*input) % N;

		// y must be even now
		i = i>>1; // y = y/2
		input = (input*input) % N;
	}
	decrypted[payint]= res;

}
