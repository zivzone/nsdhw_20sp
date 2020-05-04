import time
import _matrix

def main():
    first_matrix = _matrix.Matrix(1100, 1100)
    for i in range(1100):
        for j in range(1100):
            first_matrix[i, j] = i + j

    second_matrix = _matrix.Matrix(1100, 1100)
    for i in range(1100):
        for j in range(1100):
            second_matrix[i, j] = 1    
    start_1 = time.time()
    _matrix.multiply_mkl(first_matrix, second_matrix)
    end_1 = time.time()

    start_2 = time.time()
    _matrix.multiply_naive(first_matrix,second_matrix)
    end_2 = time.time()

    state_1 = "multiply_mkl use:" + str(end_1 - start_1)
    state_2 = "multiply_naive use:" + str(end_2 - start_2)

    fp = open("performance.txt", "a")
    fp.write("This is a testing for 1100*1100 matrix times 1100*1100 matrix!")
    fp.write(state_1)
    fp.write(state_2)
    fp.close()

if __name__ == '__main__':
    main()