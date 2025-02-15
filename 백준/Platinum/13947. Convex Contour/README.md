# [Platinum IV] Convex Contour - 13947 

[문제 링크](https://www.acmicpc.net/problem/13947) 

### 성능 요약

메모리: 2216 KB, 시간: 0 ms

### 분류

많은 조건 분기, 볼록 껍질, 기하학

### 제출 일자

2023년 12월 26일 08:52:24

### 문제 설명

<p>A number of geometric shapes are neatly arranged in a rectangular grid. The shapes occupy consecutive cells in a single row with each cell containing exactly one shape. Each shape is either:</p>

<ul>
	<li>a square perfectly aligned with the grid square,</li>
	<li>a circle inscribed in the grid square,</li>
	<li>or an equilateral triangle with a side corresponding to the bottom side of the grid square.</li>
</ul>

<p><img alt="" src="" style="height:93px; width:370px"></p>

<p>The shapes from the first example input and their convex contour.</p>

<p>Informally, the convex contour of an arrangement is the shortest line that encloses all the shapes. Formally, we can define it as the circumference of the convex hull of the union of all shapes.</p>

<p>Given an arrangement of shapes, find the length of its contour.</p>

### 입력 

 <p>The first line contains an integer n (1 ≤ n ≤ 20) — the number of shapes. The following line contains a string consisting of n characters that describes the shapes in the arrangement left to right. Each character is an uppercase letter “S”, “C” or “T” denoting a square, circle or a triangle respectively.</p>

### 출력 

 <p>Output a single floating point number — the length of the contour. The solution will be accepted if the absolute or the relative difference from the judges solution is less than 10<sup>−6</sup> .</p>

