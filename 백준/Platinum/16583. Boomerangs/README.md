# [Platinum I] Boomerangs - 16583 

[문제 링크](https://www.acmicpc.net/problem/16583) 

### 성능 요약

메모리: 19848 KB, 시간: 76 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘, 트리

### 제출 일자

2023년 6월 6일 11:11:37

### 문제 설명

<p>Let G = (V, E) be a simple undirected graph with N vertices and M edges, where V = {1, . . . , N}. A tuple <u, v, w> is called as boomerang in G if and only if {(u, v),(v, w)} ⊆ E and u ≠ w; in other words, a boomerang consists of two edges which share a common vertex.</p>

<p>Given G, your task is to find as many disjoint boomerangs as possible in G. A set S contains disjoint boomerangs if and only if each edge in G only appears at most once (in one boomerang) in S. You may output any valid disjoint boomerangs, but the number of disjoint boomerangs should be maximum.</p>

<p>For example, consider a graph G = (V, E) of N = 5 vertices and M = 7 edges where E = {(1, 2), (1, 4), (2, 3), (2, 4), (2, 5), (3, 4), (3, 5)}.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 242px; height: 167px;"></p>

<p>The maximum number of disjoint boomerangs in this example graph is 3. One example set containing the 3 disjoint boomerangs is {<4, 1, 2>,<4, 3, 2>,<2, 5, 3>}; no set can contain more than 3 disjoint boomerangs in this example.</p>

### 입력 

 <p>Input begins with a line containing two integers: N M (1 ≤ N, M ≤ 100000), representing the number of vertices and the number edges in G, respectively. The next M lines, each contains two integers: u<sub>i</sub> v<sub>i</sub> (1 ≤ u<sub>i</sub> < v<sub>i</sub> ≤ N), representing the edge (u<sub>i</sub>, v<sub>i</sub>) in G. You may safely assume that each edge appears at most once in the given list.</p>

### 출력 

 <p>The first line of output contains an integer: K, representing the maximum number of disjoint boomerangs in G. The next K lines, each contains three integers: u v w (each separated by a single space), representing a boomerang <u, v, w>. All boomerangs in the output should be disjoint. If there is more than one valid solution, you can output any of them.</p>

