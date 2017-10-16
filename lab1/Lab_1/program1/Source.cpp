#include <iostream>
#include "Neuron.h"
#include <ctime>

using namespace std;

void testuj(Neuron *neuron, double **inputs );
double learn(Neuron *neuron, double** inputs, double *outputs, int n, double ni);


double activateFunction(double x, double threshold)
{
	if (x >= threshold)
		return 1;
	else
		return 0;
}

int main()
{

	double **inputs = new double*[4];
	for (int i = 0; i < 4; i++)
		inputs[i] = new double[2];
	
	inputs[0][0] = 0; 	inputs[0][1] = 0;
	inputs[1][0] = 0; 	inputs[1][1] = 1;
	inputs[2][0] = 1; 	inputs[2][1] = 0;
	inputs[3][0] = 1; 	inputs[3][1] = 1;
	double outputs[4] = { 0,0,0,1 };







	double e=1;
	int i;

		Neuron *neuron1 = new Neuron(2);
		Neuron *neuron2 = new Neuron(2);
		Neuron *neuron3 = new Neuron(2);
		Neuron *neuron4 = new Neuron(2);
		Neuron *neuron5 = new Neuron(2);
		Neuron *neuron6 = new Neuron(2);

		neuron1->setactivateFunction(activateFunction);
		neuron2->setactivateFunction(activateFunction);
		neuron3->setactivateFunction(activateFunction);
		neuron4->setactivateFunction(activateFunction);
		neuron5->setactivateFunction(activateFunction);
		neuron6->setactivateFunction(activateFunction);

		
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron1, inputs, outputs, 4, 0.005));
		}
		cout << i << " ilosc cykli\n";

		e = 1;
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron2, inputs, outputs, 4, 0.015));
		}
		cout << i << " ilosc cykli\n";

		e = 1;
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron3, inputs, outputs, 4, 0.3));
		}
		cout << i << " ilosc cykli\n";
		e = 1;
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron4, inputs, outputs, 4, 0.7));
		}
		cout << i << " ilosc cykli\n";
		e = 1;
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron5, inputs, outputs, 4, 1));
		}
		cout << i << " ilosc cykli\n";
		e = 1;
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron5, inputs, outputs, 4, 3));
		}
		cout << i << " ilosc cykli\n";
		e = 1;
		for (i = 0; e > 0; i++)
		{
			(e = learn(neuron6, inputs, outputs, 4, 7));
		}
		cout << i << " ilosc cykli\n";
		//delete neuron1;
		//delete neuron2;
		//delete neuron3;
		//delete neuron4;
		//delete neuron5;
		//delete neuron6;
	



	system("pause");
	return 0;
}





void testuj(Neuron *neuron, double **inputs)
{
	cout << "0: " << neuron->start(inputs[0]) << endl;
	cout << "0: " << neuron->start(inputs[1]) << endl;
	cout << "0: " << neuron->start(inputs[2]) << endl;
	cout << "1: " << neuron->start(inputs[3]) << endl;

}

double learn(Neuron *neuron, double** inputs, double *outputs, int n, double ni)
{
	double error1=0, error=0;
	bool *T = new bool[n];
	for (int i = 0; i < n; i++)
	{
		T[i] = false;
	}
	int j;
	for (int i = 0; i < n; i++)
	{

		j = rand()%n;
		while (T[j] == true)
		{
			j = rand() % n;
		}
		T[j] = true;
		error1 = 0;
		error1+=neuron->learn(inputs[j], outputs[j], ni);
		error += error1*error1;
	}

	return error/2;
}