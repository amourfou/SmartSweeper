#pragma once

//------------------------------------------------------------------------
//
//	Name: CNeuralNet.h
//
//  Author: Mat Buckland 2002
//
//  Desc: Class for creating a feedforward neural net.From the book Game AI 
//  Programming with Neural Nets and Genetic Algorithms.
//-------------------------------------------------------------------------

#include <vector>
#include <fstream>
#include <math.h>

#include "utils.h"
#include "CParams.h"

using namespace std;

//-------------------------------------------------------------------
//	define neuron struct
//-------------------------------------------------------------------
struct SNeuron
{
	int				m_NumInputs;//the number of inputs into the neuron
	vector<double>	m_vecWeight;//the weights for each input
	SNeuron(int NumInputs);//ctor
};


//---------------------------------------------------------------------
//	struct to hold a layer of neurons.
//---------------------------------------------------------------------

struct SNeuronLayer
{
	//the number of neurons in this layer
	int				m_NumNeurons;

	//the layer of neurons
	vector<SNeuron>	m_vecNeurons;

	SNeuronLayer(int NumNeurons, int NumInputsPerNeuron);
};


//----------------------------------------------------------------------
//	neural net class
//----------------------------------------------------------------------

class CNeuralNet
{
	int		m_NumInputs;
	int		m_NumOutputs;
	int		m_NumHiddenLayers;
	int		m_NeuronsPerHiddenLyr;

	//storage for each layer of neurons including the output layer
	vector<SNeuronLayer>	m_vecLayers;

public:
	CNeuralNet();

	void	CreateNet();

	// returns total number of weights in net
	int		GetNumberOfWeights()const;

	// gets the weights from the NN
	vector<double>	GetWeights()const;

	// replaces the weights with new ones
	void	PutWeights(vector<double> &weights);

	// calculates the outputs from a set of inputs
	vector<double>	Update(vector<double> &inputs);

	// sigmoid response curve
	inline double	Sigmoid(double activation, double response);

};

