# [Gold III] 最古の遺跡 - 5593 

[문제 링크](https://www.acmicpc.net/problem/5593) 

### 성능 요약

메모리: 26656 KB, 시간: 40 ms

### 분류

브루트포스 알고리즘, 자료 구조, 기하학, 해시를 사용한 집합과 맵

### 제출 일자

2025년 3월 6일 02:49:13

### 문제 설명

<p>昔, そこには集落があり, 多くの人が暮らしていた. 人々は形も大きさも様々な建 物を建てた. だが, それらの建造物は既に失われ, 文献と, 遺跡から見つかった柱だけ が建造物の位置を知る手がかりだった.</p>

<p>文献には神殿の記述がある. 神殿は上から見ると正確に正方形になっており, その 四隅には柱があった. 神殿がどの向きを向いていたかはわからない. また, 辺上や内 部に柱があったかどうかもわからない. 考古学者たちは, 遺跡から見つかった柱の中 で, 正方形になっているもののうち, 面積が最大のものが神殿に違いないと考えた.</p>

<p>柱の位置の座標が与えられるので, 4 本の柱でできる正方形のうち面積が最大のも のを探し, その面積を出力するプログラムを書け. なお, 正方形の辺は座標軸に平行 とは限らないことに注意せよ.</p>

### 입력 

 <p>1 行目には, 遺跡から見つかった柱の本数 n が書かれている.</p>

<p>2 行目から n + 1 行目までの n 行の各々には, 柱の x 座標と y 座標が空白区切り で書かれている.</p>

<p>1 本の柱が 2 度以上現れることはない.</p>

<p>n は 1 ≤ n ≤ 3000 を満たす整数であり, 柱の x 座標と y 座標は 0 以上 5000 以 下の整数である.</p>

### 출력 

 <p>出力ファイルには 1 個の整数を出力する. 4 本の柱からなる正方形が存在する場 合は, そのような正方形のうち面積が最大のものの面積を出力し, そのような正方形 が存在しない場合は 0 を出力せよ.</p>

