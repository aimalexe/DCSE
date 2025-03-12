class Vector:
    """
    A class representing a mathematical vector with basic operations.
    """

    def __init__(self, components):
        """
        Initialize the vector with a list of components.

        :param components: List of numerical components of the vector.
        """
        self.components = components

    def __add__(self, other):
        """
        Performs vector addition.

        :param other: Another vector.
        :return: A new vector representing the sum.
        """
        return Vector([a + b for a, b in zip(self.components, other.components)])

    def __sub__(self, other):
        """
        Performs vector subtraction.

        :param other: Another vector.
        :return: A new vector representing the difference.
        """
        return Vector([a - b for a, b in zip(self.components, other.components)])

    def scalar_mult(self, scalar):
        """
        Multiplies the vector by a scalar.

        :param scalar: A numerical value.
        :return: A new scaled vector.
        """
        return Vector([scalar * a for a in self.components])

    def norm(self, order=2):
        """
        Computes the norm of the vector.

        :param order: The order of the norm (1 for L1, 2 for L2, or inf for infinity norm).
        :return: The computed norm value.
        """
        if order == 1:
            return sum(abs(a) for a in self.components)
        elif order == 2:
            return sum(a**2 for a in self.components) ** 0.5
        elif order == float('inf'):
            return max(abs(a) for a in self.components)
        else:
            raise ValueError('Unsupported norm order')

    def dot(self, other):
        """
        Computes the dot product of two vectors.

        :param other: Another vector.
        :return: A scalar value representing the dot product.
        """
        return sum(a * b for a, b in zip(self.components, other.components))

    def cross(self, other):
        """
        Computes the cross product of two 3D vectors.

        :param other: Another 3D vector.
        :return: A new vector representing the cross product.
        :raises ValueError: If the vectors are not 3-dimensional.
        """
        if len(self.components) != 3 or len(other.components) != 3:
            raise ValueError('Cross product is only defined for 3D vectors')
        a1, a2, a3 = self.components
        b1, b2, b3 = other.components
        return Vector([a2 * b3 - a3 * b2, a3 * b1 - a1 * b3, a1 * b2 - a2 * b1])

    def outer(self, other):
        """
        Computes the outer product of two vectors.

        :param other: Another vector.
        :return: A matrix representing the outer product.
        """
        return [[a * b for b in other.components] for a in self.components]

    def projection(self, other):
        """
        Computes the projection of one vector onto another.

        :param other: Another vector.
        :return: The projected vector.
        :raises ValueError: If the denominator is zero (division by zero error).
        """
        dot_product = self.dot(other)
        other_norm_squared = other.dot(other)
        if other_norm_squared == 0:
            raise ValueError("Cannot project onto a zero vector.")
        scalar = dot_product / other_norm_squared
        return other.scalar_mult(scalar)

    def transpose(self):
        """
        Returns the transpose of a vector (as a column vector).

        :return: A transposed version of the vector.
        """
        return [[a] for a in self.components]

    def __repr__(self):
        """
        Returns a string representation of the vector.

        :return: A formatted string representing the vector.
        """
        return f'Vector({self.components})'
