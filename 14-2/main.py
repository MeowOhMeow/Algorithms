def LCS(A, B):
    """Finds the longest common subsequence of two strings.

    Args:
      A: A string.
      B: A string.

    Returns:
      The longest common subsequence of A and B.
    """

    lengthA = len(A)
    lengthB = len(B)

    # Initialize the matrix.
    matrix = [[0 for i in range(lengthB+1)] for j in range(lengthA+1)]

    # Fill in the matrix.
    for i in range(1, lengthA+1):
        for j in range(1, lengthB+1):
            if A[i-1] == B[j-1]:
                matrix[i][j] = matrix[i-1][j-1] + 1
            else:
                matrix[i][j] = max(matrix[i][j-1], matrix[i-1][j])

    # Find the longest common subsequence.
    LCSs = ""
    i = lengthA
    j = lengthB
    while i > 0 and j > 0:
        if A[i-1] == B[j-1]:
            LCSs = A[i-1] + LCSs
            i -= 1
            j -= 1
        elif matrix[i][j-1] > matrix[i-1][j]:
            j -= 1
        else:
            i -= 1

    return LCSs


def longest_palindrome_subsequence(A):
    """Finds the longest palindrome subsequence of a given string.

    Args:
      A: A string.

    Returns:
      The longest palindrome subsequence of A.
    """

    return LCS(A, A[::-1])


# Example usage:
A = "character"
print(longest_palindrome_subsequence(A))
