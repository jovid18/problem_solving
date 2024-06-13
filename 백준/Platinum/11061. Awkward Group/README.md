# [Platinum II] Awkward Group - 11061 

[문제 링크](https://www.acmicpc.net/problem/11061) 

### 성능 요약

메모리: 63924 KB, 시간: 1372 ms

### 분류

자료 구조, 분리 집합

### 제출 일자

2023년 8월 31일 03:19:26

### 문제 설명

<p>A community P consists of n persons living in a small town. The persons in P may have friendly relationship with someone, but there are men whom they have never met. A closeness between any distinct persons x and y of P is expressed by a value f(x,y). Here it is assumed that f(x,y) = f(y,x)</p>

<p>A group F of persons in P, that is, a subset of P, is called an awkward group if the number of persons in F, denoted by |F|, is equal to neither n nor 1 and the maximum closeness between any two distinct persons in F is strictly less than any closeness between a person in F and one not in F, that is, if F satisfies the following conditions:</p>

<p style="text-align: center;">1 < |F| < n and max{ f(x,y) | x ≠ y, x ∈ F, y ∈ F } < min{ f(x',y') | x' ∈ F, y' ∈ P - F}.</p>

<p>Given the values f(x,y) for any distinct person x and y in P, your program is to find the number of all the possible awkward groups of P.</p>

<p>For example, there are three persons x, y, and z in a community P. The groups F of P such that 1 < |F| < 3 are {x,y}, {y,z}, and {z,x}. The values for the closeness between two persons are given as f(x,y) = 8, f(y,z) = 3, and f(z,x) = 5. Then the awkward group among the candidates is only {y,z}. So the number of all the possible awkward groups of P is 1.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with a line containing an integer, n (1 ≤ n ≤ 1,000), where n is the number of persons in the community P. The persons are represented by integers 1 to n. In the following n-1 lines, the values h<sub>ij</sub> of the closeness are given. In the ith line, there are n-i integers h<sub>ii+1</sub>, h<sub>ii+2</sub>, ..., h<sub>in</sub> separated by a single space, where h<sub>ij</sub>, j = i+1, ..., n, are the values f(i,j) of the closeness between two persons i and j (1 ≤ i < j ≤ n and 1 ≤ h<sub>ij</sub> ≤ 10<sup>6</sup>).</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line for each test case. The line should contain an integer representing the number of all the possible awkward groups of P.</p>

