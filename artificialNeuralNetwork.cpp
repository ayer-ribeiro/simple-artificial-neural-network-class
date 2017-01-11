#include "artificialNeuralNetwork.h"
/*====================Constructors and destructors====================*/
artificialNeuralNetwork::artificialNeuralNetwork(){
	quantLayers = 1;
	quantIn = 0;
	quantOut = 0;
	quantNeurons = 0;
	lastId = 0;
	//out.setId(lastId++);
}


/*==============================Getters===============================*/
int artificialNeuralNetwork::getQuantLayers(){
	return quantLayers;
}
int artificialNeuralNetwork::getQuantIn(){
	return quantIn;
}
int artificialNeuralNetwork::getQuantOut(){
	return quantOut;
}
float* artificialNeuralNetwork::getOut(){
	float * networkOut;
	networkOut = (float*)malloc(sizeof(float)*quantOut);
	for(int i = 0; i< quantOut; i++){
		networkOut[i] = out[i].getOut();
	}
	return networkOut;
}


/*==============================Setters===============================*/
void artificialNeuralNetwork::setQuantLayers(int quant){
	if(quant == 0){
		cout << "(artificialNeuralNetwork - setQuantLayers) quantLayers most be greater then 0" << endl;
		exit(1);
	}
	neurons.clear();
	quantLayers = quant;
	neurons.clear();
	for(int i = 0; i < quantLayers; i++){
		vector<neuron> vn;
		vn.clear();
		neurons.push_back(vn);
	}
}
void artificialNeuralNetwork::setQuantIn(int q){
	quantIn = q;
	in.clear();
	for(int i = 0; i< quantIn; i++){
		neuron aux;
		aux.setId(lastId++);
		in.push_back(aux);
	}
}
void artificialNeuralNetwork::setQuantOut(int q){
	quantOut = q;
	out.clear();
	for(int i = 0; i< quantOut; i++){
		neuron aux;
		aux.setId(lastId++);
		out.push_back(aux);
	}
}
void artificialNeuralNetwork::setLayers(int* layers){
	for(int i = 0; i < quantLayers; i++){
		if(layers[i] == 0){
			cout << "(artificialNeuralNetwork - setLayers) layer cant have zero neurons" << endl;
			exit(1);
		}
	}
	for(int i = 0; i< quantLayers; i++){
		for(int j = 0; j< layers[i]; j++){
			neuron temp;
			addNeurons(temp,i);
		}
	}
}
void artificialNeuralNetwork::setLearningRate(float lr){
	learningRate = lr;
}


/*===========================Class methods============================*/
float artificialNeuralNetwork::getRandonWeight(){
	return 1;
}
void artificialNeuralNetwork::addNeurons(neuron temp, int layer){
	temp.setId(lastId++);
	neurons[layer].push_back(temp);
}
void artificialNeuralNetwork::setIn(float* networkIn){
	for(int i = 0; i<quantIn; i++){
		in[i].setOut(networkIn[i]);
	}
}
void artificialNeuralNetwork::propagateIn(){
	for(int i  = 0; i< quantLayers; i++){
		for(int j = 0; j< neurons[i].size(); j++){
			neurons[i][j].calcOut();
		}
	}
	for(int i = 0;i < out.size(); i++){
		out[i].calcOut();
	}
}

void artificialNeuralNetwork::mount(){
	for(int j = 0; j < in.size(); j++){
		for(int i = 0; i< neurons[0].size(); i++){
			Connection a;
			neuron *aux;
			float tempWeight = getRandonWeight();
			aux = &in[j];
			a.connectedNeuron = &neurons[0][i];
			a.connectionWeight = tempWeight;
			(*aux).addOutConnection(a);

			aux =  &neurons[0][i];
			a.connectedNeuron = &in[j];
			a.connectionWeight = tempWeight;
			(*aux).addInConnection(a);
		}
	}
	for(int i = 0; i< quantLayers -1 ; i++){
		for(int j = 0; j<neurons[i].size(); j++){
			for(int k = 0; k<neurons[i+1].size(); k++){
				Connection a;
				neuron *aux;

				aux = &neurons[i][j];
				a.connectedNeuron = &neurons[i+1][k];
				a.connectionWeight = getRandonWeight();
				(*aux).addOutConnection(a);

				aux = &neurons[i+1][k];
				a.connectedNeuron = &neurons[i][j];
				(*aux).addInConnection(a);
			}
		}
	}
	for(int i = 0; i < neurons[neurons.size()-1].size(); i++){
		for(int j = 0; j < out.size(); j++){
			Connection a;
			neuron *aux;
			float tempWeight = getRandonWeight();

			aux = &neurons[neurons.size()-1][i];
			a.connectedNeuron = &out[j];
			a.connectionWeight = tempWeight;
			(*aux).addOutConnection(a);

			aux = &out[j];
			a.connectedNeuron = &neurons[neurons.size()-1][i];
			a.connectionWeight = tempWeight;
			(*aux).addInConnection(a);
		}
	}
	/*
	CONSERTAR
	for(int i = 0; i < neurons[neurons.size()-1].size(); i++){

		Connection a;
		neuron *aux;
		float tempWeight = getRandonWeight();

		aux = &neurons[neurons.size()-1][i];
		a.connectedNeuron = &out;
		a.connectionWeight = tempWeight;
		(*aux).addOutConnection(a);

		aux = &out;
		a.connectedNeuron = &neurons[neurons.size()-1][i];
		a.connectionWeight = tempWeight;
		(*aux).addInConnection(a);
	}
	*/
}


vector< vector<neuron> >  artificialNeuralNetwork::gambi(){
	return neurons;
}