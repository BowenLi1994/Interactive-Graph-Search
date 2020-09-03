#pragma once
#include "uniform.h"


namespace random_generator{


void uniform();

void uniform(){
    

	Dist_Genrator *dist = new Dist_Uniform(0, 100, 1);

	for(int i = 0; i < 100; ++i){
		fprintf(stderr, "%lu\n", dist->Next());
	}

	fprintf(stderr, "%s\n", dist->Name().c_str());

	delete dist;

}






};