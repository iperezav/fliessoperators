#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<int>> getPermutations(int N, int K) {
    std::vector<std::vector<int>> permutations;
    permutations.reserve(pow(K, N)); // Reserve memory for all permutations
    permutations.emplace_back(); // Add an empty permutation as the base case
    std::vector<int> sizePermutations;
    sizePermutations.push_back(0); // Initialize with 0

    for (int size = 1; size <= N; size++) {
        sizePermutations.push_back(permutations.size());
        for (int i = sizePermutations[size - 1]; i < sizePermutations[size]; i++) {
            for (int j = 1; j <= K; j++) {
                std::vector<int> currentPermutation = permutations[i];
                currentPermutation.push_back(j);
                permutations.push_back(currentPermutation);
            }
        }
    }

    return permutations;
}

int main() {
    int N = 8; // Maximum size of permutations
    int K = 4; // Elements range from 1 to K

    std::vector<std::vector<int>> permutations = getPermutations(N, K);

    // Displaying the permutations
    for (const auto& permutation : permutations) {
        for (const auto& num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
