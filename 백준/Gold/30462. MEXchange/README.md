# [Gold I] MEXchange - 30462 

[문제 링크](https://www.acmicpc.net/problem/30462) 

### 성능 요약

메모리: 5340 KB, 시간: 44 ms

### 분류

애드 혹, 해 구성하기, 그리디 알고리즘

### 제출 일자

2023년 12월 26일 06:32:04

### 문제 설명

<p>길이가 $N$인 순열은 $1$부터 $N$까지의 정수가 정확히 한 번씩 등장하는 수열이다. 예를 들어, $\left[ 2,3,1,5,4 \right]$는 순열이지만 $\left[ 1,2,2 \right]$는 $2$가 두 번 등장하기 때문에 순열이 아니다. 또한 $\left[ 1,3,4 \right]$도 길이가 $3$이지만 $4$가 등장하기 때문에 순열이 아니다.</p>

<p>길이가 $N$인 순열 $A$가 주어졌을 때, 수열 $B$를 다음과 같이 정의하자.</p>

<p>$$B_i=\operatorname{MEX}\left( \{A_1,A_2,\cdots ,A_i\} \right)\ (1 \leq i \leq N)$$</p>

<p>길이가 $N$인 수열 $B$가 주어질 때, 순열 $A$를 구해보자.</p>

<p>$\operatorname{MEX}\left( S \right)$는 집합 $S$에 포함되지 않는 가장 작은 양의 정수이다. 예를 들어, $\operatorname{MEX}\left(\{ 1,2,5 \}\right) =3$이고 $\operatorname{MEX}\left(\{ 2,3,4 \}\right) =1$이다. 이 문제에서 정의한 $\operatorname{MEX}$는 그 값으로 $0$이 나올 수 없음에 주의하라.</p>

### 입력 

 <p>첫째 줄에 순열 $A$의 길이 $N$이 주어진다. $\left( 3\leq N\leq 200\, 000 \right)$</p>

<p>둘째 줄에 수열 $B$의 원소를 나타내는 $N$개의 정수 $B_i$가 공백으로 구분되어 주어진다. $\left( 1\leq B_i\leq N+1 \right)$</p>

### 출력 

 <p>첫째 줄에 $B$가 되는 순열 $A$가 존재하면 <span style="color:#e74c3c;"><code>Yes</code></span>를 출력하고 그렇지 않으면 <span style="color:#e74c3c;"><code>No</code></span>를 출력한다.</p>

<p>만약 존재한다면 둘째 줄에 순열 $A$의 원소를 공백으로 구분하여 출력한다. 답이 여러 가지라면 아무거나 출력한다.</p>

