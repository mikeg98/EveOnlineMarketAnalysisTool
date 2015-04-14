#include <iostream>
#include <vector>

float AverageVolPerOrder(float Volume, float Orders)
{
	return Volume/Orders;
}

float Margin(float High, float Low)
{
	return (High-Low)/Low;
}

float Avg(vector<float> Numbers)
{
	float Total = 0;
	for (int i = 0; i < Numbers.size(); i++)
	{
		Total += Numbers[i];
	}
	return Total/Numbers.size();
}

vector<int> HistoricalLows(vector<float> Prices)
{
	vector<int> Answer;
	for (int i = 0; i < Prices.size(); i++)
	{
		if (i == 0)
		{
			if (Prices[i] < Prices [i+1] && Prices[i] < Prices[i+2]  && Prices[i] < Avg) Answer.pushback(i);
		}
		else if (i == Prices.size())
		{
			if (i] < Prices[i-1] && Prices[i] < Prices[i-2] && Prices[i] < Avg) Answer.pushback(i);
		}
		else if (i == 1)
		{
			if (Prices[i] < (Prices[i-1] + Prices[i+2])/2 && Prices[i] < Prices[i+2] && Prices[i] < Avg) Answer.pushback(i);
		}
		else if (i == Prices.size()-1)
		{
			if (Prices[i] < (Prices[i-1] + Prices[i+1])/2 && Prices[i] < Prices[i-2] && Prices[i] < Avg) Answer.pushback(i);
		}
		else
		{
			if (Prices[i] < (Prices[i-1] + Prices[i+1])/2 && Prices[i] < (Prices[i-2] + Prices[i+2])/2 && Prices[i] < Avg) Answer.pushback(i);
		}
	}
	return Answer;
}

vector<int> HistoricalHighs(vector<float> Prices)
{
	vector<int> Answer;
	float Avg = Avg(Prices);

	for (int i = 0; i < Prices.size(); i++)
	{
		if (i == 0)
		{
			if (Prices[i] > Prices [i+1] && Prices[i] > Prices[i+2] && Prices[i] > Avg) Answer.pushback(i);
		}
		else if (i == Prices.size())
		{
			if (Prices[i] > Prices[i-1] && Prices[i] > Prices[i-2] && Prices[i] > Avg) Answer.pushback(i);
		}
		else if (i == 1)
		{
			if (Prices[i] > (Prices[i-1] + Prices[i+1])/2 && Prices[i] > Prices[i+2] && Prices[i] < Avg) Answer.pushback(i);
		}
		else if (i == Prices.size()-1)
		{
			if (Prices[i] > (Prices[i-1] + Prices[i+1])/2 && Prices[i] > Prices[i-2] && Prices[i] < Avg) Answer.pushback(i);
		}
		else
		{
			if (Prices[i] > (Prices[i-1] + Prices[i+1])/2 && Prices[i] > (Prices[i-2] + Prices[i+2])/2 && Prices[i] > Avg) Answer.pushback(i);
		}
	}
	return Answer;
}

// Returns the P/E ratio of an item over the last 12 months
// High P/E ratios generally imply riskier investments
// If the stock has dropped in the past 12 months, there is no P/E ratio
float peRatio(vector<float> prices)
{
	// Assumes prices is vector of all prices over the past 12 months
	// Assumes prices[0] is price from 12 months before prices[prices.size() - 1]
	float PE = -1;
	
	if (prices[prices.size() - 1] - prices[0] <= 0)
	{
		return PE;
	}
	PE = prices[prices.size()-1] / (prices[prices.size() - 1] - prices[0]);
	return PE;
}