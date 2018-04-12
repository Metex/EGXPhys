#pragma once

TEST_CASE("Geometry 2D Circle"){

	//Matrix Definitions
	glm::mat3 glmMatrix;
	float arrayMatrix[9];
	std::vector<float> vectorMatrix(9);

	glm::mat3 glmZeroMatrix;
	glmZeroMatrix = glm::mat3(0.0);
	float arrayZeroMatrix[9];
	std::fill(arrayZeroMatrix, arrayZeroMatrix + 9, 0.0f);
	std::vector<float> vectorZeroMatrix(9,0);

	float m1 = 1.0; float m2 = 2.0; float m3 = 4.0;
	float r1 = 1.0; float r2 = 2.0; float r3 = 4.0;

	//Area
	CHECK(CircleArea(0.0) == 0.0);
	CHECK(CircleArea(r1) == Approx(EGXMath::pi<float>).scale(0.0).epsilon(0.001));
	CHECK(CircleArea(r2) == Approx(4.0*EGXMath::pi<float>).scale(0.0).epsilon(0.001));
	CHECK(CircleArea(r3) == Approx(16.0*EGXMath::pi<float>).scale(0.0).epsilon(0.001));
	
	//Circumference
	CHECK(CircleCircumference(0.0) == 0.0);
	CHECK(CircleCircumference(r1) == Approx(2.0 * EGXMath::pi<float>).scale(0.0).epsilon(0.001));
	CHECK(CircleCircumference(r2) == Approx(4.0 * EGXMath::pi<float>).scale(0.0).epsilon(0.001));
	CHECK(CircleCircumference(r3) == Approx(8.0*EGXMath::pi<float>).scale(0.0).epsilon(0.001));

	
	//Array Matrix check
	CircleThinHoopInertia(0.0, 0.0, arrayMatrix);
	for (int i = 0; i < 9; i++) {
		CHECK(arrayMatrix[i] == arrayZeroMatrix[i]);
	}

	CircleThinHoopInertia(r1, m1, arrayMatrix);
	CHECK(arrayMatrix[0] == 0.5 * m1 * r1 * r1);
	CHECK(arrayMatrix[4] == 0.5 * m1 * r1 * r1);
	CHECK(arrayMatrix[8] == m1 * r1 * r1);

	CircleThinHoopInertia(r2, m2, arrayMatrix);
	CHECK(arrayMatrix[0] == 0.5 * m2 * r2 * r2);
	CHECK(arrayMatrix[4] == 0.5 * m2 * r2 * r2);
	CHECK(arrayMatrix[8] == m2 * r2 * r2);

	CircleThinHoopInertia(r3, m3, arrayMatrix);
	CHECK(arrayMatrix[0] == 0.5 * m3 * r3 * r3);
	CHECK(arrayMatrix[4] == 0.5 * m3 * r3 * r3);
	CHECK(arrayMatrix[8] == m3 * r3 * r3);

	CircleThinDiskInertia(0.0, 0.0, arrayMatrix);
	for (int i = 0; i < 9; i++) {
		CHECK(arrayMatrix[i] == arrayZeroMatrix[i]);
	}

	CircleThinDiskInertia(r1, m1, arrayMatrix);
	CHECK(arrayMatrix[0] == 0.25 * m1 * r1 * r1);
	CHECK(arrayMatrix[4] == 0.25 * m1 * r1 * r1);
	CHECK(arrayMatrix[8] == 0.5 * m1 * r1 * r1);

	CircleThinDiskInertia(r2, m2, arrayMatrix);
	CHECK(arrayMatrix[0] == 0.25 * m2 * r2 * r2);
	CHECK(arrayMatrix[4] == 0.25 * m2 * r2 * r2);
	CHECK(arrayMatrix[8] == 0.5 * m2 * r2 * r2);

	CircleThinDiskInertia(r3, m3, arrayMatrix);
	CHECK(arrayMatrix[0] == 0.25 * m3 * r3 * r3);
	CHECK(arrayMatrix[4] == 0.25 * m3 * r3 * r3);
	CHECK(arrayMatrix[8] == 0.5 * m3 * r3 * r3);


	//Vector matrix check
	CircleThinHoopInertia(0.0, 0.0, vectorMatrix);
	CHECK(vectorMatrix == vectorZeroMatrix);

	CircleThinHoopInertia(r1, m1, vectorMatrix);
	CHECK(vectorMatrix[0] == 0.5 * m1 * r1 * r1);
	CHECK(vectorMatrix[4] == 0.5 * m1 * r1 * r1);
	CHECK(vectorMatrix[8] == m1 * r1 * r1);

	CircleThinHoopInertia(r2, m2, vectorMatrix);
	CHECK(vectorMatrix[0] == 0.5 * m2 * r2 * r2);
	CHECK(vectorMatrix[4] == 0.5 * m2 * r2 * r2);
	CHECK(vectorMatrix[8] == m2 * r2 * r2);

	CircleThinHoopInertia(r3, m3, vectorMatrix);
	CHECK(vectorMatrix[0] == 0.5 * m3 * r3 * r3);
	CHECK(vectorMatrix[4] == 0.5 * m3 * r3 * r3);
	CHECK(vectorMatrix[8] == m3 * r3 * r3);

	CircleThinDiskInertia(0.0, 0.0, vectorMatrix);
	CHECK(vectorMatrix == vectorZeroMatrix);

	CircleThinDiskInertia(r1, m1, vectorMatrix);
	CHECK(vectorMatrix[0] == 0.25 * m1 * r1 * r1);
	CHECK(vectorMatrix[4] == 0.25 * m1 * r1 * r1);
	CHECK(vectorMatrix[8] == 0.5 * m1 * r1 * r1);

	CircleThinDiskInertia(r2, m2, vectorMatrix);
	CHECK(vectorMatrix[0] == 0.25 * m2 * r2 * r2);
	CHECK(vectorMatrix[4] == 0.25 * m2 * r2 * r2);
	CHECK(vectorMatrix[8] == 0.5 * m2 * r2 * r2);

	CircleThinDiskInertia(r3, m3, vectorMatrix);
	CHECK(vectorMatrix[0] == 0.25 * m3 * r3 * r3);
	CHECK(vectorMatrix[4] == 0.25 * m3 * r3 * r3);
	CHECK(vectorMatrix[8] == 0.5 * m3 * r3 * r3);

	//Glm matrix check
	CircleThinHoopInertia(0.0, 0.0, glmMatrix);
	CHECK(glmMatrix == glmZeroMatrix);

	CircleThinHoopInertia(r1, m1, glmMatrix);
	CHECK(glmMatrix[0][0] == 0.5 * m1 * r1 * r1);
	CHECK(glmMatrix[1][1] == 0.5 * m1 * r1 * r1);
	CHECK(glmMatrix[2][2] == m1 * r1 * r1);

	CircleThinHoopInertia(r2, m2, glmMatrix);
	CHECK(glmMatrix[0][0] == 0.5 * m2 * r2 * r2);
	CHECK(glmMatrix[1][1] == 0.5 * m2 * r2 * r2);
	CHECK(glmMatrix[2][2] == m2 * r2 * r2);

	CircleThinHoopInertia(r3, m3, glmMatrix);
	CHECK(glmMatrix[0][0] == 0.5 * m3 * r3 * r3);
	CHECK(glmMatrix[1][1] == 0.5 * m3 * r3 * r3);
	CHECK(glmMatrix[2][2] == m3 * r3 * r3);

	CircleThinDiskInertia(0.0, 0.0, glmMatrix);
	CHECK(glmMatrix == glmZeroMatrix);

	CircleThinDiskInertia(r1, m1, glmMatrix);
	CHECK(glmMatrix[0][0] == 0.25 * m1 * r1 * r1);
	CHECK(glmMatrix[1][1] == 0.25 * m1 * r1 * r1);
	CHECK(glmMatrix[2][2] == 0.5 * m1 * r1 * r1);

	CircleThinDiskInertia(r2, m2, glmMatrix);
	CHECK(glmMatrix[0][0] == 0.25 * m2 * r2 * r2);
	CHECK(glmMatrix[1][1] == 0.25 * m2 * r2 * r2);
	CHECK(glmMatrix[2][2] == 0.5 *m2 * r2 * r2);

	CircleThinDiskInertia(r3, m3, glmMatrix);
	CHECK(glmMatrix[0][0] == 0.25 * m3 * r3 * r3);
	CHECK(glmMatrix[1][1] == 0.25 * m3 * r3 * r3);
	CHECK(glmMatrix[2][2] == 0.5 * m3 * r3 * r3);

	CHECK(glmMatrix == glm::make_mat3(arrayMatrix));

}