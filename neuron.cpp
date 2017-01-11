#include "neuron.h"
/*====================Constructors and destructors====================*/
neuron::neuron(){
	learningRate = 0.1f;
	bias = 0.0f;
	activationFunction = NULL;
	sigmoidActivationFunctionFlag = true;
}


/*==============================Getters===============================*/
vector<Connection> neuron::getInConnections(){
	return inConnections;
}
vector<Connection> neuron::getOutConnections(){
	return outConnections;
}
int neuron::getQuantInConnections(){
	return inConnections.size();
}
int neuron::getQuantOutConnections(){
	return outConnections.size();
}
float neuron::getBias(){
	return bias;
}
float neuron::getLearningRate(){
	return learningRate;
}
bool neuron::isSigmoidActivationFunction(){
	return sigmoidActivationFunctionFlag;
}
float neuron::getOut(){
	return out;
}
float neuron::getError(){
	return error;
}
int neuron::getId(){
	return id;
}


/*==============================Setters===============================*/
void neuron::setActivationFunction(float (*function)(float)){
	activationFunction = function;
	sigmoidActivationFunctionFlag = false;
}
void neuron::setLearningRate(float lr){
	learningRate = lr;
}
void neuron::setBias(float b){
	bias = b;
}
void neuron::setSigmoidActivationFunction(bool s){
	sigmoidActivationFunctionFlag = s;
}
void neuron::setOut(float o){
	out = o;
}
void neuron::setError(float e){
	error = e;
}
void neuron::setId(int i){
	id = i;
}


/*===========================Class methods============================*/
void neuron::addInConnection(Connection temp){
	inConnections.push_back(temp);
}
void neuron::addOutConnection(Connection temp){
	outConnections.push_back(temp);
}
void neuron::addInConnection(void* neuron, float weight){
	if (neuron == NULL){
		cout << "(neuron - addInConnection) Connection neuron with null pointer" << endl;
		exit(1);
	}
	if(weight < 0){
		cout << "(neuron - addInConnection) Invalid weight" << endl;
		exit(1);
	}
	Connection temp;
	temp.connectedNeuron = neuron;
	temp.connectionWeight = weight;
	addInConnection(temp);
}
void neuron::addOutConnection(void* neuron, float weight){
	if (neuron == NULL){
		cout << "(neuron - addOutConnection) Connection neuron with null pointer" << endl;
		exit(1);
	}
	if(weight < 0){
		cout << "(neuron - addOutConnection) Invalid weight" << endl;
		exit(1);
	}
	Connection temp;
	temp.connectedNeuron = neuron;
	temp.connectionWeight = weight;
	addOutConnection(temp);
}
void neuron::removeInConnectionByIndex(int index){
	if(index < inConnections.size())
		inConnections.erase(inConnections.begin() + index);
	else{
		cout << "(neuron - removeInConnectionByIndex) Out of range, its not possible remove" << endl;
		exit(1);
	}
	return;
}
void neuron::removeOutConnectionByIndex(int index){
	if(index < outConnections.size())
		outConnections.erase(outConnections.begin() + index);
	else{
		cout << "(neuron - removeOutConnectionByIndex) Out of range, its not possible remove" << endl;
		exit(1);
	}
	return;
}
float neuron::sigmoidActivationFunction(float x){
	float beta = learningRate;
	float sigmoid = 1.0f/( 1.0 + exp(-beta*x));
	return sigmoid;
}
float neuron::sigmoidDerivate(float x){
	return x * (1 - x);
}
void neuron::calcOut(){
	float sum = 0;
	for(int i = 0; i < inConnections.size(); i++){
		neuron * aux;
		float weight =  inConnections[i].connectionWeight;
		aux = (neuron*)inConnections[i].connectedNeuron;
		float x = (*aux).getOut();
		sum += x;
	}

	sum += bias;

	if(isSigmoidActivationFunction()){
		setOut(sigmoidActivationFunction(sum));
	}else{
		setOut(activationFunction(sum));
	}
}