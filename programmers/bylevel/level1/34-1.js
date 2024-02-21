function solution(sizes) {
  // 전략: 가로 세로길이가 어떤것은 가로가 길고 어떤 것은 세로가 긴 상황이므로
  // 모든 명함을 세로가 가로보다 크도록 함 (그리디 전략, 이유는 모름, 찍었는데 맞춤 good)
  // 그리고 모든 명함의 가로의 최댓값, 모든 명함의 세로의 최댓값을 구해서 그 둘을 곱한게 정답
  let maxh = 0; //최종 지갑의 세로
  let maxw = 0; //최종 지갑의 가로
  sizes.forEach(([noww, nowh]) => {
    maxh = Math.max(maxh, Math.max(noww, nowh)); //noww와 nowh의 값중 큰 것으로 maxh를 갱신
    maxw = Math.max(maxw, Math.min(noww, nowh)); //noww와 nowh의 값중 작은 것으로 maxw를 갱신
  });
  return maxw * maxh;
}
// 초기 지갑 사이즈 maxh :0 , maxw : 0
// 60 50 => 60 50  maxh :60 , maxw : 50
// 30 70 => 70 30  maxh :70 , maxw : 50
// 60 30 => 60 30  maxh :70 , maxw : 50
// 80 40 => 80 40  maxh :80 , maxw : 50

// 가로 길이의 최대는 80 세로 길이의 최대는 50 이 둘을 곱하면 4000
