from vector import Vector

class Matrix(Vector):
    """
    A class representing a mathematical matrix, inheriting from Vector.
    """

    def __init__(self, rows):
        """
        Initialize a matrix with a list of row vectors.

        :param rows: A list of lists representing the matrix.
        """
        if not all(len(row) == len(rows[0]) for row in rows):
            raise ValueError("All rows must have the same length")
        self.rows = rows
        self.num_rows = len(rows)
        self.num_cols = len(rows[0])

    def __add__(self, other):
        """
        Performs matrix addition.

        :param other: Another matrix.
        :return: A new matrix representing the sum.
        """
        if self.num_rows != other.num_rows or self.num_cols != other.num_cols:
            raise ValueError("Matrices must have the same dimensions for addition")
        return Matrix([[self.rows[i][j] + other.rows[i][j] for j in range(self.num_cols)] for i in range(self.num_rows)])

    def __sub__(self, other):
        """
        Performs matrix subtraction.

        :param other: Another matrix.
        :return: A new matrix representing the difference.
        """
        if self.num_rows != other.num_rows or self.num_cols != other.num_cols:
            raise ValueError("Matrices must have the same dimensions for subtraction")
        return Matrix([[self.rows[i][j] - other.rows[i][j] for j in range(self.num_cols)] for i in range(self.num_rows)])

    def scalar_mult(self, scalar):
        """
        Multiplies the matrix by a scalar.

        :param scalar: A numerical value.
        :return: A new scaled matrix.
        """
        return Matrix([[scalar * self.rows[i][j] for j in range(self.num_cols)] for i in range(self.num_rows)])

    def transpose(self):
        """
        Returns the transpose of the matrix.

        :return: A new transposed matrix.
        """
        return Matrix([[self.rows[j][i] for j in range(self.num_rows)] for i in range(self.num_cols)])

    def mat_mult(self, other):
        """
        Performs matrix multiplication.

        :param other: Another matrix.
        :return: A new matrix representing the product.
        """
        if self.num_cols != other.num_rows:
            raise ValueError("Number of columns in the first matrix must equal the number of rows in the second matrix")
        return Matrix([[sum(self.rows[i][k] * other.rows[k][j] for k in range(self.num_cols)) for j in range(other.num_cols)] for i in range(self.num_rows)])

    def determinant(self):
        """
        Computes the determinant of the matrix (only for square matrices).

        :return: Determinant value.
        """
        if self.num_rows != self.num_cols:
            raise ValueError("Determinant is only defined for square matrices")
        if self.num_rows == 1:
            return self.rows[0][0]
        if self.num_rows == 2:
            return self.rows[0][0] * self.rows[1][1] - self.rows[0][1] * self.rows[1][0]

        det = 0
        for col in range(self.num_cols):
            minor = [[self.rows[i][j] for j in range(self.num_cols) if j != col] for i in range(1, self.num_rows)]
            det += ((-1) ** col) * self.rows[0][col] * Matrix(minor).determinant()
        return det

    def inverse(self):
        """
        Computes the inverse of the matrix (only for square matrices).

        :return: Inverse matrix.
        :raises ValueError: If the matrix is not invertible.
        """
        if self.num_rows != self.num_cols:
            raise ValueError("Inverse is only defined for square matrices")

        det = self.determinant()
        if det == 0:
            raise ValueError("Matrix is singular and cannot be inverted")

        if self.num_rows == 2:
            inv_det = 1 / det
            return Matrix([
                [self.rows[1][1] * inv_det, -self.rows[0][1] * inv_det],
                [-self.rows[1][0] * inv_det, self.rows[0][0] * inv_det]
            ])

        cofactors = [[((-1) ** (i + j)) * Matrix(
            [[self.rows[x][y] for y in range(self.num_cols) if y != j] for x in range(self.num_rows) if x != i]
        ).determinant() for j in range(self.num_cols)] for i in range(self.num_rows)]

        adjugate = Matrix(cofactors).transpose()
        return adjugate.scalar_mult(1 / det)

    def rank(self):
        """
        Computes the rank of the matrix using row reduction.

        :return: Rank of the matrix.
        """
        matrix = [row[:] for row in self.rows]
        rank = 0

        for col in range(self.num_cols):
            if col >= len(matrix):
                break
            pivot_row = next((r for r in range(col, len(matrix)) if matrix[r][col] != 0), None)
            if pivot_row is None:
                continue
            matrix[col], matrix[pivot_row] = matrix[pivot_row], matrix[col]
            rank += 1
            pivot = matrix[col][col]
            matrix[col] = [val / pivot for val in matrix[col]]

            for r in range(len(matrix)):
                if r != col:
                    factor = matrix[r][col]
                    matrix[r] = [matrix[r][i] - factor * matrix[col][i] for i in range(self.num_cols)]

        return rank
    
    def trace(self):
        """
        Computes the trace of the matrix (sum of diagonal elements).

        :return: The trace value.
        """
        if self.num_rows != self.num_cols:
            raise ValueError("Trace is only defined for square matrices")
        return sum(self.rows[i][i] for i in range(self.num_rows))

    def adjoint(self):
        """
        Computes the adjugate (adjoint) of the matrix.

        :return: The adjugate matrix.
        """
        if self.num_rows != self.num_cols:
            raise ValueError("Adjugate is only defined for square matrices")

        cofactors = [[((-1) ** (i + j)) * Matrix(
            [[self.rows[x][y] for y in range(self.num_cols) if y != j] 
            for x in range(self.num_rows) if x != i]
        ).determinant() for j in range(self.num_cols)] for i in range(self.num_rows)]

        return Matrix(cofactors).transpose()

    def kronecker_product(self, other):
        """
        Computes the Kronecker product of two matrices.

        :param other: Another matrix.
        :return: The Kronecker product matrix.
        """
        result = []
        for row in self.rows:
            new_rows = [[] for _ in range(other.num_rows)]
            for elem in row:
                sub_matrix = [[elem * other.rows[i][j] for j in range(other.num_cols)] for i in range(other.num_rows)]
                for i in range(other.num_rows):
                    new_rows[i].extend(sub_matrix[i])
            result.extend(new_rows)
        return Matrix(result)
    
    def is_identity(self):
        """
        Checks if the matrix is an identity matrix.

        :return: True if the matrix is an identity matrix, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False
        for i in range(self.num_rows):
            for j in range(self.num_cols):
                if (i == j and self.rows[i][j] != 1) or (i != j and self.rows[i][j] != 0):
                    return False
        return True

    def is_diagonal(self):
        """
        Checks if the matrix is a diagonal matrix.

        :return: True if the matrix is diagonal, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False
        for i in range(self.num_rows):
            for j in range(self.num_cols):
                if i != j and self.rows[i][j] != 0:
                    return False
        return True

    def is_upper_triangular(self):
        """
        Checks if the matrix is an upper triangular matrix.

        :return: True if the matrix is upper triangular, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False
        for i in range(1, self.num_rows):
            for j in range(i):
                if self.rows[i][j] != 0:
                    return False
        return True

    def is_lower_triangular(self):
        """
        Checks if the matrix is a lower triangular matrix.

        :return: True if the matrix is lower triangular, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False
        for i in range(self.num_rows):
            for j in range(i + 1, self.num_cols):
                if self.rows[i][j] != 0:
                    return False
        return True

    def is_symmetric(self):
        """
        Checks if the matrix is symmetric (A^T = A).

        :return: True if the matrix is symmetric, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False
        for i in range(self.num_rows):
            for j in range(i, self.num_cols):
                if self.rows[i][j] != self.rows[j][i]:
                    return False
        return True

    def is_skew_symmetric(self):
        """
        Checks if the matrix is skew-symmetric (A^T = -A).

        :return: True if the matrix is skew-symmetric, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False
        for i in range(self.num_rows):
            for j in range(i, self.num_cols):
                if self.rows[i][j] != -self.rows[j][i]:
                    return False
        return True

    def is_orthogonal(self):
        """
        Checks if the matrix is orthogonal (A^T * A = I).

        :return: True if the matrix is orthogonal, False otherwise.
        """
        if self.num_rows != self.num_cols:
            return False

        # Compute A^T * A
        transpose_matrix = self.transpose()
        product = transpose_matrix.mat_mult(self)

        # Check if product is identity matrix
        return product.is_identity()

    def __repr__(self):
        """
        Returns a string representation of the matrix.

        :return: A formatted string representing the matrix.
        """
        return '\n'.join([' '.join(map(str, row)) for row in self.rows])
