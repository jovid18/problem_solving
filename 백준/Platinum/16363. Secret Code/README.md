# [Platinum II] Secret Code - 16363 

[문제 링크](https://www.acmicpc.net/problem/16363) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

미적분학, 포함 배제의 원리, 수학

### 제출 일자

2023년 10월 11일 22:29:51

### 문제 설명

<p>Three secret agents <em>A</em>, <em>B</em> and <em>C</em> want to confirm if their secret codes are identical. To keep this secret, they did not set the meeting time. Instead, they decided to appear randomly at a café during the time interval [0, <em>S</em>] of a day. Let <em>t<sub>A</sub></em>, <em>t<sub>B</sub></em>, <em>t<sub>C</sub></em> denote the arrival time of <em>A</em>, <em>B</em>, and <em>C</em> to the café, respectively. So, <em>t<sub>A</sub></em>, <em>t<sub>B</sub></em>, <em>t<sub>C</sub></em> are random numbers chosen uniformly from time interval [0, <em>S</em>].</p>

<p>The code confirmation proceeds as follows. The agent who arrives earlier waits for the next agents to appear for a predetermined waiting time. If two agents encounter in the café, both check if their codes are identical. Then the agent who arrived earlier leaves the café immediately after the code confirmation. The second agent then waits till the third agent appears at the café. The agent leaves the café if the agent encounters the last agent in the agent’s own waiting time.</p>

<p>The waiting times of three agents <em>A</em>, <em>B</em>, <em>C</em> have already been determined as <em>w<sub>A</sub></em>, <em>w<sub>B</sub></em>, <em>w<sub>C</sub></em>. It is crucial that each of the arrival times <em>t<sub>A</sub></em>, <em>t<sub>B</sub></em>, <em>t<sub>C</sub></em> is a real number between 0 and <em>S</em>, not necessarily an integer, whereas each of the waiting times <em>w<sub>A</sub></em>, <em>w<sub>B</sub></em>, <em>w<sub>C</sub></em> is a positive integer satisfying 0 < <em>w<sub>A</sub></em> + <em>w<sub>B</sub></em>, <em>w<sub>B</sub></em> + <em>w<sub>C</sub></em>, <em>w<sub>A</sub></em> + <em>w<sub>C</sub></em> < <em>S</em>. We assume it takes no time in code confirmation task. The agent immediately leaves the café if the agent confirms the code with the agent arrived later. Let us explain this procedure using Figure G.1.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 557px; height: 299px;"></p>

<p style="text-align: center;">Figure G.1 Four cases for successful and unsuccessful confirmations.</p>

<p>Successful code confirmation needs at least two encounters among three agents. When the arrival order is <em>A</em>, <em>B</em>, <em>C</em>, both of Case-1 and Case-4 are examples for successful confirmation, but Case-2 and Case-3 are not. In Case-1, the agent <em>A</em> leaves the café at time <em>x</em> = <em>t<sub>B</sub></em> immediately not waiting by time <em>t<sub>A</sub></em> + <em>w<sub>A</sub></em>. It is easy to see that Case-2 is an unsuccessful case. In Case-2, though the waiting time of <em>A</em> overlaps those of <em>B</em> and <em>C</em>, <em>B</em> cannot confirm the code with <em>C</em> since the agent <em>A</em> (who already confirmed the code with B) leaves the café at time <em>x</em>. So, there is no way to confirm the code between <em>B</em> and <em>C</em>. Note that <em>A</em> also leaves the café at time <em>x</em> in Case-3 and Case-4.</p>

<p>We know the probability of the successful code confirmation depends on four integers (<em>S</em>, <em>w<sub>A</sub></em>, <em>w<sub>B</sub></em>, <em>w<sub>C</sub></em>). We are given <em>n</em> different scenarios determined by four integers (<em>S</em>, <em>w<sub>A</sub></em>, <em>w<sub>B</sub></em>, <em>w<sub>C</sub></em>). We want to sort these <em>n</em> scenarios in terms of this confirmation probability.</p>

<p>Given <em>n</em> scenarios, write a program to print the scenario indices in the non-decreasing order of the probability.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (3 ≤ <em>n</em> ≤ 20), where <em>n</em> is the number of scenarios. In the following <em>n</em> lines, each line contains four positive integers <em>S</em>, <em>w<sub>A</sub></em>, <em>w<sub>B</sub></em>, <em>w<sub>C</sub></em> in this order, describing a scenario (<em>S</em>, <em>w<sub>A</sub></em>, <em>w<sub>B</sub></em>, <em>w<sub>C</sub></em>) where 0 < <em>w<sub>A</sub></em> + <em>w<sub>B</sub></em>, <em>w<sub>B</sub></em> + <em>w<sub>C</sub></em>, <em>w<sub>A</sub></em> + <em>w<sub>C</sub></em> ≤ 1,000.</p>

### 출력 

 <p>Your program is to write to standard output. Print the indices of <em>n</em> scenarios in the non-decreasing order of the probability in one line. If scenarios <em>i</em> and <em>j</em> for 1 ≤ <em>i</em> < <em>j</em> ≤ <em>n</em> have the same probability, then print <em>i</em> before <em>j</em>.</p>

