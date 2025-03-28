# [Silver I] 지연 평가 - 27973 

[문제 링크](https://www.acmicpc.net/problem/27973) 

### 성능 요약

메모리: 2020 KB, 시간: 32 ms

### 분류

애드 혹, 사칙연산, 수학

### 제출 일자

2023년 4월 16일 16:08:39

### 문제 설명

<p>지연이는 자신이 가진 배열 $S$의 상태를 평가하려고 한다. <strong>처음에 $S$에는 $1$부터 $1 \, 234 \, 567 \, 890 \, 123$까지의 모든 정수가 $1$개씩 들어 있다.</strong></p>


<p>지연이를 도와 다음 명령을 수행하는 프로그램을 작성하시오.</p>

<ul>
	<li><code>0 x</code>: $S$의 모든 원소에 <code>x</code>를 더한다. $(-100 \, 000 \leq$ <code>x</code> $\leq 100 \, 000)$</li>
	<li><code>1 x</code>: $S$의 모든 원소에 <code>x</code>를 곱한다. $(1 \leq$ <code>x</code> $\leq 100)$</li>
	<li><code>2 n</code>: $S$에서 작은 원소부터 차례대로 <code>n</code>개를 제거한다. $(1 \leq$ <code>n</code> $\leq 100 \, 000 \, 000)$</li>
	<li><code>3</code>: $S$에서 가장 작은 원소를 출력한다.</li>
</ul>

<p><strong>이 문제의 풀이를 작성하기 전에, <code>예제</code> 밑의 <code>힌트</code>를 참조할 수 있다.</strong></p>

### 입력 

 <p>첫 줄에 명령의 개수 $Q$가 주어진다. $(1 \leq Q \leq 170 \, 000)$</p>

<p>다음 줄부터 위에서 설명한 네 개의 명령 중 하나가 주어진다. <code>x</code>, <code>n</code>은 정수이다.</p>

<p>하나의 테스트케이스에서 <code>2</code>번 명령으로 들어오는 모든 <code>n</code>의 합은 $1 \, 234 \, 567 \, 890 \, 120$ 이하이다.</p>

<p>하나의 테스트케이스에서 배열 $S$에 들어 있는 어떤 수든지 그 절댓값이 언제나 $10^{18}$ 이하가 되도록 하는 명령만이 주어진다.</p>

<p>마지막 명령은 항상 <code>3</code>이다.</p>

### 출력 

 <p>3번 명령이 들어올 때마다 그 시점에서 $S$에서 가장 작은 값을 한 줄에 하나씩 출력한다.</p>

