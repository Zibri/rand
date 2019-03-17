/*****************************************************************************
Very fast random generator streaming output on stdout.
Example usage:
./rand | ffplay -fs -f rawvideo -pixel_format rgb24 -video_size 1920x1080 -framerate 60 -
./rand | ffplay -fs -f rawvideo -pixel_format gray -video_size 1920x1080 -framerate 60 -
./rand|ffplay -f u8 -ar 48000 -ac 1 -

on my pc the bandwidth is about 1.2 GB/sec :D
*****************************************************************************/  

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fastrand.h"


int main() {


	fastrand fr;

	uint32_t prngSeed[8];

	uint16_t * sptr = (uint16_t *) prngSeed;



	for (uint8_t i = 0; i < 8; i++)

	{

		prngSeed[i] = rand();

	}



	InitFastRand(sptr[0], sptr[1], 
	sptr[2], sptr[3], 
	sptr[4], sptr[5], 
	sptr[6], sptr[7], 
	sptr[8], sptr[9], 
	sptr[10], sptr[11], 
	sptr[12], sptr[13], 
	sptr[14], sptr[15], 
	&fr);


  int res[32];
	while (1)

	{

		FastRand_SSE4(&fr);
		res[0]=fr.res[0];
		res[1]=fr.res[1];
		res[2]=fr.res[2];
		res[3]=fr.res[3];
		FastRand_SSE4(&fr);
		res[4]=fr.res[0];
		res[5]=fr.res[1];
		res[6]=fr.res[2];
		res[7]=fr.res[3];
		FastRand_SSE4(&fr);
		res[8]=fr.res[0];
		res[9]=fr.res[1];
		res[10]=fr.res[2];
		res[11]=fr.res[3];
		FastRand_SSE4(&fr);
		res[12]=fr.res[0];
		res[13]=fr.res[1];
		res[14]=fr.res[2];
		res[15]=fr.res[3];
		FastRand_SSE4(&fr);
		res[16]=fr.res[0];
		res[17]=fr.res[1];
		res[18]=fr.res[2];
		res[19]=fr.res[3];
		FastRand_SSE4(&fr);
		res[20]=fr.res[0];
		res[21]=fr.res[1];
		res[22]=fr.res[2];
		res[23]=fr.res[3];
		FastRand_SSE4(&fr);
		res[24]=fr.res[0];
		res[25]=fr.res[1];
		res[26]=fr.res[2];
		res[27]=fr.res[3];
		FastRand_SSE4(&fr);
		res[28]=fr.res[0];
		res[29]=fr.res[1];
		res[30]=fr.res[2];
		res[31]=fr.res[3];
		fwrite(&res, 128, 1, stdout);

	}

}
