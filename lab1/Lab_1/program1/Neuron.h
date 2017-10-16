#pragma once
typedef double(*fun1)(double x, double threshold);

class Neuron
{
public:
	Neuron();
	Neuron(int n);
	Neuron(int n, double *weight);
	~Neuron();

	void setweight(double *m_weight);
	void setweight(double x, int i);
	void setN(int m_n);
	void setactivateFunction(fun1 activateFunction);
	double getweight(int i);
	int getN() { return n; }
	double start(double *m_input);
	double learn(double *input, double output, double ni);



private:
	double *weight;
	int n;
	fun1 activateFunction;
	fun1 pochodna;
	double threshold;
	double b;

	double update(double *m_input);
};

