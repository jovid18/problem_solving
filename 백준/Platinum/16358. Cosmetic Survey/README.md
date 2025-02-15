# [Platinum IV] Cosmetic Survey - 16358 

[문제 링크](https://www.acmicpc.net/problem/16358) 

### 성능 요약

메모리: 5032 KB, 시간: 636 ms

### 분류

플로이드–워셜, 그래프 이론, 최단 경로

### 제출 일자

2023년 10월 4일 23:04:22

### 문제 설명

<p>ICP(International Cosmetic Perfection) Company plans to survey the preferences of new <em>m</em> cosmetics in order to know which cosmetic is the most preferred. For this survey, ICPC selected <em>n</em> people as evaluators. Each evaluator must submit an ordered list of the preferences on those <em>m</em> cosmetics. Each evaluator can rank the cosmetics as follows:</p>

<ul>
	<li>An evaluator can rank cosmetics with positive integer numbers, but the positive integers are not necessarily consecutive. The cosmetics with the smallest positive number are the most preferred ones, and the ones with the second smallest positive number are the second most preferred ones, and so on.</li>
	<li>An evaluator can give the same preference to more than one cosmetic. This indicates that this evaluator has no preference among those cosmetics.</li>
	<li>An evaluator may not rank some cosmetics. The unranked cosmetics are marked with number 0 in the ordered list. This indicates that this evaluator strictly prefers all ranked to all unranked ones, and has no preference among all unranked ones.</li>
</ul>

<p><img alt="" src="" style="width: 194px; height: 182px; float: right;">For example, the right figure shows an ordered list of the preferences on six cosmetics A, B, C, D, E, F that an evaluator submitted. The cosmetics A, C, E, F are ranked with nonconsecutive integers of 1, 4, 1, 3, respectively. The other two cosmetics B and D are not ranked, thus they are marked with 0 . A and E have the same preference, which are the most preferred cosmetics because their preference number is the smallest positive integer. The unranked B and D are less preferred than the ranked ones. As a result, the preference order of this evaluator is A = E ≻ F ≻ C ≻ B = D, where X ≻ Y means that X is strictly preferred to Y and X = Y means the same preference.</p>

<p>Which cosmetics are the most preferred ones from <em>n</em> evaluators in this preference survey? We must now define which one is preferred to another. Let d(X, Y) be the number of evaluators who strictly prefer X to Y. A path from X to Y is a sequence of distinct cosmetics C<sub>1</sub>, ..., C<sub>k</sub> such that C<sub>1</sub> = X, C<sub>k</sub> = Y, and d(C<sub>t</sub>, C<sub>t+1</sub>) > d(C<sub>t+1</sub>, C<sub>t</sub>) for every t = 1, ... , k − 1. The preference index of this path is defined as the minimum of d(C<sub>t</sub>, C<sub>t+1</sub>) for 1 ≤ t < k. For two distinct cosmetics X and Y that are connected by a path from X to Y, the preference strength S(X,Y) is the maximum preference index over all paths from X to Y. If there is no path from X to Y, then S(X,Y) is defined as zero. Cosmetic X is one of the most preferred cosmetics from this survey if and only if S(X,Y) ≥ S(Y,X) for every Y other than X. You note that it has been known for this type of surveys that there always exists at least one cosmetic that is preferred the most.</p>

<p>Given preference lists of <em>n</em> evaluators for <em>m</em> cosmetics, write a program to output all the most preferred cosmetics.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing two integers, <em>m</em> and <em>n</em> (1 ≤ <em>m</em> ≤ 500, 1 ≤ <em>n</em> ≤ 500), where <em>m</em> is the number of cosmetics and <em>n</em> is the number of evaluators. The cosmetics are numbered from 1 to <em>m</em>, and the evaluators are numbered from 1 to <em>n</em>. In the following <em>n</em> lines, the <em>i</em>-th line contains <em>m</em> nonnegative integers that represent the preference values for the <em>m</em> cosmetics of the evaluator <em>i</em>. The preference values are ordered from the cosmetic 1 to the cosmetic <em>i</em>. The zero values in the list mean that the evaluator unranked the corresponding cosmetics. The preference values are no more than 10<sup>6</sup>.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the numbers of the cosmetics that are preferred the most. Such cosmetic numbers must appear in increasing order.</p>

