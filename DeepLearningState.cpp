// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "DeepLearningState.h"
#include <iostream>

void DeepLearningState::initFonts()
{
	if (!font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		throw("ERROR::MAINMENUSTATE:: COULD NOT LOAD FONT");
	}
}

void DeepLearningState::initParams()
{
	w1 = rand() % 2 - 1;
	w2 = rand() % 2 - 1;
	b = rand() % 2 - 1;
	iterations = 10000;
	learningRate = 0.15;

}

//Initializer functions
void DeepLearningState::initKeybinds()
{
	std::ifstream ifs("Config/deeplearningstate_keybinds.ini");

	if (ifs.is_open())
	{
		std::string key_;
		std::string key2_;
		while (ifs >> key_ >> key2_)
		{
			keybinds[key_] = supportedKeys.at(key2_);
		}
	}

	ifs.close();
}

void DeepLearningState::initScatterPlot()
{
	sf::Vector2f _pos(100.0f, 100.0f);
	sf::Vector2f _size(500.0f, 500.0f);
	float _xMin = 0.0f;
	float _xMax = 10.0f;
	float _yMin = 0.0f;
	float _yMax = 5.0f;
	float _xIncr = 50.0f;
	float _yIncr = 50.0f;
	
	std::vector<Point> _points;

	scatterPlot = new ScatterPlot(_pos, _size, _xMin, _xMax, _yMin, _yMax, _xIncr, _yIncr, _points);
}

void DeepLearningState::initLineChart()
{
	sf::Vector2f _pos(700.0f, 100.0f);
	sf::Vector2f _size(800.0f, 800.0f);
	float _xMin = 0.0f;
	float _xMax = 10000.0f;
	float _yMin = 0.0f;
	float _yMax = 4.0f;
	float _xIncr = 100.0f;
	float _yIncr = 100.0f;

	std::vector<Point> _points;


	lineChart = new LineChart(_pos, _size, _xMin, _xMax, _yMin, _yMax, _xIncr, _yIncr, _points);
}

void DeepLearningState::initButtons()
{
	buttons["RETRAIN"] = new Button(800.0f, 950.0f, 150.0f, 50.0f,
		font, "Re-train", 50,
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent, 0.5f);
}

//Sigmoid function to squish cost to 0-1 interval
double DeepLearningState::sigmoid(double x_)
{
	return 1 / (1 + exp(-x_));
}

//derivative of sigmiod
double DeepLearningState::sigmoid_p(double x_)
{
	return sigmoid(x_) * (1 - sigmoid(x_));
}

//Consutrctor destructors

DeepLearningState::DeepLearningState(sf::RenderWindow* _window, std::map<std::string, int>& _supportedKeys, std::stack<State*>* _states)
	: State(_window, _supportedKeys, _states)
{
	DeepLearningState::initKeybinds();
	
	initFonts();
	initParams();
	initScatterPlot();
	initLineChart();
	initButtons();

	training();
}

DeepLearningState::~DeepLearningState()
{
	delete scatterPlot;
	delete lineChart;
}

void DeepLearningState::training()
{
	//Training data (length, size, type)
	double data[8][3] = {
		{3,   1.5, 1},
		{2,   1,   0},
		{4,   1.5, 1},
		{3.5, .5,  1},
		{2,   .5,  0},
		{5.5,  1,  1},
		{1,    1,  0}
	};

	for (int i = 0; i < sizeof(data) / sizeof(data[0]); ++i)
	{
		scatterPlot->addPoint(Point(data[i][0], data[i][1], data[i][2] == 0 ? sf::Color::Blue : sf::Color::Red));
	}

	//Red of type 1 (should be type 1 for the computer) 
	double mystery[2] = { 3, 1 };

	//TRAINING THE PROGRAM

	//Initialize a random seed

	//Initialize weights and biases randomly at first

	//w1 and w2 are for lengths and widths


	for (int i = 0; i < iterations; i++)
	{
		
		//get a random dataset from data
		int r = rand() % sizeof(data) / sizeof(data[0]);
		double randomSet[3];
		randomSet[0] = data[r][0];
		randomSet[1] = data[r][1];
		randomSet[2] = data[r][2];



		//pred before squishing
		double z = randomSet[0] * w1 + randomSet[1] * w2 + b;

		//squished prediction between 0 and 1
		double pred = sigmoid(z);

		//What I want the computer to predict
		double target = randomSet[2];



		//cost for current point (the lower the cost, the more correct the prediction, 0 = correct)
		double cost = pow(pred - target, 2);

		if (i % 10 == 0)
		{
			//calculates the cost over the whole dataset
			float c = 0;
			for (int j = 0; j < sizeof(data) / sizeof(data[0]); j++)
			{
				
				pred = sigmoid(data[j][0] * w1 + data[j][1] * w2 + b);
				c += pow(pred - data[j][2], 2);
			}
			lineChart->addPoint((Point(i, c)));
		}



		//DERIVATIVE PART (FUN)
		double dcost_dpred = 2 * (pred - target);
		double dpred_dz = sigmoid_p(z);
		double dz_dw1 = randomSet[0];
		double dz_dw2 = randomSet[1];
		double dz_db = 1;



		double dcost_dz = dcost_dpred * dpred_dz;

		double dcost_dw1 = dcost_dz * dz_dw1;
		double dcost_dw2 = dcost_dz * dz_dw2;
		double dcost_db = dcost_dz * dz_db;



		w1 = w1 - learningRate * dcost_dw1;
		w2 = w2 - learningRate * dcost_dw2;
		b = b - learningRate * dcost_db;
	}
	//Training complete (w1, w2 and b have been adjusted)

	double z = w1 * mystery[0] + w2 * mystery[1] + b;
	double pred = sigmoid(z);

	std::cout << std::setprecision(9) << pred << "\n";
	std::cout << (pred > 0.5 ? "red" : "blue") << "\n";


	//Color the graph with red or blue values
	sf::Color _color;
	for (float i = scatterPlot->getLimits().xMin + 0.5; i < scatterPlot->getLimits().xMax; i+=0.5f)
	{
		for (float j = scatterPlot->getLimits().yMin + 0.25; j < scatterPlot->getLimits().yMax; j+=0.25f)
		{
			z = w1 * i + w2 * j + b;
			pred = sigmoid(z);
			_color = pred < 0.5 ? sf::Color(173, 216, 230) : sf::Color(255, 114, 118);
			scatterPlot->addPoint(Point(i, j, _color, 5.0f));

		}
	}
}

void DeepLearningState::clearTrainingData()
{
	w1 = rand() % 2 - 1;
	w2 = rand() % 2 - 1;
	b = rand() % 2 - 1;
	lineChart->clearPoints();
	scatterPlot->clearPoints();
}

void DeepLearningState::updateInput(const float _dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(keybinds.at("CLOSE"))))
		endState();
}

void DeepLearningState::updateButtons(const float _dt)
{
	for (auto &it : buttons)
	{
		it.second->update(mousePosView, _dt);
	}

	if (buttons["RETRAIN"]->isPressed())
	{
		clearTrainingData();
		training();
	}
}

void DeepLearningState::update(const float _dt)
{
	updateMousePositions();
	updateInput(_dt);
	updateButtons(_dt);
}

void DeepLearningState::renderButtons(sf::RenderTarget & _target)
{
	for (auto &it : buttons)
	{
		it.second->render(_target);
	}
}

void DeepLearningState::renderParameters(sf::RenderTarget & _target)
{
	//Display the paramaters
	sf::Text _text;
	std::stringstream _ss;

	_text.setFont(font);

	_ss << "w1:  " << w1;
	_text.setString(_ss.str());
	_text.setPosition(100.0f, 700.0f);
	_target.draw(_text);

	_ss.str("");

	_ss << "w2:  " << w2;
	_text.setString(_ss.str());
	_text.setPosition(100.0f, 750.0f);
	_target.draw(_text);

	_ss.str("");

	_ss << "b:  " << b;
	_text.setString(_ss.str());
	_text.setPosition(100.0f, 800.0f);
	_target.draw(_text);

}


void DeepLearningState::render(sf::RenderTarget& _target)
{
	if (scatterPlot)
		scatterPlot->render(_target);

	if (lineChart)
		lineChart->render(_target);

	renderButtons(_target);
	renderParameters(_target);
}
