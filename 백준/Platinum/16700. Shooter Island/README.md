# [Platinum III] Shooter Island - 16700 

[문제 링크](https://www.acmicpc.net/problem/16700) 

### 성능 요약

메모리: 171456 KB, 시간: 1044 ms

### 분류

자료 구조, 분리 집합

### 제출 일자

2023년 11월 11일 13:49:15

### 문제 설명

<p>You were recently promoted to captain and your troopers are now operating on a special mission in a storm. The battlefield is kind of extraordinary, it is located above the Arctic Circle on a huge ice floe. You coordinate the actions from the headquarters. There are many high-end computers keeping you up to date on the developments at the battlefield, which is modeled by the AI interface as a grid of unit squares. Each unit square is identified by its row and column index in the grid. Bigger rectangles, consisting of unit squares, are described by a pair of unit squares in the opposite corners of the rectangle. At the beginning, all squares are covered with ice.</p>

<p>There are two important types of information you receive from the computers:</p>

<ol start="0">
	<li>Information about hits: Your enemy hit a rectangle described by unit squares [x<sub>1</sub>,y<sub>1</sub>] and [x<sub>2</sub>,y<sub>2</sub>]. This rectangle is then immediately flooded by cold arctic water.</li>
	<li>A query by your troopers: They ask whether it is possible to go from square [x<sub>1</sub>,y<sub>1</sub>] to [x<sub>2</sub>,y<sub>2</sub>] by a boat. The boat may be represented by a circle of radius 0.31416. Note that the boat has to stay fully on water surface all the time and it is not allowed to leave the battlefield area.</li>
</ol>

<p>Your troopers need your help! Can you guide them reliably?</p>

### 입력 

 <p>The first input line contains an integer L (1 ≤ L ≤ 2 · 10<sup>5</sup>), the number of lines to follow. Each of the next L lines contains five integers t, x<sub>1</sub>, y<sub>1</sub>, x<sub>2</sub>, y<sub>2</sub> (t ∈ {0, 1}, 1 ≤ x<sub>1</sub>, x<sub>2</sub> ≤ 50, 1 ≤ y<sub>1</sub>, y<sub>2</sub> ≤ 10<sup>5</sup>). Number t is the type of information and pairs [x<sub>1</sub>, y<sub>1</sub>] and [x<sub>2</sub>, y<sub>2</sub>] specify the respective unit squares.</p>

### 출력 

 <p>For each query, output 1 if it is possible to sail from unit square [x<sub>1</sub>,y<sub>1</sub>] to unit square [x<sub>2</sub>,y<sub>2</sub>], and 0 otherwise.</p>

