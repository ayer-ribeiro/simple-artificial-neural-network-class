#include "gLib.h"
#include "neuron.h"

class artificialNeuralNetwork{

	private:
		int quantLayers;
		int quantIn;
		int quantOut;
		int quantNeurons;
		vector<neuron> in;
		vector<neuron> out;
		vector< vector<neuron> > neurons;
		float learningRate;
		int lastId;


	public:
		/*Constructors and destructors*/
		artificialNeuralNetwork();

		/*Getters*/
		int getQuantLayers();
		int getQuantIn();
		int getQuantOut();
		float* getOut();
		
		/*Setters*/
		void setQuantLayers(int);
		void setQuantIn(int);
		void setQuantOut(int);
		void setLayers(int*);
		void setLearningRate(float);
		

		/*Class methods*/
		float getRandonWeight();
		void addNeurons(neuron, int);
		void setIn(float*);
		void propagateIn();
		void mount();



		vector< vector<neuron> >  gambi();
		

};



