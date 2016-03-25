#pragma once

//------------------------------------------------------------------------
//
//	Name: CMineSweeper.h
//
//  Author: Mat Buckland 2002
//
//  Desc: Class to create a minesweeper object used in the 'Smart Sweeper'
//        example from the book Game AI Programming with Neural Nets and 
//        Genetic Algorithms.
//
//------------------------------------------------------------------------
#include <vector>
#include <math.h>

#include "CNeuralNet.h"
#include "utils.h"
#include "C2DMatrix.h"
#include "SVector2D.h"
#include "CParams.h"

using namespace std;

class CMinesweeper
{
	CNeuralNet	m_ItsBrain;// the minesweeper's neural net
	SVector2D	m_vPosition;// its position in the world
	SVector2D	m_vLookAt;// direction sweeper is facing
	double		m_dRotation;// its rotation (surprise surprise)
	double		m_dSpeed;
	double		m_lTrack, m_rTrack;// to store output from the ANN
	double		m_dFitness;// the sweeper's fitness score 
	double		m_dScale;// the scale of the sweeper when drawn
	int			m_iClosestMine;// index position of closest mine

public:
	CMinesweeper();
	
	// updates the ANN with information from the sweepers enviroment
	bool		Update(vector<SVector2D> &mines);

	// used to transform the sweepers vertices prior to rendering
	void		WorldTransform(vector<SPoint> &sweeper);

	// returns a vector to the closest mine
	SVector2D	GetClosestMine(vector<SVector2D> &objects);

	// checks to see if the minesweeper has 'collected' a mine
	int			CheckForMine(vector<SVector2D> &mines, double size);

	void		Reset();

	//-------------------accessor functions
	SVector2D	Position() const { return m_vPosition; }
	void		IncrementFitness() { ++m_dFitness; }
	double		Fitness() const { return m_dFitness; }
	void		PutWeights(vector<double> &w) { m_ItsBrain.PutWeights(w); }
	int			GetNumberOfWeights()const { return m_ItsBrain.GetNumberOfWeights(); }
};

