#pragma once

#include <iomanip>
#include <sstream>

#include "State.h"
#include "ScatterPlot.h"
#include "LineChart.h"
#include "Button.h"


class DeepLearningState
	: public State
{
private:
	double w1;
	float w2;
	float b;
	int iterations;
	float learningRate;

	ScatterPlot* scatterPlot;
	LineChart* lineChart;

	std::map<std::string, Button*> buttons;
	sf::Font font;
	
	//Functions
	void initFonts();
	void initParams();
	void initKeybinds();
	void initScatterPlot();
	void initLineChart();
	void initButtons();
	
	double sigmoid(double x_);
	double sigmoid_p(double x_);

public:
	DeepLearningState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states);
	virtual ~DeepLearningState();

	void training();
	void clearTrainingData();

	//Functions
	void updateInput(const float _dt);
	void updateButtons(const float _dt);
	void update(const float _dt);
	void renderButtons(sf::RenderTarget& _target);
	void renderParameters(sf::RenderTarget& _target);
	void render(sf::RenderTarget& _target);
};

