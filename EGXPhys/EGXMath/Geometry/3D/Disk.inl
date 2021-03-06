/// @file EGXMath/Geometry/3D/Disk.inl
///
/// @brief Implimentation of functions related to disk shape.
/// @author Elliot Grafil 
/// @date 4/11/18


namespace EGXMath {

	template <typename T, typename T2>
	void DiskInertia(const T mass, const T height, const T radius, T2(&matrix)[9]) {
		CylinderInertia(mass, height, radius, matrix);
	}

	template <typename T, typename T2>
	void DiskThinInertia(const T mass, const T radius, T2(&matrix)[9]) {
		std::fill(matrix, matrix + 9, T2(0)); // Prefer fill to memset see https://stackoverflow.com/questions/9146395/reset-c-int-array-to-zero-the-fastest-way

		matrix[0] = (T2)((T)1.0 / (T)4.0 * mass * radius * radius);
		matrix[4] = (T2)((T)1.0 / (T)4.0 * mass * radius * radius);
		matrix[8] = (T2)((T)1.0 / (T)2.0 * mass * radius * radius);
	}

	template <typename T, typename T2>
	void DiskInertia(const T mass, const T height, const T radius, std::vector<T2>& matrix) {
		CylinderInertia(mass, height, radius, matrix);
	}

	template <typename T, typename T2>
	void DiskThinInertia(const T mass, const T radius, std::vector<T2>& matrix) {
		std::fill(matrix.begin(), matrix.end(), T2(0)); // Prefer fill to memset see https://stackoverflow.com/questions/9146395/reset-c-int-array-to-zero-the-fastest-way

		matrix[0] = (T2)((T)1.0 / (T)4.0 * mass * radius * radius);
		matrix[4] = (T2)((T)1.0 / (T)4.0 * mass * radius * radius);
		matrix[8] = (T2)((T)1.0 / (T)2.0 * mass * radius * radius);
	}

#ifdef EGXMATH_GLM
	template <typename T>
	void DiskInertia(const T mass, const T height, const T radius, glm::mat3& matrix) {
		CylinderInertia(mass, height, radius, matrix);
	}


	template <typename T>
	void DiskThinInertia(const T mass, const T radius, glm::mat3& matrix) {
		matrix = glm::mat3(0.0f);

		matrix[0][0] = static_cast<decltype(matrix[0].x)>(1.0f / 4.0f * mass * radius * radius);
		matrix[1][1] = static_cast<decltype(matrix[0].x)>(1.0f / 4.0f * mass * radius * radius);
		matrix[2][2] = static_cast<decltype(matrix[0].x)>(1.0f / 2.0f * mass * radius * radius);
	}

#endif // EGXMATH_GLM

}//namespace EGXMath
