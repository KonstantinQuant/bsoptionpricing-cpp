
#ifndef QUANTNET_HW_COMMON_H
#define QUANTNET_HW_COMMON_H

#include <cmath>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>

#include <iostream>

using namespace boost::math;

/// <summary>
/// Constructs a gaussian distribution, with a mean of 0, a standard deviation of 1, and calculates the cumulative distribution value for a given x.
/// </summary>
/// <param name="x">The parameter for the cumulative distribution function.</param>
/// <returns>Returns the output of the cumulative distribution function as a double.</returns>
inline double N(double x) {
	normal_distribution<> myNormal(0.0, 1.0); // m = 0, sd = 1
	return cdf(myNormal, x);
}

/// <summary>
/// Constructs a gaussian distribution, with a mean of 0, a standard deviation of 1, and calculates the probability density value for a given x.
/// </summary>
/// <param name="x">The parameter for the probability density function.</param>
/// <returns>Returns the output of the probability density function as a double.</returns>
inline double n(double x) {
	normal_distribution<> myNormal(0.0, 1.0);
	return pdf(myNormal, x);
}

/// <summary>
/// Constructs a mesh array. It has a variable size, and is filled by h increasing values starting from the start parameter.
/// </summary>
/// <param name="start">The starting value for the mesh array.</param>
/// <param name="end">The end value for the mesh array.</param>
/// <param name="h">The size of the mesh.</param>
/// <returns>Returns the mesh array as an std::vector.</returns>
inline std::vector<double> meshArray(double start, double end, double h) {
	std::vector<double> mesh;

	double run = start;

	while (run <= end) {
		mesh.push_back(run);
		run += h;
	}

	return mesh;
}

/// <summary>
/// Used to determine the wanted return type of the modifiedMatrixPricer. Can return the prices, delta and gamma for varying input parameters.
/// </summary>
enum class MatrixReturnContent {
	PRICE,
	DELTA,
	GAMMA
};

/// <summary>
/// A function that takes a matrix as input, that contains variations of option parameters. Calculates the standalone, isolated change in price, delta, or gamma of the inputted option batch.
/// </summary>
/// <param name="batch">The option batch. Represents the "start" values of the option.</param>
/// <param name="data">A 2D-Matrix with 3 entries: Monotonically increasing values for T, sig and a random modifier different from the first two. To change the last modifier change the setter in the last foor loop. The data for the respective modifiers should be generated using the mesh array.</param>
/// <returns>Returns the prices, delta or gamma results stored in a matrix that used the same architecture as the input matrix.</returns>
inline std::vector<std::vector<double>> modifiedMatrixPricer(Option& batch, std::vector<std::vector<double>> data, MatrixReturnContent content = MatrixReturnContent::PRICE) {
	const Option& batchCopy = batch;

	std::vector<std::vector<double>> results(3);

	for (unsigned i = 0; i < data[0].size(); i++) {
		batch.setT(data[0][i]);

		switch (content) {
		case MatrixReturnContent::PRICE: results[0].push_back(batch.calculatePrice()); break;
		case MatrixReturnContent::DELTA: results[0].push_back(batch.delta()); break;
		case MatrixReturnContent::GAMMA: results[0].push_back(batch.gamma()); break;
		default: results[0].push_back(batch.calculatePrice()); break;
		}

	}

	for (unsigned j = 0; j < data[1].size(); j++) {
		batch.setT(batchCopy.getT()); // Reset the changed T value
		batch.setSig(data[1][j]);
		switch (content) {
		case MatrixReturnContent::PRICE: results[1].push_back(batch.calculatePrice()); break;
		case MatrixReturnContent::DELTA: results[1].push_back(batch.delta()); break;
		case MatrixReturnContent::GAMMA: results[1].push_back(batch.gamma()); break;
		default: results[1].push_back(batch.calculatePrice()); break;
		}
	}

	for (unsigned k = 0; k < data[2].size(); k++) {
		batch.setSig(batchCopy.getSig());
		batch.setS(data[2][k]);
		switch (content) {
		case MatrixReturnContent::PRICE: results[2].push_back(batch.calculatePrice()); break;
		case MatrixReturnContent::DELTA: results[2].push_back(batch.delta()); break;
		case MatrixReturnContent::GAMMA: results[2].push_back(batch.gamma()); break;
		default: results[2].push_back(batch.calculatePrice()); break;
		}
	}

	return results;
}

/// <summary>
/// Helper function the print a matrix, containing various values.
/// </summary>
/// <param name="results">The matrix to be printed.</param>
inline void printMatrixPrice(std::vector<std::vector<double>> results) {
	for (unsigned i = 0; i < results.size(); i++) {
		std::cout << "Only applying modifier " << i << ":" << std::endl;
		for (unsigned j = 0; j < results[i].size(); j++) {
			std::cout << results[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


#endif