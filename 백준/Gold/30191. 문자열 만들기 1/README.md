# [Gold III] 문자열 만들기 1 - 30191 

[문제 링크](https://www.acmicpc.net/problem/30191) 

### 성능 요약

메모리: 8304 KB, 시간: 44 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2023년 9월 25일 17:21:46

### 문제 설명

<p>이번 학기 물리학실험의 조교장을 맡은 서현이는 학생들의 성적을 입력하는 일을 하고 있다.</p>

<p>서현이가 맡은 분반의 학생 수는 $N$명이고, 이 중 정확히 절반에 해당하는 학생들은 <code>S</code>, 나머지 절반의 학생들은 <code>U</code>를 받게 된다. $N$은 항상 짝수이다.</p>

<p>$1$번 학생, $2$번 학생, $\cdots$, $N$번 학생이 받을 성적이 길이 $N$인 문자열 $T$로 주어진다. 서현이가 할 일은 이 문자열을 전산 시스템에 입력하는 것이다.</p>

<p>서현이는 다음 시행만을 반복하여 학생들의 성적을 입력하려고 한다.</p>

<ol>
	<li>현재 커서의 위치에 <code>SU</code> 를 추가한다.</li>
	<li>커서가 맨 왼쪽에 있지 않은 경우, 커서를 왼쪽으로 한 글자 움직인다.</li>
	<li>현재 커서의 위치에 <code>US</code> 를 추가한다.</li>
</ol>

<p>처음 상태는 빈 문자열이며, 커서는 매 순간 문자열의 맨 앞이나 맨 끝, 또는 글자와 글자 사이에 위치한다. 1번 시행과 3번 시행이 끝난 뒤, 커서는 추가된 문자열의 바로 뒤로 이동한다.</p>

<p>서현이를 위해, 시행을 <strong>최대</strong> $2N$<strong>번 사용</strong>하여 학생들의 성적을 모두 입력하는 방법을 하나 찾아주자!</p>

### 입력 

 <p>첫째 줄에 문자열의 길이 $N$이 주어진다. ($2\le N\le 1\,000\,000$, $N$은 짝수)</p>

<p>둘째 줄에 학생들의 성적을 나타내는 S와 U로만 이루어진 문자열 $T$가 주어진다. $T$에서 S와 U의 개수는 같다.</p>

### 출력 

 <p>첫째 줄에 시행의 횟수 $K$를 출력한다. ($0\le K\le 2N$)</p>

<p>둘째 줄에 서현이의 시행을 나타내는 길이 $K$의 문자열을 출력한다. 1번 시행은 <code>S</code>, 2번 시행은 <code>N</code>, 3번 시행은 <code>U</code>로 나타낸다. 커서가 맨 왼쪽에 있을 때에는 2번 시행을 출력해서는 안 된다.</p>

<p>모든 시행이 끝난 뒤에 커서의 위치는 어디에 있든 상관없다.</p>

<p>답이 여러 가지 존재하는 경우 아무거나 하나만 출력한다.</p>

<p>입력 조건 하에서 답이 항상 존재함을 증명할 수 있다.</p>

