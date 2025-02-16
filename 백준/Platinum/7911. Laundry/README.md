# [Platinum IV] Laundry - 7911 

[문제 링크](https://www.acmicpc.net/problem/7911) 

### 성능 요약

메모리: 56836 KB, 시간: 1000 ms

### 분류

자료 구조, 그리디 알고리즘, 트리를 사용한 집합과 맵

### 제출 일자

2023년 10월 31일 10:31:20

### 문제 설명

<p>A few friends have decided to do laundry together. They are all very neat, so each day each of the friends wears one clean pair of socks and one clean shirt. The friends have put all dirty socks and shirts to their washing machine. Now they have started to plan how they will dry their laundry. To put this in order, they have decided that:</p>

<ul>
	<li>every sock will be fastened to the string with a single clothespin,</li>
	<li>each shirt will be fastened with three clothespins,</li>
	<li>one person’s socks should all be fastened with clothespins of the same color,</li>
	<li>one person’s shirts should all be fastened with clothespins of the same color,</li>
	<li>clothes belonging to different persons may not be fastened with clothespins of the same color,</li>
	<li>apart from that, they wish to use the smallest possible number of clothespin’s colors.</li>
</ul>

<p>Now they have scattered all their clothespins on the floor and counted the number of clothespins of each color. Unfortunately, they were not able to figure out which colors should each of them use. Write a program that will help them with this problem.</p>

### 입력 

 <p>The first line of input contains two integers n and k (2 ≤ n, k ≤ 1 000 000) denoting the number of friends and the number of clothespins’ colors available. The second line contains n numbers d<sub>1</sub>, d<sub>2</sub>, ..., d<sub>n</sub> representing the number of days each friend was collecting laundry (1 ≤ d<sub>i</sub> ≤ 1 000 000). The third line contains k numbers l<sub>1</sub>, l<sub>2</sub>, ..., l<sub>k</sub> representing the numbers of clothespins of respective colors (1 ≤ l<sub>i</sub> ≤ 4 000 000).</p>

### 출력 

 <p>Your program should output the minimal number of clothespins needed to dry all the laundry. If it is not possible to dry all the laundry in the requested manner, your program should output a single word NIE (i.e., no in Polish).</p>

