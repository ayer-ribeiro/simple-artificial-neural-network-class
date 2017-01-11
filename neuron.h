#include "gLib.h"

typedef struct structConnection{
	void * connectedNeuron;
	float connectionWeight;
}Connection;

class neuron{
	
	private:
		vector<Connection> inConnections;
		vector<Connection> outConnections;
		float bias;
		float (*activationFunction)(float);
		float learningRate;
		bool sigmoidActivationFunctionFlag;
		float out;
		float error;
		int id;

	public:
		/*Constructors and destructors*/
		neuron();

		/*Getters*/
		vector<Connection> getInConnections();
		vector<Connection> getOutConnections();
		int getQuantInConnections();
		int getQuantOutConnections();
		float getBias();
		float getLearningRate();
		bool isSigmoidActivationFunction();
		float getOut();
		float getError();
		int getId();
		
		/*Setters*/
		void setActivationFunction(float (*)(float));
		void setLearningRate(float);
		void setBias(float);
		void setSigmoidActivationFunction(bool);
		void setOut(float);
		void setError(float);
		void setId(int);

		/*Class methods*/	
		void addInConnection(Connection);
		void addOutConnection(Connection);
		void addInConnection(void*,float);
		void addOutConnection(void*,float);
		void removeInConnectionByIndex(int);
		void removeOutConnectionByIndex(int);
		float sigmoidActivationFunction(float);
		float sigmoidDerivate(float);
		//float unitStepActivationFunction(float);
		void calcOut();

};




