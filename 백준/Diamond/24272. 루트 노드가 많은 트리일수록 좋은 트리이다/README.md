# [Diamond V] 루트 노드가 많은 트리일수록 좋은 트리이다 - 24272 

[문제 링크](https://www.acmicpc.net/problem/24272) 

### 성능 요약

메모리: 22384 KB, 시간: 364 ms

### 분류

자료 구조, 오일러 경로 테크닉, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 트리

### 제출 일자

2023년 6월 13일 08:28:58

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="height: 174px; width: 320px;"></p>

<p>$N$ 개의 노드와 $N-1$ 개의 간선으로 이루어진 그래프가 있다. 노드는 $1$번부터 $N$번까지 번호가 매겨져 있으며, 각 간선은 방향성을 가지고 있을 수도 있고, 무방향성일 수도 있다. 모든 간선의 방향성을 제거할 경우 이 그래프는 트리가 된다.</p>

<p>어떤 노드에서 다른 모든 노드로 가는 경로가 존재하는 경우 이 노드를 ‘루트 노드’라고 하자. 이 그래프의 ‘좋음’은 루트 노드의 수로 정의한다. 이 때, 다음 쿼리들을 수행하자.</p>

<ol>
	<li>$u$와 $v$를 잇는 간선을 $u \rightarrow v$의 방향 간선으로 바꾼다.</li>
	<li>$u$와 $v$를 잇는 간선을 $u \leftarrow v$의 방향 간선으로 바꾼다.</li>
	<li>$u$와 $v$를 잇는 간선을 무방향 간선으로 바꾼다.</li>
</ol>

<p>쿼리의 실행 결과는 그래프에 누적된다.</p>

### 입력 

 <p>첫 번째 줄에는 노드의 수 $N$이 주어진다.</p>

<p>두 번째 줄부터 $N-1$ 개 줄에 걸쳐 간선들에 대한 정보가 주어진다. 간선의 정보는 공백으로 구분된 세 개의 토큰 $U_i$, $D_i$, $V_i$로 주어지며, $U_i$와 $V_i$는 정점 번호를 의미하는 정수이고 $D_i$는 방향을 의미하는 문자열로 <span style="color:#e74c3c;"><code>-></code></span>, <span style="color:#e74c3c;"><code><-</code></span>, <span style="color:#e74c3c;"><code>--</code></span> 중 하나이다.</p>

<ul>
	<li>$D_i$가 <span style="color:#e74c3c;"><code>-></code></span>라면 $i$번째 간선은 $U_i \rightarrow V_i$인 방향 간선이다.</li>
	<li>$D_i$가 <span style="color:#e74c3c;"><code><-</code></span>라면 $i$번째 간선은 $U_i \leftarrow V_i$인 방향 간선이다.</li>
	<li>$D_i$가 <span style="color:#e74c3c;"><code>--</code></span>라면 $i$번째 간선은 $U_i \leftrightarrow V_i$인 무방향 간선이다.</li>
</ul>

<p>다음 줄에는 수행할 쿼리의 수 $Q$가 주어진다.</p>

<p>다음 줄부터 $Q$ 개의 줄의 각 줄마다 쿼리가 순서대로 주어진다. $i$ 번째 줄에는 세 개의 토큰 $u_i$ $d_i$ $v_i$로 주어지며, $u_i$와 $v_i$는 정점 번호를 의미하는 정수이고 $d_i$는 방향을 의미하는 문자열로 <span style="color:#e74c3c;"><code>-></code></span>, <span style="color:#e74c3c;"><code><-</code></span>, <span style="color:#e74c3c;"><code>--</code></span> 중 하나이다.</p>

<ul>
	<li>$d_i$가 <span style="color:#e74c3c;"><code>-></code></span>라면 $i$번째 간선을 $u_i \rightarrow v_i$인 방향 간선으로 설정한다.</li>
	<li>$d_i$가 <span style="color:#e74c3c;"><code><-</code></span>라면 $i$번째 간선을 $u_i \leftarrow v_i$인 방향 간선으로 설정한다.</li>
	<li>$d_i$가 <span style="color:#e74c3c;"><code>--</code></span>라면 $i$번째 간선을 $u_i \leftrightarrow v_i$인 무방향 간선으로 설정한다.</li>
</ul>

### 출력 

 <p>쿼리를 수행할 때마다 그래프의 ‘좋음’을 한 줄에 하나씩 출력한다.</p>

