# [Platinum IV] Dyson Circle - 23770 

[문제 링크](https://www.acmicpc.net/problem/23770) 

### 성능 요약

메모리: 11408 KB, 시간: 72 ms

### 분류

애드 혹, 볼록 껍질, 기하학

### 제출 일자

2023년 9월 20일 12:16:12

### 문제 설명

<p>A Dyson Sphere is a theoretical construction around the sun or another star, that captures the entire energy output of the star. Science fiction writers have speculated that advanced civilizations will eventually build such a sphere, as the energy demands of such a society continue to grow without bounds. In our three-dimensional space, Dyson spheres are still in the realm of fiction. <em>Dy & Son</em>, the main energy company of your dimensional neighbours, has tasked you with carrying out a feasibility study in the two-dimensional world of Flatland.</p>

<p>Dy & Son has developed a modular Dyson Circle. It consists of independent square Dyson Units that can chain together to form a closed loop that gathers energy. Your task is to figure out how many of these Dyson units they actually need to enclose the star or stars they are interested in. Note that they want a single Dyson Circle, not a separate one for each star.</p>

<p>For convenience, both the stars Dy & Son wants to enclose and the Dyson Units used for this are modeled as squares of exactly $1$ by $1$ <em>Intergalactic Unit</em>, aligned to the <em>Intergalactic Coordinate System</em>. Your Dyson units connect if they have at least a corner in common. See Figure 1 for an example.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 212px; height: 212px;"></p>

<p style="text-align: center;">Figure 1: Illustration of Sample Input 1: four stars (yellow squares) and an optimal Dyson Circle (dashed blue squares) surrounding them, and the remaining blackness of space shown in white.</p>

<p>Formally, select some squares in the plane to turn into Dyson Units, such that the remaining squares can be split into <em>inside</em> and <em>outside</em> squares. All the stars must be inside squares. The inside squares must form a contiguous region (connected via edges) and not connect to the outside squares (via edges). The outside squares form a contiguous region stretching off to infinity.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1 \le n \leq 2 \cdot 10^5$), the number of stars.</li>
	<li>$n$ lines, each containing two integers $x$ and $y$ ($-10^6 \leq x, y \leq 10^6$), the location of the center of a star.</li>
</ul>

<p>No two stars are at the same location.</p>

### 출력 

 <p>Output the least number of Dyson units required to capture the energy of all stars in the input.</p>

