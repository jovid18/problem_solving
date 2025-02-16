# [Platinum V] 숲속에서 새 구경하기 - 25196 

[문제 링크](https://www.acmicpc.net/problem/25196) 

### 성능 요약

메모리: 2020 KB, 시간: 164 ms

### 분류

브루트포스 알고리즘, 구현, 수학, 시뮬레이션

### 제출 일자

2023년 7월 25일 23:38:47

### 문제 설명

<p style="text-align: center;"><img alt="곰곰이" src="" style="max-height:120px; object-fit:contain; display:inline-block;"></p>

<p>곰곰이는 바위에 앉아 새 3마리가 숲 주변을 비행하는 것을 구경하고 있다. 곰곰이는 새들을 관찰하면서 아래와 같은 사실들을 알아냈다.</p>

<ul>
	<li>첫 번째 새는 $A_v$ 초, 두 번째 새는 $B_v$ 초, 세 번째 새는 $C_v$ 초 주기로 숲을 한 바퀴 돈다.</li>
	<li>현재로부터 $t\ (t \ge 0)$ 초가 지났다고 할 때, 곰곰이는...
	<ul>
		<li>$A_v \times k_a + A_s \le t \le A_v \times k_a + A_e$ 일 때 첫 번째 새를 볼 수 있다. ($k_a$ 는 $0$ 이상의 정수)</li>
		<li>$B_v \times k_b + B_s \le t \le B_v \times k_b + B_e$ 일 때 두 번째 새를 볼 수 있다. ($k_b$ 는 $0$ 이상의 정수)<img alt="" src=""></li>
		<li>$C_v \times k_c + C_s \le t \le C_v \times k_c + C_e$ 일 때 세 번째 새를 볼 수 있다. ($k_c$ 는 $0$ 이상의 정수)<img alt="" src=""><img alt="" src=""></li>
	</ul>
	</li>
</ul>

<p>곰곰이가 새 3마리를 한번에 볼 수 있는 최초의 시각은 현재로부터 몇 초 뒤인지 구해보자.</p>

### 입력 

 <p>첫 번째 줄에 정수 $A_v$, $A_s$, $A_e$ 가 공백을 사이에 두고 주어진다. ($1 \le A_v \le 2\,000, 0 \le A_s \le A_e \lt A_v$)</p>

<p>두 번째 줄에 정수 $B_v$, $B_s$, $B_e$ 가 공백을 사이에 두고 주어진다. ($1 \le B_v \le 2\,000, 0 \le B_s \le B_e \lt B_v$)</p>

<p>세 번째 줄에 정수 $C_v$, $C_s$, $C_e$ 가 공백을 사이에 두고 주어진다. ($1 \le C_v \le 2\,000, 0 \le C_s \le C_e \lt C_v$)</p>

### 출력 

 <p>현재로부터 $t$ 초 뒤에 곰곰이가 새 3마리를 최초로 한번에 볼 수 있다고 할 때, $t$ 를 첫 번째 줄에 출력하라.</p>

<p>만약 그런 순간이 영원히 오지 않는다면 <code>-1</code> 을 출력하라.</p>

