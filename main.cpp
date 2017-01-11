//	

#include "gLib.h"
#include "artificialNeuralNetwork.h"
using namespace std;

int main(){

	artificialNeuralNetwork rede;
	int vet[3] = {2,2,3};
	float in[4] = {1,2,3,4};

	rede.setQuantLayers(3);
	rede.setQuantIn(4);
	rede.setQuantOut(2);
	rede.setLayers(vet);
	rede.mount();

	rede.setIn(in);
	rede.propagateIn();

	float * saida = rede.getOut();
	for(int i = 0; i< rede.getQuantOut(); i++){
		cout << saida[i] << " ";
	}
	cout << endl;

	/*
	vector<vector<neuron> > v;
	v = rede.gambi();
	for(int i = 0; i< v.size();i++){
		for(int j = 0; j < v[i].size(); j++){
			cout << v[i][j].getId() << endl;
			cout << "Connected with:" << endl;
			cout << "in: ";
			for(int k = 0; k < v[i][j].getInConnections().size(); k++){
				neuron *aux;
				Connection a = (Connection)v[i][j].getInConnections()[k];
				aux = (neuron*)a.connectedNeuron;
				cout << (*aux).getId() << " ";
			}
			cout << endl;
			cout << "out: ";
			for(int k = 0; k < v[i][j].getOutConnections().size(); k++){
				neuron *aux;
				Connection a = (Connection)v[i][j].getOutConnections()[k];
				aux = (neuron*)a.connectedNeuron;
				cout << (*aux).getId() <<  " ";
			}
			cout << endl;
		}
	}
	*/

	return 0;
}
