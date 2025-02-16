# [Platinum I] Cow Land - 17033 

[문제 링크](https://www.acmicpc.net/problem/17033) 

### 성능 요약

메모리: 18760 KB, 시간: 128 ms

### 분류

자료 구조, Heavy-light 분할, 최소 공통 조상, 세그먼트 트리, 트리

### 제출 일자

2023년 6월 4일 09:34:25

### 문제 설명

<p>Cow Land is a special amusement park for cows, where they roam around, eat delicious grass, and visit different cow attractions (the roller cowster is particularly popular).</p>

<p>There are a total of $N$ different attractions ($2 \leq N \leq 10^5$). Certain pairs of attractions are connected by pathways, $N-1$ in total, in such a way that there is a unique route consisting of various pathways between any two attractions. Each attraction $i$ has an integer enjoyment value $e_i$, which can change over the course of a day, since some attractions are more appealing in the morning and others later in the afternoon.</p>

<p>A cow that travels from attraction $i$ to attraction $j$ gets to experience all the attractions on the route from $i$ to $j$. Curiously, the total enjoyment value of this entire route is given by the bitwise XOR of all the enjoyment values along the route, including those of attractions $i$ and $j$.</p>

<p>Please help the cows determine the enjoyment values of the routes they plan to use during their next trip to Cow Land.</p>

### 입력 

 <p>The first line of input contains $N$ and a number of queries $Q$ ($1 \leq Q \leq 10^5$). The next line contains $e_1 \ldots e_N$ ($0 \leq e_i \leq 10^9$). The next $N-1$ lines each describe a pathway in terms of two integer attraction IDs $a$ and $b$ (both in the range $1 \ldots N$). Finally, the last $Q$ lines each describe either an update to one of the $e_i$ values or a query for the enjoyment of a route. A line of the form "1 $i$ $v$" indicates that $e_i$ should be updated to value $v$, and a line of the form "2 $i$ $j$" is a query for the enjoyment of the route connecting attractions $i$ and $j$.</p>

<p>In test data worth at most 50% of points, there will be no changes to the values of the attractions.</p>

### 출력 

 For each query of the form "2 $i$ $j$", print on a single line the enjoyment of
the route from $i$ to $j$.

