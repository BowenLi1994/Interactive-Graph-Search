#pragma once
#include "uniform.h"
#include "normal.h"
#include "zipf.h"


namespace random_generator{


void uniform(int min, int max, int num_val,std::vector<int>& result);
void normal(int mean,int stddev,int num_val,std::vector<int>& result);
void zipf(int max, int alpha,int num_val,std::vector<int>& result);


void uniform(int min, int max, int num_val,std::vector<int>& result){

	Dist_Genrator *dist = new Dist_Uniform(min, max, 1);

	for(int i = 0; i < num_val; ++i){
		result.push_back(dist->Next());
	}

	delete dist;

}


void normal(int mean,int stddev,int num_val,std::vector<int>& result){

	Dist_Genrator *dist = new Dist_Normal(mean, stddev, time(NULL));

	for(int i = 0; i < num_val; ++i){

		int temp;
		do{
			temp=dist->Next();
		}
		while(temp<0 || temp > 2* mean-1);


		
		result.push_back(temp);
	}
	delete dist;
}

void zipf(int max, int alpha,int num_val,std::vector<int>& result){

	Dist_Genrator *dist = new Dist_Zipf(max, alpha, false, 1);

	for(int i = 0; i < num_val; ++i){
		int temp;
		do{
			temp=dist->Next();
		}while(temp<0);
		result.push_back(temp);
	}

	delete dist;
}



};