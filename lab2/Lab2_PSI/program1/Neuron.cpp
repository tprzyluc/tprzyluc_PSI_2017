#include "Neuron.h"
#include <cstdlib>
#include <iostream>
#include <ctime>




double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

Neuron::Neuron()
{
	weights = NULL;
	activatingFunction = NULL;

	threshold = 0;
	b = 0;
}

Neuron::Neuron(int m_n) :
	n(m_n)
{

	threshold = 0;
	b = 0;
	activatingFunction = NULL;

	weights = new double[n];
	
	for (int i = 0; i < n; i++)
	{
		weights[i] = fRand(-0.5, 0.5);
	}
}

Neuron::Neuron(int m_n, double *m_wagi) :
	n(m_n),
	weights(m_wagi)
{
	threshold = 0;
	activatingFunction = NULL;

	b = 0;
}

void Neuron::setWagi(double *m_wagi)
{
	weights = m_wagi;
}

void Neuron::setWagi(double x, int i)
{
	if (weights != NULL && i < n)
	{
		weights[i] = x;
	}
	else
	{
		throw "error-setWagi";
	}
}

void Neuron::setN(int m_n)
{
	n = m_n;
	weights = new double[n];

	for (int i = 0; i < n; i++)
	{
		weights[i] = fRand(-0.5, 0.5);
	}
}

void Neuron::setActivatingFunction(fun1 m_funkcjaAktywuj¹ca)
{
	activatingFunction = m_funkcjaAktywuj¹ca;
}

double Neuron::getWagi(int i)
{
	if (weights != NULL && i < n)
	{
		return weights[i];
	}
	else
	{
		throw "error-getWagi";
	}
}

double Neuron::start(double *m_inputs)
{
	if (activatingFunction == NULL)
		throw "ustaw funkcje aktywujaca!";
	double a = sumowanie(m_inputs);
	return activatingFunction(a, threshold);

}

double Neuron::learn(double * input, double output, double ni)
{


	double result = this->start(input);
	double error = output - result;
	if (result != output)
	{
		for (int i = 0; i < n; i++)
		{
			weights[i] += ni*error*input[i];
		}
		b += ni*error;

	}

	return error;
}

double Neuron::sumowanie(double *m_input)
{

	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += weights[i] * m_input[i];
	}

	return suma+b;
}

Neuron::~Neuron()
{
	delete weights;
}
