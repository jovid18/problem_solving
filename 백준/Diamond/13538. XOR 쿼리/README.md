# [Diamond IV] XOR 쿼리 - 13538 

[문제 링크](https://www.acmicpc.net/problem/13538) 

### 성능 요약

메모리: 162408 KB, 시간: 1184 ms

### 분류

자료 구조, 퍼시스턴트 세그먼트 트리, 세그먼트 트리

### 제출 일자

2023년 7월 9일 20:57:28

### 문제 설명

<p>비어있는 배열 A가 주어졌을 때, 다음과 같은 5가지 쿼리를 수행하는 프로그램을 작성하시오. 배열의 인덱스는 1부터 시작한다.</p>

<ul>
	<li><code>1 x</code>: 배열 A의 끝에 x를 추가한다.</li>
	<li><code>2 L R x</code>: A의 L번째 수부터 R번째 수까지 중에서 x와 xor한 값이 가장 큰 y를 찾아 출력한다.</li>
	<li><code>3 k</code>: 배열 A의 마지막 k개를 제거한다.</li>
	<li><code>4 L R x</code>: A의 L번째 수부터 R번째 수까지 중에서 x보다 작거나 같은 원소의 개수를 출력한다.</li>
	<li><code>5 L R k</code>: A의 L번째 수부터 R번째 수까지 중에서 k번째로 작은 수를 출력한다.</li>
</ul>

### 입력 

 <p>첫째 줄에 쿼리의 개수 M (1 ≤ M ≤ 500,000)이 주어진다.</p>

<p>둘째 줄부터 M개의 줄에는 쿼리가 한 줄에 하나씩 주어진다. (1 ≤ x ≤ 500,000, 1 ≤ L ≤ R ≤ N)</p>

<p>3번 쿼리의 경우 1 ≤ k ≤ N, 5번 쿼리의 경우: k ≤ R-L+1</p>

<p>N은 쿼리를 실행하기 전 배열 A의 크기이다.</p>

### 출력 

 <p>2,4,5번 쿼리의 정답을 한 줄에 하나씩 순서대로 출력한다.</p>

