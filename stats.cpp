#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& data) {
    //Implement statistics here
    Stats val;
	if (data.size() > 0)
	{
		float avg = 0;
		for (auto input : data)
		{
			avg = avg + input;
		}
		avg = avg / data.size();
		val.average = avg;
		val.max = *max_element(data.begin(), data.end());
		val.min = *min_element(data.begin(), data.end());
	}
	else
	{
		val.average = NAN;
		val.max = NAN;
		val.min = NAN;
	}
	return val;
}

void StatsAlerter::checkAndAlert(const std::vector<float>& data)
{
	float max = data[0];
	max = *max_element(data.begin(), data.end());
	if (max > maxThres)
	{
		std::vector<IAlerter*>::iterator iterator = IAlerts.begin();
		while (iterator != IAlerts.end())
		{
			(*iterator)->updateState();
			++iterator;
		}
	}
}
