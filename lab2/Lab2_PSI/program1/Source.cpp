#include "Neuron.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <map>


using namespace std;

void csv(std::string file, double*T, int index);
double learn(Neuron *neuron, double** inputs, double **outputs, int n, double ni);

double activateFunction(double x, double threshold)
{
	return 0.0001*x+1/x;
}


int main()
{
	
	srand(time(NULL));
	double **output=new double*[20];
	for (int i = 0; i < 20; i++)
		output[i] = new double[2];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			output[i][0] = 1;
			output[i][1] = -1;
		}
		else
		{
			output[i][1] = 1;
			output[i][0] = -1;
		}
	}

	double inputs[20 * 56];
	double **_inputs=new double*[20];
	for (int i = 0; i < 20; i++)
	{
		_inputs[i] = new double[56];
	}




	for (int i = 'A'; i <= 'J'; i++)
	{

		string file = "../../Litery/";
		file += char(i);
		file += "1.csv";
		csv(file, _inputs[i-'A'], 0);
	}


	for (int i = 'a'; i <= 'j'; i++)
	{
		string file = "../../Litery/";
		file += char(i);
		file += "m1.csv";
		csv(file, _inputs[i - 'a'+10], 0);
	}



	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 56; j++)
		{
			cout << _inputs[i][j];
		}
		cout << endl;
	}

	Neuron neurons[2];
	for (int i = 0; i < 2; i++)
	{
		neurons[i].setActivatingFunction(activateFunction);
		neurons[i].setN(56);
	}

	cout << "Uczenie: " << endl;
	double error=1;
	int i = 0;
	while (error > 0)
	{
		error = learn(neurons, _inputs, output, 2, 0.3);
		cout << "numer iteracji: " << i << "   blad sredniokwadratowy: " <<   error << endl;
		i++;
	}

	for (int i = 'A'; i <= 'J'; i++)
	{
		cout << (char)i << ": " << neurons[0].start(_inputs[i - 'A']) << " " << neurons[1].start(_inputs[i - 'A']) << endl;
	}
	for (int i = 'a'; i <= 'j'; i++)
	{
		cout << (char)i << ": " << neurons[0].start(_inputs[i - 'a'+10]) << neurons[1].start(_inputs[i - 'a' + 10]) << endl;
	}


	system("pause");
	return 0;
}


double learn(Neuron *neuron, double** inputs, double **outputs, int n, double ni)
{
	double error1=0, error=0;


	int j;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			
			error1 = neuron[j].learn(inputs[i], outputs[i][j], ni);

			error += error1*error1;
		}

	}

	return error/2;
}

void csv(std::string file, double*T, int index)
{
	std::ifstream is(file);
	char  c;
	while (is.get(c))
	{
		if (c != ',' && c != '\n')
		{
			if (c == 48)
				T[index] = -1;
			else
				T[index] = 1;

			index++;
		}
	}
	is.close();
}