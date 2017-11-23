#pragma once
typedef double(*fun1)(double x, double threshold);

class Neuron
{
public:
	Neuron();
	Neuron(int n);
	Neuron(int n, double *wagi);
	~Neuron();

	void setWagi(double *m_wagi);
	void setWagi(double x, int i);
	void setN(int m_n);
	void setActivatingFunction(fun1 funkcjaAktywuj¹ca);
	double getWagi(int i);
	int getN() { return n; }
	double start(double *m_input);
	double learn(double *input, double output, double ni);



private:
	double *weights;
	int n;
	fun1 activatingFunction;
	double threshold;
	double b;

	double sumowanie(double *m_input);
};

