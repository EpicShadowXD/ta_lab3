#pragma once

namespace MergeSort {
    void merge(std::vector<int>& nums, int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }

        for (i = left, k = 0; i <= right; i++, k++) {
            nums[i] = temp[k];
        }
    }

    void mergeSort(std::vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void test(std::vector<int> nums = {38, 27, 43, 3, 9, 82, 10}) {
        mergeSort(nums, 0, nums.size() - 1);
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

namespace Hanoi {
    void hanoi(int n, char from, char to, char aux) {
        if (n == 1) {
            std::cout << "Muta discul 1 de la " << from << " la " << to << std::endl;
            return;
        }
        hanoi(n - 1, from, aux, to);
        std::cout << "Muta discul " << n << " de la " << from << " la " << to << std::endl;
        hanoi(n - 1, aux, to, from);
    }

    void test(int n = 3, char from = 'A', char to = 'C', char aux = 'B') {
        hanoi(n, from, to, aux);
    }
}

namespace MinMax {
    std::pair<int, int> getMinAndMax(const std::vector<int>& nums, int left, int right) {
        if (left == right)  // Dacă există un singur element
            return {nums[left], nums[left]};

        if (right == left + 1) {  // Dacă sunt două elemente
            if (nums[left] < nums[right])
                return {nums[left], nums[right]};
            else
                return {nums[right], nums[left]};
        }

        int mid = left + (right - left) / 2;
        auto leftResult = getMinAndMax(nums, left, mid);
        auto rightResult = getMinAndMax(nums, mid + 1, right);

        return {
            std::min(leftResult.first, rightResult.first),
            std::max(leftResult.second, rightResult.second)
        };
    }

    void test(std::vector<int> nums = {3, 1, 90, 42, 23}) {
        auto result = getMinAndMax(nums, 0, nums.size() - 1);
        std::cout << "Min: " << result.first << ", Max: " << result.second << std::endl;
    }
}

namespace GCD {
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    int findGCD(std::vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + (right - left) / 2;
        int leftGCD = findGCD(nums, left, mid);
        int rightGCD = findGCD(nums, mid + 1, right);
        return gcd(leftGCD, rightGCD);
    }

    void test(std::vector<int> nums = {42, 56, 14, 70, 28}) {
        std::cout << "CMMDC: " << findGCD(nums, 0, nums.size() - 1) << std::endl;
    }
}