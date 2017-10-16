#include "Neuron.h"
#include <cstdlib>
#include <iostream>
#include <ctime>



double losuj(double Min, double Max)
{
	double f = (double)rand() / RAND_MAX;
	return Min + f * (Max - Min);
}

Neuron::Neuron()
{
	weight = NULL;
	activateFunction = NULL;
	srand(time(NULL));
	threshold = 0;
	b = 0;
}

Neuron::Neuron(int m_n) :
	n(m_n)
{
	activateFunction = NULL;
	srand(time(NULL));
	threshold = 0;
	b = 0;
	weight = new double[n];
	for (int i = 0; i < n; i++)
	{
		weight[i] = losuj(-0.5, 0.5);
	}
}

Neuron::Neuron(int m_n, double *m_weight) :
	n(m_n),
	weight(m_weight)
{
	threshold = 0;
	activateFunction = NULL;
	srand(time(NULL));
	b = 0;
}

void Neuron::setweight(double *m_weight)
{
	weight = m_weight;
}

void Neuron::setweight(double x, int i)
{
	if (weight != NULL && i < n)
	{
		weight[i] = x;
	}
	else
	{
		throw "error-setweight";
	}
}

void Neuron::setN(int m_n)
{
	n = m_n;
	
}

void Neuron::setactivateFunction(fun1 m_activateFunction)
{
	activateFunction = m_activateFunction;
}

double Neuron::getweight(int i)
{
	if (weight != NULL && i < n)
	{
		return weight[i];
	}
	else
	{
		throw "error-getweight";
	}
}

double Neuron::start(double *m_inputs)
{
	if (activateFunction == NULL)
		throw "ustaw funkcje aktywujaca!";
	double a = update(m_inputs);
	return activateFunction(a, threshold);

}

double Neuron::learn(double * input, double output, double ni)
{


	double result = this->start(input);
	double error = output - result;
	if (result != output)
	{
		for (int i = 0; i < n; i++)
		{
			weight[i] += ni*error*input[i];
		}
		b += ni*error;

	}

	return error;
}

double Neuron::update(double *m_input)
{

	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += weight[i] * m_input[i];
	}

	return suma+b;
}

Neuron::~Neuron()
{
	delete weight;
}
